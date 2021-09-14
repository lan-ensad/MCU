int state;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
}

void loop() {
  state = digitalRead(2);

  
  if(state){
    Blink(500);
  }else{
    Static();
  }
  delay(20);
}

void Blink(int del) {
  digitalWrite(3, HIGH);
  delay(del);
  digitalWrite(3, LOW);
  delay(del/1.618);
}

void Static(){
  digitalWrite(3, HIGH);
}
