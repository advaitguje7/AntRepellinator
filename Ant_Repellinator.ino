int arduinoList[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
int espList[] = {14, 12, 13, 25, 26, 27, 33, 32, 35};
// SERVO

//#include <Servo.h>
#include <ESP32Servo.h>
Servo myservo;
int servoPin = espList[6];

// ULTRASONIC SENSOR

const int trigPin = espList[7];
const int echoPin = espList[8];
float duration, distance; 

// variables
float front_distance;
float left_distance;
float right_distance;
float threshold = 50;
int turn_time = 750;
// MOTOR DRIVER


// Motor A Connections
const int enA = espList[5];
const int RF = espList[3]; // used to be 7
const int RB = espList[4];
// Motor B connections
const int enB = espList[0];
const int LF = espList[2];
const int LB = espList[1];




void setup() {
  //put your setup code here, to run once:
  myservo.attach(servoPin);
  myservo.write(180); // initialize position to zero
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);


  
  Serial.begin(9600);
}

void stopMotors() {
  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW); 
  digitalWrite(LB, LOW);
  digitalWrite(RB, LOW); 
  digitalWrite(enA, LOW); 
  digitalWrite(enB, LOW);
}

float check_distance(int trigPin, int echoPin) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);

  long duration = pulseIn(echoPin, HIGH, 30000);  // timeout after 30ms
  float distance = duration * 0.0343 / 2.0;

  Serial.print("Distance (cm): ");
  Serial.println(distance);

  delay(100);  // short delay is okay
  return distance;
}

void move_forward() {
  Serial.println("[Move forward]");

  digitalWrite(RF, LOW);
  digitalWrite(LF, LOW);

  digitalWrite(enA, 250); 
  digitalWrite(enB, 250);

  digitalWrite(RF, 250);
  digitalWrite(LF, 250);
  delay(2000); // move for (2) seconds
  stopMotors();
  delay(1000);
}

void turn_right() {
  Serial.println("[Turn right]");
  digitalWrite(enA, 250); 
  digitalWrite(enB, 250); 
  digitalWrite(LF, 250);
  digitalWrite(RB, 250);

  delay(turn_time); // move for (0.5) seconds (time TK)
  stopMotors();
}

void turn_left() {
  Serial.println("[Turn left]");
  digitalWrite(enA, 250); 
  digitalWrite(enB, 250); 
  digitalWrite(RF, 250);
  digitalWrite(LB, 250);

  delay(1000); // move for (1) seconds (time TK)
  stopMotors();
}

void turn_around() {
  Serial.println("[Turning around]");
  turn_right();
  delay(20);
  turn_right();
  delay(20);
  stopMotors();   
}


void loop() {
  
  
  // put your main code here, to run repeatedly:
  myservo.write(180); // rotate left
  Serial.println("Checking left...");
  delay(1000);

  left_distance = check_distance(trigPin,echoPin); // check left
  delay(1000);

  myservo.write(90); // rotate front
  Serial.println("Checking front");
  delay(1000);

  front_distance = check_distance(trigPin, echoPin);
  delay(1000);

  myservo.write(0); // rotate right
  Serial.println("Checking right...");
  delay(1000);

  right_distance = check_distance(trigPin,echoPin);
  Serial.println("Motion:");
  delay(1000);

  if (left_distance > threshold) {
  	turn_left();
    move_forward();
  } else if ( (left_distance < threshold) && (front_distance > threshold) ) {
    move_forward();
  } else if ( (left_distance < threshold) && (front_distance < threshold) && (right_distance > threshold) ) {
  	turn_right();
    move_forward();
  } else if ( (left_distance < threshold) && (front_distance < threshold) && (right_distance < threshold) ) {
    turn_around();
  }
delay(500);
}

