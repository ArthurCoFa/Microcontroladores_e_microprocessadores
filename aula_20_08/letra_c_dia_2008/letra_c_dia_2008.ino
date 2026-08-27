byte vet[10]={4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int i, j;

void setup() {
  pinMode(vet, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for(i = 9; i >= 0; i--){ 
    for(j = 0; j <= i; j++){
      digitalWrite(vet[j], HIGH);
      delay(100);
    }
    for(j = i; j >= 0; j--){
      digitalWrite(vet[j], LOW);
      delay(100);
    }
  }
}