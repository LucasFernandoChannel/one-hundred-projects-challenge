// Project #12 - Traffic light
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#define redLed 2
#define yellowLed 3
#define greenLed 4
#define longWait 2000
#define shortWait 500

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

void loop() {
  digitalWrite(greenLed, HIGH);
  delay(longWait);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, HIGH);
  delay(shortWait);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, HIGH);
  delay(longWait);
  digitalWrite(redLed, LOW);
}
