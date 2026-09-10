////////////////////////////////////////////////
// Código para parte 2 com integração de LEDs //
////////////////////////////////////////////////

int pinBotao = 2;
int pinLD = 9;
int val = 0;
int IN1 = 3;
int IN2 = 4;
int pinLed = 5;
int pinLed_2 = 6;
int pinLed_3 = 11;
int pinLed_4 = 8;
int pinLed_5 = 10;
// Pinos dos 5 LEDs

void setup() {
  pinMode(pinBotao, INPUT);
  pinMode(pinLD, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  analogWrite(pinLD, val);
  Serial.println(val/4);
  int valorBotao = digitalRead(pinBotao);
  if(valorBotao == 0){ // Se o botão não for apertado
    digitalWrite(pinLed, HIGH); // LED liga
    digitalWrite(pinLed_2, LOW); // LED apaga
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH);
  } else { // Se o botão for apertado
    digitalWrite(pinLed, LOW); // LED apaga 
    digitalWrite(pinLed_2, HIGH); // LED liga
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }

  if(val/4 < 170){ // Se o valor do potenciômetro < 170
    digitalWrite(pinLed_5, HIGH); 
    digitalWrite(pinLed_4, LOW);
    digitalWrite(pinLed_3, LOW);
	// Somente 1 LED liga
  } else if(170 >= val/4 && val/4 <= 200){ 
  // Se o valor do potenciômetro estiver entre 170 e 200
    digitalWrite(pinLed_5, HIGH);
    digitalWrite(pinLed_4, HIGH);
    digitalWrite(pinLed_3, LOW);
  // 2 LEDs ligam
  } if(val/4 > 200) { // Se o valor do potenciômetro > 200
    digitalWrite(pinLed_5, HIGH);
    digitalWrite(pinLed_4, HIGH);
    digitalWrite(pinLed_3, HIGH);
	// Todos os LEDs ligam
  }
}