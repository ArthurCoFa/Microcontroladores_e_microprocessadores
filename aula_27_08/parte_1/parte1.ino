////////////////////////////////////////////////
// Código para ligar os LEDs de forma binária //
//////////////////////////////////////////////// 

byte ledPin[8] = {6, 7, 8, 9, 10, 11, 12, 13}; // Pinos onde os LEDs estão ligados

int dado; 	 // Variável para os valores em decimal que serão convertidos em binários
int biti;    // Variável para percorrer os 8 bits
int bitshow; // Variável que armazena o valor do bit a partir do 'dado'

void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(ledPin[i], OUTPUT); // Configura os pinos como saída digital
  }
}

void loop() {
  for(dado = 0; dado < 256; dado++){ // Loop de contagem de 0 a 255
    for(biti = 0; biti < 8; biti++){ // Loop de contagem do bit (pino do LED)
      bitshow = bitRead(dado, biti); // Lê o estado do bit atual da variável 'dado' na posição 'biti'
      digitalWrite(ledPin[biti], bitshow); // Acende ou apaga o LED correspondente à posição do bit
      delay(100); // Delay de acendimento do LED
    }
  } 
  delay(5000); // Delay de 5 segundos antes de reinicar a contagem
}