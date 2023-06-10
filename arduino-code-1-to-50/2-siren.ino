// Project #2 - Siren
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

int redLed = 2;
int blueLed = 3;
int buzzer = 4;
int waitTime = 250;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(buzzer, LOW);
}

void loop() {
  digitalWrite(blueLed, HIGH);
  digitalWrite(redLed, LOW);
  tone(buzzer, 500);
  delay(waitTime);

  digitalWrite(blueLed, LOW);
  digitalWrite(redLed, HIGH);
  tone(buzzer, 1000);
  delay(waitTime);
}
