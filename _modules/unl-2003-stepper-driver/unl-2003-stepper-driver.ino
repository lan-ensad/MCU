#define A 2
#define B 3
#define C 4
#define D 5

#define NUMBER_OF_STEPS_PER_REV 520

const int nbTour = 2; //nombre de tour à faire
const int mSpeed = 1; //1=max speed

int val;

void setup() {
  Serial.begin(9600);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

//================================================
//              Dans le sens horaire
void write(int a, int b, int c, int d) {
  digitalWrite(D, a);
  digitalWrite(C, b);
  digitalWrite(B, c);
  digitalWrite(A, d);
}
void clockWise() {
  write(1, 0, 0, 0);
  delay(mSpeed);
  write(1, 1, 0, 0);
  delay(mSpeed);
  write(0, 1, 0, 0);
  delay(mSpeed);
  write(0, 1, 1, 0);
  delay(mSpeed);
  write(0, 0, 1, 0);
  delay(mSpeed);
  write(0, 0, 1, 1);
  delay(mSpeed);
  write(0, 0, 0, 1);
  delay(mSpeed);
  write(1, 0, 0, 1);
  delay(mSpeed);
}
//================================================
//             Dans le sens anti-horaire
void writeOpp(int a, int b, int c, int d) {
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
  digitalWrite(D, d);
}
void counterClockWise() {
  writeOpp(1, 0, 0, 0);
  delay(mSpeed);
  writeOpp(1, 1, 0, 0);
  delay(mSpeed);
  writeOpp(0, 1, 0, 0);
  delay(mSpeed);
  writeOpp(0, 1, 1, 0);
  delay(mSpeed);
  writeOpp(0, 0, 1, 0);
  delay(mSpeed);
  writeOpp(0, 0, 1, 1);
  delay(mSpeed);
  writeOpp(0, 0, 0, 1);
  delay(mSpeed);
  writeOpp(1, 0, 0, 1);
  delay(mSpeed);
}

void refreshPotar(){
  val = analogRead(A0);
  if(val < 200 && val > 0){
    Serial.println("Cas 1");
  }else if(val < 500 && val > 201){
    Serial.println("Cas 2");
  }else if(val < 800 && val > 501){
    Serial.println("Cas 3");
  }else {
    Serial.println("Cas 4");
  }
}

void loop() {
//--------- Tourne sens Horaire ---------
  for(int i=0; i<NUMBER_OF_STEPS_PER_REV*nbTour; i++){
    clockWise();
    refreshPotar();
  }
  delay(500);//attente pour le prochain cycle

//--------- Tourne sens Anti-horaire ---------
  for(int i=0; i<NUMBER_OF_STEPS_PER_REV*nbTour; i++){
    counterClockWise();
    refreshPotar();
  }
  delay(500);//attente pour le prochain cycle
}
