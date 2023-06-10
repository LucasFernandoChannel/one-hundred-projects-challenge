// Project #4 - Servo
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(2);
  myServo.write(0);
}

void loop() {
  for(int i = 0; i <= 180; i++) {
    myServo.write(i);
    delay(2);
  }

  for(int n = 180; n >= 0; n = n - 1) {
    myServo.write(n);
    delay(2);
  }
}
