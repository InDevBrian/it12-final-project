void menuInit() {
  tft.fillScreen(rgb(152, 174, 209));

  tft.fillRect(30, 30, 180, 120, rgb(255, 255, 255));
  tft.fillRect(30, 170, 180, 120, rgb(255, 255, 255));
}

int xPos = 120;
int yPos = 160;

void menu() {
  int sw = analogRead(2);
  int mm = analogRead(3);
  int dx = analogRead(0)-514;
  int dy = analogRead(1)-516;

  if (mm > 1000) {
    menuInit();
  }

  if ( sw > 1000 ) {
    if (xPos > 30 && xPos < 210) {
      if (yPos > 30 && yPos < 150) {
        while (mm < 1000) { snake(); mm = analogRead(3);}
      } else if (yPos > 170 && yPos < 290) {
        while (mm < 1000) { draw(); mm = analogRead(3);}
      }
    }
  }

  int lastxPos = xPos;
  int lastyPos = yPos;

  xPos += dx / 300;
  yPos += dy / 300;

  if (lastxPos != xPos || lastyPos != yPos) {
    if (lastxPos > 30 && lastxPos < 210) {
      if (lastyPos > 30 && lastyPos < 150) {
        tft.fillCircle(lastxPos, lastyPos, 5, rgb(255, 255, 255));
      } else if (lastyPos > 170 && lastyPos < 290) {
        tft.fillCircle(lastxPos, lastyPos, 5, rgb(255, 255, 255));
      } else { tft.fillCircle(lastxPos, lastyPos, 5, rgb(152, 174, 209)); }
    } else { tft.fillCircle(lastxPos, lastyPos, 5, rgb(152, 174, 209)); }
    tft.fillCircle(xPos, yPos, 5, rgb(0, 255, 0));
  }
}