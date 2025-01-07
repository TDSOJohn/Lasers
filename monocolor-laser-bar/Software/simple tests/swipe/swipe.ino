
const int bar_id = 0;

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;


void setup() {
  pinMode(Laser1, OUTPUT);
  pinMode(Laser2, OUTPUT);
  pinMode(Laser3, OUTPUT);
  pinMode(Laser4, OUTPUT);

  analogWrite(Laser1, 255);
  analogWrite(Laser2, 255);
  analogWrite(Laser3, 255);
  analogWrite(Laser4, 255);
}

int val = 0;

void loop() {
  analogWrite(Laser1, val);
  analogWrite(Laser2, val);
  analogWrite(Laser3, val);
  analogWrite(Laser4, val);
  delay(100);
  val++;
  if(val > 255)
    val = 0;
}
