const int PWM = 5;
const int PHASE = 4;

int val;



void setup() {
  pinMode(PWM, OUTPUT);
  pinMode(PHASE, OUTPUT);

  Serial.begin (9600);
}

void loop() {
  val = map(analogRead(A0), 0, 1023, 50, 255);
  Serial.println(val);

  
  digitalWrite(PHASE, HIGH);

  analogWrite(PWM, val);

  
  /*
  for(int i=0; i<255; i++){
    analogWrite(PWM, i);
    delay(50);
  }
  
  for(int i=255; i>0; i--){
    analogWrite(PWM, i);
    delay(50);
  }
  */
  
}
