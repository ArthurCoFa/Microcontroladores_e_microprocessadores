byte ledPin[8] = {6, 7, 8, 9, 10, 11, 12, 13};
int dado, biti, bitshow;

void setup() {
  for(int i = 0; i < 8; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  for(dado = 0; dado < 256; dado++){
    for(biti = 0; biti < 8; biti++){
      bitshow = bitRead(dado, biti);
      digitalWrite(ledPin[biti], bitshow);
      delay(10);
    }
  } 
  delay(5000);
}