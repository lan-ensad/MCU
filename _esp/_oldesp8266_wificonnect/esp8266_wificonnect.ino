#include <ESP8266WiFi.h>

#ifndef STASSID
#define STASSID "WIFI SSID"
#define STAPSK  "WIFI PASSWPRD"
#define B 10
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

int32_t Buffer[B];
int c = 0;

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to : ");
  Serial.print(ssid);

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
  //Serial.printf("RSSI : %d dBm\n", WiFi.RSSI());
  
  Buffer[c] = WiFi.RSSI();
  c++;
  if(c>B){
    Serial.println(Averager(Buffer));
    c = 0;
  }
  delay(100);
}

int32_t Averager(int32_t s[]){
  int32_t sum = 0;
  int32_t a = 0;
  for(int i=0;i<B;i++){
    sum=sum+s[i];
  }
  a = sum/B;
  return a;
}
