// Projeto 02 - LED SOS

// Led conectado ao pino 10
int ledPin = 10;

// Executa uma vez, quando o sketch inicia
void setup() {
  // Define o pino como saída
  pinMode(ledPin, OUTPUT);
}

// Exeuta repetidas vezes
void loop() {
  // 3 pontos
  for (int x=0; x<3; x++){
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150);                 // espera 150ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);                 // espera 100ms
  }

  // Espera 100ms para marcar intevalo entre as letras
  delay(100);

  // 3 traços
  for (int x=0; x<3; x++) {
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(400);                 // espera 400ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);                 // espera 100ms
  }

  // Espera 100ms para marcar intervalo entre as letras
  delay(100);

  // 3 pontos novamente
  for (int x=0; x<3; x++) {
    digitalWrite(ledPin, HIGH); // acende o LED
    delay(150);                 // espera 150ms
    digitalWrite(ledPin, LOW);  // apaga o LED
    delay(100);                 // espera 100ms
  }

  // Espera 5 segundos para repetir o sinal de SOS
  delay(5000);
}

