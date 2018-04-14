// Projeto 06 - Efeito de iluminação sequencial (Potenciômetro)

// Array para os LEDs
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
byte ledDelay;
byte direction = 1;
byte currentLED = 0;
unsigned long changeTime;
byte potPin = 2; // Seleciona o pino de entrada para o potenciômetro

void setup() {
  // Define todos os pinos como saída
  for (byte x=0; x<10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }

  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin);
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  // Apaga todos os LEDs
  for (byte x=0; x<10; x++) {
    digitalWrite(ledPin[x], LOW);
  }

  // Acende o LED atual
  digitalWrite(ledPin[currentLED], HIGH);

  // Incrementa de acordo com o valor de direction
  currentLED += direction;

  // Altera a direção se tivermos atingindo o fim
  if (currentLED == 9) {
    direction = -1;
  }

  if (currentLED == 0) {
    direction = 1;
  }
}

