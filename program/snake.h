int snakeBody [192][2] = {{8, 8}, {8, 9}};
int food [2] = {random(11), random(0, 15)};
int score [3] = {48, 48, 49};

int firstRender = 1;
int snakeDirection = 0;
int snakeLength = 1;
int gameOver = 0;

void gameRender() {
  if (firstRender == 1) {
    tft.fillScreen(rgb(114, 114, 114));
    for (a = 0; a < 12; a++) {
      for (b = 0; b < 16; b++) {
        tft.fillRect(a*20+2, b*20+2, 18, 18, rgb(32, 32, 32));
      }
    }

    firstRender = 0;
  }

  tft.fillRect(snakeBody[1][0]*20+2, snakeBody[1][1]*20+2, 18, 18, rgb(211, 211, 211));
  tft.fillRect(snakeBody[snakeLength][0]*20+2, snakeBody[snakeLength][1]*20+2, 18, 18, rgb(32, 32, 32));
  tft.fillRect(snakeBody[0][0]*20+2, snakeBody[0][1]*20+2, 18, 18, rgb(223, 64, 64));
  tft.fillRect(food[0]*20+3, food[1]*20+3, 16, 16, rgb(235, 115, 65));
}

void checkGame() {
  for (a = 1; a < snakeLength; a++) {
    if (snakeBody[0][0] == snakeBody[a][0] && snakeBody[0][1] == snakeBody[a][1]) {
      gameOver = 1;
      firstRender = 1;
    }
  }

  if (snakeBody[0][0] == -1 || snakeBody[0][0] == 12 || snakeBody[0][1] == -1 || snakeBody[0][1] == 16) {
    gameOver = 1;
    firstRender = 1;
  }

  if (snakeBody[0][0] == food[0] && snakeBody[0][1] == food[1]) {
    randomSeed(analogRead(0));
    food[0] = random(11);
    food[1] = random(15);
    for (a = 0; a < snakeLength; a++) {
      if (food[0] == snakeBody[a][0] && food[1] == snakeBody[a][1]) {
        food[0] = random(11);
        food[1] = random(15);
        a = 0;
      }
    }

    gameRender();

    snakeLength++;

    if (score[2] < 57) {
      score[2] ++;
    } else {
      score[2] = 48;
      if (score[1] < 57) {
        score[1] ++;
      } else {
        score[1] = 48;
        score[0] ++;
      }
    }
  }
}

void snake() {
  if (b1 > 1000 && dy < 300) {
    tft.fillScreen(0);
    score[0] = 48;
    score[1] = 48;
    score[2] = 49;
    for (a = 0; a < snakeLength+1; a++) {
      snakeBody[a][0] = 0;
      snakeBody[a][1] = 0;
    }
    snakeBody[0][0] = 8;
    snakeBody[0][1] = 8;
    snakeBody[1][0] = 8;
    snakeBody[1][1] = 9;
    firstRender = 1;
    snakeDirection = 0;
    snakeLength = 1;
    gameOver = 0;
  }

  if (gameOver == 0) {
    if (dy < -200 && snakeDirection != 2) {
      snakeDirection = 0;
    } else if (dx > 200 && snakeDirection != 3) {
      snakeDirection = 1;
    } else if (dy > 200 && snakeDirection != 0) {
      snakeDirection = 2;
    } else if (dx < -200 && snakeDirection != 1) {
      snakeDirection = 3;
    }

    for (a = snakeLength; a > 0; a--) {
      snakeBody[a][0] = snakeBody[a-1][0];
      snakeBody[a][1] = snakeBody[a-1][1];
    }

    switch(snakeDirection) {
      case 0 : snakeBody[0][1] -= 1; break;
      case 1 : snakeBody[0][0] += 1; break;
      case 2 : snakeBody[0][1] += 1; break;
      case 3 : snakeBody[0][0] -= 1; break;
    }

    gameRender();

    checkGame();

    delay(300);
  } else if (firstRender == 1) {
    tft.fillScreen(rgb(255, 0, 0));

    tft.drawChar(15, 100, score[0], 0, rgb(255, 255, 255), 12);
    tft.drawChar(85, 100, score[1], 0, rgb(255, 255, 255), 12);
    tft.drawChar(155, 100, score[2], 0, rgb(255, 255, 255), 12);

    firstRender = 0;
  }
}
