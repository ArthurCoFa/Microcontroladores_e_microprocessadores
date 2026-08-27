int pinLatch = 8;
int pinClock = 12;
int pinDado = 11;
int i;

void setup() {
  pinMode(pinLatch, OUTPUT);
  pinMode(pinClock, OUTPUT);
  pinMode(pinDado, OUTPUT);
}

void loop() {
  for (i = 0; i < 256; i++) {
    digitalWrite(pinLatch, LOW);
    shiftOut(pinDado, pinClock, LSBFIRST, i);
    digitalWrite(pinLatch, HIGH);
    
    delay(200);
  }
}