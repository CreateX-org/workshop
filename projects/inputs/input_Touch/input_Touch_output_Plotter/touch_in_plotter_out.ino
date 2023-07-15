// Mit welchen Pins sind die Bauteile verbunden?

// Touch Sensor mit Pin 2 verbunden
int TOUCH = 2;

// Welche Pins sind Input und was ist Output?
void setup()
{
  pinMode(TOUCH, INPUT);

  // Kommunikation zwischen Microcontroller und Computer aktivieren
  Serial.begin(9600);
}

// Was soll das Programm machen, während es läuft?
void loop()
{
  // Prüfen, ob der Sensor berührt wird oder nicht
  bool button_state = digitalRead(TOUCH);

  if (button_state == HIGH) {
    // Mit Serial.print können wir einen Text an den Seriellen Monitor senden
    // Zahlen lassen sich auch gut am Seriellen Plotter darstellen
    Serial.println(1);
  } else {
    Serial.println(0);
  }

  // Für bessere Lesbarkeit pausieren wir den loop nach jedem Durchgang 
  // um 10 Millisekunden, also 0.01 Sekunden
  delay(10);

}
