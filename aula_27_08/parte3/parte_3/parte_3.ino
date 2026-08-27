int pinLatch = 8;
int pinClock = 12;
int pinDado = 11;
int i;

void setup() {
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinDado, OUTPUT);
}

void loop() {
  for (i = 0; i < 8; i++) {
    // Ligando os leds nas posições decimais 1, 3, 5 e assim por diante
  }
  for (i = 7; i >= 0; i--){
    // Apagando na ordem inversa do primeiro for
  }
}