#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "domo";
const char* password =  "th1Sp4((!";
const char* mqttServer = "192.168.0.101";
const int mqttPort = 1883;

String commands = "";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void callback(char* topic, byte* payload, unsigned int length) {
  commands = "";
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    //Serial.print((char)payload[i]);
    commands+=(char)payload[i];
  }
  Serial.print(commands);
  Serial.println();
  Serial.println("-----------------------");
}
 
void setup() {
  Serial.begin(115200);
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
  client.subscribe("new");
}
 
void loop() {
  client.loop();
}
