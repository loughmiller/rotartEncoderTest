#include <Arduino.h>
#include <Encoder.h>

const uint_fast8_t leftPin = 11;
const uint_fast8_t rightPin = 12;

Encoder myEnc(leftPin, rightPin);


void setup() {
  Serial.begin(9600);
  Serial.println("setup");

  // pinMode(leftPin, INPUT);
  // pinMode(rightPin, INPUT);
}

uint8_t oldPosition = 128;

void loop() {
  uint8_t position = myEnc.read();
  if (position != oldPosition) {
    Serial.print("position: ");
    Serial.println(position);
    oldPosition = position;
  }
}

// uint_fast8_t lastLeft = 0;
// uint_fast8_t lastRight = 0;

// int_fast16_t lastC = 0;
// int_fast16_t c = 0;

// void loop() {

//   uint_fast8_t left = digitalRead(leftPin);
//   uint_fast8_t right = digitalRead(rightPin);

//   if (left != lastLeft && right != lastRight) {
//     c = min(c + 1, 255);
//   }

//   if (left != lastLeft && right == lastRight) {
//     c = max(c - 1, 0);
//   }

//   if (lastC != c) {
//     lastLeft = left;
//     lastRight = right;
//     lastC = c;
//     Serial.println(c);
//   }
// }
