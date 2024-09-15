#include <DMXSerial.h>


const int bar_id = 1;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;
const int Laser5 = 10;
const int Laser6 = 11;

#define L1DefaultLevel 255
#define L2DefaultLevel 255
#define L3DefaultLevel 255
#define L4DefaultLevel 255
#define L5DefaultLevel 255
#define L6DefaultLevel 255


void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(1, L1DefaultLevel);
  DMXSerial.write(2, L2DefaultLevel);
  DMXSerial.write(3, L3DefaultLevel);
  DMXSerial.write(4, L4DefaultLevel);
  DMXSerial.write(5, L5DefaultLevel);
  DMXSerial.write(6, L6DefaultLevel);

  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);
  pinMode(Laser5, OUTPUT);
  pinMode(Laser6, OUTPUT);

  analogWrite(Laser1, L1DefaultLevel);
  analogWrite(Laser2, L2DefaultLevel);
  analogWrite(Laser3, L3DefaultLevel);
  analogWrite(Laser4, L4DefaultLevel);
  analogWrite(Laser5, L5DefaultLevel);
  analogWrite(Laser6, L6DefaultLevel);

  randomSeed(analogRead(0));
}

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 2 && lastPacket < 10000) {
    analogWrite(Laser1, DMXSerial.read(startChannel));
    analogWrite(Laser2, DMXSerial.read(startChannel + 1));
    analogWrite(Laser3, DMXSerial.read(startChannel + 2));
    analogWrite(Laser4, DMXSerial.read(startChannel + 3));
    analogWrite(Laser5, DMXSerial.read(startChannel + 4));
    analogWrite(Laser6, DMXSerial.read(startChannel + 5));
  } else {
      analogWrite(Laser1, L1DefaultLevel);
      analogWrite(Laser2, L2DefaultLevel);
      analogWrite(Laser3, L3DefaultLevel);
      analogWrite(Laser4, L4DefaultLevel);    
      analogWrite(Laser5, L5DefaultLevel);    
      analogWrite(Laser6, L6DefaultLevel);    
  }
}
