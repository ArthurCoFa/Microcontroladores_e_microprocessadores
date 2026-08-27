//////////////////////////////////////////////////////
// NÃO TESTADO EM LABORATÓRIO, SOMENTE NO TINKERCAD //
//////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
// Código para ligar os LEDs e apagar em ordem inversa com 74HC595 //
/////////////////////////////////////////////////////////////////////

int pinLatch = 8;  // Pino 8 do arduino no pino 12 do 74HC595 (ST_CP)
int pinClock = 12; // Pino 12 do arduino no pino 11 do 74HC595 (SH-CP)
int pinDado = 11; // Pino 11 do arduino no pino 14 do 74HC595 (DS)
int contador[9] = {0, 1, 3, 7, 15, 31, 63, 127, 255};

void setup() {
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinDado, OUTPUT);
}

void loop() {
  for (int i = 0; i < 9; i++) {
    // Ligando os leds nas posições decimais 1, 3, 5 e assim por diante
    digitalWrite(pinLatch, LOW); // Garantindo que o estado esteja LOW para segurar as saídas anteriores
    shiftOut(pinDado, pinClock, LSBFIRST, contador[i]); 
	// Envia byte atual [i] de forma serial ligando através do bit menos significativo
    digitalWrite(pinLatch, HIGH); // Faz o Latch ficar HIGH para transferir os dados para memória do 74HC595
    delay(300);
  }
  delay(2000);
  for (int i = 8; i >= 0; i--){
    digitalWrite(pinLatch, LOW);
    shiftOut(pinDado, pinClock, LSBFIRST, contador[i]);
    digitalWrite(pinLatch, HIGH);
    delay(300);
  }
}