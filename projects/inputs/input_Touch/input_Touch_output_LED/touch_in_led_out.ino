// Mit welchen Pins sind die Bauteile verbunden?

// Touch Sensor mit Pin 2 verbunden
int TOUCH = 2;
// LED1 mit Pin 3 verbunden
int LED1 = 3;

// Welche Pins sind Input und welche Output?
void setup()
{
  pinMode(TOUCH, INPUT);
  pinMode(LED1, OUTPUT);
}

// Was soll das Programm machen, während es läuft?
void loop()
{
  // Prüfen, ob der Sensor berührt wird oder nicht
  bool button_state = digitalRead(TOUCH);
  
  // Wenn der Sensor nicht berührt wird (Pin ist LOW)
  if(button_state == LOW) {
    // LED1 ausschalten
    digitalWrite(LED1, LOW);
    
  // Im anderen Fall (Sensor wird berührt, Pin ist HIGH)
  } else {
    // LED1 einschalten
    digitalWrite(LED1, HIGH);
  }
}
