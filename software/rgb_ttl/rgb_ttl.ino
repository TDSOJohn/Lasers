// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

int timer = 10000;
int counter = 0;

// the loop function runs over and over again forever
void loop() {
  counter++;
  if(counter > 3) {
    timer = timer - 100;
    if(timer <= 0)
      timer = 10000;
    counter = 0;
  }
  digitalWrite(5, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(4, HIGH);  // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(timer);                      // wait for a second
  digitalWrite(5, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(4, LOW);   // turn the LED off by making the voltage LOW
  delayMicroseconds(10000 - timer);                      // wait for a second
}
