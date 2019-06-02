int board [15][20];
int boardDirections [15][20];
int snakeBody [15][2] = { {8, 8}, {8, 9}, {8, 10} };

int snakeDirection = 0;

unsigned long snakeRender() {
  for ( int x = 0; x < 15; x++ ) {
    for ( int y = 0; y < 20; y++ ) {
      if (board[x][y] == 0) {
        tft.fillRect(x*16+1, y*16+1, 14, 14, 0xFFFF);
      } else if ( board[x][y] == 1 ) {
        tft.fillRect(x*16+1, y*16+1, 14, 14, 0xF000);
      } else {
        tft.fillRect(x*16+1, y*16+1, 14, 14, rgb(0, 255, 0));
      }
    }
  }
}

unsigned long snake() {
  int up = analogRead(0);
  int down = analogRead(1);
  int left = analogRead(2);
  int right = analogRead(3);

  Serial.println(snakeDirection);

  board[snakeBody[0][0]][snakeBody[0][1]] = 0;

  if ( (up == 1022) && (snakeDirection != 2) ) {
    Serial.println("Up");
    snakeDirection = 0;
  } else if ( (right == 1022) && (snakeDirection != 3) ) {
    Serial.println("Right");
    snakeDirection = 1;
  } else if ( (down == 1022) && (snakeDirection != 0) ) {
    Serial.println("Down");
    snakeDirection = 2;
  } else if ( (left == 1022) && (snakeDirection != 1) ) {
    Serial.println("Left");
    snakeDirection = 3;
  }

  boardDirections[snakeBody[0][0]][snakeBody[0][1]] = snakeDirection;

  switch( snakeDirection ) {
    case 0 : snakeBody[0][1] = snakeBody[0][1] - 1; break;
    case 1 : snakeBody[0][0] = snakeBody[0][0] + 1; break;
    case 2 : snakeBody[0][1] = snakeBody[0][1] + 1; break;
    case 3 : snakeBody[0][0] = snakeBody[0][0] - 1; break;
  }

  board[snakeBody[0][0]][snakeBody[0][1]] = 1;

  for (int b = 1; b < 15; b++) {
    board[snakeBody[b][0]][snakeBody[b][1]] = 0;

    switch( boardDirections[snakeBody[b][0]][snakeBody[b][1]] ) {
      case 0 : snakeBody[b][1] = snakeBody[b][1] - 1; break;
      case 1 : snakeBody[b][0] = snakeBody[b][0] + 1; break;
      case 2 : snakeBody[b][1] = snakeBody[b][1] + 1; break;
      case 3 : snakeBody[b][0] = snakeBody[b][0] - 1; break;
    }

    board[snakeBody[b][0]][snakeBody[b][1]] = 2;
  }

  snakeRender();
}
