#include <Adafruit_NeoPixel.h>

// Mit welchen Pins sind die Bauteile verbunden?
// Button mit Pin 2 verbunden
int BUTTON = 2;
// Neopixel mit Pin 3 verbunden
int NEOPIXEL = 3;

// Anzahl der LEDs auf dem Neopixel
int NUM_LEDS = 10;

// Name unseres Neopixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, NEOPIXEL, NEO_GRB + NEO_KHZ800);

// Aktuelle LED position
int position = 0;

// Welche Pins sind Input und welche Output?
void setup()
{
  // Der Button ist ein Input
  pinMode(BUTTON, INPUT);
  
  // Eine spezielle Form des Outputs: Ein Neopixel
  pixels.begin();
  
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
  	
  	for (int i=0; i < NUM_LEDS; i++) {
    	// pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      
      // Wenn der Index i gleich der aktuellen LED ist, wird diese LED angeschaltet
      if(position == i){
        // Frage: Wie kann hier die Farbe geändert werden?
        // Tipp: pixels.Color nimmt RGB (Rot, Grün, Blau) Werte an.
        // Das sind Werte zwischen 0 (aus) und 255 (volle Helligkeit dieser Farbe).
    	pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      } else {
        // Ansonsten wird die LED ausgeschaltet (alles 0)
      	pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      
      // Aktuelle Konfiguration der Pixel auf dem Streifen anzeigen
      pixels.show();
  	}
	
    // Beim nächsten Durchlauf sind wir eine LED weiter
    position = position + 1;
    
    // Wenn die letzte LED erreicht wurde (Zählung beginnt bei 0!), wieder von Vorne anfangen
    if(position >= NUM_LEDS) {
    	position = 0;
    }
    
    // Ausgabe der Position auf den PC
  	Serial.println(position);
    
    // 200 ms warten, damit wir es beobachten können
    delay(200);
  }
}




