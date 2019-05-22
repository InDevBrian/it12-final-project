using namespace std;

int rgb(int red, int green, int blue) {
  int bin[16], i, tRed, tGreen, tBlue;
  double number;

  tRed = red * 31 / 255;
  tGreen = green * 63 / 255;
  tBlue = blue * 31 / 255;

  for (i=0; i<16; i++) {
    if (i<5) {
      bin[i] = tBlue % 2;
      tBlue = tBlue / 2;
    }

    else if (i<11) {
      bin[i] = tGreen % 2;
      tGreen = tGreen / 2;
    }

    else {
      bin[i] = tRed % 2;
      tRed = tRed / 2;
    }
  }

  number = 0;

  for (i=0; i<16; i++) {
    number = number + pow(bin[i]*2, i);
  }

  return number;
}
