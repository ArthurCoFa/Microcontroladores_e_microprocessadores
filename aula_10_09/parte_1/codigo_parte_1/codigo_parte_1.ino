#include <Wire.h> // Biblioteca comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca comunicação com o display 16x2

#DEFINE col 16 // Define numero de colunas do display
#DEFINE lin  2 // Define numero de linhas do display
#DEFINE ende  0x27 // Define endereço do display.

LiquidCrystal_I2C lcd(ende,col,lin); // função LiquidCrystal para ser usada com o I2C

byte name0x0[] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte name1x0[] = { B11011, B11011, B11011, B11011, B11011, B11011, B11111, B11111 };
byte name1x1[] = { B00000, B00000, B00000, B10110, B11001, B10001, B10001, B10001 };
byte name1x2[] = { B00000, B00000, B00100, B00000, B01100, B00100, B00100, B01110 };
byte name1x3[] = { B01110, B11111, B11001, B11000, B11000, B11001, B11111, B01110 };
byte name1x4[] = { B11111, B11111, B10000, B11111, B11111, B10000, B11111, B11111 };
byte name1x5[] = { B11011, B11011, B11011, B11011, B11011, B11011, B11111, B11111 };
byte name1x6[] = { B11110, B10011, B10011, B11110, B11110, B10011, B10011, B11110 };
// Pixels de cada letra formando a palavra UNICEUB na linha 1 totalmente a esquerda

byte name0x9[] = { B11011, B11011, B11011, B11011, B11011, B11011, B11111, B11111 };
byte name0x10[] = { B00000, B00000, B00000, B10110, B11001, B10001, B10001, B10001 };
byte name0x11[] = { B00000, B00000, B00100, B00000, B01100, B00100, B00100, B01110 };
byte name0x12[] = { B01110, B11111, B11001, B11000, B11000, B11001, B11111, B01110 };
byte name0x13[] = { B11111, B11111, B10000, B11111, B11111, B10000, B11111, B11111 };
byte name0x14[] = { B11011, B11011, B11011, B11011, B11011, B11011, B11111, B11111 };
byte name0x15[] = { B11110, B10011, B10011, B11110, B11110, B10011, B10011, B11110 };
// Pixels de cada letra formando a palavra UNICEUB na linha 0 totalmente a direta

void setup() {
  lcd.init(); // Iniciar a comunicação com o display
  lcd.backlight(); // Liga a luz do display
  lcd.clear(); // Limpa a tela do display
}

void loop() {
  rodarDireitaCeub();
  delay(1000);
  rodarEsquerdaCeub();
};

void imprimirCeub(){
  // Função para imprimir o nome UniCEUB com caracteres personalizados
  lcd.begin(16, 2);
  
  lcd.createChar(0, name0x0);
  lcd.write(0);
  
  lcd.createChar(1, name1x0);
  lcd.setCursor(0, 1);
  lcd.write(1);
  
  lcd.createChar(2, name1x1);
  lcd.setCursor(1, 1);
  lcd.write(2);
  
  lcd.createChar(3, name1x2);
  lcd.setCursor(2, 1);
  lcd.write(3);
  
  lcd.createChar(4, name1x3);
  lcd.setCursor(3, 1);
  lcd.write(4);
  
  lcd.createChar(5, name1x4);
  lcd.setCursor(4, 1);
  lcd.write(5);
  
  lcd.createChar(6, name1x5);
  lcd.setCursor(5, 1);
  lcd.write(6);
  
  lcd.createChar(7, name1x6);
  lcd.setCursor(6, 1);
  lcd.write(7);

  delay(2000);

  lcd.clear();
}

void rodarDireitaCeub() { 
  // Função que faz o nome UniCEUB percorrer a linha 1 para a direita até sumir
  lcd.clear(); // Limpa o display 

  lcd.begin(16, 2);
  
  lcd.createChar(0, name0x0);
  lcd.write(0);
  
  lcd.createChar(1, name1x0);
  lcd.setCursor(0, 1);
  lcd.write(1);
  
  lcd.createChar(2, name1x1);
  lcd.setCursor(1, 1);
  lcd.write(2);
  
  lcd.createChar(3, name1x2);
  lcd.setCursor(2, 1);
  lcd.write(3);
  
  lcd.createChar(4, name1x3);
  lcd.setCursor(3, 1);
  lcd.write(4);
  
  lcd.createChar(5, name1x4);
  lcd.setCursor(4, 1);
  lcd.write(5);
  
  lcd.createChar(6, name1x5);
  lcd.setCursor(5, 1);
  lcd.write(6);
  
  lcd.createChar(7, name1x6);
  lcd.setCursor(6, 1);
  lcd.write(7);
  
  for(int x=0; x<16; x++) { 
    lcd.scrollDisplayRight(); // Rola o display 16 vezes para a direita 
    delay(250); 
  } 
} 

void rodarEsquerdaCeub(){
  // Função que faz o nome UniCEUB percorrer a linha 1 para a direita até sumir
  lcd.clear(); // Limpa o display 

  lcd.begin(16, 2);
  
  lcd.createChar(0, name0x0);
  lcd.write(0);
  
  lcd.createChar(1, name0x9);
  lcd.setCursor(9, 0);
  lcd.write(1);
  
  lcd.createChar(2, name0x10);
  lcd.setCursor(10, 0);
  lcd.write(2);
  
  lcd.createChar(3, name0x11);
  lcd.setCursor(11, 0);
  lcd.write(3);
  
  lcd.createChar(4, name0x12);
  lcd.setCursor(12, 0);
  lcd.write(4);
  
  lcd.createChar(5, name0x13);
  lcd.setCursor(13, 0);
  lcd.write(5);
  
  lcd.createChar(6, name0x14);
  lcd.setCursor(14, 0);
  lcd.write(6);
  
  lcd.createChar(7, name0x15);
  lcd.setCursor(15, 0);
  lcd.write(7);

  for(int x=0; x<16; x++) { 
    lcd.scrollDisplayLeft(); // Rola o display 16 vezes para a direita 
    delay(250); 
  }   
}