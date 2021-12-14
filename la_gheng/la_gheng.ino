int pinBottone = 7;
int pinRosso = 6;
int pinVerde = 5;
int pinBlu = 4;
int statoBottone = 0;

void setup() {
  pinMode(pinBottone, INPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinRosso, OUTPUT);
  pinMode(pinBlu, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int isPremuto = digitalRead(pinBottone);
 
  if(isPremuto == 0) {
    statoBottone++;
    delay(200);
  }
  if (statoBottone == 1) {
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinRosso, LOW);
    digitalWrite(pinBlu, LOW);
  }
  if (statoBottone == 2) {
    digitalWrite(pinRosso, HIGH);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinBlu, LOW);
  }
  if (statoBottone == 3) {
    digitalWrite(pinBlu, HIGH);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinRosso, LOW);
  } if (statoBottone > 3) {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinRosso, LOW);
    digitalWrite(pinBlu, LOW);
    statoBottone = 0;
  }
}
