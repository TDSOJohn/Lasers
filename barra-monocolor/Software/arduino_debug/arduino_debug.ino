
#include <DMXSerial.h>

const int Laser1 = 3;
const int Laser2 = 5;
const int Laser3 = 6;
const int Laser4 = 9;


void setup() {
  analogWrite(Laser1, 0);
  analogWrite(Laser2, 0);
  analogWrite(Laser3, 0);
  analogWrite(Laser4, 0);
}


int modulo(int n, int mod) {
  if (n >= 0)
    return (n % mod);
  else
    return ((n + mod) % mod);
}

int counter = 0;

void loop() {
  
  analogWrite(Laser1, counter);
  analogWrite(Laser2, modulo(63 - counter, 255));
  analogWrite(Laser3, modulo(counter - 127, 255));
  analogWrite(Laser4, modulo(191 - counter, 255));
  
/*
  analogWrite(Laser1, 255);
  analogWrite(Laser2, 255);
  analogWrite(Laser3, 255);
  analogWrite(Laser4, 255);
*/
  
  counter += 1;
  if (counter > 255) {
    counter = 0;
  }
  delay(30);
}
