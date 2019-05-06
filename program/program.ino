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
  tft.fillScreen(rgb(255, 255, 255));
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
  joystickTest();
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

/*
  * X is inline with the pins, 0 is towards, 1021 is other way 514 is idle
  * Y is Perpindicular to pins, 0 is towards power pins, 1021 is sw pin, 516 is idle
*/

int xPos = 0;
int yPos = 0;

unsigned long joystickTest() {
  int dx = analogRead(0)-514;
  int dy = analogRead(1)-516;
  dx = dx / 300;
  dy = dy / 300;
  ::xPos = ::xPos + dx;
  ::yPos = ::yPos + dy;
  int swVal = analogRead(2);

  tft.fillCircle(::xPos-dx, ::yPos-dy, 5, rgb(255, 255, 255));
  tft.fillCircle(::xPos, ::yPos, 5, rgb(255, 0, 0));

  delay(5);
}
