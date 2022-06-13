#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "harmattan"
#define STAPSK  "123soleil"
#define B 10
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

const int INTERRSSI = 100;
const int LED = 2;
const int32_t SEUILBAS = -75;
const int32_t SEUILHAUT = -40;

unsigned long currentMillis;
unsigned long previousRssiMillis = 0;
unsigned long previousBlinkMillis = 0;
int32_t Buffer[B];
int c = 0;
int ledState = LOW;
int32_t blinkDel= 1000;
int32_t val;


void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to : ");
  Serial.print(ssid);

  pinMode(LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connection success");
  Serial.print("IP : "); Serial.println(WiFi.localIP());
}

void loop() {
  currentMillis = millis();

  //Serial.printf("RSSI : %d dBm\n", WiFi.RSSI());

  if (currentMillis - previousRssiMillis  >= INTERRSSI) {
    previousRssiMillis  = currentMillis;
    Buffer[c] = WiFi.RSSI();
    c++;
    if (c > B) {
      val = Averager(Buffer);
      //Serial.println(val);
      c = 0;
    }
  }
  
  LedBlink();
}

void LedBlink() {
  if (val >= SEUILBAS) {
    blinkDel = map(val, SEUILBAS, SEUILHAUT, 1000, 10);
    //Serial.println(blinkDel);
    if (currentMillis - previousBlinkMillis >= blinkDel) {
      previousBlinkMillis  = currentMillis;
      ledState=!ledState;
      Serial.println(ledState);
    }
  }else{
    ledState = LOW;
  }
  Serial.printf("Blink : %d ms\t State : %d\n", blinkDel, ledState);
  digitalWrite(LED, ledState);
  //digitalWrite(LED_BUILTIN, ledState);
}

int32_t Averager(int32_t s[]) {
  int32_t sum = 0;
  int32_t a = 0;
  for (int i = 0; i < B; i++) {
    sum = sum + s[i];
  }
  a = sum / B;
  return a;
}
