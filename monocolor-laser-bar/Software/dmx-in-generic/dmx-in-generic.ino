
#include <DMXSerial.h>
#include "data.h"

//  [dip switch pins 3..6]
int bar_id = 0;

int num_of_lasers = 4;

int startChannel = 1;

const int laserOut[6] = {3, 5, 6, 9, 10, 11};
int funModeVal[6] = {0, 0, 0, 0, 0, 0};

const int primes[6] = {1, 2, 3, 5, 7, 11};

const int defaultLevel = 255;

byte speed = 20;

//  [dip switch pin 1]
//  0 for DMX MODE ( all lasers on if no dmx is received for 10s )
//  1 for FUN MODE
byte mode = 0;

//  [dip switch pin 2]
byte pattern = 0;


void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);

  for(int i = 0; i < num_of_lasers; i++) {
    pinMode(laserOut[i], OUTPUT);
    delay(10);
    analogWrite(laserOut[i], defaultLevel);
  }

  for(int i = A0; i <= A5; i++)
    pinMode(i, INPUT_PULLUP);
  delay(50);
  
  bar_id = !digitalRead(A2);
  delay(50);
  bar_id += (!digitalRead(A3) * 2);
  delay(50);
  bar_id += (!digitalRead(A4) * 4);
  delay(50);
  bar_id += (!digitalRead(A5) * 8);
  delay(50);

  pattern = !digitalRead(A1);
  delay(50);
  mode = !digitalRead(A0);
  delay(50);

  startChannel = bar_id * num_of_lasers + startChannel;

  for(int i = 0; i < num_of_lasers; i++)
    DMXSerial.write(startChannel + i, defaultLevel);
}


void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 0 && lastPacket < 10000) {
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], DMXSerial.read(startChannel + i));
  } else if(mode == 0 && lastPacket >= 10000) {
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], defaultLevel);
    delay(100);
  } else if(mode == 1 && pattern == 0) {
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], rand() % 256);
    delay(250);
  } else {
    for(int i = 0; i < num_of_lasers; i++) {
      analogWrite(laserOut[i], funModeVal[i]);
      funModeVal[i] += primes[i];
      if(funModeVal[i] > 255)
        funModeVal[i] -= 255;
    }
    delay(25);
  }
}
