// Projeto 05 - Efeito de iluminação sequencial

// Array para os LEDs
byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
byte ledDelay(65);
byte direction = 1;
byte currentLED = 0;
unsigned long changeTime;

void setup() {
  // Define todos os pinos como saída
  for (byte x=0; x<10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }

  changeTime = millis();
}

void loop() {
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

