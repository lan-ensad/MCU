
//  https://github.com/lpaseen/ht16k33

#include "ht16k33.h"

HT16K33 HT;

const uint8_t NBSEG = 4;

uint8_t allSeg[] = {
  0, 1, 2, 3, 4, 5, 6,         //7,//dot
  16, 17, 18, 19, 20, 21, 22,  //23,//dot
  //33, //double dots
  48, 49, 50, 51, 52, 53, 54,  //55,//dot
  64, 65, 66, 67, 68, 69, 70,  //71,//dot
};
int segs[4][7] = {
  { 0, 1, 2, 3, 4, 5, 6 },
  { 16, 17, 18, 19, 20, 21, 22 },
  { 48, 49, 50, 51, 52, 53, 54 },
  { 64, 65, 66, 67, 68, 69, 70 }
};
uint8_t seg0[] = { 0, 1, 2, 3, 4, 5, 6 };
uint8_t seg1[] = { 16, 17, 18, 19, 20, 21, 22 };
uint8_t seg2[] = { 48, 49, 50, 51, 52, 53, 54 };
uint8_t seg3[] = { 64, 65, 66, 67, 68, 69, 70 };


void setup() {
  HT.begin(0x00);
}

void Sleep(int del) {
  for (int i = 0; i < NBSEG; i++) {
    HT.setLedNow(segs[i][3]);
    delay(del);
  }
  for (int i = 0; i < NBSEG; i++) {
    HT.clearLedNow(segs[i][3]);
    delay(del);
  }
}

void AngryAll(int del){
  for (int i = 0; i < NBSEG; i++) {
    HT.setLedNow(segs[i][int(random(7))]);
  }
  delay(del);
  HT.clearAll();
}

void loop() {
  uint8_t led;

  //Sleep(200);
  AngryAll(30);

}  // loop
