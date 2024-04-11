#include <Wire.h>

// Dokumentation fuer FastLED gibt es hier: https://fastled.io/docs/index.html
#include "FastLED.h"

// Pin, mit dem die Datenleitung des NeoHex Boards verbunden ist
#define Neopixel_PIN 2
// Anzahl der LEDs auf dem Board
#define NUM_LEDS 37

CRGB leds[NUM_LEDS];

// Globale Variable, die den Start-Farbton fuer die "fill_rainbow" Funktion speichert
uint8_t gHue = 0;

void setup() {
  Serial.begin(115200);

  // Neopixel initialisieren
  FastLED.addLeds<WS2811, Neopixel_PIN, GRB>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip);  // Farbkorrektur, einfach so lassen.

  // LED Helligkeit zwischen 0 (dunkel) und 255 (SEHR hell).
  // 255 braucht auch relativ viel Strom, am Laptop eventuell nicht moeglich.
  FastLED.setBrightness(20);
}

void loop() {
  // Setzt die Farben im "leds" array automatisch so, dass sich ein Regenbogen ergibt.
  // Der Startfarbton ist in "gHue" gespeichert und wird
  fill_rainbow(leds, NUM_LEDS, gHue, 7);


  // Hier wird gezeigt, wie einzelne LEDs angesteuert werden.
  // Es sollte sich eine diagonale Linie aus weissen LEDs ergeben.
  // Wenn man die LEDs der Reihe nach abzaehlt (und bei 0 zu zaehlen beginnt),
  // dann sollte man genau auf die Indices in den eckigen Klammern kommen.
  // Die 255 bedeutet volle Helligkeit bei der Farbe.
  // Wenn rot, gruen und blau gleich hell sind, ergibt sich weiss.
  leds[0] = CRGB(255, 255, 255);
  leds[5] = CRGB(255, 255, 255);
  leds[11] = CRGB(255, 255, 255);
  leds[18] = CRGB(255, 255, 255);
  leds[25] = CRGB(255, 255, 255);
  leds[31] = CRGB(255, 255, 255);
  leds[36] = CRGB(255, 255, 255);

  // LED Farben auf dem Board ausgeben
  FastLED.show();

  // Nur, wenn 50 ms abgelaufen sind, wird "gHue" hochgezählt.
  // Achtung: Hier kein delay verwenden, die Schleife sollte moeglichst schnell hintereinander immer wieder ausgefuehrt werden.
  EVERY_N_MILLISECONDS(2) {
    gHue++;
  }
}