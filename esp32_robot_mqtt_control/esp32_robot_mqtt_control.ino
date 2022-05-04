/*
  https://wiki.dfrobot.com/Dual_1.5A_Motor_Driver_-_HR8833_SKU__DRI0040
  ======================================================================
  Ix1   Ix2   Mx1   Mx2   Function
  -----------------------------------------
  0     0     Z     Z    Coast/fast decay
  0     1     L     H    Reverse
  1     0     H     L    Forward
  1     1     L     L    Brake/slow decay
  ======================================================================
  Ix1   Ix2   Function                  Description
  --------------------------------------------------------------
  PWM    0    Forward PWM,fast decay    Speed = High duty-cycle
  1     PWM   Forward PWM,slow decay    Speed = Low duty-cycle
  0     PWM   Reverse PWM,fast decay    Speed = High duty-cycle
  PWM    1    Reverse PWM,slow decay    Speed = Low duty-cycle
  ======================================================================
  TABLE OF MOVMENTS
  _______________________________________________________________
  | 5 | 1 | 6 |   ||  Turn Left     |  Forward    |   Turn Right
  | 3 | 0 | 4 |   ||  Slide Left    |    STOP     |   Slide Right
  | 7 | 2 | 8 |   ||  Rotation CCW  |  Backward   |   Rotation CW
  see README.md for more
*/

#include <Arduino.h>
#include <analogWrite.h>
#include <WiFi.h>
#include <PubSubClient.h>

//----------------------------------
//        MQTT CONTROLLER
const char* ssid = "domo";
const char* password =  "th1Sp4((!";
const char* mqttServer = "192.168.0.101";
const int mqttPort = 1883;
String command = "";

String sp = "125"; //Defaut speed motor value
WiFiClient espClient;
PubSubClient client(espClient);
//----------------------------------
//         PINMAP DRI0040
const int BACKIA1 = 25;
const int BACKIA2 = 26;
const int BACKIB1 = 27;
const int BACKIB2 = 9;
const int FRONTIA1 = 16;
const int FRONTIA2 = 4;
const int FRONTIB1 = 12;
const int FRONTIB2 = 14;

void callback(char* topic, byte* payload, unsigned int length) {
  String top = topic;
  Serial.print("Message arrived in topic: ");
  Serial.println(top);
  Serial.print("Message: ");
  if (top == "robot/action") {
    command = "";
    for (int i = 0; i < length; i++) {
      command += (char)payload[i];
    }
    Serial.print(command);
  } else if (top == "robot/speed") {
    sp = "";
    for (int i = 0; i < length; i++) {
      sp += (char)payload[i];
    }
    Serial.print(sp);
  }
  Serial.println();
  Serial.println("-----------------------");
}

