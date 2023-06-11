// Project #8 - Showing temperature and humidity on LCD display
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

// Before running this code, you must install the DHTLib and LiquidCrystal_I2C libraries.
// The .zip files are available here: https://github.com/LucasFernandoChannel/one-hundred-projects-challenge/tree/main/arduino-libraries
#include <dht.h>
#include <LiquidCrystal_I2C.h>
// This project needs a I2C LCD. The first parameter of the lcd() function is the I2C address.
// To find this information, follow these instructions: https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/ 
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHT_PIN 2
#define waitTime 2000

dht DHTSensor;

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("DHT11 sensor");
  Serial.begin(9600);
  delay(waitTime);
}

void loop() {
  int data = DHTSensor.read11(DHT_PIN);
  float temp = DHTSensor.temperature;
  float hum = DHTSensor.humidity;

  // Use the Serial.print to know if your sensor is working
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C | ");
  Serial.print((temp * 9/5) + 32);
  Serial.println("°F");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println("%");
  Serial.println("");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print((temp * 9/5) + 32);
  lcd.setCursor(5, 1);
  lcd.print("F");
  delay(waitTime);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Humidity:");
  lcd.setCursor(0, 1);
  lcd.print(hum);
  lcd.setCursor(5, 1);
  lcd.print("%");
  delay(waitTime);    
}
