// Project #21 - Colorful lights blinking
// This code is part of the challenge 100 Arduino and ESP32 projects.
// You can find more information about this initiative at https://github.com/LucasFernandoChannel/one-hundred-projects-challenge
// Created by Lucas Fernando - check my Youtube channel at https://www.youtube.com/@lucasfernandochannel

int lightsOne[11][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 0}, {1, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0},
                        {1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 1, 0}, {0, 0, 1, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

int lightsTwo[4][8] = {{1, 1, 1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 1, 1, 1}};

int lightsThree[38][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1},
                          {1, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1},
                          {1, 0, 0, 0, 0, 0, 1, 1}, {0, 1, 0, 0, 0, 0, 1, 1}, {0, 0, 1, 0, 0, 0, 1, 1}, {0, 0, 0, 1, 0, 0, 1, 1}, {0, 0, 0, 0, 1, 0, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 1},
                          {1, 0, 0, 0, 0, 1, 1, 1}, {0, 1, 0, 0, 0, 1, 1, 1}, {0, 0, 1, 0, 0, 1, 1, 1}, {0, 0, 0, 1, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1},
                          {1, 0, 0, 0, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 1, 1, 1}, {0, 0, 1, 0, 1, 1, 1, 1}, {0, 0, 0, 1, 1, 1, 1, 1},
                          {1, 0, 0, 1, 1, 1, 1, 1}, {0, 1, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1},
                          {1, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 0, 0, 0, 0, 0}};

int lightsFour[10][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0},
                         {1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

int lightsFive[10][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 1}, {0, 0, 0, 0, 1, 1, 1, 1},
                         {0, 0, 0, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 1, 1, 1, 1}, {0, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}};
void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  int i;
  int j;
  // First effect
  for(i = 0; i < 11; i++) {
    for(j = 0; j < 8; j++) {
      digitalWrite(j + 2, lightsOne[i][j]);
    }
    delay(100);
  }
  // Second effect
  for(int k = 0; k < 4; k++) {
    for(i = 0; i < 4; i++) {
      for(j = 0; j < 8; j++) {
        digitalWrite(j + 2, lightsTwo[i][j]);
      }
      delay(100);
    }
  }
  // Third effect
  for(i = 0; i < 38; i++) {
    for(j = 0; j < 8; j++) {
      digitalWrite(j + 2, lightsThree[i][j]);      
      delay(10);
    }    
  }
  // Forth effect
  for(i = 0; i < 10; i++) {
    for(j = 0; j < 8; j++) {
      digitalWrite(j + 2, lightsFour[i][j]);
    }
    delay(250);
  }
  // Fifth effect
  for(i = 0; i < 10; i++) {
    for(j = 0; j < 8; j++) {
      digitalWrite(j + 2, lightsFive[i][j]);
    }
    delay(200);        
  }
}
