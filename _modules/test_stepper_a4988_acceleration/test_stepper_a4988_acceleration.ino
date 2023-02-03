//  https://howtomechatronics.com/tutorials/arduino/stepper-motors-and-arduino-the-ultimate-guide/

#include <AccelStepper.h>

AccelStepper stepper1(1, 3, 2);  // (Type of driver: with 2 pins, STEP, DIR)

int pos = 0;
unsigned long prevMillis = 0;
long interval = 500;

void setup() {
  stepper1.setMaxSpeed(2000);        // Set maximum speed value for the stepper
  stepper1.setAcceleration(500);    // Set acceleration value for the stepper
  stepper1.setCurrentPosition(pos);  // Set the current position to 0 steps
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - prevMillis >= interval) {
    prevMillis = currentMillis;
    interval = long(random(200, 3000));
    pos -= 5;
    stepper1.moveTo(pos);
    stepper1.runToPosition(); 
  }
}