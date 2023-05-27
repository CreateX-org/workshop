// Mit welchen Pins sind die Bauteile verbunden?

// Button mit Pin 2 verbunden
int BUTTON = 2;
// LED1 mit Pin 3 verbunden
int LED1 = 3;

// Welche Pins sind Input und welche Output?
void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED1, OUTPUT);
}

// Was soll das Programm machen, während es läuft?
void loop()
{
  // Prüfen, ob der Button gedrückt ist oder nicht
  bool button_state = digitalRead(BUTTON);
  
  // Wenn der Button nicht gedrückt ist (Pin ist LOW)
  if(button_state == LOW) {
    // LED1 ausschalten
  	digitalWrite(LED1, LOW);
    
  // Im anderen Fall (Button nicht gedrückt, Pin ist HIGH)
  } else {
    // LED1 einschalten
  	digitalWrite(LED1, HIGH);
  }
}