
#include <DMXSerial.h>

#include "data.h"

const int bar_id = 0;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;

const int startChannel = bar_id * 4 + 1;

#define L1DefaultLevel 255
#define L2DefaultLevel 255
#define L3DefaultLevel 255
#define L4DefaultLevel 255

#define DIP_SWITCH_SIZE 8;

byte speed = 20;

const int SWITCH_PINS[] = {A0, A1, A2, A3, A4, A5, A6, A7};

// 0 for ALL ON
// 1 for FUN MODE
// 2 for DMX MODE
byte mode = 2;

void changeMode() {
  mode = (mode + 1) % 3;
}
void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(1, L1DefaultLevel);
  DMXSerial.write(2, L2DefaultLevel);
  DMXSerial.write(3, L3DefaultLevel);
  DMXSerial.write(4, L4DefaultLevel);

  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);

  analogWrite(Laser1, L1DefaultLevel);
  analogWrite(Laser2, L2DefaultLevel);
  analogWrite(Laser3, L3DefaultLevel);
  analogWrite(Laser4, L4DefaultLevel);

  for(int i = 0; i < DIP_SWITCH_SIZE; i++)
    pinMode(SWITCH_PINS[i], INPUT_PULLUP);
    delay(50);
  
  int dip_switch_state = 0;
  for(int i = 0; i < DIP_SWITCH_SIZE; i++) {
    int state = digitalRead(SWITCH_PINS[i]);

    if(state == LOW)
      dip_switch_state |= 1 << (DIP_SWITCH_SIZE - i - 1);
  }

  startChannel = dip_switch_state;
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
      analogWrite(Laser1, L1DefaultLevel);
      analogWrite(Laser2, L2DefaultLevel);
      analogWrite(Laser3, L3DefaultLevel);
      analogWrite(Laser4, L4DefaultLevel);
      delay(100);
  }
}
