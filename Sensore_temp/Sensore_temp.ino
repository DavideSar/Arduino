#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include "max6675.h"
int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

float T_NTC;
float T_DHT;
float T_THERMO;
float Vout = 0;
float R1 = 10000;
float R25 = 10000;
const float Vi = 1023;
float Rt;
const float T0 = 273.15;
const float T2 = 298.15;
const float B = 3965;
float HUM;

const unsigned long delta = 2000;
unsigned long now;
unsigned long old = 0;
unsigned long minutes = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  now = millis();
  if(now >= old + delta){
    
    /*
    Serial.print("o: ");
    Serial.print(old);
    Serial.print(" - n: ");
    Serial.println(now);
    */

    old = now;

    //NTC
    Vout = analogRead(A0);
    Rt = (Vi/Vout - 1)*R1;
    T_NTC = (B/(log(Rt/R25) + (B/T2))) - T0;

    //DHT
    T_DHT = dht.readTemperature();

    //THERMOCOUPLE
    T_THERMO = thermocouple.readCelsius();

    //Stampa su file csv
    Serial.print(now);
    Serial.print(",");
    Serial.print(T_NTC);
    Serial.print(",");
    Serial.print(T_DHT);
    Serial.print(",");
    Serial.println(T_THERMO);
  }

}
