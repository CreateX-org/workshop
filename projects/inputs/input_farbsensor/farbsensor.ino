// Definiere die Pins für den Sensor
#define SENSOR_S0 5
#define SENSOR_S1 4
#define SENSOR_S2 7
#define SENSOR_S3 6
#define SENSOR_OUT 8

int frequency = 0;

void setup() {
  pinMode(SENSOR_S0, OUTPUT);
  pinMode(SENSOR_S1, OUTPUT);
  pinMode(SENSOR_S2, OUTPUT);
  pinMode(SENSOR_S3, OUTPUT);
  pinMode(SENSOR_OUT, INPUT);

  // Setting frequency-scaling to 20%
  // digitalWrite(SENSOR_S0, HIGH);
  // digitalWrite(SENSOR_S1, LOW);

  // Setting frequency-scaling to 100%
  // Details: https://elektro.turanis.de/html/prj029/index.html
  digitalWrite(SENSOR_S0, HIGH);
  digitalWrite(SENSOR_S1, HIGH);

  Serial.begin(9600);
}

void loop() {
  // ROT ---------------------------------------------------------------------------
  // Rotfilter: S2 und S3 auf LOW, steuert den roten Fotoioden Typen an
  digitalWrite(SENSOR_S2, LOW);
  digitalWrite(SENSOR_S3, LOW);
  frequency = pulseIn(SENSOR_OUT, LOW);  // Reading the output frequency

  // Wert für Rot wird auf dem seriellen Monitor ausgegeben
  // Serial.print("R=");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);


  // GRÜN --------------------------------------------------------------------------
  // Rotfilter: S2 und S3 auf HIGH, steuert den günen Fotoioden Typen an
  digitalWrite(SENSOR_S2, HIGH);
  digitalWrite(SENSOR_S3, HIGH);
  frequency = pulseIn(SENSOR_OUT, LOW);

  // Serial.print("G=");
  Serial.print(frequency);
  Serial.print("  ");
  delay(100);


  // BLAU --------------------------------------------------------------------------
  // Rotfilter: S2 auf LOW und S3 auf HIGH, steuert den blauen Fotoioden Typen an
  digitalWrite(SENSOR_S2, LOW);
  digitalWrite(SENSOR_S3, HIGH);
  frequency = pulseIn(SENSOR_OUT, LOW);

  // Serial.print("B=");
  Serial.print(frequency);
  Serial.println("  ");


  // Pause
  delay(200);
}