void olde(String text) {
  display.clearDisplay();
  display.setTextColor(SH110X_WHITE, SH110X_BLACK);  //(1,0)
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.print(text);
  display.display();
}