// Projeto 07 - Lâmpada pulsante

byte ledPin = 11;
float sinVal;
int ledVal;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  for (byte x; x<180; x++) {
    // Converte graus para radianos e, então, obtém o valor do seno
    sinVal = (sin(x*(3.1416/180)));
    ledVal = int(sinVal*255);
    analogWrite(ledPin, ledVal);
    delay(25);
  }
}
