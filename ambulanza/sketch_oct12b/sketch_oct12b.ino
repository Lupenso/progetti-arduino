int red_light_pin = 7;
int green_light_pin = 6;
int blue_light_pin = 8;
void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
 void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
void loop() {
  RGB_color(255, 0, 0); // Red
  delay(250);
  RGB_color(0, 255, 0); // Green
  delay(250);
  RGB_color(0, 0, 255); // Blue
  delay(250);
  RGB_color(255, 255, 125); // Raspberry
  delay(250);
  RGB_color(0, 255, 255); // Cyan
  delay(250);
  RGB_color(255, 0, 255); // Magenta
  delay(250);
  RGB_color(255, 255, 0); // Yellow
  delay(250);
  RGB_color(255, 255, 255); // White
  delay(250);
}
