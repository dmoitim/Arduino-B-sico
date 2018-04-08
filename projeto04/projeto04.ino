// Projeto 04 - Semáforo Interativo (Sistema de semáforos do Reino Unido)

// Semáforo dos carros
int carRed = 12;
int carYellow = 11;
int carGreen = 10;

// Semáforo dos pedestres
int pedRed = 9;
int pedGreen = 8;

// Pino do botão
int button = 4;

int crossTime = 5000; // Tempo para que os pedestres atravessem
unsigned long changeTime; // Tempo desde a última vez que o botão foi pressionado

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);

  pinMode(button, INPUT); // Botão é entrada

  // Inicialização
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);

  // Verifica se o botão foi pressionado e se transcorreram 5 segundos desde a última vez que ele foi pressionado
  if (state == HIGH && (millis() - changeTime > 5000)) {
    // Chamada da função para alterar os leds
    changeLights();
  }
}

void changeLights() {
  digitalWrite(carGreen, LOW);   // Apaga o verde
  digitalWrite(carYellow, HIGH); // Acende o amarelo
  delay(2000);                   // Espera 2 segundos

  digitalWrite(carYellow, LOW);  // Apaga o amarelo
  digitalWrite(carRed, HIGH);    // Acende o vermelho
  delay(1000);                   // Espera 1 segundo por segurança

  digitalWrite(pedRed, LOW);     // Apaga o vermelho dos pedestres
  digitalWrite(pedGreen, HIGH);  // Acende o verde dos pedestres

  delay(crossTime);              // Espera o tempo predefinido para travessia

  // Pisca 10x o verde dos pedestres
  for (int x=0; x<10; x++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  digitalWrite(pedRed, HIGH);    // Acende o vermelho dos pedestres
  delay(500);

  digitalWrite(carYellow, HIGH); // Acende o amarelo
  digitalWrite(carRed, LOW);     // Apaga o vermelho
  delay(1000);
  
  digitalWrite(carGreen, HIGH);  // Acende o verde
  digitalWrite(carYellow, LOW);  // Apaga o amarelo

  changeTime = millis(); // Registra o tempo desde a última alteração do semáforo
}
