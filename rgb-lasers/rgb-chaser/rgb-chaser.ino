
#include "data.h"


int num_of_lasers = 3;

const int laserOut[3] = {3, 5, 6};
int funModeVal[6] = {0, 0, 0, 0, 0, 0};

const int primes[6] = {1, 2, 3, 5, 7, 11};

const int defaultLevel = 0;

// in milliseconds
byte period = 20;

// 0 = DMX
// 1 = FUN
// 2 = ALL ON
// DIP switch all 1 (value 255): fun mode
byte mode = 0;

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

Color White = {0, 0, 0};
Color Black = {255, 255, 255};
Color Red = {255, 0, 0};
Color Green = {0, 255, 0};
Color Blue = {0, 0, 255};


void colorOut(Color &c_in) {
  analogWrite(laserOut[0], c_in.r);
  delay(10);
  analogWrite(laserOut[1], c_in.g);
  delay(10);
  analogWrite(laserOut[2], c_in.b);
  delay(10);
}

void colorOut(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(laserOut[0], r);
  delay(10);
  analogWrite(laserOut[1], g);
  delay(10);
  analogWrite(laserOut[2], b);
  delay(10);
}

void setup() {
  for(int i = 0; i < num_of_lasers; i++) {
    pinMode(laserOut[i], OUTPUT);
    delay(200);
  }

  colorOut(Black);

  for(int i = A0; i <= A5; i++)
    pinMode(i, INPUT_PULLUP);
  delay(50);
  
  if(!digitalRead(A0))
    mode = 0;
  else if(!digitalRead(A1))
    mode = 1;
  else if(!digitalRead(A2))
    mode = 2;
  else if(!digitalRead(A3))
    mode = 3;
  else if(!digitalRead(A4))
    mode = 4;
  else if(!digitalRead(A5))
    mode = 5;
  delay(50);

  randomSeed(analogRead(0));
}

Color current_color = {0, 0, 0};
int step = 0;

void loop() {
  if(mode == 0) {
    for(int i = 0; i < 256; i++) {
      colorOut(i, 255 - i, 255 - i);
      delay(period / 2);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(255 - i, i, 255 - i);
      delay(period / 2);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(255 - i, 255 - i, i);
      delay(period / 2);
    }
  }

  if(mode == 1) {
    for(int i = 0; i < 256; i++) {
      colorOut(255 - i, 255 - i, 255 - i);
      delay(period);
    }
  }

  if(mode == 2) {
    for(int i = 0; i < 256; i++) {
      colorOut(255, random(255), random(255));
      delay(period * 10);
    }
  }

  if(mode == 3) {
    for(int i = 0; i < 256; i++) {
      colorOut(random(255), 255, random(255));
      delay(period * 10);
    }
  }

  if(mode == 4) {
    for(int i = 0; i < 256; i++) {
      colorOut(random(255), random(255), 255);
      delay(period * 10);
    }
  }

  if(mode == 5) {
    for(int i = 0; i < 256; i++) {
      colorOut(i, 255 - i, 255 - i);
      delay(period / 2);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(255 - i, i, 255 - i);
      delay(period / 2);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(255 - i, 255 - i, i);
      delay(period / 2);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(255 - i, 255 - i, 255 - i);
      delay(period);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(255, random(255), random(255));
      delay(period * 10);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(random(255), 255, random(255));
      delay(period * 10);
    }
    for(int i = 0; i < 256; i++) {
      colorOut(random(255), random(255), 255);
      delay(period * 10);
    }
  }
}
