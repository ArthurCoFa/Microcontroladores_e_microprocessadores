#include <Servo.h> //Inclusão da biblioteca Servo

Servo servomotor; //Criando objeto do tipo Servo de nome servomotor

int pos = 0;//Variável que armazena a posição do servo (ângulo)
int pinButton = 4;
int pinLaser = 2;
int pinLed = 6;
int pinBuzzer = 5;

void setup(){
  pinMode(pinButton, INPUT);
  pinMode(pinLaser, OUTPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  servomotor.attach(9);//Atribui o pino digital 9 ao objeto servomotor
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  int ldr = analogRead(A2);
  int estadoButton = digitalRead(pinButton);
  
  Serial.println(ldr);
  
  if (estadoButton == HIGH){
    digitalWrite(pinLaser, HIGH);
  } else {
    digitalWrite(pinLaser, LOW);
  }
  
  if (ldr <= 50) {
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinBuzzer, HIGH);
  } else {
    digitalWrite(pinBuzzer, LOW);
  }

  if (val <= 512) {
    servomotor.write(val / 5.7);// Comanda o servo para ir para o posição da variável pos
    delay(15);//Intervalo de 15 milissegundos
  }
  else {
    servomotor.write(val / 5.7);//Comanda o servo para ir para a posição da variável pos
    delay(15);// Intervalo de 15 milissegundos
  }
}