#include <LiquidCrystal.h>

#define diaPOT A0
#define mesPOT A1
#define led_vermelho 13
#define led_amarelo 9
#define led_verde 6

int leds[] = {led_vermelho, led_amarelo, led_verde};
String produto[] = {"leite","manteiga","queijo"};
int dia_val[] = {5, 12, 30};
int mes_val[] = {2, 9, 5};

int tempo_antecedencia = 10;

LiquidCrystal LCD (5, 4, 3, 2, A4, A5); // LCD nos pinos 13, 12, 5, 4, 3 e 2

void setup()
{
  Serial.begin(9600);
  pinMode(diaPOT, INPUT);
  pinMode(mesPOT, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  LCD.begin(16,2);
}

void loop()
{
  int dia_atual = analogRead(diaPOT);
  int mes_atual = analogRead(mesPOT);
  
  dia_atual = dia_atual*30/1023;
  mes_atual = mes_atual*12/1023;
  
  int data_atual = (mes_atual - 1)*30+dia_atual;
  
  for(int i = 0; i < 3; i++)
  {
    int data_val = (mes_val[i] - 1)*30+dia_val[i];
    
    if(data_atual >= data_val - tempo_antecedencia
      && data_atual <= data_val)
    {
      digitalWrite(leds[i], HIGH);
    }
    else
    {
      digitalWrite(leds[i], LOW);
    }
  } 
  
  //PRINT LCD
  LCD.clear();
  LCD.print("data_atual: ");
  LCD.print(data_atual);
}