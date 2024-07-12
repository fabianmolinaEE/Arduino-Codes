#include <dht.h>

#include <LiquidCrystal.h>

#define trigPin 10
#define echoPin 13
#define DHT11_PIN 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  float duration, distance;
  float speed;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  speed = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity);
  distance = (duration / 2) * (speed / 10000);

  if (distance >= 400 || distance <= 2) {
    lcd.print("Out of range");
    delay(500);
  } else {
    lcd.print(distance);
    lcd.print(" cm");
    delay(500);
  }
  delay(500);
  lcd.clear();
}