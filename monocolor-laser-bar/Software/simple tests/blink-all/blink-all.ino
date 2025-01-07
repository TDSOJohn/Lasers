const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;
const int Laser5 = 10;
const int Laser6 = 11;


void setup() {
  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);
  pinMode(Laser5, OUTPUT);
  pinMode(Laser6, OUTPUT);

  analogWrite(Laser1, 255);
  analogWrite(Laser2, 255);
  analogWrite(Laser3, 255);
  analogWrite(Laser4, 255);
  analogWrite(Laser5, 255);
  analogWrite(Laser6, 255);
}

int step = 0;

void loop() {
  analogWrite(Laser1, 255);
  analogWrite(Laser2, 255);
  analogWrite(Laser3, 255);
  analogWrite(Laser4, 255);
  analogWrite(Laser5, 255);
  analogWrite(Laser6, 255);

  delay(5000);

  analogWrite(Laser1, 0);
  analogWrite(Laser2, 0);
  analogWrite(Laser3, 0);
  analogWrite(Laser4, 0);
  analogWrite(Laser5, 0);
  analogWrite(Laser6, 0);

  delay(5000);
}
