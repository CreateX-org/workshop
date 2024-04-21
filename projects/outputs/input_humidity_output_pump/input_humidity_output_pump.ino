// Dieser Pin kann vom Analog-to-Digital Converter (ADC) ausgelesen werden, wodurch indirekt die Feuchtigkeit bestimmt werden kann.
#define INPUT_PIN A0
// Diser Pin steuert die Wasserpumpe. An ist HIGH und aus ist LOW.
#define PUMP_PIN 2


// // Glättung ------------------------------------------------------
// const int numReadings = 20;
// int readings[numReadings];  // the readings from the analog input
// int readIndex = 0;          // the index of the current reading
// int total = 0;              // the running total
// int average = 0;            // the average
// // ---------------------------------------------------------------


void setup() {
  Serial.begin(115200);

  // INPUT_PIN auf INPUT und PUMP_PIN auf OUTPUT setzen.
  pinMode(INPUT_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
}



void loop() {
  // ADC Wert auslesen
  int ADC_reading = analogRead(INPUT_PIN);

  // ADC Wert ueber das serielle Interface ausgeben (v.a. zum Testen)
  Serial.print("Watering ADC value: ");
  Serial.print(ADC_reading);


  // // ---------------------------- Glättung ----------------------------
  // // subtract the last reading:
  // total = total - readings[readIndex];
  // // read from the sensor:
  // readings[readIndex] = ADC_reading;
  // // add the reading to the total:
  // total = total + readings[readIndex];
  // // advance to the next position in the array:
  // readIndex = readIndex + 1;

  // // if we're at the end of the array...
  // if (readIndex >= numReadings) {
  //   // ...wrap around to the beginning:
  //   readIndex = 0;
  // }

  // // calculate the average:
  // average = total / numReadings;

  // // Um beide Ergebnisse mit dem Seriellen Plotter darzustellen:
  // // (Die anderen Print Statements müssen auskommentiert werden)
  // Serial.print(ADC_reading);
  // Serial.print(", ");
  // Serial.println(average);
  // // ------------------------------------------------------------------


  // Beispiel: Wenn der Wert größer als 350 wird schalten wir die Pumpte an (HIGH), wegen Trockenheit
  // Wenn der Wert kleiner als 350 wird schalten wir die Pumpte aus (LOW), wegen Feuchtigkeit (z.B. durch Anfassen des Sensors oder feuchte Erde).
  // Der Wert muss eventuell angepasst werden.
  if (ADC_reading > 350) {
    digitalWrite(PUMP_PIN, HIGH);
  } else {
    digitalWrite(PUMP_PIN, LOW);
  }

  delay(100);
}