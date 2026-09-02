////////////////////////////////////////////////////////////
// Código para ligar os LEDs de forma binária com 74HC595 //
////////////////////////////////////////////////////////////

// O CI 74HC595 gera o sinal para os LEDs quando seu Latch muda de LOW para HIGH

int pinLatch = 8;  // Pino 8 do arduino no pino 12 do 74HC595 (ST_CP)
int pinClock = 12; // Pino 12 do arduino no pino 11 do 74HC595 (SH-CP)
int pinDado = 11; // Pino 11 do arduino no pino 14 do 74HC595 (DS)

void setup() {
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinDado, OUTPUT);
  // Configuração dos pinos de controle do registrador como saídas
}

void loop() {
  for (int i = 0; i < 256; i++) { // Loop em decimal de 0 a 255 que será convertido em byte no shiftOut()
    digitalWrite(pinLatch, LOW); // Garantindo que o estado esteja LOW para segurar as saídas anteriores
    shiftOut(pinDado, pinClock, LSBFIRST, i); 
	// Envia byte atual [i] de forma serial ligando através do bit menos significativo
    digitalWrite(pinLatch, HIGH); // Faz o Latch ficar HIGH para transferir os dados para memória do 74HC595
    
    delay(200);
  }
}