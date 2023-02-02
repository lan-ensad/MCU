//  BITMAPPING
//      0
//    5   1
//      6
//    4   2
//      3  7

//  DISPLAYBUFFER
// 0 1 2 3 4
//     :
// displaybuffer(3) => double point

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();

uint8_t counter = 0;

void setup() {
  Serial.begin(9600);
  matrix.begin(0x70);  // pass in the address

  matrix.displaybuffer[2]=bit(1);
  matrix.writeDisplay();
  delay(1000);
  matrix.displaybuffer[2]=bit(0);
  matrix.writeDisplay();
  delay(1000);
}

void loop() {
  for (int i = 0; i < 9; i++) {
    matrix.displaybuffer[0] = bit(i);
    matrix.displaybuffer[1] = bit(i);
    matrix.displaybuffer[3] = bit(i);
    matrix.displaybuffer[4] = bit(i);
    matrix.writeDisplay();
    delay(100);
  }
  delay(300);
}
