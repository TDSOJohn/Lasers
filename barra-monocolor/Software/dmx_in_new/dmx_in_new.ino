#include "DmxReceiver.h"

const byte pinDmx = 0;
const byte channels = 4;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;

DmxReceiver dmx(pinDmx, channels);


void setup() {
  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);
}

void loop() {
  if (dmx.poll()) {
    analogWrite(Laser1, dmx.getValue(0));
    analogWrite(Laser2, dmx.getValue(1));
    analogWrite(Laser3, dmx.getValue(2));
    analogWrite(Laser4, dmx.getValue(3));
  }
}
