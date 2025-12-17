int led = 4;
int readTime = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(led, HIGH);
  delay(analogRead(readTime));

  digitalWrite(led, LOW);
  delay(analogRead(readTime));

  Serial.println(analogRead(readTime));
}
