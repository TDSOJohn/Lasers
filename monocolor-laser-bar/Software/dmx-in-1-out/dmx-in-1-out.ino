
#include <DMXSerial.h>

#define DefaultLevel 0

const int out_pin = 9;

int startChannel = 89;

// 0 for ALWAYS ON
// 1 for DMX MODE
byte mode = 1;

void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(1, DefaultLevel);

  pinMode(out_pin, OUTPUT);

  analogWrite(out_pin, DefaultLevel);
}

int step = 0;

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 1 && lastPacket < 10000) {
    byte value_in = DMXSerial.read(startChannel);
    if(value_in >= 128)
      analogWrite(out_pin, 255);
    else
      analogWrite(out_pin, 0);
  }
  else {
      analogWrite(out_pin, DefaultLevel);
      delay(1000);
  }
}
