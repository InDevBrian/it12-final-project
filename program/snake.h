#include "functions.h"

int board [15][20];
int boardDirections [15][20];

int headX = 8;
int headY = 8;
int snakeDirection = 0;

unsigned long snakeRender() {
  for ( int x = 0; x < 15; x++ ) {
    for ( int y = 0; y < 20; y++ ) {
      if (::board[x][y] == 0) {
        tft.fillRect(x*16+1, y*16+1, 14, 14, 0xFFFF);
      } else if ( ::board[x][y] == 1 ) {
        tft.fillRect(x*16+1, y*16+1, 14, 14, 0xF000);
      } else {
        tft.fillRect(x*16+1, y*16+1, 14, 14, rgb(0, 255, 0);
      }
    }
  }
}

unsigned long snake() {
  int up = analogRead(0);
  int down = analogRead(1);
  int left = analogRead(2);
  int right = analogRead(3);

  ::board[::headX][::headY] = 0;

  if ( up == 1022 ) {
    snakeDirection = 0;
  } else if ( right == 1022 ) {
    snakeDirection = 1;
  } else if ( down == 1022 ) {
    snakeDirection = 2;
  } else if ( left == 1022 ) {
    snakeDirection = 3;
  }

  switch( snakeDirection ) {
      case 0 : ::headY = ::headY - 1; break;
      case 1 : ::headX = ::headX + 1; break;
      case 2 : ::headY = ::headY + 1; break;
      case 3 : ::headX = ::headX - 1; break;
  }

  ::board[::headX][::headY] = 1;

   for ( int x = 0; x < 15; x++ ) {
    for ( int y = 0; y < 20; y++ ) {
      if (::board[x][y] == 2) {
        ::board[x][y] == 0
        newPos = snakeBody({ x, y });
        ::board[newPos[0]][newPos[1]] = 2;
      }
    }
  }
  
  snakeRender();
}

unsigned long snakeBody( int snakeBodyArray[2] ) {
  bodyX = snakeBodyArray[0];
  bodyY = snakeBodyArray[1];

  switch( ::boardDirections[::bodyX][::bodyY] ) {
      case 0 : bodyY = bodyY - 1; break;
      case 1 : bodyX = bodyX + 1; break;
      case 2 : bodyY = bodyY + 1; break;
      case 3 : bodyX = bodyX - 1; break;
  }
  
  return { bodyX, bodyY };
}
