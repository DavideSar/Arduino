int red = 7;
int yellow = 7;
int green = 7;
int onRnG = 1000;
int onY = 500;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
}


void loop() {
  //S
  digitalWrite(led, HIGH);
  delay(delayDash);
  digitalWrite(led, LOW);
  delay(delaySpento);
  digitalWrite(led, HIGH);
  delay(delayDash);
  digitalWrite(led, LOW);
  delay(delaySpento);
  digitalWrite(led, HIGH);
  delay(delayDash);
  digitalWrite(led, LOW);
  delay(delaySpento);
  //O
  digitalWrite(led, HIGH);
  delay(delayDot);
  digitalWrite(led, LOW);
  delay(delaySpento);
  digitalWrite(led, HIGH);
  delay(delayDot);
  digitalWrite(led, LOW);
  delay(delaySpento);
  digitalWrite(led, HIGH);
  delay(delayDot);
  digitalWrite(led, LOW);
  delay(delaySpento);
  //S
  digitalWrite(led, HIGH);
  delay(delayDash);
  digitalWrite(led, LOW);
  delay(delaySpento);
  digitalWrite(led, HIGH);
  delay(delayDash);
  digitalWrite(led, LOW);
  delay(delaySpento);
  digitalWrite(led, HIGH);
  delay(delayDash);
  digitalWrite(led, LOW);
  delay(delaySpento);
}
