#include <Arduino.h>
#include <analogWrite.h>

const int BACKIA1 = 25;
const int BACKIA2 = 26;
const int BACKIB1 = 27;
const int BACKIB2 = 9;

void setup() {
  analogWriteResolution(10);

  pinMode(BACKIA1, OUTPUT);
  pinMode(BACKIA2, OUTPUT);
  pinMode(BACKIB1, OUTPUT);
  pinMode(BACKIB1, OUTPUT);
}

void Tourne(int sp, int d) {
  digitalWrite(BACKIA2, LOW);
  for (int i = 0; i < sp; i++) {
    analogWrite(BACKIA1, i);
    delay(d);
  }
  analogWrite(BACKIA1, sp);
}


void Stope(int v, int d) {
  for (int i = v; i > 0; i--) {
    analogWrite(BACKIA1, i);
    delay(d);
  }
}

void loop() {
  Tourne(255, 20);
  delay(3000);
  Stope(255, 5);
  delay(1000);
}
