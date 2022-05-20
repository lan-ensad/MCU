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
String msg;

bool fan01, fan02 = false;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  String top = topic;
  Serial.print("Message arrived in topic: ");
  Serial.println(top);
  Serial.print("Message: ");
  if (top == "fans/01") {
    fan01 = !fan01;
    msg = "";
    for (int i = 0; i < length; i++) {
      msg += (char)payload[i];
    }
    Serial.print(msg);Serial.print("\t \t");Serial.print("Fan 01 : ");Serial.println(fan01);
  } else if (top == "fans/02") {
    fan02 = !fan02;
    msg = "";
    for (int i = 0; i < length; i++) {
      msg += (char)payload[i];
    }
    Serial.print(msg);Serial.print("\t \t");Serial.print("Fan 02 : ");Serial.println(fan02);
  }
  Serial.println();
  Serial.println("-----------------------");
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
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
  client.subscribe("fans/01");
  client.subscribe("fans/02");
}
void loop(){
  client.loop();

  //====== Activation des pin relais ======
  if(fan02){
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    digitalWrite(LED_BUILTIN, LOW);
  }
}
