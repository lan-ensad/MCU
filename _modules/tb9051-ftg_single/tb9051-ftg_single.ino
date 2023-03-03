// https://www.pololu.com/product/2997

/*
o → VM
o → GND
o → VCC
o → OCC
o → EN
o → ENB
o → PWM2
o → PWM1
o → OCM
o → DIAG
*/
#define EN 3    //LOW to ON
#define ENB 2   //HIGH to ON
#define PWM2 6
#define PWM1 5

void setup() {
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  digitalWrite(ENB, LOW);
  digitalWrite(EN, HIGH);
}

void loop() {
  digitalWrite(PWM2, LOW);
  analogWrite(PWM1, 255);

  delay(2000);

  analogWrite(PWM2, 150);
  digitalWrite(PWM1, LOW);

  delay(2000);
}
