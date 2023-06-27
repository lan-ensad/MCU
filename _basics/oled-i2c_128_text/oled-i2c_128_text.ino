#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#define OLED_RESET 4
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Adressierung beachten, hier 0x3C!
}

void loop() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(40, 10);
  display.println("OLED");
  display.setTextSize(1);
  display.setCursor(23, 28);
  display.println("www.joy-it.net");
  display.setCursor(8, 40);
  display.setTextSize(2);
  display.println("SBC-OLED01");
  display.display();
  delay(8000);
  display.clearDisplay();
  display.invertDisplay(true);
  delay(8000);
  display.invertDisplay(false);
  delay(1000);
}