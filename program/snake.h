int boardDirections [12][16];
int snakeBody [100][2] = { {8, 8}, {8, 9}, {8, 10} };

int firstRender = 1;
int snakeDirection = 0;
int snakeLength = 3;

unsigned long snakeRender() {
  if ( firstRender == 1 ) {
    for ( int x = 0; x < 12; x++ ) {
      for ( int y = 0; y < 16; y++ ) {
        tft.fillRect(x*20+2, y*20+2, 16, 16, 65535);
      }
    }

    firstRender = 0;
  }

  tft.fillRect(snakeBody[0][0]*20+2, snakeBody[0][1]*20+2, 16, 16, 61440);

  for ( int p = 1; p < snakeLength-1; p++ ) {
    int x = snakeBody[p][0];
    int y = snakeBody[p][1];
    
    tft.fillRect(x*20+2, y*20+2, 16, 16, 2016);
  }

  tft.fillRect(snakeBody[snakeLength-1][0]*20+2, snakeBody[snakeLength-1][1]*20+2, 16, 16, 65535);
}

unsigned long snakeMove(int a, int d) {
  switch( d ) {
    case 0 : snakeBody[a][1] -= 1; break;
    case 1 : snakeBody[a][0] += 1; break;
    case 2 : snakeBody[a][1] += 1; break;
    case 3 : snakeBody[a][0] -= 1; break;
  }
}

unsigned long snake() {
  int up = analogRead(0);
  int down = analogRead(1);
  int left = analogRead(2);
  int right = analogRead(3);

  if ( (up == 1022) && (snakeDirection != 2) ) {
    snakeDirection = 0;
  } else if ( (right == 1022) && (snakeDirection != 3) ) {
    snakeDirection = 1;
  } else if ( (down == 1022) && (snakeDirection != 0) ) {
    snakeDirection = 2;
  } else if ( (left == 1022) && (snakeDirection != 1) ) {
    snakeDirection = 3;
  }

  boardDirections[snakeBody[0][0]][snakeBody[0][1]] = snakeDirection;

  for (int b = 0; b < 15; b++) {
    snakeMove(b, boardDirections[snakeBody[b][0]][snakeBody[b][1]]);
  }

  snakeRender();

  delay(500);
}
