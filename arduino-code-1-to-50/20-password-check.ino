// Project #20 - Password check
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#include <Keypad.h>
// Before running this code, you must install the DHTLib and LiquidCrystal_I2C libraries.
// The .zip files are available here: https://github.com/LucasFernandoChannel/one-hundred-projects-challenge/tree/main/arduino-libraries
#include <LiquidCrystal_I2C.h>

// This project used a 4x4 keypad. But a 3x4 keypad will work the same.
// You just need to update the code below.
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

// This project needs a I2C LCD. The first parameter of the lcd() function is the I2C address.
// To find this information, follow these instructions: https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/ 
LiquidCrystal_I2C lcd(0x27, 16, 2);

String password = "123580"; // The user password stored into Arduino
String userPassword = ""; // The password the user has typed
String maskPassword = ""; // For example, if the user typed 7362, maskPassword will be ****

bool correct = false;

int buzzer = 10;
int redLed = 11;
int greenLed = 12; 

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);

  digitalWrite(buzzer, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Type password:");
  lcd.setCursor(0, 1);
}

void loop() {

  if (correct == false) {
    char customKey = customKeypad.getKey();
    
    if (customKey) {
      if ((customKey != '*') && (customKey != '#')) {
        maskPassword  += "*";
        userPassword += customKey;

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Type password:");
        lcd.setCursor(0, 1);
        lcd.print(maskPassword);
      } else if (customKey == '#') {
        int len = userPassword.length();
        if (len > 1) {
          userPassword = userPassword.substring(0, len - 1);
          maskPassword = maskPassword.substring(0, len - 1);

        } else if (len == 1) {
          userPassword = "";
          maskPassword = "";
        }

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Type password:");
        lcd.setCursor(0, 1);
        lcd.print(maskPassword);
      } else if (customKey == '*') {
        if (userPassword == password) {
          digitalWrite(greenLed, HIGH); 
          
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Right password");

          for (int h = 400; h <= 1000; h += 100) {
            tone(buzzer, h);
            delay(250);          
          }
          noTone(buzzer);
          
          correct = true;
        } else {
          digitalWrite(redLed, HIGH);    

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Wrong password");
          lcd.setCursor(0, 1);
          lcd.print("Try again");
                
          for (int i = 1000; i <= 2000; i += 100) {
            tone(buzzer, i);
            delay(250);
          }
          
          noTone(buzzer);
          delay(2000);              
          digitalWrite(redLed, LOW);

          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Type password:");
          lcd.setCursor(0, 1);
          maskPassword = "";
          userPassword = "";

          correct = false;        
        }
      }
    }
  }
}
