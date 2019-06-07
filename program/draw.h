int colours[10] = {
  rgb(255, 0, 0),
  rgb(255, 150, 0),
  rgb(255, 240, 0),
  rgb(0, 255, 0),
  rgb(0, 255, 240),
  rgb(0, 0, 255),
  rgb(150, 0, 255),
  rgb(255, 0, 200),
  rgb(255, 255, 255),
  rgb(0, 0, 0)
};

int colourIndex = 0;

int x = 120;
int y = 160;

unsigned long draw() {
  /*
    * X is inline with the pins, 0 is towards, 1021 is other way 514 is idle
    * Y is Perpindicular to pins, 0 is towards power pins, 1021 is sw pin, 516 is idle
  */
  int dx = analogRead(0)-514;
  int dy = analogRead(1)-516;
  int cleft = analogRead(5);
  int cright = analogRead(4);
  int rs = analogRead(2);

  if (cleft > 1000) {
    delay (150);
    colourIndex = colourIndex - 1;
  }
  if (cright > 1000) {
    delay (150);
    colourIndex = colourIndex + 1;
  }
  int color = colours[colourIndex];
  x += dx / 300;
  y += dy / 300;

  tft.fillCircle(x-dx/300, y-dy/300, 5, color);
  tft.fillCircle(x, y, 5, color);

  delay(5);

  if (rs > 1000) {
    tft.fillScreen(rgb(255, 255, 255));
  }
}
