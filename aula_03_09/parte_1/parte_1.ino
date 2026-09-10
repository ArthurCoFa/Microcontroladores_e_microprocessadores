/////////////////////////////////////////////////////////
// Código para controlar sentido e velocidade do motor //
/////////////////////////////////////////////////////////

int pinBotao = 2; // Pino onde do Arduino onde está o botão, que muda o sentido do motor
int pinLD = 9; // Pino onde está o controle de velocidade do motor
int val = 0; // Variável para guardar o valor do potenciômetro
int IN1 = 3;
int IN2 = 4;
// IN1 e IN2 são variáveis para mudança do sentido do motor

void setup() {
  pinMode(pinBotao, INPUT); // Configura botão como entrada
  pinMode(pinLD, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Configura saídas de dados 
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0); // Lê o valor do potenciômetro
  analogWrite(pinLD, val); // Controla velocidade do motor de acordo com o potenciômetro
  Serial.println(val); // Escreve o valor do potenciômetro no Serial Monitor
  int valorBotao = digitalRead(pinBotao); // Lê se o botão foi apertado ou não
  Serial.println(valorBotao); // Escreve se o botão foi pressionado ou não
  if(valorBotao == 0){ // Se o botão não foi apertado o motor gira no sentido horário
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else { // Se foi apertado gira no sentido anti-horário
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }
}