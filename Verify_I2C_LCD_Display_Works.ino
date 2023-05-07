#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //lcd.print("Hello, world!");
}

void loop()
{
  // Do nothing here...
  lcd.clear();
  lcd.print("Zoe Han");
  delay(1000);
  lcd.clear();
 

  lcd.print("Science Project");
  lcd.setCursor(3,1);
  lcd.print("Water Savior");
  delay(1000);
  lcd.clear();
}
