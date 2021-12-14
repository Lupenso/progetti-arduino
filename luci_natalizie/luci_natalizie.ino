int pinVerde1 = 5;
int pinVerde2 = 8;
int pinVerde3 = 11;

int pinRosso1 = 4;
int pinRosso2 = 7;
int pinRosso3 = 10;

int pinBlu1 = 6;
int pinBlu2 = 9;
int pinBlu3 = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinVerde1, OUTPUT);
  pinMode(pinVerde2, OUTPUT);
  pinMode(pinVerde3, OUTPUT);

  pinMode(pinRosso1, OUTPUT);
  pinMode(pinRosso2, OUTPUT);
  pinMode(pinRosso3, OUTPUT);

  pinMode(pinBlu1, OUTPUT);
  pinMode(pinBlu2, OUTPUT);
  pinMode(pinBlu3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lucineOn();
  delay(500);
  lucineOff();
}

void lucineOn() {
  // spegne e accende le lucine
  int n = 1;
  if (n < 4) {
    if (n == 1) {
      digitalWrite(pinVerde1, HIGH);
      delay(500);
      n++;
    }
    if (n == 2) {
      digitalWrite(pinRosso2, HIGH);
      delay(500);
      n++;
    }
    if (n == 3) {
      digitalWrite(pinBlu3, HIGH);
      delay(500);
      n++;
    } 
  }
}
void lucineOff() {
  int n = 3;
    if (n > 0) {
      if (n == 3) {
        digitalWrite(pinBlu3, LOW);
        delay(500);
        n--;
      }
      if (n == 2) {
        digitalWrite(pinRosso2, LOW);
        delay(500);
        n--;
      }
      if (n == 1) {
        digitalWrite(pinVerde1, LOW);
        delay(500);
        n--;
      }
    }
}
