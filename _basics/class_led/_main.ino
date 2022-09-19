#define PIN_LED1 3
#define PIN_LED2 6
#define PIN_LED3 9

//Blinker(PIN, DuringHIGH, DuringLOW)
Blinker blink1 = Blinker(PIN_LED1, 200, 500);
Blinker blink2 = Blinker(PIN_LED2, 1200, 700);

//Fader(PIN, StepsUp, StepsDown, TimeToDown, TimeToUp, DuringHIGH, DuringLOW)
Fader fader1 = Fader(PIN_LED3, 5, 5, 500, 5, 1000, 1000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  blink1.check();
  blink2.check();
  fader1.check();
}
