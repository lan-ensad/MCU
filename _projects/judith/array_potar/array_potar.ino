#define NBLED 6

const int POTAR []={A0, A1, A2, A3, A4, A5}; //Potar pins
const int LED[] = {3, 5, 6, 9, 10, 11};     //Led pins
int val [NBLED];//Value of each leds
int state;

void setup() {
  Serial.begin(9600);
  Serial.print("INIT");
  pinMode(8, INPUT_PULLUP);
  
  for(int i=0; i<NBLED; i++){
    pinMode(LED[i], OUTPUT);
    Serial.print(" . ");
  }
  Serial.println("");
  delay(500);
  for(int i=0; i<NBLED; i++){
    val[i] = analogRead(POTAR[i]);
    analogWrite(LED[i], map(val[i], 0, 1023, 0, 255));
  }
  
}

void loop() {
  state = digitalRead(8);
  Serial.println(state);
  if(state){
    Blink();
  }else{
    Static();
  }
  
  delay(10);
}

void Blink(){
  for(int i=0; i<NBLED; i++){
    val[i] = analogRead(POTAR[i]);
    analogWrite(LED[i], map(val[i], 0, 1023, 0, 255));
  }
  delay(500);
  for(int i=0; i<NBLED; i++){
    val[i] = analogRead(POTAR[i]);
    analogWrite(LED[i], 0);
  }
  delay(333);
}

void Static(){
  for(int i=0; i<NBLED; i++){
    val[i] = analogRead(POTAR[i]);
    analogWrite(LED[i], map(val[i], 0, 1023, 0, 255));
  }
}
