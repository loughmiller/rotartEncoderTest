#include <Arduino.h>

const uint_fast8_t leftPin = 5;
const uint_fast8_t rightPin = 8;

void setup() {
  Serial.begin(9600);
  Serial.println("setup");

  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
}

uint_fast8_t lastLeft = 0;
uint_fast8_t lastRight = 0;

void loop() {

  uint_fast8_t left = digitalRead(leftPin);
  uint_fast8_t right = digitalRead(rightPin);

  if (lastLeft == left && lastRight == right) {
    return;
  }

  Serial.print(left);
  Serial.print("\t");
  Serial.print(right);
  Serial.println();
}
