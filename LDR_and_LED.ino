//LDR
void ldr_sensor() {
  int analogReadPin;
  String print_str;
  analogReadPin = analogRead(LDR);
  print_str = "ldr is: " + String(analogReadPin);
  Serial.println(print_str);
  if (analogReadPin < darkness)
    led_on();
  else
    led_off();
}
void led_on() {
  for (byte i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, 255, 255, 255);
    pixels.show();
  }
}
void led_off() {
  pixels.clear();
  pixels.show();
}