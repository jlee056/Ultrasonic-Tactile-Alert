#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 3;

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
Servo s;

void setup() {
  // ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  // lcd
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("hello");

  // servo
  s.attach(servoPin);

  Serial.println("starting");
  delay(1000);
}

void loop() {
  // Clear trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 µs pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration (30 ms timeout)
  unsigned long duration = pulseIn(echoPin, HIGH, 30000);

  lcd.clear();
  lcd.setCursor(0, 0);

  if (duration == 0) {
    Serial.println("No echo");
    lcd.print("No echo");
  } else {
    float distance_cm = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");

    lcd.print("Dist: ");
    lcd.print(distance_cm, 1);
    lcd.print(" cm");

    if (distance_cm < 30) {
      s.write(0);
      delay(200);
      s.write(45);
      delay(200);
      s.write(90);
      delay(200);
      Serial.println("going");
    }
  }

  delay(500);
}
