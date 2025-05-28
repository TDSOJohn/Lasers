
#include <DMXSerial.h>
#include "data.h"


int num_of_lasers = 6;

// set using DIP switches on the pcb
int start_channel = 1;

const int laserOut[6] = {3, 5, 6, 9, 10, 11};
int funModeVal[6] = {0, 0, 0, 0, 0, 0};

const int primes[6] = {1, 2, 3, 5, 7, 11};

const int defaultLevel = 0;

byte speed = 20;

// 0 = DMX
// 1 = FUN
// 2 = ALL ON
// DIP switch all 1 (value 255): fun mode
byte mode = 0;


void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);

  for(int i = 0; i < num_of_lasers; i++) {
    pinMode(laserOut[i], OUTPUT);
    delay(200);
    analogWrite(laserOut[i], 255);
  }

  for(int i = A0; i <= A5; i++)
    pinMode(i, INPUT_PULLUP);
  delay(50);
  
  start_channel = !digitalRead(A0);
  delay(50);
  start_channel += (!digitalRead(A1) * 2);
  delay(50);
  start_channel += (!digitalRead(A2) * 4);
  delay(50);
  start_channel += (!digitalRead(A3) * 8);
  delay(50);
  start_channel += (!digitalRead(A4) * 16);
  delay(50);
  start_channel += (!digitalRead(A5) * 32);
  delay(50);

  if(start_channel == 0)
    mode = 2;
  else if(start_channel == 63)
    mode = 1;

  for(int i = 0; i < num_of_lasers; i++)
    DMXSerial.write(start_channel + i, defaultLevel);
}


void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  // DMX mode and last packet < 10s
  if(mode == 0 && lastPacket < 10000) {
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], DMXSerial.read(start_channel + i));
  } else if(mode == 0 && lastPacket >= 10000) {
  // DMX mode and last packet > 10s
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], defaultLevel);
    delay(100);
  } else if(mode == 1) {
  // FUN mode
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], rand() % 256);
    delay(250);
  } else {
  // ALL ON mode
    for(int i = 0; i < num_of_lasers; i++)
      analogWrite(laserOut[i], 255);
    delay(25);
  }
}
