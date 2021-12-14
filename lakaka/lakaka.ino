/* Sketch
 *  il 16/11/2021
 */

int pinRosso = A1;
int pinVerde = A2;
int pinBlu = A3;

void setup() {
  pinMode(pinRosso, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBlu, OUTPUT);
  randomSeed(analogRead[0]);
  Serial.begin(9600);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(pinRosso, red_light_value);
  analogWrite(pinVerde, green_light_value);
  analogWrite(pinBlu, blue_light_value);
}

void loop() {
  int n = random(1, 10469);
  delay(300);
  if (n % 3 == 0) {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" è divisibile per 3");
    RGB_color(255, 0, 0);
    delay(500);
  }if (n % 5 == 0)  {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" è divisibile per 5");
    RGB_color(0, 255, 0);
    delay(500);
  }if (n % 7 == 0) {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" è divisibile per 7");
    RGB_color(0, 0, 255);
    delay(500);
  } 
    if (n % 3 == 0 && n % 5 == 0)  {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" è divisibile per 3 e per 5");
    RGB_color(255, 255, 125);
    delay(500);
  }
   if (n % 3 == 0 && n % 7 == 0)  {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" è divisibile per 3 e per 7");
    RGB_color(0, 255, 255);
    delay(500);
  }
   if (n % 7 == 0 && n % 5 == 0)  {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" è divisibile per 5 e per 7");
    RGB_color(255, 255, 0
    );
    delay(500);
  }else {
    Serial.print("Il numero ");
    Serial.print(n);
    Serial.println(" Non è divisibile ne per tre, ne per 5, ne per 7");
    RGB_color(0, 0, 0);
    delay(500);    
  }
}
