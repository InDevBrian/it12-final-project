void menuInit() {
  tft.fillScreen(rgb(152, 174, 209));

  tft.fillRect(30, 30, 180, 120, rgb(255, 255, 255));
  tft.fillRect(30, 170, 180, 120, rgb(255, 255, 255));
}

void menu() {
  updateInput();
  int b2 = analogRead(3);

  if (b2 > 1000) {
    menuInit();
  }

  if ( b1 > 1000 ) {
    if (x > 30 && x < 210) {
      if (y > 30 && y < 150) {
        while (b2 < 1000) { snake(); b2 = analogRead(3);}
      } else if (y > 170 && y < 290) {
        while (b2 < 1000) { draw(); b2 = analogRead(3);}
      }
    }
  }

  int lastx = x;
  int lasty = y;

  x += dx / 300;
  y += dy / 300;

  if (lastx != x || lasty != y) {
    if (lastx > 30 && lastx < 210) {
      if (lasty > 30 && lasty < 150) {
        tft.fillCircle(lastx, lasty, 5, rgb(255, 255, 255));
      } else if (lasty > 170 && lasty < 290) {
        tft.fillCircle(lastx, lasty, 5, rgb(255, 255, 255));
      } else { tft.fillCircle(lastx, lasty, 5, rgb(152, 174, 209)); }
    } else { tft.fillCircle(lastx, lasty, 5, rgb(152, 174, 209)); }
    tft.fillCircle(x, y, 5, rgb(0, 255, 0));
  }
}