int t=0;
float h=0;
int sensor = A0;
float temp;
float tempc;
float tempf;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16);
void setup() 
{
  pinMode(sensor,INPUT);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor (0,0);
  lcd.print ("WEATHER MONITOR");
  lcd.setCursor (0,1);
  lcd.print ("MARK PAGARIGAN");
  delay (3000);
  Serial.begin(9600);
} 
void loop() {
  delay(2000);
  t=t+2;
  temp=analogRead(sensor);
  tempc=(temp*5)/10;
  tempf=(tempc*1.8)+32;
  if(t>=1800 || h==0)
  {
    Serial.println("_______________________________________");
    Serial.print("Current Hours = ");
    Serial.println(h);
    Serial.print("Temp in deg Celcius = ");
    Serial.println(tempc);
    Serial.print("Temp in deg Fahrenheit = ");
    Serial.println(tempf);
    h=h+0.5;
    t=0;
  }
  lcd.setCursor(0,0);
  lcd.print("Temp in C = ");
  lcd.println(tempc);
  lcd.setCursor(0,1);
  lcd.print("Temp in F = ");
  lcd.println(tempf);
}
