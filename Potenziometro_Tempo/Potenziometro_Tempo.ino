const int LED = 4;
const int IN = 1;
int lastRead=0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(LED, HIGH);
  delay(analogRead(IN));

  digitalWrite(LED, LOW);
  delay(analogRead(IN));

  if (analogRead(IN)!=lastRead){
    Serial.println(analogRead(IN));
    lastRead = analogRead(IN);
  }
}
