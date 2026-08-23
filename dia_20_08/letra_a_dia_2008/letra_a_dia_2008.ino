byte vet[10]={4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

void setup() {
  pinMode(vet, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(int i = 0; i < 10; i++){
    digitalWrite(vet[i], HIGH);
    delay(200);
  }
  for(int i = 9; i > 0; i--){
    digitalWrite(vet[i], LOW);
    delay(200);
  }  
}