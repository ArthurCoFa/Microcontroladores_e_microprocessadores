#include <LiquidCrystal.h>

////////////////////////////////////////////////////////////////////////
// Código que usa um potenciômetro para fazer uma barra de progressão //
////////////////////////////////////////////////////////////////////////

#include <Wire.h> // Biblioteca comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca comunicação com o display 16x2

#define col 16 // define numero de colunas do display
#define lin  2 // define numero de linhas do display
#define ende  0x27 // define endereço do display.

int transPin = 9;
int potValue = 0;

LiquidCrystal_I2C lcd(ende,col,lin); 
// função LiquidCrystal para ser usada com o I2C

byte acende[] = { B11000, B11100, B11110, B11111, B11111, B11110, B11100, B11000 };

void setup() {
  lcd.init(); // iniciar a comunicação com o display
  lcd.backlight(); // liga a luz do display
  lcd.clear(); // limpa a tela do display
  Serial.begin(9600);
}

void loop() {
  createGlyphDemo();
  barraProgressao();
  potValue = analogRead(A0) / 4;
  Serial.println(potValue);
  analogWrite(transPin, potValue);
}

void createGlyphDemo() {
  lcd.clear(); 
  // Cria um array de bytes com uma cara feliz
  lcd.createChar(0, acende); // Cria o caractere personalizado 0
} 

void barraProgressao(){

  if(potValue >= 0 && potValue <16)
  {
    lcd.setCursor(0,1);
    lcd.write(byte (0));
  }
  if(potValue >= 16 && potValue <32)
  {
    for(int i=0;i<2;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }
  if(potValue >= 32 && potValue <48)
  {
    for(int i=0;i<3;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 48 && potValue <64)
  {
    for(int i=0;i<4;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 64 && potValue <80)
  {
    for(int i=0;i<5;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 80 && potValue <96)
  {
    for(int i=0;i<6;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 96 && potValue <112)
  {
    for(int i=0;i<7;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 112 && potValue <128)
  {
    for(int i=0;i<8;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 128 && potValue <144)
  {
    for(int i=0;i<9;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 144 && potValue <160)
  {
    for(int i=0;i<10;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 160 && potValue <176)
  {
    for(int i=0;i<11;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 176 && potValue <192)
  {
    for(int i=0;i<12;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 192 && potValue <208)
  {
    for(int i=0;i<13;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 208 && potValue <224)
  {
    for(int i=0;i<14;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 224 && potValue <240)
  {
    for(int i=0;i<15;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }

  if(potValue >= 240 && potValue <256)
  {
    for(int i=0;i<16;i++)
    {   
      lcd.setCursor(i,1);
      lcd.write(byte (0));
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Velocidade:");
  lcd.print(potValue);
  delay(200); 
  lcd.clear(); 
}