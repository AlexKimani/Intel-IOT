// demo of Starter Kit V2.0
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
int i;
const int colorR = 001;
const int colorG = 100;
const int colorB = 150;
const int potentiometer = A0;                    // rotary angle sensor connect to A0

int led = A0;

void setup()
{
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    delay(1000);
    
    pinMode(led, OUTPUT); 
    Serial.begin(9600);                         // set the serial communication frequency at 9600 bits per sec
    pinMode(potentiometer, INPUT);
    pinMode(led, OUTPUT); 
}

void loop()
{
    int value = analogRead(potentiometer);
    String br = "brightness = ";
    Serial.println(value);     // pirnt the value on the serial monitor screen
    delay(2000);                // wait 1000ms before printing next value
    analogWrite(led, value); 
    lcd.print(br + value);
    delay(1000);
    lcd.clear();
}
