
const int R = 3;
const int G = 5;
const int B = 6;

int speed = 0;
int pattern = 0;
float max_val = 255.0;

void setup() {
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);

  pinMode(A0, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  pinMode(A6, INPUT_PULLUP);
  pinMode(A7, INPUT_PULLUP);
  delay(50);

  speed = !digitalRead(A0);
  delay(50);
  speed += !digitalRead(A1);
  delay(50);

  pattern = !digitalRead(A2);
  delay(50);
  pattern += !digitalRead(A3);
  delay(50);
/*
  int max_val_div = !digitalRead(A4);
  delay(50);
  max_val_div += !digitalRead(A5);

  max_val /= max_val_div;*/
}

int step = 0;
int step_r = 0;
int step_g = 0;
int step_b = 0;


void loop() {
  if(pattern == 0) {
    analogWrite(R, step);
    analogWrite(G, step);
    analogWrite(B, step);

    step += 1;
    if(step >= max_val)
      step = 0;
  } else if(pattern == 1) {
    analogWrite(R, step_r);
    analogWrite(G, step_g);
    analogWrite(B, step_b);

    step_r += 1;
    step_g += 3;
    step_b += 5;

    if(step_r > 255)
      step_r = 0;
    if(step_g > 255)
      step_g = 0;
    if(step_b > 255)
      step_b = 0;
  }
    
  delay(100 / (speed * speed * speed + 1));
}
