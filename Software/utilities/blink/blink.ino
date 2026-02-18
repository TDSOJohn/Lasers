int num_of_lasers = 4;
const int laserOut[6] = {3, 5, 6, 9, 10, 11};


void setup() {
  for(int i = 0; i < num_of_lasers; i++) {
    pinMode(laserOut[i], OUTPUT);
    delay(200);
    analogWrite(laserOut[i], 255);
  }
}

int step = 0;

void loop() {
  for(int i = 0; i < num_of_lasers; i++) {
    analogWrite(laserOut[i], 255);
  }

  delay(500);

  for(int i = 0; i < num_of_lasers; i++) {
    analogWrite(laserOut[i], 0);
  }

  delay(500);
}
