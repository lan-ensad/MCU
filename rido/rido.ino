//#include <AccelStepper.h>

#define dirPin 27
#define stepPin 26
#define stepsPerRevolution 200
//#define motorInterfaceType 1

const int LIMITSWITCH = 25;

bool limitSwitch, state;

//AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LIMITSWITCH, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  //stepper.setMaxSpeed(1000);

  limitSwitch = digitalRead(LIMITSWITCH);
  state = true;

  Serial.begin(9600);
  Blink();
  Serial.println("... INIT DONE ...");
}

void Blink(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}
void Rewind() {
  //CLOWKWISE
  digitalWrite(dirPin, HIGH);
  //COUNTER CLOCKWISE
  //digitalWrite(dirPin, LOW);
  if (state) {
    SwitchState();
    if (!limitSwitch) {
      state = false;
    }
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
}
void Wind(){
  digitalWrite(dirPin, LOW);
  if (!state) {
    SwitchState();
    if (limitSwitch) {
      state = true;
    }
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(600);
  }
}
void SwitchState() {
  limitSwitch = digitalRead(LIMITSWITCH);
}

void loop() {
  if(Serial.read() == 't'){
    state = true;
  }
  if (state) {
    Rewind();
    Wind();
  }else{
    Blink();
  }
}
