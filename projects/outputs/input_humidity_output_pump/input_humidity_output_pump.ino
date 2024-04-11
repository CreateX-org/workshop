// Dieser Pin kann vom ADC ausgelesen werden, wodurch indirekt die Feuchtigkeit bestimmt werden kann.
#define INPUT_PIN A0
// Diser Pin steuert die Wasserpumpe. An ist HIGH und aus ist LOW.
#define PUMP_PIN 2

void setup() {
  Serial.begin(115200);

  // INPUT_PIN auf INPUT und PUMP_PIN auf OUTPUT setzen. Logisch ;P
  pinMode(INPUT_PIN, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
}

void loop() {
  // ADC Wert auslesen
  int ADC_reading = analogRead(INPUT_PIN);

  // ADC Wert ueber das serielle Interface ausgeben (v.a. zum Testen)
  Serial.print("Watering ADC value: ");
  Serial.println(ADC_reading);

  // Beispiel: Wenn der Wert kleiner als 350 wird (z.B. durch Anfassen des Sensors oder feuchte Erde), schalten wir die Pumpte an (HIGH)
  if (rawADC < 350) {
    digitalWrite(PUMP_PIN, HIGH);
  } else {
    digitalWrite(PUMP_PIN, LOW);
  }

  delay(100);
}