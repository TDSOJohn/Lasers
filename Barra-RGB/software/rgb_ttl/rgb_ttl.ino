// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

int timer = 1500;
int counter = 0;

// the loop function runs over and over again forever
void loop() {
  timer = timer - 10;
  if(timer <= 0) {
    timer = 1500;
    counter = ((counter + 1) % 3);
  }
  
  digitalWrite(counter + 3, HIGH);   // turn the LED off by making the voltage LOW
  delayMicroseconds(timer);   // wait for timer microseconds
  digitalWrite(counter + 3, LOW);  // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(1500 - timer);   // wait for timer microseconds
}
