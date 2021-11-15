//#include <AccelStepper.h>

#define dirPin 27
#define stepPin 26
#define stepsPerRevolution 200
//#define motorInterfaceType 1

const int LIMITSWITCH = 25;

bool limitSwitch, state;

//AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);


void setup() {
  pinMode(LIMITSWITCH, INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  //stepper.setMaxSpeed(1000);

  limitSwitch = digitalRead(LIMITSWITCH);
  state = true;

  Serial.begin(9600);
  Serial.println("... INIT DONE ...");
}

void Rewind() {
  //CLOWKWISE
  digitalWrite(dirPin, HIGH);
  //COUNTER CLOCKWISE
  //digitalWrite(dirPin, LOW);
  while (state) {
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
void SwitchState() {
  limitSwitch = digitalRead(LIMITSWITCH);
}

void loop() {
  if(Serial.read() == 't'){
    state = true;
  }
  if (state) {
    Rewind();
  }
}
