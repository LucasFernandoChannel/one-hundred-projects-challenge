// Project #5 - Control LEDs with push-ups buttons
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

int redLed = 2;
int blueLed = 3;
int greenLed = 4;
int yellowLed = 5;

int redButton = 6;
int blueButton = 7;
int greenButton = 8;
int yellowButton = 9;

int ledsState[4] = {0, 0, 0, 0};

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);

  pinMode(redButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(yellowButton, INPUT_PULLUP);

  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
}

void loop() {
  int redValue = digitalRead(redButton);
  int blueValue = digitalRead(blueButton);
  int greenValue = digitalRead(greenButton);
  int yellowValue = digitalRead(yellowButton);

  if (redValue == 0) {
    if (ledsState[0] == 0) {
      ledsState[0] = 1;
    } else {
      ledsState[0] = 0;
    }
  }

  if (blueValue == 0) {
    if (ledsState[1] == 0) {
      ledsState[1] = 1;
    } else {
      ledsState[1] = 0;
    }
  }

  if (greenValue == 0) {
    if (ledsState[2] == 0) {
      ledsState[2] = 1;
    } else {
      ledsState[2] = 0;
    }
  }      

  if (yellowValue == 0) {
    if (ledsState[3] == 0) {
      ledsState[3] = 1;
    } else {
      ledsState[3] = 0;
    }
  }

  digitalWrite(redLed, ledsState[0]);
  digitalWrite(blueLed, ledsState[1]);
  digitalWrite(greenLed, ledsState[2]);
  digitalWrite(yellowLed, ledsState[3]);
}
