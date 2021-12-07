#define PIN_LED1 3
#define PIN_LED2 4
#define PIN_LED3 5
#define PIN_LED4 6

Blinker blink1 = Blinker(PIN_LED1, 200, 500);
Blinker blink2 = Blinker(PIN_LED2, 1200, 700);
Blinker blink3 = Blinker(PIN_LED3, 2000, 200);
Blinker blink4 = Blinker(PIN_LED4, 700, 300);

void setup() {
}

void loop() {
  blink1.check();
  blink2.check();
  blink3.check();
  blink4.check();
}
