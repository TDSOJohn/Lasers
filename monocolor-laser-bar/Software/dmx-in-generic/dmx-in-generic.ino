
#include <DMXSerial.h>
#include "data.h"

//  [dip switch pins 1..4]
int bar_id = 0;

int num_of_lasers = 4;

int startChannel = 0;

const int laserOut[6] = {3, 5, 6, 9, 10, 11};

const int defaultLevel = 255;

byte speed = 20;

//  [dip switch pin 8]
//  0 for DMX MODE ( all lasers on if no dmx is received for 10s )
//  1 for FUN MODE
byte mode = 0;

void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);

  for(int i = 0; i < num_of_lasers; i++) {
    pinMode(laserOut[i], OUTPUT);
    delay(10);
    analogWrite(laserOut[i], defaultLevel);
  }

//  for(int i = A0; i <= A7; i++)
//    pinMode(i, INPUT_PULLUP);  
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

  mode = !digitalRead(A7);

  startChannel = bar_id * num_of_lasers + 1;

  for(int i = 0; i < num_of_lasers; i++)
    DMXSerial.write(startChannel + i, defaultLevel);
}

int step = 0;

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 0 && lastPacket < 10000) {
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], DMXSerial.read(startChannel + i));
  } else if(mode == 0 && lastPacket >= 10000) {
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], defaultLevel);
    delay(100);
  } else {
    // fun mode code
  }
}
