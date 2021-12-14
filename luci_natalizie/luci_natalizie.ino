int pinVerde1 = 3;
int pinVerde2 = 8;
int pinVerde3 = 1;

int pinRosso1 = 4;
int pinRosso2 = 10;
int pinRosso3 = 11;

int pinBlu1 = 6;
int pinBlu2 = 9;
int pinBlu3 = 5;

int inputLucine;

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

  Serial.begin(9600);
  Serial.println("Scegli il gioco di luci (1-2-3)");

}

void loop() {
  
  // lucineOn3();
  // delay(1000);
  // lucineOff3();

  // lucineOn2();
  // delay(200);
  // lucineOff2();
  // delay(200);
}



void lucineOn1() {
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
void lucineOff1() {
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
void lucineOn2() {
  digitalWrite(pinVerde1, HIGH);
  digitalWrite(pinRosso2, HIGH);
  digitalWrite(pinBlu3, HIGH);
}
void lucineOff2() {
  digitalWrite(pinVerde1, LOW);
  digitalWrite(pinRosso2, LOW);
  digitalWrite(pinBlu3, LOW);
}

void lucineOn3() {
  for (int num = 0; num < 255; num++) {
    analogWrite(pinVerde1, num);
    analogWrite(pinRosso2, num);
    analogWrite(pinBlu3, num);
    delay(10);
  }
}
void lucineOff3() {
  for (int num = 255; num > 0; num--) {
    analogWrite(pinVerde1, num);
    analogWrite(pinRosso2, num);
    analogWrite(pinBlu3, num);
    delay(10);
  }
}
