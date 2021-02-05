#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int sensorPin = A0;
const int buzzerPin = 10;
const int sensorLimit = 300;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  GAS SENSOR ");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("  WARMING UP ! ");
  delay(20000); //20 seconds for the MQ2 to warm up
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  lcd.clear();
  int sensorValue = analogRead(sensorPin);
  lcd.setCursor(0, 0);
  lcd.print("VALUE: ");
  lcd.print(sensorValue);
  lcd.print("ppm");
  if (sensorValue > sensorLimit)
  {
    lcd.setCursor(0, 1);
    lcd.print("SMOKE DETECTED");
    tone(buzzerPin, 500, 2000);
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("  NO SMOKE");
    noTone(buzzerPin);
  }
  delay(2000);
}
