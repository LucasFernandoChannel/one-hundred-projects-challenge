// Project #17 - Sound sensor
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

const int blueLed = 7;
const int microphone = 8;
int ledState = 0;


void setup() {
  pinMode(microphone, INPUT);
  pinMode(blueLed, OUTPUT);
  digitalWrite(blueLed, ledState);
}

void loop() {
  int value = digitalRead(microphone);
  if (value == 1) {
    if (ledState == 0) {
      ledState = 1;
    } else {
      ledState = 0;
    }
  }
  digitalWrite(blueLed, ledState);
}