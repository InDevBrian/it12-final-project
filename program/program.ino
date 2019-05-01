using namespace std;
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  Serial.begin(9600);
  tft.begin();
}

int rgb(int red, int green, int blue) {
  int bin[16], i, tRed, tGreen, tBlue;
  double number;

  tRed = red * 31 / 255;
  tGreen = green * 63 / 255;
  tBlue = blue * 31 / 255;

  for (i=0; i<16; i++) {
    if (i<5) {
      bin[i] = tBlue % 2;
      tBlue = tBlue / 2;
    }

    else if (i<11) {
      bin[i] = tGreen % 2;
      tGreen = tGreen / 2;
    }

    else {
      bin[i] = tRed % 2;
      tRed = tRed / 2;
    }
  }

  number = 0;

  for (i=0; i<16; i++) {
    number = number + pow(bin[i]*2, i);
  }

  return number;
}

void loop(void) {
  test();
}

unsigned long test() {
  tft.fillScreen(rgb(255, 255, 255));
  delay(1000);
  tft.fillScreen(rgb(255, 0, 0));
  delay(1000);
  tft.fillScreen(rgb(0, 255, 0));
  delay(1000);
  tft.fillScreen(rgb(0, 0, 255));
  delay(1000);
  tft.fillScreen(rgb(0, 0, 0));
  delay(1000);
}
