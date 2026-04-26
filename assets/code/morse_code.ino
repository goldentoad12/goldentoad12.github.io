const int led1=2;


int dotDuration = 200;
int dashDuration = 500;
int symbolGap = dotDuration;
int wordGap = 2 * dashDuration;
int letterGap = 2 * dotDuration;

void setup() {
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  morseM(led1);
  delay(letterGap);
  morseA(led1);
  delay(letterGap);
  morseT(led1);
  delay(letterGap);
  morseT(led1);
  delay(letterGap);
  morseH(led1);
  delay(letterGap);
  morseE(led1);
  delay(letterGap);
  morseW(led1);
  delay(wordGap);
  Serial.println();
}


void dot(int led) {
  digitalWrite(led,HIGH);
    delay(dotDuration);
  digitalWrite(led,LOW);
    delay(symbolGap);
}

void dash(int led)  {
  digitalWrite(led,HIGH);
    delay(dashDuration);
  digitalWrite(led,LOW);
    delay(symbolGap);
}

void morseA(int led) {
  dot(led);
  dash(led);
  Serial.print("A");
}

void morseB(int led) {
  dash(led);
  dot(led);
  dot(led);
  dot(led);
  Serial.print("B");
}

void morseC(int led)  {
  dash(led);
  dot(led);
  dash(led);
  dot(led);
  Serial.print("C");
}

void morseD(int led) {
  dash(led);
  dot(led);
  dot(led);
  Serial.print("D");
}

void morseE(int led)  {
  dot(led);
  Serial.print("E");
}

void morseF(int led)  {
  dot(led);
  dot(led);
  dash(led);
  dot(led);
  Serial.print("F");
}

void morseG(int led)  {
  dash(led);
  dash(led);
  dot(led);
  Serial.print("G");
}

void morseH(int led)  {
  dot(led);
  dot(led);
  dot(led);
  dot(led);
  Serial.print("H");
}

void morseI(int led)  {
  dot(led);
  dot(led);
  Serial.print("I");
}

void morseJ(int led)  {
  dot(led);
  dash(led);
  dash(led);
  dash(led);
  Serial.print("J");
}

void morseK(int led)  {
  dash(led);
  dot(led);
  dash(led);
  Serial.print("K");
}

void morseL(int led)  {
  dot(led);
  dash(led);
  dot(led);
  dot(led);
  Serial.print("L");
}

void morseM(int led)  {
  dash(led);
  dash(led);
  Serial.print("M");
}

void morseN(int led)  {
  dash(led);
  dot(led);
  Serial.print("N");
}

void morseO(int led)  {
  dash(led);
  dash(led);
  dash(led);
  Serial.print("O");
}

void morseP(int led)  {
  dot(led);
  dash(led);
  dash(led);
  dot(led);
  Serial.print("P");
}

void morseQ(int led)  {
  dash(led);
  dash(led);
  dot(led);
  dash(led);
  Serial.print("Q");
}

void morseR(int led)  {
  dot(led);
  dash(led);
  dot(led);
  Serial.print("R");
}

void morseS(int led)  {
  dot(led);
  dot(led);
  dot(led);
  Serial.print("S");
}

void morseT(int led)  {
  dash(led);
  Serial.print("T");
}

void morseU(int led)  {
  dot(led);
  dot(led);
  dash(led);
  Serial.print("U");
}

void morseV(int led)  {
  dot(led);
  dot(led);
  dot(led);
  dash(led);
  Serial.print("V");
}

void morseW(int led)  {
  dot(led);
  dash(led);
  dash(led);
  Serial.print("W");
}

void morseX(int led)  {
  dash(led);
  dot(led);
  dot(led);
  dash(led);
  Serial.print("X");
}

void morseY(int led)  {
  dash(led);
  dot(led);
  dash(led);
  dash(led);
  Serial.print("Y");
}

void morseZ(int led)  {
  dash(led);
  dash(led);
  dot(led);
  dot(led);
  Serial.print("Z");
}























