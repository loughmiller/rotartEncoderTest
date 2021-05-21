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

int_fast16_t lastC = 0;
int_fast16_t c = 0;

void loop() {

  uint_fast8_t left = digitalRead(leftPin);
  uint_fast8_t right = digitalRead(rightPin);

  if (left != lastLeft && right != lastRight) {
    c = min(c + 1, 255);
  }

  if (left != lastLeft && right == lastRight) {
    c = max(c - 1, 0);
  }

  if (lastC != c) {
    lastLeft = left;
    lastRight = right;
    lastC = c;
    Serial.println(c);
  }
}
