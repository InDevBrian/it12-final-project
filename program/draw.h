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
  if ( b4 > 1000 && dy < 300 ) { colourIndex = colourIndex - 1; delay(175); }

  if ( b3 > 1000 && dy < 300 ) { colourIndex = colourIndex + 1; delay(175); }

  if ( colourIndex == 10) {
    colourIndex = 0;
  } else if ( colourIndex == -1 ) {
    colourIndex = 9;
  }

  int color = colours[colourIndex];
  x += dx / 300;
  y += dy / 300;

  tft.fillCircle(x-dx/300, y-dy/300, 5, color);
  tft.fillCircle(x, y, 5, color);

  delay(5);

  if ( b1 > 1000 && dy < 300 ) { tft.fillScreen(rgb(255, 255, 255)); }
}
