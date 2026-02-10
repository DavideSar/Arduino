#include <ArduinoBLE.h>
//#define PRINT_DEBUG
// --- Parametri di Calibrazione ---
const int measuredPower = -30;             // RSSI misurato a 1 metro
const float environmentalFactor = 2.5;     // Esponente di attenuazione (2-4)

// --- Configurazione Filtro ---
const int WINDOW_SIZE = 10;       // Numero di letture per la media
int rssiHistory[WINDOW_SIZE];     // Array per memorizzare i valori
int historyIndex = 0;             // Indice corrente nell'array
bool bufferFull = false;          // Diventa true dopo le prime 10 letture

int rssiArray[4] = {-1,-1,-1,-1};
float filteredRSSI[4];
float distance[4];

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("Errore BLE!");
    while (1);
  }

  // Inizializza l'array a zero
  for (int i = 0; i < WINDOW_SIZE; i++) rssiHistory[i] = 0;

  Serial.println("Scansione con Filtro Media Mobile avviata...");
  BLE.scan();
}

void loop() {
  BLEDevice peripheral = BLE.available();
  
  if (peripheral) {
    // Sostituisci "NomeDispositivo" con il nome del tuo target per filtrare i dati
    if (peripheral.hasLocalName()) {
#ifdef PRINT_DEBUG
      Serial.println(peripheral.localName());
#endif


      if(peripheral.localName()=="POINT_00"){
        int rawRSSI = peripheral.rssi();
        rssiArray[0] = rawRSSI;
        filteredRSSI[0] = updateFilter(rawRSSI);
        distance[0] = calculateDistance(filteredRSSI[0]);
#ifdef PRINT_DEBUG
        Serial.print("RSSI Grezzo: "); Serial.print(rawRSSI);
        Serial.print(" | RSSI Filtrato: "); Serial.print(filteredRSSI[0]);
        Serial.print(" | Distanza: "); Serial.print(distance[0]);
        Serial.println(" m");
#endif
      }


      if(peripheral.localName()=="POINT_01"){
        int rawRSSI = peripheral.rssi();
        rssiArray[1] = rawRSSI;
        filteredRSSI[1] = updateFilter(rawRSSI);
        distance[1] = calculateDistance(filteredRSSI[1]);

#ifdef PRINT_DEBUG
        Serial.print("RSSI Grezzo: "); Serial.print(rawRSSI);
        Serial.print(" | RSSI Filtrato: "); Serial.print(filteredRSSI[1]);
        Serial.print(" | Distanza: "); Serial.print(distance[1]);
        Serial.println(" m");
#endif
      }


      if(peripheral.localName()=="POINT_10"){
        int rawRSSI = peripheral.rssi();
        rssiArray[2] = rawRSSI;
        filteredRSSI[2] = updateFilter(rawRSSI);
        distance[2] = calculateDistance(filteredRSSI[2]);

#ifdef PRINT_DEBUG
        Serial.print("RSSI Grezzo: "); Serial.print(rawRSSI);
        Serial.print(" | RSSI Filtrato: "); Serial.print(filteredRSSI[2]);
        Serial.print(" | Distanza: "); Serial.print(distance[2]);
        Serial.println(" m");
#endif
      }


      if(peripheral.localName()=="POINT_11"){
        int rawRSSI = peripheral.rssi();
        rssiArray[3] = rawRSSI;
        filteredRSSI[3] = updateFilter(rawRSSI);
        distance[3] = calculateDistance(filteredRSSI[3]);
#ifdef PRINT_DEBUG
        Serial.print("RSSI Grezzo: "); Serial.print(rawRSSI);
        Serial.print(" | RSSI Filtrato: "); Serial.print(filteredRSSI[3]);
        Serial.print(" | Distanza: "); Serial.print(distance[3]);
        Serial.println(" m");
#endif
      }


      Serial.print(rssiArray[0]);
      Serial.print(","); 
      Serial.print(rssiArray[1]);
      Serial.print(","); 
      Serial.print(rssiArray[2]);
      Serial.print(","); 
      Serial.print(rssiArray[3]);
     /*
      Serial.print(","); 
      Serial.print(filteredRSSI[0]);
      Serial.print(","); 
      Serial.print(filteredRSSI[1]);
      Serial.print(","); 
      Serial.print(filteredRSSI[2]);
      Serial.print(","); 
      Serial.print(filteredRSSI[3]);


      Serial.print(","); 
      Serial.print(distance[0]);
      Serial.print(","); 
      Serial.print(distance[1]);
      Serial.print(","); 
      Serial.print(distance[2]);
      Serial.print(","); 
      Serial.print(distance[3]);

      */
      Serial.println("");
    }
  }
}

// Funzione per aggiornare il filtro e restituire la media
float updateFilter(int newRSSI) {
  rssiHistory[historyIndex] = newRSSI;
  historyIndex = (historyIndex + 1) % WINDOW_SIZE;
  
  if (historyIndex == 0) bufferFull = true;

  int count = bufferFull ? WINDOW_SIZE : historyIndex;
  long sum = 0;
  for (int i = 0; i < count; i++) {
    sum += rssiHistory[i];
  }
  return (float)sum / count;
}

// Calcolo distanza basato su RSSI filtrato
float calculateDistance(float rssi) {
  return pow(10, (measuredPower - rssi) / (10 * environmentalFactor));
}