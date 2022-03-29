int potenzio = A0;
int valoreP = 0;
int ledVerde = 4;
void setup() {
  Serial.begin(9600);
  pinMode (ledVerde, OUTPUT);
}

void loop() {
  valoreP = analogRead(potenzio);
  Serial.print( "il valore del potenziometro è: ");
  Serial.println(valoreP);
  delay(1000);
  if (valoreP == 69) {
    digitalWrite(ledVerde, HIGH);
  }

  else {
    digitalWrite (ledVerde, LOW);
  }
}
