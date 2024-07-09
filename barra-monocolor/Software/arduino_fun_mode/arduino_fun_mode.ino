
#include <DMXSerial.h>

#include "data.h"

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;

int speed = 10;

void setup() {
  analogWrite(Laser1, 0);
  analogWrite(Laser2, 0);
  analogWrite(Laser3, 0);
  analogWrite(Laser4, 0);

  randomSeed(analogRead(0));
}

void move_to(int step1, int step2) {
  int vals[4] = {data[step1][0], data[step1][1], data[step1][2], data[step1][3]};
  
  while(vals[0] != data[step2][0] ||
        vals[1] != data[step2][1] ||
        vals[2] != data[step2][2] ||
        vals[3] != data[step2][3]) {
    analogWrite(Laser1, vals[0]);
    analogWrite(Laser2, vals[1]);
    analogWrite(Laser3, vals[2]);
    analogWrite(Laser4, vals[3]);

    if (vals[0] > data[step2][0])
      vals[0] -= (vals[0] - data[step2][0]) / 2;
    else if (vals[0] < data[step2][0])
      vals[0] += (data[step2][0] - vals[0]) / 2;
    if (vals[1] > data[step2][1])
      vals[1] -= (vals[1] - data[step2][1]) / 2;
    else if (vals[1] < data[step2][1])
      vals[1] += (data[step2][1] - vals[1]) / 2;
    if (vals[2] > data[step2][2])
      vals[2] -= (vals[2] - data[step2][2]) / 2;
    else if (vals[2] < data[step2][2])
      vals[2] += (data[step2][2] - vals[2]) / 2;
    if (vals[3] > data[step2][3])
      vals[3] -= (vals[3] - data[step2][3]) / 2;
    else if (vals[3] < data[step2][3])
      vals[3] += (data[step2][3] - vals[3]) / 2;
    delay(300 / speed);
  }
}

int step = 0;

void loop() {
  analogWrite(Laser1, data[step][0]);
  analogWrite(Laser2, data[step][1]);
  analogWrite(Laser3, data[step][2]);
  analogWrite(Laser4, data[step][3]);
  
  step = rand() % 16;
  
  delay(1000 / speed);
}
