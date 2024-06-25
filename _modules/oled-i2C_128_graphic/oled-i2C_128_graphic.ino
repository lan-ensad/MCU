#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
#define OLED_RESET 4
#define OLED_WIDTH 128
#define OLED_HEIGHT 64

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#endif
const unsigned char logo[] PROGMEM = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xff, 0xe0,
    0x00, 0xff, 0xf0, 0x1f, 0xe0, 0x3f, 0xff, 0xff, 0x80, 0xf0, 0x00, 0x03,
    0xfe, 0x01, 0xff, 0x80, 0x00, 0x3f, 0xf0, 0x1f, 0xe0, 0x3f, 0xff, 0xff,
    0x80, 0xf0, 0x00, 0x03, 0xfe, 0x01, 0xff, 0x00, 0x00, 0x0f, 0xf0, 0x1f,
    0xe0, 0x3f, 0xff, 0xff, 0x80, 0xf0, 0x00, 0x03, 0xfe, 0x01, 0xfe, 0x00,
    0x00, 0x07, 0xf0, 0x1f, 0xe0, 0x3f, 0xff, 0xff, 0x80, 0xf0, 0x00, 0x03,
    0xfe, 0x01, 0xfc, 0x00, 0x00, 0x03, 0xf0, 0x1f, 0xe0, 0x3f, 0xff, 0xff,
    0x80, 0xf0, 0x00, 0x03, 0xfe, 0x01, 0xfc, 0x00, 0x00, 0x03, 0xf0, 0x1f,
    0xe0, 0x3f, 0xff, 0xff, 0x80, 0xf0, 0x00, 0x03, 0xfe, 0x01, 0xf8, 0x01,
    0xf8, 0x01, 0xf0, 0x1f, 0xe0, 0x3f, 0xff, 0xff, 0x80, 0xf0, 0x00, 0x03,
    0xff, 0xff, 0xf0, 0x07, 0xfe, 0x00, 0xf0, 0x0f, 0xe0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xfe, 0x00, 0xf0, 0x0f,
    0xe0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0f,
    0xff, 0x00, 0xf0, 0x0f, 0xc0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0f, 0xff, 0x00, 0xf0, 0x07, 0xc0, 0x3f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0x01, 0xf0, 0x1f, 0xff, 0x00, 0xf8, 0x00,
    0x00, 0x3f, 0xff, 0xff, 0x80, 0xfc, 0x03, 0xff, 0xfe, 0x01, 0xe0, 0x1f,
    0xff, 0x00, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0xff, 0x80, 0xfc, 0x03, 0xff,
    0xfe, 0x01, 0xe0, 0x1f, 0xff, 0x00, 0xfc, 0x00, 0x00, 0xf8, 0x00, 0x07,
    0x80, 0xfc, 0x03, 0xff, 0xfe, 0x01, 0xe0, 0x1f, 0xff, 0x00, 0xfe, 0x00,
    0x00, 0xf8, 0x00, 0x07, 0x80, 0xfc, 0x03, 0xff, 0xfe, 0x01, 0xe0, 0x1f,
    0xff, 0x00, 0xff, 0x00, 0x01, 0xf8, 0x00, 0x07, 0x80, 0xfc, 0x03, 0xff,
    0xfe, 0x01, 0xf0, 0x1f, 0xff, 0x00, 0xff, 0x80, 0x07, 0xf8, 0x00, 0x07,
    0x80, 0xfc, 0x03, 0xff, 0xfe, 0x01, 0xf0, 0x0f, 0xff, 0x00, 0xff, 0xc0,
    0x0f, 0xf8, 0x00, 0x07, 0x80, 0xfc, 0x03, 0xff, 0xfe, 0x01, 0xf0, 0x0f,
    0xff, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x07, 0x80, 0xfc, 0x03, 0xff,
    0xfe, 0x01, 0xf0, 0x07, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x80, 0xfc, 0x03, 0xff, 0xfe, 0x01, 0xf0, 0x07, 0xfe, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0xfc, 0x03, 0xff, 0xfc, 0x01, 0xf8, 0x03,
    0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0xfc, 0x01, 0xff,
    0x80, 0x01, 0xfc, 0x00, 0x00, 0x03, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff,
    0x80, 0xfc, 0x00, 0x03, 0x80, 0x03, 0xfc, 0x00, 0x00, 0x03, 0xff, 0x80,
    0x03, 0xff, 0xff, 0xff, 0x80, 0xfc, 0x00, 0x03, 0x80, 0x03, 0xfe, 0x00,
    0x00, 0x07, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0x80, 0xfe, 0x00, 0x03,
    0x80, 0x03, 0xff, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff,
    0x80, 0xff, 0x00, 0x03, 0x80, 0x0f, 0xff, 0x80, 0x00, 0x3f, 0xff, 0x80,
    0x03, 0xff, 0xff, 0xff, 0x80, 0xff, 0x00, 0x03, 0x80, 0x0f, 0xff, 0xc0,
    0x00, 0x3f, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0x80, 0xff, 0x80, 0x03,
    0xff, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff};

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawBitmap(0, 0, logo, 128, 64, WHITE);
  display.display();
}
void loop() {}