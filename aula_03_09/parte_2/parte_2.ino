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
  if(valorBotao == 0){
    digitalWrite(pinLed, HIGH);
    digitalWrite(pinLed_2, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
    digitalWrite(pinLed_2, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }

  if(val/4 < 170){
    digitalWrite(pinLed_5, HIGH);
    digitalWrite(pinLed_4, LOW);
    digitalWrite(pinLed_3, LOW);
  } else if(170 >= val/4 && val/4 <= 200){
    digitalWrite(pinLed_5, HIGH);
    digitalWrite(pinLed_4, HIGH);
    digitalWrite(pinLed_3, LOW);
  } if(val/4 > 200) {
    digitalWrite(pinLed_5, HIGH);
    digitalWrite(pinLed_4, HIGH);
    digitalWrite(pinLed_3, HIGH);
  }
}