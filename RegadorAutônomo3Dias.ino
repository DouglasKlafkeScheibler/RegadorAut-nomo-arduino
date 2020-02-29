#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>
#define motor 3
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF
#define __CS 10
#define __DC 12
#define red 4 
#define blue 5 
#define green 6 
unsigned long delay1=0;

//musica mario
int portSpeak(9);  //porta ligada no speaker
int melodia[] = {660,660,660,510,660,770,380};
int duracaodasnotas[] = {100,100,100,100,100,100,100};

//display
TFT_ILI9163C tft = TFT_ILI9163C(__CS,8, __DC);

//sensor boia
int pinosensor = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(13, OUTPUT);//buzzer
  pinMode (RED, OUTPUT); 
  pinMode (BLUE, OUTPUT); 
  pinMode (GREEN, OUTPUT);
  pinMode (red, OUTPUT); 
  pinMode (blue, OUTPUT); 
  pinMode (green, OUTPUT);
   
  tft.begin();
  desliga();
}

void loop() 
{
  Motor();
  Tela();
  NivelAgua();
}
void Motor()
{
  if ((millis() - delay1) >= 0 && (millis() - delay1) < 20000)
  {
       tft.clearScreen(BLUE);
       tft.setCursor(0, 0);
       tft.setTextColor(RED,CYAN);  
       tft.setTextSize(3);
       tft.println("Regando");   
       analogWrite(motor,255);
       delay(1000);
       
  }
    if ((millis() - delay1) >= 20000 && (millis() - delay1) < 60000)
  {
       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(WHITE);  
       tft.setTextSize(2);
       tft.println("Esperando");
       tft.setTextColor(CYAN);
       tft.println(" agua");
       tft.setTextColor(WHITE);
       tft.println(" baixar");
       analogWrite(motor,0);
       delay(1000);
  }
    if ((millis() - delay1) >= 60000 && (millis() - delay1) < 80000)
  {
       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(GREEN,BLUE);  
       tft.setTextSize(3);
       tft.println("Regando");
       analogWrite(motor,255);
       delay(1000);
       
  }
    if ((millis() - delay1) >= 80000)
  {
       analogWrite(motor,0);
  }
    if (( millis() - delay1) > 259200000)
  {
       delay1 = millis();
  }
}
void Tela()
{
    if ((millis() - delay1) >= 91000 && (millis() - delay1) < 86400000)
  {
       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(WHITE);  
       tft.setTextSize(2);
       tft.println(" Faltando");
       tft.setTextSize(4);
       tft.println("  3");
       tft.setTextSize(2);
       tft.println(" dias para regar");
       delay(3000);   
  }
    if ((millis() - delay1) >= 86400000 && (millis() - delay1) < 172800000)
  {
       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(WHITE);  
       tft.setTextSize(2);
       tft.println(" Faltando");
       tft.setTextSize(4);
       tft.println("  2");
       tft.setTextSize(2);
       tft.println(" dias para regar");
       delay(3000);      
  }
    if ((millis() - delay1) >= 172800000 && (millis() - delay1) < 257400000)
  {

       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(WHITE);  
       tft.setTextSize(2);
       tft.println(" Faltando");
       tft.setTextSize(4);
       tft.println("  1");
       tft.setTextSize(2);
       tft.println(" dias para regar");
       delay(3000);
      
  }
    if ((millis() - delay1) >= 257400000 && (millis() - delay1) < 258900000)
  {
       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(WHITE,RED);  
       tft.setTextSize(2);
       tft.println(" Faltando");
       tft.setTextSize(4);
       tft.println("  30");
       tft.setTextSize(2);
       tft.println(" minutos para regar");
       delay(3000);   
  }
    if ((millis() - delay1) >= 258900000 && (millis() - delay1) < 259200000)
  {
       tft.clearScreen();
       tft.setCursor(0, 0);
       tft.setTextColor(WHITE,GREEN);  
       tft.setTextSize(2);
       tft.println(" Faltando");
       tft.setTextSize(4);
       tft.println("  5");
       tft.setTextSize(2);
       tft.println(" minutos para regar");
       delay(3000);   
  }
}

void NivelAgua()
{
int estado = digitalRead(pinosensor);
Serial.print("Estado sensor :");
Serial.println(estado);
Serial.print("");
switch(estado)
{
  case 0:
    Serial.print("com agua\n\n");
    break;

  
  case 1:
    Serial.print("sem agua\n\n");
    Red();
    Blue();
    Green();
    Turquesa();
    VermelhoVerde();
    Violeta();
    Branco();
    Mario();
    break;
}
delay(250);
}

void Red()
{
   analogWrite(red, 0);
   analogWrite(green, 255);
   analogWrite(blue, 255);
   delay(250);
   desliga();
}
void Blue()
{
   analogWrite(red, 255);
   analogWrite(green, 255);
   analogWrite(blue, 0);
   delay(250);
   desliga();
}
void Green()
{
   analogWrite(red, 255);
   analogWrite(green, 0);
   analogWrite(blue, 255);
   delay(250);
   desliga();
}
void Turquesa()
{
   analogWrite(red, 255);
   analogWrite(green, 0);
   analogWrite(blue, 0);
   delay(250);
   desliga();
}
void VermelhoVerde()
{
   analogWrite(red, 0);
   analogWrite(green, 0);
   analogWrite(blue, 255);
   delay(250);
   desliga();
}
void Violeta()
{
   analogWrite(red, 0);
   analogWrite(green, 255);
   analogWrite(blue, 0);
   delay(250);
   desliga();
}
void Branco()
{
   analogWrite(red, 0);
   analogWrite(green, 0);
   analogWrite(blue, 0);
   delay(250);
   desliga();
}
void desliga()
{
   analogWrite(red, 255);
   analogWrite(green, 255);
   analogWrite(blue, 255);
}
void Mario()
{
        for (int nota = 0; nota < 7; nota++) {

              int duracaodanota = duracaodasnotas[nota];
              tone(portSpeak, melodia[nota],duracaodanota);
              //pausa depois das notas
              int pausadepoisdasnotas[] ={150,300,300,100,300,550,575};
              delay(pausadepoisdasnotas[nota]);}

              noTone(portSpeak);
}

