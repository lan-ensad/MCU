#define PIN_LED1 3
#define PIN_LED2 6
#define PIN_LED3 9

Blinker blink1 = Blinker(PIN_LED1, 200, 500);
Blinker blink2 = Blinker(PIN_LED2, 1200, 700);
Blinker blink3 = Blinker(PIN_LED3, 2000, 200);

void setup() {
}

void loop() {
  blink1.check();
  blink2.check();
  blink3.check();
}