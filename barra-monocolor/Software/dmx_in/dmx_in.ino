
#include <DMXSerial.h>

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;

const int startChannel = 1;

#define L1DefaultLevel 255
#define L2DefaultLevel 0
#define L3DefaultLevel 0
#define L4DefaultLevel 0


void setup() {
  // initialize dmx serial as receiver and set max channel to 4
  DMXSerial.init(DMXReceiver);
  DMXSerial.maxChannel(4);
  
  DMXSerial.write(1, L1DefaultLevel);
  DMXSerial.write(2, L2DefaultLevel);
  DMXSerial.write(3, L3DefaultLevel);
  DMXSerial.write(4, L4DefaultLevel);

  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);

  analogWrite(Laser1, 255);
  analogWrite(Laser2, 0);
  analogWrite(Laser3, 0);
  analogWrite(Laser4, 0);
}

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(lastPacket < 60000) {
    analogWrite(Laser1, DMXSerial.read(startChannel));
    analogWrite(Laser2, DMXSerial.read(startChannel + 1));
    analogWrite(Laser3, DMXSerial.read(startChannel + 2));
    analogWrite(Laser4, DMXSerial.read(startChannel + 3));
  } else {
    analogWrite(Laser1, L1DefaultLevel);
    analogWrite(Laser2, L2DefaultLevel);
    analogWrite(Laser3, L3DefaultLevel);
    analogWrite(Laser4, L4DefaultLevel);
  }
}
