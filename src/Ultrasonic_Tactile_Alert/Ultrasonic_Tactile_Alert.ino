#include <LiquidCrystal.h>
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 3;

LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
Servo s;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Starting...");

  s.attach(servoPin);

  delay(800);
  lcd.clear();
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo duration (timeout 30ms)
  unsigned long duration = pulseIn(echoPin, HIGH, 30000);

  // Update LCD without clearing the whole screen (reduces flicker)
  lcd.setCursor(0, 0);

  if (duration == 0) {
    Serial.println("No echo");
    lcd.print("No echo         ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    float distance_cm = duration * 0.0343 / 2.0;

    Serial.print("Distance: ");
    Serial.print(distance_cm, 1);
    Serial.println(" cm");

    lcd.print("Dist: ");
    lcd.print(distance_cm, 1);
    lcd.print(" cm   ");

    lcd.setCursor(0, 1);

    if (distance_cm < 30) {
      lcd.print("ALERT           ");

      // Continuous tapping pattern (repeats while close)
      s.write(0);
      delay(200);
      s.write(45);
      delay(200);
      s.write(90);
      delay(200);

      Serial.println("going");
    } else {
      lcd.print("Safe            ");
    }
  }

  delay(200);
}
