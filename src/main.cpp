#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>

/*
  Simple distance triggered servo demo (Arduino Uno + HC-SR04 + 16x2 LCD)

  What it does:
  - Reads distance from an HC-SR04 ultrasonic sensor
  - Prints distance to Serial and displays on a 16x2 LCD
  - If something is closer than a threshold (set to 30 cm), moves the servo through a few angles

  Notes:
  - pulseIn() has a timeout so the loop doesn’t hang forever if there’s no echo.
  - LCD flicker can happen because we clear the screen each loop.
*/

// Pins
const int trigPin  = 9;
const int echoPin  = 10;
const int servoPin = 3;

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
Servo s;

// Variables (subject to change based on set up)
const unsigned long echoTimeoutUs = 30000; // 30ms timeout for pulseIn
const float triggerDistanceCm = 30.0; // distance threshold for servo action

void setup() {
  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Serial monitor with lage to ensure LCD is ready
  Serial.begin(9600);

  // LCD setup
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("hello");

  // Servo setup
  s.attach(servoPin);
  s.write(90); // start position

  Serial.println("starting");
  delay(1000);
}

void loop() {
  // HC-SR04 distance measurement
  // Clear trigger pin and wait a bit to ensure clean pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 µs pulse to trigger the ultrasonic burst
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration in microseconds to prevent freezing if no echo is received
  unsigned long duration = pulseIn(echoPin, HIGH, echoTimeoutUs);

  // Display
  lcd.clear(); // subject to flickering (for simplicity)
  lcd.setCursor(0, 0);

  if (duration == 0) {
    // No echo received within timeout
    Serial.println("No echo");
    lcd.print("No echo");
  } else {
    // Convert time to distance:
    // speed of sound ≈ 0.0343 cm/us, divide by 2 because sound goes there and back
    float distance_cm = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distance_cm, 1);
    Serial.println(" cm");

    lcd.print("Dist: ");
    lcd.print(distance_cm, 1);
    lcd.print(" cm");

    // Servo action
    if (distance_cm < triggerDistanceCm) {
      // Simple movement to show response
      s.write(0);
      delay(200);
      s.write(45);
      delay(200);
      s.write(90);
      delay(200);

      Serial.println("Triggered servo");
    }
  }

  delay(500); // slow down updates so Serial and LCD are readable
}
