// Project #7 - Temperature and humidity sensor (DHT11)
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

// Before running this code, you must install the DHTLib library.
// The .zip file is available here: https://github.com/LucasFernandoChannel/one-hundred-projects-challenge/tree/main/arduino-libraries
#include <dht.h>
#define DHT_PIN 4
#define RED_PIN 3
#define GREEN_PIN 2
#define waitTime 2000

dht DHTSensor;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.begin(9600);
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

  if (temp >= 20.00 && hum <= 50.00) {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
  } else {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
  }
    
  delay(waitTime);
}