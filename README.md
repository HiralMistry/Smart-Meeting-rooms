Overview
===

This project is all about making the meeting rooms smarter which automatically turns ON the lights if required and controls the room temperature if a person is present in the room. It automatically turns OFF lights and AC/Heater if nobody is present in the room. 
It is a type of finite state machine and the complete operation can be achieved by using elma (Event Loop Management) and finite state machines.

I am going to implement this code on Raspberry Pi.

The project can be considered complete once I have tests for each of the events such as 
- Temperature changes
- Motion detected
- No motion for certain time

Resources
===

- [Event loop management](https://github.com/klavinslab/elma)
- Docker
- C++ libraries: iostream , chrono, vector, string, deque, json/json.h, tuple, stdexcept, map, functional

Tasks Completed
======

1) Decided to go for the project of Finite State Machine and selected the topic of Project: Smart Meeting rooms
2) Forked the professors elma code and made a new repository.
3) Started making the code for the project.
4) Made a state machine diagram for the project and uploaded to the hw_8 folder.


Milestones
======

1) Search and learn more about Raspberry Pi and Download the Pi Desktop. (Before Next Class)
2) Analyze what all is needed to install to the Pi for making my code working on Pi. (Before Next Class)
3) Implement a simple event management process (as described in state diagram) (Before Next Class)
4) Write tests for a simple workflow. (By next Sunday)
5) Add more features such as "checkAvailability" of rooms, "changeTemperature" of rooms based on temperature sensors and other conditions, "changeLightIntensities" of room based on related light intensity sensors. 
6) Write more tests for these new features
7) Complete the project report.