//=========== MOTOR CONTROLLER ===========
void AllStop() {
  analogWrite(FRONTIA1, 0);
  analogWrite(FRONTIA2, 0);
  analogWrite(FRONTIB1, 0);
  analogWrite(FRONTIB2, 0);
  analogWrite(BACKIA1, 0);
  analogWrite(BACKIA2, 0);
  analogWrite(BACKIB1, 0);
  analogWrite(BACKIB2, 0);
}
//====== FRONT CONTROLS  ======
void FrontLeftForward(int sp) {
  analogWrite(FRONTIB2, 0);
  analogWrite(FRONTIB1, 0);
  digitalWrite(FRONTIB1, HIGH);
  analogWrite(FRONTIB2, sp);
}
void FrontLeftBackward(int sp) {
  analogWrite(FRONTIB2, 0);
  analogWrite(FRONTIB1, 0);
  digitalWrite(FRONTIB2, HIGH);
  analogWrite(FRONTIB1, sp);
}
void FrontRightBackward(int sp) {
  analogWrite(FRONTIA2, 0);
  analogWrite(FRONTIA1, 0);
  digitalWrite(FRONTIA1, HIGH);
  analogWrite(FRONTIA2, sp);
}
void FrontRightForward(int sp) {
  analogWrite(FRONTIA2, 0);
  analogWrite(FRONTIA1, 0);
  digitalWrite(FRONTIA2, HIGH);
  analogWrite(FRONTIA1, sp);
}
//====== BACK CONTROLS  ======
void BackLeftForward(int sp) {
  analogWrite(BACKIB2, 0);
  analogWrite(BACKIB1, 0);
  digitalWrite(BACKIB1, HIGH);
  analogWrite(BACKIB2, sp);
}
void BackLeftBackward(int sp) {
  analogWrite(BACKIB2, 0);
  analogWrite(BACKIB1, 0);
  digitalWrite(BACKIB2, HIGH);
  analogWrite(BACKIB1, sp);
}
void BackRightBackward(int sp) {
  analogWrite(BACKIA2, 0);
  analogWrite(BACKIA1, 0);
  digitalWrite(BACKIA1, HIGH);
  analogWrite(BACKIA2, sp);
}
void BackRightForward(int sp) {
  analogWrite(BACKIA2, 0);
  analogWrite(BACKIA1, 0);
  digitalWrite(BACKIA2, HIGH);
  analogWrite(BACKIA1, sp);
}
//====== SLIDE CONTROLS  ======
void SlideLeft(int v) {
  AllStop();
  FrontLeftBackward(v);
  FrontRightForward(v);
  BackLeftForward(v);
  BackRightBackward(v);
}
void SlideRight(int v) {
  AllStop();
  FrontLeftForward(v);
  FrontRightBackward(v);
  BackLeftBackward(v);
  BackRightForward(v);
}
//====== ROTATION CONTROLS  ======
void RotateCW(int v) {
  AllStop();
  FrontLeftForward(v);
  FrontRightBackward(v);
  BackLeftForward(v);
  BackRightBackward(v);
}
void RotateCCW(int v) {
  AllStop();
  FrontLeftBackward(v);
  FrontRightForward(v);
  BackLeftBackward(v);
  BackRightForward(v);
}
//====== TURN CONTROLS  ======
void TurnRight(int v) {
  AllStop();
  FrontLeftForward(v);
  BackRightForward(v);
}
void TurnLeft(int v) {
  AllStop();
  FrontRightForward(v);
  BackLeftForward(v);
}
//====== DIRECTION CONTROLS  ======
void Forward(int v) {
  AllStop();
  FrontLeftForward(v);
  FrontRightForward(v);
  BackLeftForward(v);
  BackRightForward(v);
}
void Backward(int v) {
  AllStop();
  FrontLeftBackward(v);
  FrontRightBackward(v);
  BackLeftBackward(v);
  BackRightBackward(v);
}

void setup() {
  Serial.begin(115200);
  analogWriteResolution(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }

  client.subscribe("robot/action");
  client.subscribe("robot/speed");

  pinMode(BACKIA1, OUTPUT);
  pinMode(BACKIA2, OUTPUT);
  pinMode(BACKIB1, OUTPUT);
  pinMode(BACKIB1, OUTPUT);
  pinMode(FRONTIA1, OUTPUT);
  pinMode(FRONTIA2, OUTPUT);
  pinMode(FRONTIB1, OUTPUT);
  pinMode(FRONTIB1, OUTPUT);

  AllStop();
}

void loop() {
  client.loop();
  switch (command.toInt()) {
    case 0:
      AllStop();
      break;
    case 1:
      Forward(sp.toInt());
      break;
    case 2:
      Backward(sp.toInt());
      break;
    case 3:
      SlideLeft(sp.toInt());
      break;
    case 4:
      SlideRight(sp.toInt());
      break;
    case 5:
      TurnLeft(sp.toInt());
      break;
    case 6:
      TurnRight(sp.toInt());
      break;
    case 8:
      RotateCW(sp.toInt());
      break;
    case 7:
      RotateCCW(sp.toInt());
      break;
  }
}
