## Members
Advait Guje, Electrical Engineering Student (2028)
advaitg108@vt.edu

## Mentor
MENTOR NAME HERE

## Current Status
In Progress
## Project Overview

The Ant Repellinator (AR) is an ant-control car that will detect and deter ants in a given room. The AR will work by placing it in the corner of a room, after which it will traverse the edge of the room, determining the location of the ants. After a data-collection period, the AR will loop back around the room, releasing a surface-treatment liquid to repel ants from entering the room through those entry points. For this project, however, I will not be using any chemicals. Instead I will be using water.

<timeline>
I expect the project to take 4-5 months to complete at most, as it is a larger project. My planned division of tasks are as follows:
Design and Planning (including determining dimensions of parts, general organization of components, and particular types of each component) : 1-2 weeks
Actual Designing (Chassis using CAD and PCB using KiCAD): 2-3 weeks
Construction: 4-6 weeks
-> Chassis
-> Device Circuitry
    -> Ultrasonic Sensor
    -> ESP-32 CAM
    -> Motors
-> Repellant Release System (uses a servo and oval cam)
Computer Vision: Unsure
Testing: 3-4 weeks
  
<delays>
My estimates result in a timeline of 4.5 months (12 weeks) at most. However, factoring in midterms, clubs, and work, I think this timeline isn't realistic. I am also completely new to computer vision, so I believe there may be some unforseen issues/delays. Furthermore, the code I wrote for room traversal has not been tested, so I am not even sure if it works with real walls, objects, etc.

<components>
The AR will have four general parts: The car, the guidance system, the detection system, and the spray system. The car consists of the chassis and wheels. The guidance system will consist an ultrasonic sensor and a stepper motor. The ant-detection circuit will use an ESP-32 CAM. A central ESP-32 Arduino will control all three parts. 

The components are:
an ESP-32 (have)
an ultrasonic sensor (have)
motor drivers (have)
9V battery (have)
two DC geared motors (do not have)
an ESP-32 cam (do not have) 
two stepper motors (do not have)

## Educational Value Added

The project will allow me to develop/hone my understanding of both hardware and software. I plan on 3D printing the AR chassis and the wheels (if needed), giving me the opportunity to hone my CAD skills. Designing the PCBs and building the circuits will give me an invaluable understanding of some practical applications of circuit design. Finally, programming the ESP-32 and ESP-32 CAM in the Arduino IDE (C/C++) will give me programming experience. 

## Milestones
1. The car
   - Tasks: 3D printing the body, designing the central PCB
   - Components: DC geared motor
2. Guidance + Detection System
   - Tasks: 3D printing the servo box, designing the PCB, building circuit
   - Components: Stepper Motors, ESP-32 CAM
3. Spray System
   - Tasks: 3D printing repellent holder
   - Components: Stepper Motor

## Tasks

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## Design Decisions

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## Design Misc

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## Steps for Documenting Your Design Process

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## BOM + Component Cost

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## Timeline

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## Useful Links

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->

## Log

<!-- Your Text Here. You may work with your mentor on this later when they are assigned -->






