// Project #16 - Stepper motor
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#include <Stepper.h>
const int stepsPerRevolution = 2038;
const int speed = 15;
const int waitTime = 500;
Stepper stepperMotor(stepsPerRevolution, 2, 4, 3, 5);

void setup() {
  stepperMotor.setSpeed(speed);
}

void loop() {
  stepperMotor.step(stepsPerRevolution);
  delay(waitTime);
  
  stepperMotor.step(-stepsPerRevolution);
  delay(waitTime);
}