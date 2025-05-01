#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int SDA_pin = D2;
int SCL_pin = D3;
LiquidCrystal_I2C lcd(0x27,16, 2);


void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PRAKTIKUM PST");
  lcd.setCursor(0, 1);
  lcd.print("DITIADAKAN");
}

void loop() {
  lcd.scrollDisplayLeft();
  delay(300);
}

