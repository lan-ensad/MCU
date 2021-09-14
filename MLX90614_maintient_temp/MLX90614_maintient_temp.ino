#include <Wire.h>
#include <IR_Thermometer_Sensor_MLX90614.h>

IR_Thermometer_Sensor_MLX90614 MLX90614 = IR_Thermometer_Sensor_MLX90614();

int temp = 50;
int RELAIS = 8;
int POTAR = A0;
int potVal, sens;

void setup() {
  Serial.begin(9600);

  pinMode(RELAIS, OUTPUT);
  MLX90614.begin();
}

void loop() {
  sens = MLX90614.GetObjectTemp_Celsius();
  potVal = map(analogRead(POTAR), 0, 1023, 0, 99);

  delay(100);

  
}
