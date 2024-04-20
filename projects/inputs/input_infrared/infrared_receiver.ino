// Definiere die Arduino Pins, die mit den Ausgangspins des Empfängers verbunden sind
int inputPins[] = { 2, 3, 4, 5 };  // OUT1, OUT2, OUT3, OUT4
int ledPins[] = { 7, 8, 9, 10 };
int numPins = 4;

void setup() {
  // Beginne die serielle Kommunikation mit dem Computer
  Serial.begin(9600);

  // Setze die definierten Pins als Eingang
  for (int i = 0; i < numPins; i++) {
    pinMode(inputPins[i], INPUT);
  }

  for (int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Speichere den Status von jedem der Infrarot Channel
  int state_out1 = digitalRead(inputPins[0]);
  int state_out2 = digitalRead(inputPins[1]);
  int state_out3 = digitalRead(inputPins[2]);
  int state_out4 = digitalRead(inputPins[3]);

  // Wenn wir den Status für den seriellen Monitor durch ein Komma trennen
  // dann aber in eine Zeile schreiben, können wir den Seriellen Plotter nutzen
  // in dem jede Variabel dann mit einer eigenen Farbe dargestellt wird.
  // Serial.print(state_out1);
  // Serial.print(",");
  // Serial.print(state_out2);
  // Serial.print(",");
  // Serial.print(state_out3);
  // Serial.print(",");
  // Serial.println(state_out4);

  // Wir können den Status aber auch an einen anderen Output weitergeben,
  // zB für zwei LEDs
  if (state_out1 == HIGH) {
    // LED1 einschalten, wenn der Status von Channel 1 aktiv ist (1 ausgibt)
    digitalWrite(ledPins[0], HIGH); // die erste LED im Array mit Index 0
  } else {
    // Ansonsten LED1 immer ausgeschalten lassen
    digitalWrite(ledPins[0], LOW);
  }
  if (state_out2 == HIGH) {
    digitalWrite(ledPins[1], HIGH); // die zweite LED im Array mit Index 1
  } else {
    digitalWrite(ledPins[1], LOW);
  }

  // Warte kurz, um die Ausgaben lesbar zu halten
  delay(200);
}
