#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = A0;

void setup()
{
  Serial.begin(9600);

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();

  delay(2000);
  pinMode(input,INPUT);
}

void loop()
{

  X = pulseIn(input, HIGH);
  Y = pulseIn(input, LOW);
  TIME = X + Y;
  FREQUENCY = 1000000/TIME;
  WATER = FREQUENCY/7.5;
  LS = WATER/60;

  if(FREQUENCY >= 0)
  {
    if(isinf(FREQUENCY))
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Zoe Han Idle");
      lcd.setCursor(0,1);
      lcd.print("TOTAL:");
      lcd.print( TOTAL);
      lcd.print(" L");
    }
    else
    {
      TOTAL = TOTAL + LS;
      Serial.println(FREQUENCY);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("VOL.: ");
      lcd.print(WATER);
      lcd.print(" L/M");
      lcd.setCursor(0,1);
      lcd.print("TOTAL:");
      lcd.print( TOTAL);
      lcd.print(" L");
    }
  }
  delay(1000);
}