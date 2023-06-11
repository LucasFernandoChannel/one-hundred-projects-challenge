// Project #15 - Fading lights
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

#define waitTime 5
int leds[4] = {3, 5, 6, 9};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
} 

void loop() {
  for (int m = 0; m < 4; m++) {
    for (int n = 0; n < 256; n++) {
      analogWrite(leds[m], n);
      delay(waitTime);
    }
    digitalWrite(leds[m], LOW);
  }  
}
