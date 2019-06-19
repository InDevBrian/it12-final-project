int dx = analogRead(0)-514;
int dy = analogRead(1)-516;
int b1 = analogRead(2);
int b2 = analogRead(3);
int b3 = analogRead(4);
int b4 = analogRead(5);

void updateInput() {
  dx = analogRead(0)-514;
  dy = analogRead(1)-516;
  b1 = analogRead(2);
  b2 = analogRead(5);
  b3 = analogRead(4);
  b4 = analogRead(3);
}