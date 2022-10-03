#define PIN_LED1 3
#define PIN_LED2 6
#define PIN_LED3 9

//Blinker(PIN, DuringHIGH, DuringLOW)
//Blinker blink1 = Blinker(PIN_LED1, 200, 500);
//Blinker blink2 = Blinker(PIN_LED2, 1200, 700);
//Blinker blink3 = Blinker(PIN_LED2, 1200, 700);

//Fader(PIN, minBrighntess, maxBrightness, StepsUp, StepsDown, TimeToDown, TimeToUp, DuringHIGH, DuringLOW)
Fader fader1 = Fader(PIN_LED1, 0, 255, 1, 15, 1, 618, 571, 1579);
Fader fader2 = Fader(PIN_LED2, 0, 157, 1, 5, 309, 59, 6485, 745);
Fader fader3 = Fader(PIN_LED3, 0, 135, 25, 7, 444, 222, 1541, 795);

void setup() {
  Serial.begin(9600);
}

void loop() {
  fader1.check();
  fader2.check();
  fader3.check();
}
