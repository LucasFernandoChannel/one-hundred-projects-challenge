// Project #3 - Photoresistor
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

int photoresistorPort = A0;
int greenLed = 2;

void setup() {
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, LOW);
  Serial.begin(9600);
}

void loop() {  
  long value = 0;
  // The average of 100 measurements is a more stable value  
  for (int i = 0; i < 100; i++)  {
    value += analogRead(photoresistorPort);
  }
  value = value / 100;
  // You can ajust the threshold value (if condition) by looking at the serial monitor
  Serial.print("Value: ");
  Serial.println(value);
  
  if (value <= 170) {
    digitalWrite(greenLed, HIGH);        
  } else {
    digitalWrite(greenLed, LOW);
  }
}
