int coloreRosso = A0;
int coloreBlu = A2;
int coloreVerde = A1;

int pinBottone = 2;

void RGBcolor(int red, int green, int blue) {
  analogWrite(coloreRosso, red);
  analogWrite(coloreVerde, green);
  analogWrite(coloreBlu, blue);
}
void funzionamentoNormale() {
  RGBcolor(0, 255, 0);
  delay(10000);
  RGBcolor(255, 255, 0);
  delay(5000);
  RGBcolor(255, 0, 0);
  delay(10000);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pinBottone, INPUT);
  pinMode(coloreRosso, OUTPUT);
  pinMode(coloreBlu, OUTPUT);
  pinMode(coloreVerde, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  funzionamentoNormale();
}
