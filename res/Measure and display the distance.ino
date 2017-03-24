#include <SoftwareSerial.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include "Ultrasonic.h"

rgb_lcd lcd;
Ultrasonic ultrasonic(7);
void setup()
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // initialize the serial communications:
    Serial.begin(9600);
}

void loop()
{
    long RangeInCentimeters;
    RangeInCentimeters = ultrasonic.MeasureInCentimeters();
    delay(150);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("The distance:");
    lcd.setCursor(0,1) ;
    lcd.print(RangeInCentimeters,DEC);
    lcd.setCursor(5,1) ;
    lcd.print("cm");
}
