# include < Servo .h >

Servo myServo ; // Crea un oggetto Servo
int potPin = A0 ; // Pin del potenziometro
int val ; // Variabile per il valore letto

void setup () {
  myServo . attach (9) ; // Collega il servo al pin digitale 9
  Serial . begin (9600) ; // Per monitoraggio opzionale su Serial Monitor
}

  void loop () {
  val = analogRead ( potPin ) ; // Legge il valore (0 -1023)
  int angolo = map ( val , 0 , 1023 , 0 , 180) ; // Conversione in gradi
  myServo . write ( angolo ) ; // Muove il servo all ’angolo
corrispondente

  Serial . print (" Valore potenziometro : ") ;
  Serial . print ( val ) ;
  Serial . print (" --> Angolo : ") ;
  Serial . println ( angolo ) ;

  delay (15) ; // Breve pausa per stabilizzare il movimento
}
