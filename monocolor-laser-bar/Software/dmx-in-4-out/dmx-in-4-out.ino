
#include <DMXSerial.h>

#include "data.h"

#define DefaultLevel 255

int bar_id = 0;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;

int startChannel = 0;

byte speed = 20;

// 0 for ALL ON
// 1 for FUN MODE
// 2 for DMX MODE
byte mode = 2;

void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(1, DefaultLevel);
  DMXSerial.write(2, DefaultLevel);
  DMXSerial.write(3, DefaultLevel);
  DMXSerial.write(4, DefaultLevel);

  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);

  analogWrite(Laser1, DefaultLevel);
  analogWrite(Laser2, DefaultLevel);
  analogWrite(Laser3, DefaultLevel);
  analogWrite(Laser4, DefaultLevel);

  
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
/*
  int state_pin_0 = digitalRead(MODE_PINS[0]);
  int state_pin_1 = digitalRead(MODE_PINS[1]);

  if((state_pin_0 == HIGH) && (state_pin_1 == HIGH))
    mode = 0;
  else if((state_pin_0 == HIGH) && (state_pin_1 == LOW))
    mode = 1;
  else if((state_pin_0 == LOW) && (state_pin_1 == HIGH))
    mode = 2;
*/
  startChannel = bar_id * 4 + 1;
}

int step = 0;

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 2 && lastPacket < 10000) {
    analogWrite(Laser1, DMXSerial.read(startChannel));
    analogWrite(Laser2, DMXSerial.read(startChannel + 1));
    analogWrite(Laser3, DMXSerial.read(startChannel + 2));
    analogWrite(Laser4, DMXSerial.read(startChannel + 3));
  } else if(mode == 1) {
    analogWrite(Laser1, data[step][0]);
    analogWrite(Laser2, data[step][1]);
    analogWrite(Laser3, data[step][2]);
    analogWrite(Laser4, data[step][3]);
    
    step = rand() % 16;
    
    delay(1000 / speed);
  } else {
      analogWrite(Laser1, DefaultLevel);
      analogWrite(Laser2, DefaultLevel);
      analogWrite(Laser3, DefaultLevel);
      analogWrite(Laser4, DefaultLevel);
      delay(100);
  }
}
