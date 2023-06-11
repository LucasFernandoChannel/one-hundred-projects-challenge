// Project #13 - Party lights
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

int ledsState[8][10] = {{0, 0, 0, 0, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                     {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}};
#define waitTime 100

void setup() {
  for (int i = 2; i < 12; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  for (int m = 0; m < 8; m++) {
    for (int n = 0; n < 10; n++) {
      digitalWrite(n + 2, ledsState[m][n]);
    }
    delay(waitTime);
  }
}
