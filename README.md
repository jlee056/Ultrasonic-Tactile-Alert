# Ultrasonic Tactile Alert

Arduino project exploring tactile feedback for blind/low-vision navigation using an ultrasonic sensor.

## Overview
This repository contains a proof-of-concept Arduino build that uses an ultrasonic sensor to measure how close an obstacle is. The distance is shown on a 16×2 LCD, and when an object is within a set threshold (default: 30 cm) a servo motor provides repeated “tap” alerts.

This is a prototype made for learning and demonstration. It is not a finished assistive or safety device and has not been validated for real-world use.

## What it does
- Measures distance with an ultrasonic sensor
- Displays the distance on an LCD
- Repeatedly triggers a servo “tap” when the object is within the threshold

## Parts used
- Arduino Uno
- Ultrasonic sensor
- 16×2 LCD
- Servo motor 

## How to run
1. Open the `.ino` file in the Arduino IDE
2. Select the correct board and port
3. Upload to the Arduino
4. Place an object in front of the sensor and observe the LCD and servo response

## Configuration
You can change these values in the code:
- Distance threshold (cm)
- How often the servo taps while the object is close
- Servo angles and timing 

## Limitations
- Ultrasonic sensors can miss objects depending on angle, surface, and environment
- This uses a single forward-facing sensor, so it does not provide directional feedback

## Future improvements
- Add multiple sensors for left/right feedback
- Create an enclosure and wearable mounting
- Replace the servo with a vibration motor for a smaller, quieter alert

