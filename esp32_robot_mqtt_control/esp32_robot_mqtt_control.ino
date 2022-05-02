/*
https://wiki.dfrobot.com/Dual_1.5A_Motor_Driver_-_HR8833_SKU__DRI0040
*======================================================================
Ix1   Ix2   Mx1   Mx2   Function     
-----------------------------------------
 0     0     Z     Z    Coast/fast decay
 0     1     L     H    Reverse
 1     0     H     L    Forward
 1     1     L     L    Brake/slow decay
*======================================================================
Ix1   Ix2   Function                  Description          
--------------------------------------------------------------
PWM    0    Forward PWM,fast decay    Speed = High duty-cycle
1     PWM   Forward PWM,slow decay    Speed = Low duty-cycle
0     PWM   Reverse PWM,fast decay    Speed = High duty-cycle
PWM    1    Reverse PWM,slow decay    Speed = Low duty-cycle
*======================================================================
*/

#include <Arduino.h>
#include <analogWrite.h>

const int BACKIA1 = 25;
const int BACKIA2 = 26;
const int BACKIB1 = 27;
const int BACKIB2 = 9;
const int FRONTIA1 = 16;
const int FRONTIA2 = 4;
const int FRONTIB1 = 12;
const int FRONTIB2 = 14;

void BackStop(){
  analogWrite(BACKIA1, 0);
  analogWrite(BACKIA2, 0);
  analogWrite(BACKIB1, 0);
  analogWrite(BACKIB2, 0);
}
void BackRightStop(){
  analogWrite(BACKIA1, 0);
  analogWrite(BACKIA2, 0);
}
void BackLeftStop(){
  analogWrite(BACKIB1, 0);
  analogWrite(BACKIB2, 0);
}
void FrontStop(){
  analogWrite(FRONTIA1, 0);
  analogWrite(FRONTIA2, 0);
  analogWrite(FRONTIB1, 0);
  analogWrite(FRONTIB2, 0);
}
void FrontRightStop(){
  analogWrite(FRONTIA1, 0);
  analogWrite(FRONTIA2, 0);
}
void FrontLeftStop(){
  analogWrite(FRONTIB1, 0);
  analogWrite(FRONTIB2, 0);
}

void BackRightBackward(int sp){
  analogWrite(BACKIA2, 0);
  analogWrite(BACKIA1, 0);
  digitalWrite(BACKIA1, HIGH);
  analogWrite(BACKIA2, sp);
}
void BackRightForward(int sp){
  analogWrite(BACKIA2, 0);
  analogWrite(BACKIA1, 0);
  digitalWrite(BACKIA2, HIGH);
  analogWrite(BACKIA1, sp);
}
void FrontRightBackward(int sp){
  analogWrite(FRONTIA2, 0);
  analogWrite(FRONTIA1, 0);
  digitalWrite(FRONTIA1, HIGH);
  analogWrite(FRONTIA2, sp);
}
void FrontRightForward(int sp){
  analogWrite(FRONTIA2, 0);
  analogWrite(FRONTIA1, 0);
  digitalWrite(FRONTIA2, HIGH);
  analogWrite(FRONTIA1, sp);
}

void BackLeftForward(int sp){
  analogWrite(BACKIB2, 0);
  analogWrite(BACKIB1, 0);
  digitalWrite(BACKIB1, HIGH);
  analogWrite(BACKIB2, sp);
}
void BackLeftBackward(int sp){
  analogWrite(BACKIB2, 0);
  analogWrite(BACKIB1, 0);
  digitalWrite(BACKIB2, HIGH);
  analogWrite(BACKIB1, sp);
}
void FrontLeftForward(int sp){
  analogWrite(FRONTIB2, 0);
  analogWrite(FRONTIB1, 0);
  digitalWrite(FRONTIB1, HIGH);
  analogWrite(FRONTIB2, sp);
}
void FrontLeftBackward(int sp){
  analogWrite(FRONTIB2, 0);
  analogWrite(FRONTIB1, 0);
  digitalWrite(FRONTIB2, HIGH);
  analogWrite(FRONTIB1, sp);
}


void setup() {
  analogWriteResolution(10);
  pinMode(BACKIA1, OUTPUT);
  pinMode(BACKIA2, OUTPUT);
  pinMode(BACKIB1, OUTPUT);
  pinMode(BACKIB1, OUTPUT);
  pinMode(FRONTIA1, OUTPUT);
  pinMode(FRONTIA2, OUTPUT);
  pinMode(FRONTIB1, OUTPUT);
  pinMode(FRONTIB1, OUTPUT);
  
  BackStop();
  FrontStop();
  
  delay(2000);
  BackRightForward(75);
  delay(2000);
  BackRightBackward(200);
  delay(2000);
  BackRightStop();
  
  BackLeftBackward(150);
  delay(2000);
  BackLeftForward(125);
  delay(2000);
  BackLeftStop();


  delay(2000);
  FrontRightForward(75);
  delay(2000);
  FrontRightBackward(200);
  delay(2000);
  FrontRightStop();
  
  FrontLeftBackward(150);
  delay(2000);
  FrontLeftForward(125);
  delay(2000);
  FrontLeftStop();  
}

void loop() {
}
