// Project #6 - Control RGB LED with joystick
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

int redPin = 2;
int greenPin = 3;
int bluePin = 4;
int x = A0;
int y = A1;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

  Serial.begin(9600);
}

void loop() {
  long xValue = 0;
  long yValue = 0;

  for(int i = 0; i < 100; i++) {
    xValue += analogRead(x);
    yValue += analogRead(y);
  }

  xValue = xValue / 100;
  yValue = yValue / 100;

  // Use these values to adjust the thresholds
  Serial.print("X: ");
  Serial.println(xValue);
  Serial.print("Y: ");
  Serial.println(yValue);

  if (xValue > 600) {
    digitalWrite(redPin, HIGH);
  }  else {
    digitalWrite(redPin, LOW);
  }

  if (yValue >= 0 && yValue <= 400) {
    digitalWrite(greenPin, HIGH);
  } else if (yValue > 400 && yValue <= 600) {
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else {
    digitalWrite(bluePin, HIGH);
  }
}
