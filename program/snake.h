int board [12][16];
int boardDirections [12][16];
int snakeBody [15][2] = { {8, 8}, {8, 9}, {8, 10} };

int firstRender = 1;
int snakeDirection = 0;

unsigned long snakeRender() {
  if ( firstRender == 1 ) {
    for ( int x = 0; x < 12; x++ ) {
      for ( int y = 0; y < 16; y++ ) {
        if (board[x][y] == 0) {
          tft.fillRect(x*20+2, y*20+2, 16, 16, 65535);
        } else if ( board[x][y] == 1 ) {
          tft.fillRect(x*20+2, y*20+2, 16, 16, 61440);
        } else {
          tft.fillRect(x*20+2, y*20+2, 16, 16, 2016);
        }
      }
    }

    firstRender = 0;
  }

  for ( int p = 0; p < 15; p++ ) {
    int x = snakeBody[p][0];
    int y = snakeBody[p][1];

    if (board[x][y] == 0) {
      tft.fillRect(x*20+2, y*20+2, 16, 16, 65535);
    } else if ( board[x][y] == 1 ) {
      tft.fillRect(x*20+2, y*20+2, 16, 16, 61440);
    } else {
      tft.fillRect(x*20+2, y*20+2, 16, 16, 2016);
    }
  }
}

unsigned long snakeMove(int a, int d) {
  board[snakeBody[a][0]][snakeBody[a][1]] = 0;
  
  switch( d ) {
    case 0 : snakeBody[a][1] -= 1;
    case 1 : snakeBody[a][0] += 1;
    case 2 : snakeBody[a][1] += 1;
    case 3 : snakeBody[a][0] -= 1;
  }

  if ( a == 0 ) { board[snakeBody[a][0]][snakeBody[a][1]] = 1; }
  else { board[snakeBody[a][0]][snakeBody[a][1]] = 2; }
}

unsigned long snake() {
  int up = analogRead(0);
  int down = analogRead(1);
  int left = analogRead(2);
  int right = analogRead(3);

  delay(300);

  if ( (up == 1022) && (snakeDirection != 2) ) {
    snakeDirection = 0;
  } else if ( (right == 1022) && (snakeDirection != 3) ) {
    snakeDirection = 1;
  } else if ( (down == 1022) && (snakeDirection != 0) ) {
    snakeDirection = 2;
  } else if ( (left == 1022) && (snakeDirection != 1) ) {
    snakeDirection = 3;
  }

  for (int b = 0; b < 15; b++) {
    snakeMove(b, snakeDirection);
  }

  boardDirections[snakeBody[0][0]][snakeBody[0][1]] = snakeDirection;



  snakeRender();
}
