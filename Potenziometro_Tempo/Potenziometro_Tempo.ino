const int LED = 4;
const int IN = 1;
int lastRead=0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(IN);
  int volt = 0;

  digitalWrite(LED, HIGH);
  delay(val);

  digitalWrite(LED, LOW);
  delay(val);

  if (val!=lastRead){
    volt = (5000*val)/1023;
    Serial.print(val);
    Serial.print(", ");
    Serial.print(volt);
    Serial.println();
    lastRead = val;
  }
}
