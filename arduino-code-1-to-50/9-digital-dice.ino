// Project #9 - Digital dice
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

// Before running this code, you must install the LiquidCrystal_I2C library.
// The .zip file is available here: https://github.com/LucasFernandoChannel/one-hundred-projects-challenge/tree/main/arduino-libraries
#include <LiquidCrystal_I2C.h>
// This project needs a I2C LCD. The first parameter of the lcd() function is the I2C address.
// To find this information, follow these instructions: https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/ 
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define button 2

void setup() {
  pinMode(button, INPUT_PULLUP);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Digital dice");
}

void loop() {    
  int value = digitalRead(button);
  if (value == 0) {
    int number = random(1, 7); // Choose a number from 1 to 6
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Face: ");
    lcd.setCursor(6, 0);
    lcd.print(number);
  }
}
