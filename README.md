# Ultrasonic Tactile Alert

Arduino project exploring tactile feedback for blind/low-vision navigation using an ultrasonic sensor.

## Overview
This repository contains a proof-of-concept build using an ultrasonic sensor to measure obstacle distance. The measured distance is displayed on a 16×2 LCD, and when an object is within a defined threshold (default: 30 cm), a servo motor generates repeated tactile “tap” alerts. This project is intended for experimentation and demonstration. It is not a finished assistive or safety device and has not been validated for real-world deployment.

## What it does
- Measures distance using an ultrasonic sensor
- Displays real-time distance data on a 16×2 LCD
- Triggers repeated servo “tap” feedback when an object is within a set threshold

## Parts used
- Arduino Uno (ATmega328P)
- HC-SR04 ultrasonic sensor (or compatible)
- 16×2 LCD display
- Servo motor
- Breadboard and jumper wires

## How to run
### Using PlatformIO (Recommended)
1. Install Visual Studio Code
2. Install the PlatformIO IDE extension
3. Clone this repository:
   git clone https://github.com/jlee056/Ultrasonic-Tactile-Alert.git
4. Open the project folder in VS Code
5. Connect the Arduino Uno
6. Build and upload using the PlatformIO interface

### Using PlatformIO CLI
pio run
pio run --target upload

## Configuration
You can modify the following parameters in `main.cpp`:
- Distance threshold (cm)
- Servo tap interval and timing
- Servo angles used for the tactile motion

## Limitations
- Ultrasonic sensing accuracy depends on surface angle, material, and environment
- Uses a single forward-facing sensor (no directional awareness)
- Not calibrated for assistive or safety-critical use

## Future improvements
- Add multiple sensors for directional feedback
- Replace servo tapping with a vibration motor for quieter operation
- Implement basic filtering for more stable distance readings
- Design an enclosure for wearable mounting

## License
MIT License — see the LICENSE file for details.
