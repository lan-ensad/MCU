// Complete Instructions to Get and Change ESP MAC Address: https://RandomNerdTutorials.com/get-change-esp32-esp8266-mac-address-arduino/

#ifdef ESP32
#include <WiFi.h>
#include <esp_wifi.h>
#else
#include <ESP8266WiFi.h>
#endif

const char* ssid = "WIFI_SSID";
const char* password = "WIFI_PASS";
String hostname = "HOSTNAME";
uint8_t newMac[] = { "NEW MAC ADDRESS" };

void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
  //WiFi.setHostname(hostname.c_str());  //define hostname
  //-------------------------------
  //     Set Mac Adress ESP32
  //esp_wifi_set_mac(ESP_IF_WIFI_STA, &newMac[0]);// ESP32 Board add-on before version < 1.0.5
  //esp_wifi_set_mac(WIFI_IF_STA, &newMac[0]);  // ESP32 Board add-on after version > 1.0.5
  //-------------------------------

  //-------------------------------
  //   Set Mac Adress ESP8266
  //wifi_set_macaddr(SOFTAP_IF, &newMac[0]);// For Soft Access Point (AP) Mode
  //wifi_set_macaddr(STATION_IF, &newMac[0]);// For Station Mode
  //-------------------------------

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println("WiFi Connected !");
}
void WiFiInfos() {
  if (WiFi.isConnected()) {
    Serial.print("Local IP : ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC Address : ");
    Serial.println(WiFi.macAddress());
    Serial.print("hostname : ");
    Serial.println(WiFi.getHostname());
    Serial.print("RSSI : ");
    Serial.println(WiFi.RSSI());
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Avant : ");
  WiFiInfos();
  initWiFi();
  Serial.println("Après : ");
  WiFiInfos();
}

void loop() {
  delay(10000);
  WiFiInfos();
}