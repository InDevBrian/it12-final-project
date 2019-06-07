#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

#include "functions.h"
#include "snake.h"
#include "draw.h"
#include "menu.h"

void setup() {
  Serial.begin(9600);
  tft.begin();
  menuInit();
}

void loop(void) {
  menu();
}
