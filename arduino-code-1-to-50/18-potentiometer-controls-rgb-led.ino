// Project #18 - Potentiometer controls RGB LED
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

const int potentiometer = A0;
const int redPin = 2;
const int greenPin = 3;
const int bluePin = 4;
const int ledsState[4][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
}

void loop() {
  int value = analogRead(potentiometer);  
  int state;
  if (value <= 250) {
    state = 3;
  } else if (value > 250 && value <= 500) {
    state = 2;
  } else if (value > 500 && value <= 750) {
    state = 1;
  } else {
    state = 0;
  }

  for (int i = 0; i < 3; i++) {
    digitalWrite(i + 2, ledsState[state][i]);
  }
}
