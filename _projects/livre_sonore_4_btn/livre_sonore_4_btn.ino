#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int BTN1 = 5;
const int BTN2 = 6;
const int BTN3 = 7;
const int BTN4 = 8;
const int BUSY = 2;

int btn1State, btn2State, btn3State, btn4State;
int readyToPlay = 1;

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);


void setup() {
  pinMode(BTN1, INPUT_PULLUP);//paramettrage du bouton
  pinMode(BTN2, INPUT_PULLUP);//paramettrage du bouton
  pinMode(BTN3, INPUT_PULLUP);//paramettrage du bouton
  pinMode(BTN4, INPUT_PULLUP);//paramettrage du bouton
  pinMode(BUSY, INPUT);

  mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(25);  //Set volume value. From 0 to 30
  //myDFPlayer.play(1);  //Play the first mp3
  delay(1000);
}

void loop() {
  btn1State = digitalRead(BTN1); //lit l'etat du bouton
  btn2State = digitalRead(BTN2); //lit l'etat du bouton
  btn3State = digitalRead(BTN3); //lit l'etat du bouton
  btn4State = digitalRead(BTN4); //lit l'etat du bouton
  readyToPlay = digitalRead(BUSY);

  if (btn1State == 0) {
    myDFPlayer.play(1);
    Serial.println("PREMIER SON");
  } else if (btn2State == 0) {
    myDFPlayer.play(2);
    Serial.println("DEUXIEME SON");
  } else if (btn3State == 0) {
    myDFPlayer.play(3);
    Serial.println("TROISIEME SON");
  } else if (btn4State == 0) {
    myDFPlayer.play(4);
    Serial.println("QUATRIEME SON");
  }

  delay(10);
  //static unsigned long timer = millis();

  //if (millis() - timer > 3000) {
  //timer = millis();
  //myDFPlayer.next();  //Play next mp3 every 3 seconds

}

void printDetail(uint8_t type, int value) {
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerUSBInserted:
      Serial.println("USB Inserted!");
      break;
    case DFPlayerUSBRemoved:
      Serial.println("USB Removed!");
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
