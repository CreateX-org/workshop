// Library um die Messungen des Sensors direkt verwenden zu können
#include "Adafruit_VL53L0X.h"

// Name unseres "Time Of Flight" Distanz-Sensors
Adafruit_VL53L0X tof_sensor = Adafruit_VL53L0X();

// unsere LED ist mit Pin 3 verbunden
int LED = 3;

// Aktivierung der Schnittstellen
void setup()
{
  // Kommunikation zwischen Microcontroller und Computer aktivieren
  Serial.begin(115200);

  // Sensor aktivieren
  tof_sensor.begin();

  // Pin 3 wird als Output gesetzt
  pinMode(LED, OUTPUT);
}


// Wie zuvor führt unser Programm eine Messung aus
// Abhängig von dem Ergebnis soll nun aber die LED an oder aus geschalten werden
// anstatt das Ergebnis an einen Monitor zu senden
void loop() {

  // Wie zuvor:
  // Variable "messung" in welcher Messungen des Sensors gespeichert werden
  VL53L0X_RangingMeasurementData_t messung;

  // Messung und Distanz Test:
  // Das Ergebnis des Tests wird in der Variable 'messung' gespeichert
  // Das &-Symbol vor der existierenden Variable 'messung' erlaubt es uns diese zu ändern
  // Somit finden wir das Ergebnis des Tests später in dieser Variable
  // Da uns die weiteren Details des Tests nicht interessieren geben wir außerdem 'false' an
  tof_sensor.rangingTest(&messung, false);

 
  // Hier greifen wir wieder auf die 'Reichweite' (eng: 'Range') der Messung zu
  // Uns interessiert wieder nur ein Testergebnis: die Distanz in Millimetern
  // Neu:
  // Wir speichern das Ergebnis in einer neuen Variablen
  int distanz = messung.RangeMilliMeter;


  // Ist die Distanz kleiner als 20mm...
  if (distanz < 20) {
    // Schalten wir die LED ein
    digitalWrite(LED, HIGH);
  } else {
    // Falls nicht: Schalten wir die LED aus
    digitalWrite(LED, LOW);
  }


  // Vielleicht wollen wir trotzdem wissen was genau der Sensor misst:
  // Serial.print("Distanz (mm): ");
  // Serial.println(distanz);
 

  // Nach jedem Schritt machen wir eine Pause von 0.1 Sekunden
  delay(100);
  
}