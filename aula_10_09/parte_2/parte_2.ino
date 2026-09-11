////////////////////////////////////////////////////////////////////////
// Código que usa um potenciômetro para fazer uma barra de progressão //
////////////////////////////////////////////////////////////////////////

#include <Wire.h> // Biblioteca comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca comunicação com o display 16x2

#define col 16 // define numero de colunas do display
#define lin  2 // define numero de linhas do display
#define ende  0x27 // define endereço do display.

// int val = 0;

LiquidCrystal_I2C lcd(ende,col,lin); 
// função LiquidCrystal para ser usada com o I2C

byte acende[] = { B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };
byte apaga[] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };

void setup() {
  lcd.init(); // iniciar a comunicação com o display
  lcd.backlight(); // liga a luz do display
  lcd.clear(); // limpa a tela do display
}

void loop() {
  barraProgressao();
};

void barraProgressao(){

  int c = 0; // Coluna na qual vai acender ou apagar o bloco

  for(int x = 0; x < 256; x += 16, c++){
    lcd.createChar(0, acende);
    lcd.setCursor(c, 1);
    lcd.write(0);
    delay(200);
  }
  for(int x = 256, c = 16; x >= 0; x -= 16, c--){
    lcd.createChar(1, apaga);
    lcd.setCursor(c, 1);
    lcd.write(1);
    delay(200);
  }  
}