//Módulo RF 433 MHz Controlando LEDs a distancia
//Por GE Projetos e Tutoriais

#include <RH_ASK.h> //Biblioteca Radiohead
#include <SPI.h> 

//Definimos os pinos dos Leds

// Declaramos uma variavel RH_ASK que sera nosso receptor rf
RH_ASK receptor;
 
void setup()
{
  // Definimos os leds como saidas
  // Inicializamos o receptor
  receptor.init();
}
 
void loop()
{
    // Definimos como 11 caracteres o tamanho da mensagem esperada
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    // Checamos se a mensagem recebida possui o tamanho correto
    if (receptor.recv(buf, &buflen))
    {
      //Ligamos o led que corresponde a mensagem recebida
      if((char*)buf[0] == '1') {
        digitalWrite(ledVerde,!digitalRead(ledVerde));
      }
      if((char*)buf[0] == '3') {
        digitalWrite(ledAmarelo,!digitalRead(ledAmarelo));
      }
      if((char*)buf[0] == '2') {
        digitalWrite(ledVermelho,!digitalRead(ledVermelho));
      }    
    }
}
