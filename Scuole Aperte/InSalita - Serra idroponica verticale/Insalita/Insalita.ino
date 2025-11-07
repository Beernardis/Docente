// Controllo di una pompa idroponica verticale con potenziometro
// e circuito MOSFET - Visualizzazione PWM su oscilloscopio

int potPin = A0;    // Pin del potenziometro
int pompa = 9;      // Pin PWM per il MOSFET
int val;            // Variabile per il valore letto

void setup() {
  pinMode(pompa, OUTPUT);    // Imposta il pin pompa come output
  Serial.begin(9600);        // Per monitoraggio opzionale
}

void loop() {
  val = analogRead(potPin);                 // Legge il valore (0-1023)
  int velocita = map(val, 0, 1023, 0, 255); // Conversione in PWM
  analogWrite(pompa, velocita);             // Controlla la pompa

  Serial.print("Valore potenziometro: ");
  Serial.print(val);
  Serial.print(" --> Velocita pompa: ");
  Serial.print((velocita/255.0)*100.0);     // Velocita in percentuale
  Serial.println(" %");

  delay(15);  // Breve pausa per stabilizzare
}