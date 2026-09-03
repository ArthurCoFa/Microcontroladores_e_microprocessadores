int pinBotao = 2;
int pinLD = 9;
int val = 0;
int IN1 = 3;
int IN2 = 4;

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
  Serial.println(val);
  int valorBotao = digitalRead(pinBotao);
  Serial.println(valorBotao);
  if(valorBotao == 0){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else {
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }
}
