/////////////////////////////////////////////////////////////////////
// Código para acender LEDs em sequência e apagar de forma inversa //
/////////////////////////////////////////////////////////////////////

byte vet[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Portas na qual os LEDs estão conectados com o arduino
int i; // Variável para usar no loop FOR

void setup(){ // Função para inicializar e configurar o programa
	pinMode(vet, OUTPUT); // Indicando as portas onde sairá o digitalWrite
	Serial.begin(9600); // Inicialização do comando de comunicação serial do Arduino
}

void loop(){ // Função para rodar o programa em loop
	for(i = 0; i < 10; i++){ // FOR para ligar os LEDs em sequência
		digitalWrite(vet[i], HIGH); // Acende o LED na porta i
		delay(200); // Delay de 200 ms para cada acendimento de LED
	}
	for(i = 9; i >= 0; i--){ // FOR para apagar os LEDs na ordem inversa de acendimento
		digitalWrite(vet[i], LOW); // Apaga o LED na porta i
		delay(200); // Delay de 200 ms para cada apagamento de LED
	}
}