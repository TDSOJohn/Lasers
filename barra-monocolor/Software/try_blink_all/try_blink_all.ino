
const int bar_id = 0;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;

#define L1DefaultLevel 255
#define L2DefaultLevel 255
#define L3DefaultLevel 255
#define L4DefaultLevel 255


void setup() {
  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);

  analogWrite(Laser1, L1DefaultLevel);
  analogWrite(Laser2, L2DefaultLevel);
  analogWrite(Laser3, L3DefaultLevel);
  analogWrite(Laser4, L4DefaultLevel);
}

int step = 0;

void loop() {
  analogWrite(Laser1, L1DefaultLevel);
  analogWrite(Laser2, L2DefaultLevel);
  analogWrite(Laser3, L3DefaultLevel);
  analogWrite(Laser4, L4DefaultLevel);
  delay(500);
  analogWrite(Laser1, 0);
  analogWrite(Laser2, 0);
  analogWrite(Laser3, 0);
  analogWrite(Laser4, 0);
  delay(500);
}
