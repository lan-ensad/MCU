#include <Arduino.h>
#include "StepperDriver"

const int LIMITSWITCH = 25;

// using a 200-step motor (most common)
#define MOTOR_STEPS 200
// configure the pins connected
#define DIR 8
#define STEP 9
#define MS1 10
#define MS2 11
#define MS3 12
A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);

void setup() {
  pinMode(LIMITSWITCH, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(LIMITSWITCH));
}
