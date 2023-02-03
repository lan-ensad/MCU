
#include <Arduino.h>
#include <Wire.h>        // TwoWire, Wire
#include <AceWire.h>     // TwoWireInterface
#include <AceSegment.h>  // Ht16k33Module

using ace_wire::TwoWireInterface;
using ace_segment::LedModule;
using ace_segment::Ht16k33Module;

// Replace these with the PIN numbers of your dev board.
const uint8_t SDA_PIN = SDA;
const uint8_t SCL_PIN = SCL;
const uint8_t HT16K33_I2C_ADDRESS = 0x70;
const uint8_t NUM_DIGITS = 4;
unsigned int dec[4] = { 0 };  //goto Split() function

using WireInterface = TwoWireInterface<TwoWire>;
WireInterface wireInterface(Wire);
Ht16k33Module<WireInterface, NUM_DIGITS> ledModule(
  wireInterface, HT16K33_I2C_ADDRESS);

// LED segment patterns.
const uint8_t PATTERNS[] = {
  0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00000111,  // 7
  0b01111111,  // 8
  0b01101111,  // 9
  0b10000000,  // dot   → 10
  0b100000000 // BLANK  → 11
  };

void setup() {
  Serial.begin(9600);
  delay(1000);

  Wire.begin();
  wireInterface.begin();
  ledModule.begin();
  ledModule.setBrightness(10);
  ledModule.setPatternAt(3, PATTERNS[11]);
  ledModule.flush();
}

void loop() {
  for (int i = 0; i < 10; i++) {
    ledModule.setPatternAt(0, PATTERNS[i]);
    ledModule.setPatternAt(1, PATTERNS[i]);
    ledModule.setPatternAt(2, PATTERNS[i]);
    ledModule.setPatternAt(3, PATTERNS[i]);
    ledModule.flush();
    delay(100);
  }
  delay(1000);

  ledModule.setPatternAt(0, PATTERNS[11]);
  ledModule.setPatternAt(1, PATTERNS[11]);
  ledModule.setPatternAt(2, PATTERNS[11]);
  ledModule.setPatternAt(3, PATTERNS[11]);
  delay(1000);

  for (int i = 0; i < 10000; i++) {
    Counter(i);
    delay(10); 
  }
}

void Split(unsigned int number) {
  unsigned int value = number;
  value = value % 10000;
  dec[3] = value / 1000;
  value = value % 1000;
  dec[2] = value / 100;
  value = value % 100;
  dec[1] = value / 10;
  dec[0] = value % 10;

  number++;
  char buff[128];
  sprintf(buff, "%d = %d %d %d %d", number, dec[3], dec[2], dec[1], dec[0]);
  Serial.println(buff);
}

void Counter(unsigned int c) {
  if (c < 10) {
    ledModule.setPatternAt(3, PATTERNS[c]);
    ledModule.setPatternAt(2, PATTERNS[11]);
    ledModule.setPatternAt(1, PATTERNS[11]);
    ledModule.setPatternAt(0, PATTERNS[11]);
    ledModule.flush();
  } else if (c >= 10 && c < 100) {
    Split(c);
    ledModule.setPatternAt(3, PATTERNS[dec[0]]);
    ledModule.setPatternAt(2, PATTERNS[dec[1]]);
    ledModule.setPatternAt(1, PATTERNS[11]);
    ledModule.setPatternAt(0, PATTERNS[11]);
    ledModule.flush();
  } else if (c >= 100 && c < 1000) {
    Split(c);
    ledModule.setPatternAt(3, PATTERNS[dec[0]]);
    ledModule.setPatternAt(2, PATTERNS[dec[1]]);
    ledModule.setPatternAt(1, PATTERNS[dec[2]]);
    ledModule.setPatternAt(0, PATTERNS[11]);
    ledModule.flush();
  } else if (c >= 1000 && c < 10000) {
    Split(c);
    ledModule.setPatternAt(3, PATTERNS[dec[0]]);
    ledModule.setPatternAt(2, PATTERNS[dec[1]]);
    ledModule.setPatternAt(1, PATTERNS[dec[2]]);
    ledModule.setPatternAt(0, PATTERNS[dec[3]]);
    ledModule.flush();
  }
}
