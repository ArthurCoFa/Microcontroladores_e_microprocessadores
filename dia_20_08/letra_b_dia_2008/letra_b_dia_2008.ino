byte vet[10]={4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int i = 0, j = 9;

void setup() {
  pinMode(vet, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(i <= 9 && j >= 0){
    if(i < 5 && j > 4){ 
      digitalWrite(vet[i++], HIGH);
      //delay(100);
      digitalWrite(vet[j--], HIGH);
      delay(100);
    }
    else{
      digitalWrite(vet[i++], LOW);
      //delay(100);
      digitalWrite(vet[j--], LOW);
      delay(100);
    }
  }
  i = 0;
  j = 9;
}