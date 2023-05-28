// Library um die Messungen des Sensors direkt verwenden zu können
#include "Adafruit_VL53L0X.h"

// Name unseres "Time Of Flight" Distanz-Sensors
Adafruit_VL53L0X tof_sensor = Adafruit_VL53L0X();

// Aktivierung der Schnittstellen
void setup()
{
  // Kommunikation zwischen Microcontroller und Computer aktivieren
  Serial.begin(115200);

  // Sensor aktivieren
  tof_sensor.begin();
}


// Unser Programm führt eine Messung in dem Sensor aus
// Anschließend wird das Ergebnis an einen Monitor gesendet
void loop()
{

  // Variable "messung" in welcher Messungen des Sensors gespeichert wird
  VL53L0X_RangingMeasurementData_t messung;

  // Mit Serial.print können wir einen Text an den Seriellen Monitor senden
  Serial.print("Lesen und Test der Messung... ");

  // Messung und Distanz Test:
  // Das Ergebnis des Tests wird in der Variable 'messung' gespeichert
  // Das &-Symbol vor der existierenden Variable 'messung' erlaubt es diese zu ändern
  // Somit finden wir das Ergebnis des Tests später in dieser Variable
  // Da uns die weiteren Details des Tests nicht interessieren geben wir außerdem 'false' an
  tof_sensor.rangingTest(&messung, false);

  // Hier greifen wir auf die 'Reichweite' (eng: 'Range')
  // Uns interessiert nur ein Testergebnis: die Distanz in Millimetern
  // Das Ergebnis senden wir wieder an den Seriellen Monitor
  Serial.print("Distanz (mm): ");
  Serial.println(messung.RangeMilliMeter);

  
  // Für bessere Lesbarkeit pausieren wir den loop nach jedem Durchgang 
  // für 100 Millisekunden, also 0.1 Sekunde
  delay(100);
}