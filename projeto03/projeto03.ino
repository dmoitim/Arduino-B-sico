// Projeto 03 - Semáforo (Sistema de semáforos do Reino Unido - quatro estados)
int ledDelay = 10000;
int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  digitalWrite(redPin, HIGH);    // Acende o LED vermelho
  delay(ledDelay);               // Espera ledDelay milissegundos

  digitalWrite(yellowPin, HIGH); // Acende o LED amarelo
  delay(2000);                   // Espera 2 segundos

  digitalWrite(greenPin, HIGH);  // Acende o LED verde
  digitalWrite(redPin, LOW);     // Apaga o LED vermelho
  digitalWrite(yellowPin, LOW);  // Apaga o LED amarelo
  delay(ledDelay);               // Espera ledDelay milissegundos
  
  digitalWrite(yellowPin, HIGH); // Acende o LED amarelo
  digitalWrite(greenPin, LOW);   // Apaga o LED verde
  delay(2000);                   // Espera 2 segundos

  digitalWrite(yellowPin, LOW);  // Apaga o LED amarelo
}

