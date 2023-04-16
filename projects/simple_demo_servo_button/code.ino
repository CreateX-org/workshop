#include <Servo.h>

// Mit welchen Pins sind die Bauteile verbunden?
// Button mit Pin 2 verbunden
int BUTTON = 2;
// Servo mit Pin 3 verbunden
int SERVO = 3;

// Name unseres Servos
Servo servo1;

// Variable, in der die Servo position gespeichert wird
int position = 0;

// Welche Pins sind Input und welche Output?
void setup()
{
  // Der Button ist ein Input
  pinMode(BUTTON, INPUT);
  
  // Eine spezielle Form des Outputs: Ein Servo Motor
  servo1.attach(SERVO, 500, 2500);
  
  // Input und Output: Die Verbindung zum PC (hier ohne Pin Angabe)
  Serial.begin(9600);
}

// Was soll das Programm machen, während es läuft?
void loop()
{
  // Prüfen, ob der Button gedrückt ist oder nicht
  bool button_state = digitalRead(BUTTON);
  
  // Wenn der Button gedrückt ist (Pin ist HIGH)
  if(button_state == HIGH){    
    position = position + 10;
  
  	// Wenn die position größer als 180 ist, fangen wir wieder von 0 an
  	if(position > 180) {
	  	position = 0;
  	}
  
  	// Servo auf die eingestellte Position drehen
  	servo1.write(position);
  
    // Ausgabe der Position auf den PC
  	Serial.println(position);
    
    // 200 ms warten, damit wir es beobachten können
    delay(200);
  }
}

