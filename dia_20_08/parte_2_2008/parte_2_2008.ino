byte vet[10]={4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int analogPin = 2;
int val = 0;
int buzz = 2;
int tom = 1000;

void setup() {
  pinMode(vet, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);
  Serial.println(val);
  for(int i = 0; i < 10; i++){
    digitalWrite(vet[i], HIGH);
    delay(val);
  }
  for(int i = 9; i > 0; i--){
    digitalWrite(vet[i], LOW);
    delay(val);
  }  
  tone(buzz, val);
}