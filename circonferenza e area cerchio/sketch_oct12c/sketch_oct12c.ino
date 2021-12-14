int lakaka = 7;
int adam_motorola = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
  pinMode(lakaka, OUTPUT);
  pinMode(adam_motorola, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  double raggio;
  raggio = Serial.read();
  if (raggio != -1) {
    // calcolo area del cerchio
    double area = 3.14*raggio*raggio;
 
    // calcolo circonferenza
    double circ = 2*3.14*raggio;

    // Serial monitor
    Serial.print("L'area è: ");
    Serial.println(area);
    Serial.print("La circonferenza è: ");
    Serial.println(circ);
    digitalWrite(adam_motorola, HIGH);
    digitalWrite(lakaka, LOW);
  }
  else {
    digitalWrite(lakaka, HIGH);
    delay(3000);
    digitalWrite(adam_motorola, LOW);
  }
}
