#include <Servo.h> //Inclusão da biblioteca Servo
Servo servomotor; //Criando objeto do tipo Servo de nome servomotor
int pos = 0;//Variável que armazena a posição do servo (ângulo)
void setup(){
  servomotor.attach(9);//Atribui o pino digital 9 ao objeto servomotor
  Serial.begin(9600);
}
void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  if (val <= 512) {
    servomotor.write(val / 5.7);// Comanda o servo para ir para o posição da variável pos
    delay(15);//Intervalo de 15 milissegundos
  }
  else {
    servomotor.write(val / 5.7);//Comanda o servo para ir para a posição da variável pos
    delay(15);// Intervalo de 15 milissegundos
  }
}