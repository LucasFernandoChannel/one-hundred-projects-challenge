// Project #11 - LED blinking
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#define led 2
#define waitTime 250

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(waitTime);
  digitalWrite(led, LOW);
  delay(waitTime);
}
