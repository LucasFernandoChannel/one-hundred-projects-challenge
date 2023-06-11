// Project #14 - Control LEDs with a potentiometer
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#define potValue A5

int ledsState[11][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void setup() {
  for (int i = 2; i < 12; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  int value = analogRead(potValue);
  int option = 0;

  if (value <= 80) {    
    option = 10;
  } else if (value > 80 && value <= 180) {
    option = 9;
  } else if (value > 180 && value <= 280) {
    option = 8;
  } else if (value > 280 && value <= 380) {
    option = 7;
  } else if (value > 380 && value <= 480) {
    option = 6;
  } else if (value > 480 && value <= 580) {
    option = 5;
  } else if (value > 580 && value <= 680) {
    option = 4;
  } else if (value > 680 && value <= 780) {
    option = 3;
  } else if (value > 780 && value <= 880) {
    option = 2;
  } else if (value > 880 && value <= 980) {
    option = 1;
  } else if (value > 980) {
    option = 0;
  }
  for (int n = 0; n < 10; n++) {
    digitalWrite(n + 2, ledsState[option][n]);
  }
}
