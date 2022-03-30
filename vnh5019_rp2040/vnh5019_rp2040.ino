/*
PINMAP rp2040 XIAO : https://files.seeedstudio.com/wiki/XIAO-RP2040/img/xinpin.jpg
PINMAP VNH5019 : https://a.pololu-files.com/picture/0J10257.1200.jpg?29db47390e8b499ff3b6c0179ced7956
*/

const int RES = 8; // Résolution du PWM en bit
int sp = 26;      // Pin speed PWM
int INA = 27;     // Clockwise pin
int INB = 28;     // CounterClockwise pin

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(sp, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
}

void dir(int d){
  if(d==1){
    digitalWrite(INB, LOW);
    digitalWrite(INA, HIGH);
    Serial.println("CLOCKWISE");
  }else if(d==0){
    digitalWrite(INA, LOW);
    digitalWrite(INB, HIGH);
    Serial.println("COUNTER CLOCKWISE");
  }else{
    digitalWrite(INA, LOW);
    digitalWrite(INB, LOW);
    Serial.println("PLEASE SELECT 1 OR 0");
  }
}

void loop() {
  dir(1);
  for(int i=0; i<pow(2, RES); i++){
    analogWrite(sp, i);
    Serial.print("ON ");
    Serial.println(i);
    delay(20);
  }
  delay(500);
  for(int i=pow(2, RES); i>0; i--){
    analogWrite(sp, i);
    Serial.print("ON ");
    Serial.println(i);
    delay(20);
  }

  delay(1000);
  
  dir(0);
  for(int i=0; i<pow(2, RES); i++){
    analogWrite(sp, i);
    Serial.print("OFF ");
    Serial.println(i);
    delay(20);
  }
  delay(500);
  for(int i=pow(2, RES); i>0; i--){
    analogWrite(sp, i);
    Serial.print("OFF ");
    Serial.println(i);
    delay(20);
  }

  delay(1000);
}
