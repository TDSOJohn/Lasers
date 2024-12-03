#include <DMXSerial.h>

#include "data.h"


// ===============================================================================
//    0    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |
//         .         .         .         .         .         .         .         .
//    0:   .    0:   .         .         .         .         .         .         .
// FUN MODE+-STATIC-----PTRN------PTRN------PTRN------PTRN------PTRN------PTRN   .
//         |         .         .         .         .         .         .         .
//         |    1:   .    0:   .         .         .         .         .         .
//         +--ANIM---+---SEQ------SPEED-----SPEED-----SPEED-----PTRN------PTRN   .
//         .         |         .         .         .         .         .         .
//         .         |    1:   .         .         .         .         .         .
//         .         +--RANDOM----SPEED-----SPEED-----SPEED-----PTRN------PTRN   .
//         .         .         .         .         .         .         .         .
//    1:   .         .         .         .         .         .         .         .
// DMX MODE--CH SEL----CH SEL----CH SEL----CH SEL----CH SEL----CH SEL----CH SEL  .
//         .         .         .         .         .         .         .         .
//         .         .         .         .         .         .         .         .
// ===============================================================================

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;


struct Settings {
  //  0: static, 1: DMX, 2: anim
  byte mode;

  //  0: sequential, 1: random
  byte anim_type;
  int speed;
  byte pattern;
  byte curr_pattern;

  byte dmx_start_channel;
};

Settings settings;

void setup() {
  // initialize dmx serial as receiver
  DMXSerial.init(DMXReceiver);
  
  DMXSerial.write(1, 255);
  DMXSerial.write(2, 255);
  DMXSerial.write(3, 255);
  DMXSerial.write(4, 255);

  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);

  analogWrite(Laser1, 255);
  analogWrite(Laser2, 255);
  analogWrite(Laser3, 255);
  analogWrite(Laser4, 255);

  for(int i = A0; i < A7; i++)
    pinMode(i, INPUT_PULLUP);

  settings.mode = !digitalRead(A0);
  delay(30);
  // fun mode
  if(settings.mode == 0) {
    // anim mode
    if(!digitalRead(A1)) {
      settings.mode = 2;
      settings.anim_type = !digitalRead(A2);
      settings.speed = !digitalRead(A3);
      delay(30);
      settings.speed += (!digitalRead(A4) * 2);
      delay(30);
      settings.speed += (!digitalRead(A5) * 4);
      delay(30);
      settings.pattern = !digitalRead(A6);
      delay(30);
      settings.pattern += (!digitalRead(A7) * 2);
      delay(30);
      settings.curr_pattern = settings.pattern;
    }
    // static mode
    else {
      settings.pattern = !digitalRead(A2);
      delay(30);
      settings.pattern += (!digitalRead(A3) * 2);
      delay(30);
      settings.pattern += (!digitalRead(A4) * 4);
      delay(30);
      settings.pattern += (!digitalRead(A5) * 8);
      delay(30);
      settings.pattern += (!digitalRead(A6) * 16);
      delay(30);
      settings.pattern += (!digitalRead(A7) * 32);
      delay(30);
    }
  }
  //  DMX mode
  else {
    settings.dmx_start_channel = !digitalRead(A1);
    delay(30);
    settings.dmx_start_channel += (!digitalRead(A2) * 2);
    delay(30);
    settings.dmx_start_channel += (!digitalRead(A3) * 4);
    delay(30);
    settings.dmx_start_channel += (!digitalRead(A4) * 8);
    delay(30);
    settings.dmx_start_channel += (!digitalRead(A5) * 16);
    delay(30);
    settings.dmx_start_channel += (!digitalRead(A6) * 32);
    delay(30);
    settings.dmx_start_channel += (!digitalRead(A7) * 64);
    delay(30);
  }

  switch(settings.speed) {
    case 0:
      settings.speed = 1;
      break;
    case 1:
      settings.speed = 2;
      break;
    case 2:
      settings.speed = 5;
      break;
    case 3:
      settings.speed = 10;
      break;
    case 4:
      settings.speed = 25;
      break;
    case 5:
      settings.speed = 50;
      break;
    case 6:
      settings.speed = 100;
      break;
    case 7:
      settings.speed = 250;
      break;
    case 8:
      settings.speed = 500;
      break;
    default:
      settings.speed = 1;
      break;
  }
}

int step = 0;

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();
  //  DMX mode and receiving
  if(settings.mode == 1 && lastPacket < 10000) {
    analogWrite(Laser1, DMXSerial.read(settings.dmx_start_channel));
    analogWrite(Laser2, DMXSerial.read(settings.dmx_start_channel + 1));
    analogWrite(Laser3, DMXSerial.read(settings.dmx_start_channel + 2));
    analogWrite(Laser4, DMXSerial.read(settings.dmx_start_channel + 3));
  }
  //  Fun mode
  else if(settings.mode == 2) {
    analogWrite(Laser1, data[settings.curr_pattern][step][0]);
    analogWrite(Laser2, data[settings.curr_pattern][step][1]);
    analogWrite(Laser3, data[settings.curr_pattern][step][2]);
    analogWrite(Laser4, data[settings.curr_pattern][step][3]);

    //  Sequential type
    if(settings.anim_type == 0) {
      step = (step + 1) % 16;
      if(step == 15)
        settings.curr_pattern = (settings.curr_pattern + 1) % 4;
    }
    //  Random type
    else {
      step = rand() % 16;
    }
    delay(10000 / settings.speed);
  }
  //  Static mode
  else {
      analogWrite(Laser1, 255);
      analogWrite(Laser2, 255);
      analogWrite(Laser3, 255);
      analogWrite(Laser4, 255);
      delay(100);
  }
}
