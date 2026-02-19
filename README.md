# Arduino Ultrasonic + LCD + Servo (Simple Demo)

A small Arduino project using:
- **HC-SR04 ultrasonic sensor** to measure distance
- **16x2 LCD** to show the distance
- **Servo motor** that moves when something is close

This is a simple beginner-style project, but it’s organized enough to be shared and built by someone else.

## What it does
- Sends an ultrasonic pulse (HC-SR04)
- Measures echo time with `pulseIn()`
- Converts time to distance (cm)
- Prints to Serial + shows on LCD
- If distance is less than a threshold, moves the servo through a few angles

## Hardware
- Arduino Uno
- HC-SR04 ultrasonic sensor
- 16x2 LCD
- SG90 servo
- Breadboard + jumper wires

## Default pins
**HC-SR04**
- TRIG → D9  
- ECHO → D10  
- VCC → 5V  
- GND → GND  

**Servo**
- Signal → D3  
- VCC → 5V  
- GND → GND

**LCD (4-bit mode)**
- RS → D12
- E  → D11
- D4 → D4
- D5 → D5
- D6 → D6
- D7 → D7

## Build / Upload (PlatformIO)
This repo uses PlatformIO.

1. Install VS Code
2. Install the PlatformIO extension
3. Open the folder in VS Code
4. Click **Upload**
5. Open **Serial Monitor** at **9600 baud**

## Tuning
In `src/main.cpp`:
- `triggerDistanceCm` controls when the servo triggers
- `echoTimeoutUs` controls how long it waits for an echo before giving up

## Notes / Possible improvements
- LCD flickers slightly because the code clears it each loop.
- Servo movement is a simple demo pattern (could be changed to a smoother or “one-time” trigger).
- Could add averaging/filtering to reduce noisy distance readings.
