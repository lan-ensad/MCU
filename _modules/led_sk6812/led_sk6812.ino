#include <Adafruit_NeoPixel.h>

#define LED_PIN     6 //L'adresse sur l'arduino
#define LED_COUNT  220 //Le nombre de led total

const int NBLED = 5; //Nombre de led qui s'allument depuis un point avant et arriere
const int SPEED = 100; // Vitesse de la boucle;

int brightness = 255; // Set BRIGHTNESS to about 1/5 (max = 255)
int p, pp; //PAS TOUCHE

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.setBrightness(brightness);
}


void loop() {
  for (int i = 0 + NBLED - 1; i < LED_COUNT - (NBLED - 1); i++) {
    strip.clear();
    for (int j = 0; j < NBLED; j++) {
      p = i + j;
      pp = i - j;
      strip.setPixelColor(p, strip.Color(0, 0, 0, 255));
      strip.setPixelColor(pp, strip.Color(0, 0, 0, 255));
    }
    strip.setPixelColor(i, strip.Color(0, 0, 0, 255));
    strip.show();
    delay(SPEED);
  }
}
