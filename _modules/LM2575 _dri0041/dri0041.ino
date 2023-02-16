/*
  @file Motor driver DRI0042_Test.ino
  @brief DRI0042_Test.ino  Motor control program

  control motor positive inversion

  @author bernie.chen@dfrobot.com
  @version  V1.0
  @date  2016-8-10
*/
const int IN1=5;
const int IN2=4;
const int ENA=6;

const int IN3=8;
const int IN4=7;
const int ENB=9;

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  Motor1_Brake();
  Motor2_Brake();
  delay(1000);
  Motor1_Forward(50);
  Motor2_Forward(50);
  delay(1000);
  Motor1_Brake();
  Motor2_Brake();
  delay(1000);
  Motor1_Backward(50);
  Motor2_Backward(50);
  delay(1000);
}

void Motor1_Forward(int Speed){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, Speed);
  Serial.println("-- M1 FORWARD --");
}
void Motor1_Backward(int Speed){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, Speed);
  Serial.println("-- M1 BACKWARD --");
}
void Motor1_Brake(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("-- M1 BRAKE --");
}
void Motor2_Forward(int Speed){
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, Speed);
  Serial.println("-- M2 FORWARD --");
}
void Motor2_Backward(int Speed){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, Speed);
  Serial.println("-- M2 BACKWARD --");
}
void Motor2_Brake(){
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("-- M2 BRAKE --");
}
