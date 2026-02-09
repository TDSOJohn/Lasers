
#include <DMXSerial.h>

#define DefaultLevel 0

const int out_pin = 9;

int startChannel = 18;

// 0 for ALWAYS ON
// 1 for DMX MODE
byte mode = 1;

void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(startChannel, DefaultLevel);

  pinMode(out_pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(out_pin, LOW);
  // used for debugging porpuses rn
}

int step = 0;

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(mode == 1 && lastPacket < 10000) {
    byte value_in = DMXSerial.read(startChannel);
    if(value_in >= 128) {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(out_pin, 255);
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(out_pin, 0);
      delay(300);
    }
  }
  else {
      digitalWrite(out_pin, LOW);
      delay(250);
  }
}
