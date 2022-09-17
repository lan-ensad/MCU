#define PIN_LED1 3
#define PIN_LED2 6
#define PIN_LED3 9

//Fader(pin, StepsUp, StepsDown, timeToUp, timeToDown, timeOn, timeOff)

Fader led1 = Fader(PIN_LED1, 5, 5, 30, 30, 200, 500);
Fader led2 = Fader(PIN_LED2, 2, 2, 10, 10, 1000, 200);
Fader led3 = Fader(PIN_LED3, 1, 5, 20, 20, 200, 1000);

void setup() {
}

void loop() {
  led1.check();
  led2.check();
  led3.check();
}