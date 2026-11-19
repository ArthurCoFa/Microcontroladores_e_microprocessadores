#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup() {
  Serial.begin(9600);
  if (!driver.init()) {
    Serial.println("Falha na inicialização do driver");
  }
}

void loop() {
  // Add +1 to leave room for the null terminator '\0'
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN + 1]; 
  uint8_t buflen = RH_ASK_MAX_MESSAGE_LEN;

  if (driver.recv(buf, &buflen)) {
    buf[buflen] = '\0'; // Marks the exact end of the message
    Serial.print("Mensagem recebida: ");
    Serial.println((char *)buf);
  }
}
