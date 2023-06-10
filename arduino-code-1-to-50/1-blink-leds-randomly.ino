// Project #1 - Blink LEDs randomly
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

void setup() {
  for (int n = 2; n < 9; n++) {
    pinMode(n, OUTPUT);
    digitalWrite(n, LOW);
  }
}

void loop() {
  int value = random(2, 9); // Choose a digital port from 2 to 8
  for (int i = 2; i < 9; i++) {
    // The code turns on the LED connected to the chosen port and turn off all other LEDs    
    if(value == i) {
      digitalWrite(i, HIGH);      
    } else {
      digitalWrite(i, LOW);
    }
  }
  delay(250);
}
