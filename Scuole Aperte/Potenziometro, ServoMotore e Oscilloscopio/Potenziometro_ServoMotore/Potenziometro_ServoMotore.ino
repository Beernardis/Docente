#include <Servo.h>  // Libreria per il controllo del servomotore

Servo myServo;          // Crea un oggetto Servo
int potPin = A0;        // Pin a cui è collegato il potenziometro
int potValue;           // Valore letto dal potenziometro (0 - 1023)
int angolo;             // Angolo del servo in gradi (0 - 180)

void setup() {
  Serial.begin(9600);   // Avvia la comunicazione seriale
  myServo.attach(9);    // Collega il servo al pin 9
}

void loop() {
  potValue = analogRead(potPin);          // Legge il valore analogico
  angolo = map(potValue, 0, 1023, 0, 180); // Converte in angolo (0° - 180°)

  myServo.write(angolo);                  // Muove il servo alla posizione corrispondente

  // Stampa i valori su Serial Monitor
  Serial.print("Potenziometro: ");
  Serial.print(potValue);
  Serial.print("  |  Angolo servo: ");
  Serial.print(angolo);
  Serial.println("°");

  delay(20);
}
