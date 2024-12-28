
#include <DMXSerial.h>

#include "data.h"

int bar_id = 0;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;
const int Laser5 = 10;
const int Laser6 = 11;

int startChannel = 0;

#define DefaultLevel 255

byte speed = 20;

// 0 for ALL ON
// 1 for DMX MODE
byte mode = 1;

void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(1, DefaultLevel);
  DMXSerial.write(2, DefaultLevel);
  DMXSerial.write(3, DefaultLevel);
  DMXSerial.write(4, DefaultLevel);
  DMXSerial.write(5, DefaultLevel);
  DMXSerial.write(6, DefaultLevel);

  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);
  pinMode(Laser5, OUTPUT);
  pinMode(Laser6, OUTPUT);

  analogWrite(Laser1, DefaultLevel);
  analogWrite(Laser2, DefaultLevel);
  analogWrite(Laser3, DefaultLevel);
  analogWrite(Laser4, DefaultLevel);
  analogWrite(Laser5, DefaultLevel);
  analogWrite(Laser6, DefaultLevel);

  
  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  delay(50);
  bar_id = !digitalRead(A0);
  delay(50);
  bar_id += (!digitalRead(A1) * 2);
  delay(50);
  bar_id += (!digitalRead(A2) * 4);
  delay(50);
  bar_id += (!digitalRead(A3) * 8);

  startChannel = bar_id * 6 + 1;
}

int step = 0;

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 1 && lastPacket < 10000) {
    analogWrite(Laser1, DMXSerial.read(startChannel));
    analogWrite(Laser2, DMXSerial.read(startChannel + 1));
    analogWrite(Laser3, DMXSerial.read(startChannel + 2));
    analogWrite(Laser4, DMXSerial.read(startChannel + 3));
    analogWrite(Laser5, DMXSerial.read(startChannel + 4));
    analogWrite(Laser6, DMXSerial.read(startChannel + 5));
  } else {
      analogWrite(Laser1, DefaultLevel);
      analogWrite(Laser2, DefaultLevel);
      analogWrite(Laser3, DefaultLevel);
      analogWrite(Laser4, DefaultLevel);
      analogWrite(Laser5, DefaultLevel);
      analogWrite(Laser6, DefaultLevel);
      delay(100);
  }
}
