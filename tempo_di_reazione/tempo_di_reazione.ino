// Sketch di Dux_gae_69
int pinLed = 6;
int pinBottone = 9;
long tempoDiReazione = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinBottone, INPUT);
  pinMode(pinLed, OUTPUT);
  randomSeed(10469);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  trovaReazione();
}
 
void trovaReazione() {
  int tempoAccensionepinLed = random(1000, 3000);
  delay(tempoAccensionepinLed);
  digitalWrite(pinLed, 1);
  while (true) {
    tempoDiReazione++;
    delay(1);
    if (digitalRead(pinBottone) == 0) {
      break;
    }
  }
  digitalWrite(pinLed, 0);
  Serial.print("Ci hai messo: ");
  Serial.print(tempoDiReazione);
  Serial.println(" Millisecondi!");
  
  if (tempoDiReazione >= 1000) {
    Serial.println("Sei un bottazzo");
  } else if (tempoDiReazione >= 300) {
    Serial.println("Sei mediocre");
  } else if (tempoDiReazione >= 200) {
    Serial.println("Sei buono");
  } else if (tempoDiReazione >= 100) {
    Serial.println("Sei un pro player di fortnite");
  } else if (tempoDiReazione <= 10) {
    Serial.println("Sei un cheater");
  }
 
  tempoDiReazione = 0;
}
