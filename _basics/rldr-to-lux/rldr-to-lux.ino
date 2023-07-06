#define DELAY 500
#define VIN 5
#define R 10000 //ohm resistor
#define RES 12  //resolution depend of microcontroler

const int sensorPin = A0;
int sensorVal, lux;

int sensorRawToPhys(int raw) {
  float Vout = float(raw) * (VIN / float(pow(2, RES)));  // Conversion analog to voltage
  float RLDR = (R * (VIN - Vout)) / Vout;         // Conversion voltage to resistance
  int phys = 500 / (RLDR / 1000);                 // Conversion resitance to lumen
  return phys;
}

void setup(void) {
  Serial.begin(115200);
}

void loop(void) {
  sensorVal = analogRead(sensorPin);
  lux = sensorRawToPhys(sensorVal);
  Serial.print("Raw value = ");
  Serial.print(sensorVal);
  Serial.print("\t Physical value = ");
  Serial.print(lux);
  Serial.println(" lumen");
  delay(DELAY);
}