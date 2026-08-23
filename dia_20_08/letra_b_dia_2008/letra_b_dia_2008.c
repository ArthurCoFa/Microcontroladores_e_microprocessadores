//////////////////////////////////////////////////////////////////////////////////////
// Código para acender LEDs das extremidades até o centro e apagar de forma inversa //
//////////////////////////////////////////////////////////////////////////////////////

byte vet[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Portas na qual os LEDs estão conectados com o arduino
int i = 0, j = 9; // Variáveis para usar no loop FOR

void setup(){ // Função para inicializar e configurar o programa
	pinMode(vet, OUTPUT); // Indicando as portas onde sairá o digitalWrite
	Serial.begin(9600); // Inicialização do comando de comunicação serial do Arduino
}

void loop(){ // Função para rodar o programa em loop
	while(i <= 9 && j >= 0){ // Vai rodar o programa enquanto i não estiver na última porta e j na primeira
		if(i < 5 && j > 4){ // if para ligar LEDs das extremidades até o centro
			digitalWrite(vet[i++], HIGH); // Liga o LED pelo "lado" esquerdo, utiliza i depois adiciona 1 na variável
			digitalWrite(vet[j--], HIGH); // Liga o LED pelo "lado" direito, utiliza j depois retira 1 na variável
			delay(200); // Delay entre acendimento dos LEDs
		}
		else{ // else para apagar os LEDs do centro até a extremidade 
			digitalWrite(vet[i++], LOW); // Apaga o LED pelo "lado" direito, utiliza i depois adiciona 1 na variável
			digitalWrite(vet[j--], LOW); // Apaga o LED pelo "lado" esquerdo, utiliza j depois reitra 1 na variável 
			delay(200); // Delay entre o apagamento dos LEDs
		}
	}
	i = 0; // Variável volta para o valor original
	j = 9; // Variável volta para o valor original
}