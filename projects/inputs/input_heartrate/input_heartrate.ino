// Originalquelle https://github.com/gabriel-milan/Arduino-MAX30100

#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// Pulsoximeter
PulseOximeter pox;

// Zeitvariable, mit der unten festgestellt wird, ob ein Statustext ausgegeben werden soll
uint32_t time_last = 0;

// Callback (wird weiter unten gesetzt), das bei jedem erkannten Herzschlag aufgerufen wird
void onBeatDetected()
{
    Serial.println("Beat!");
}

void setup()
{
    Serial.begin(115200);

    Serial.print("Initializing pulse oximeter..");

    // Initialisieren. Wenn alles richtig verbunden ist, wird man hier meist keinen Output sehen.
    if (!pox.begin()) {
        Serial.println("FAILED");
        return;
    } else {
        Serial.println("SUCCESS");
    }

    // Den Strom der Infrarot LED auf 27,1 mA setzen verbessert die Herzschlagerkennung ein bisschen
    pox.setIRLedCurrent(MAX30100_LED_CURR_27_1MA);

    // Callback registrieren
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop()
{
    // So oft wie moeglich aufrufen
    pox.update();

    // Puls und Sauerstoffsaettigung werden alle 1000 ms ueber das serielle Interface ausgegeben.
    // Wenn der Wert 0 ist, ist die Messung fehlgeschlagen.
    if (millis() - time_last > 1000) {
        Serial.print("Puls: ");
        Serial.print(pox.getHeartRate());
        Serial.print("bpm / SpO2: ");
        Serial.print(pox.getSpO2());
        Serial.println(" %");

        time_last = millis();
    }
}