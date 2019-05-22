int xPos = 120;
int yPos = 160;
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

unsigned long draw() {
  /*
    * X is inline with the pins, 0 is towards, 1021 is other way 514 is idle
    * Y is Perpindicular to pins, 0 is towards power pins, 1021 is sw pin, 516 is idle
  */
  int dx = analogRead(0)-514;
  int dy = analogRead(1)-516;
  int left = digitalRead(8);
  int up = digitalRead(4);
  int right = digitalRead(7);
  int down = digitalRead(12);
  int middle = digitalRead(2);

  if (left == 1) {
    delay (150);
    if (left == 1) {
      ::colourIndex = ::colourIndex - 1;
    }
  }
  if (right == 1) {
    delay (150);
    if (right == 1) {
      ::colourIndex = ::colourIndex + 1; delay(150);
    }
  }
  int color = ::colours[::colourIndex];
  dx = dx / 300;
  dy = dy / 300;
  ::xPos = ::xPos + dx;
  ::yPos = ::yPos + dy;

  tft.fillCircle(::xPos-dx, ::yPos-dy, 5, color);
  tft.fillCircle(::xPos, ::yPos, 5, color);

  delay(5);

  if (middle == 1) {
    //tft.fillScreen(rgb(255, 255, 255));
  }
}
