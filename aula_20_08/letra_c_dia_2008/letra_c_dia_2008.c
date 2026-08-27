///////////////////////////////////////////////////////////////////////////////////////
// Código para acender LEDs em sequência e parando de acender 1 até nenhuma acender, //
// parecido com uma bola quicando 													 //
///////////////////////////////////////////////////////////////////////////////////////

byte vet[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Portas na qual os LEDs estão conectados com o arduino
int i, j; // Variáveis para usar no loop FOR

void setup(){ // Função para inicializar e configurar o programa
	pinMode(vet, OUTPUT); // Indicando as portas onde sairá o digitalWrite
	Serial.begin(9600); // Inicialização do comando de comunicação serial do Arduino
}

void loop(){ // Função para rodar o programa em loop
	for(i = 9; i >= 0; i--){ // FOR para controlar a parada no último LED de acendimento
		for(j = 0; j <= i; j++){ // FOR para ligar os LEDs até o desejado
			digitalWrite(vet[j], HIGH); // Ligar o LED na porta j
			delay(200); // Delay entre o acendimento dos LEDs
		}
		for(j = i; j >= 0; j--){ // FOR para apagar os LEDs desejados
			digitalWrite(vet[j], LOW); // Apaga o LED na porta j
			delay(200); // Delay entre o apagamento dos LEDs
		}
	}
}