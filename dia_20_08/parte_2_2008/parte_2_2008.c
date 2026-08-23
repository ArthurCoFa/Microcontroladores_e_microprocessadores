///////////////////////////////////////////////////////////////////////////////////////
// Código para acender LEDs controlando velocidade e tom do buzzer com potenciômetro //
///////////////////////////////////////////////////////////////////////////////////////

byte vet[10] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Portas na qual os LEDs estão conectados com o arduino
int i; // Variável para usar no loop FOR
int analogPin = 2; // Porta que está o potenciômetro
int val = 0; // Variável que vai ler o potenciômetro
int buzz = 2; // Porta que está o buzzer 

void setup(){ // Função para inicializar e configurar o programa
	pinMode(vet, OUTPUT); // Indicando as portas onde sairá o digitalWrite
	Serial.begin(9600); // Inicialização do comando de comunicação serial do Arduino
}

void loop(){ // Função para rodar o programa em loop
	val = analogRead(analogPin); // Leitura do valor do potenciômetro
	Serial.println(val); // Imprimindo o valor do potenciômetro no Serial Monitor
	for(i = 0; i < 10; i++){ // FOR para acender os LEDs
		digitalWrite(vet[i], HIGH); // Acendendo o LED na porta i
		delay(val); // Delay para acender de acordo com o valor no potenciômetro
	}
	for(i = 9; i > 0; i--){ // FOR para apagar os LEDs
		digitalWrite(vet[i], LOW); // Apagando o LED na porta i
		delay(val); // Delay para apagar de acordo com o potenciômetro
	}
	tone(buzz, val); // Frequência do som do buzzer de acordo com o potenciômetro
}