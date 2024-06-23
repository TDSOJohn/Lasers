// D6 is DMX in

#include <DMXSerial.h>

const int RedPin = 5;
const int GreenPin = 4;
const int BluePin = 3;

const int startChannel = 1;

#define RedDefaultLevel 100
#define GreenDefaultLevel 200
#define BlueDefaultLevel 255


void setup() {
  DMXSerial.init(DMXReceiver);

  DMXSerial.write(1, 120);
  DMXSerial.write(2, 0);
  DMXSerial.write(3, 0);

  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
}

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();

  if(lastPacket < 50000) {
    if(DMXSerial.read(startChannel) > 100)
      digitalWrite(RedPin, HIGH);
    else
      digitalWrite(RedPin, LOW);
    if(DMXSerial.read(startChannel + 1) > 100)
      digitalWrite(GreenPin, HIGH);
    else
      digitalWrite(GreenPin, LOW);
    if(DMXSerial.read(startChannel + 2) > 100)
      digitalWrite(BluePin, HIGH);
    else
      digitalWrite(BluePin, LOW);
  } else {
    digitalWrite(RedPin, HIGH);
    digitalWrite(GreenPin, LOW);
    digitalWrite(BluePin, LOW);
  }
}
