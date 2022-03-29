int potenzio = A0;
int valoreP = 0;
int pinVerde = 3;
int pinRosso = 6;
int pinBlu = 9;
int intensita;
char colore;

void setup() {
  Serial.begin(9600);
  pinMode(pinRosso, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBlu, OUTPUT);
  pinMode(potenzio, INPUT);
  Serial.println("Scegli il colore");
}

void loop() {
  if (Serial.available()) {
    colore = Serial.read();
    delay(400);
  }
  if (colore == 'R') {
    analogWrite(pinRosso, 255);
  } else if (colore == 'B') {
    analogWrite(pinBlu, 255);
  } else if (colore == 'G') {
    analogWrite(pinVerde, 255);
  }
}
