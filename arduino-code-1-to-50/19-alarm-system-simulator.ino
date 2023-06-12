// Project #19 - Alarm system simulator
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

const int speaker = 2;
const int blueLed = 3;
const int redLed = 4;
const int turnOn = 5;
const int turnOff = 6;
int siren[2][2] = {{1, 0}, {0, 1}};
int tones[2] = {494, 523};
int timeTones = 250;
int alarmOn = 0;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(turnOn, INPUT_PULLUP);
  pinMode(turnOff, INPUT_PULLUP);

  digitalWrite(redLed, LOW);
  digitalWrite(blueLed, LOW);
}

void loop() {
  int turnOnValue = digitalRead(turnOn);  
  if (turnOnValue == 0) {
    alarmOn = 1;
  }

  while(alarmOn == 1) {
    for(int i = 0; i < 2; i++) {
      digitalWrite(redLed, siren[i][0]);
      digitalWrite(blueLed, siren[i][1]);
      tone(speaker, tones[i]);
      delay(timeTones);
    }
    
    int turnOffValue = digitalRead(turnOff);
    if (turnOffValue == 0) {
      alarmOn = 0;
      digitalWrite(redLed, LOW);
      digitalWrite(blueLed, LOW);
      noTone(speaker);                
    }
  }
}
