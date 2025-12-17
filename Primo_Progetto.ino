int led = 4;
int delayDash = 1500;
int delayDot = 500;
int delaySpento = 500;

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
