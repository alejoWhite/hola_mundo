
#include "max6675.h"             // incluimos la libreria para manejar el modulo de la termocupla
#include <LiquidCrystal.h>       // incluimos la libreria de la lcd
LiquidCrystal lcd(7,6,5,4,3,2);  // definimos los pines que usa la lcd
float temp=0;                    // se crea una variable tipo float para guardar el valor de la temperatura

int ktcSO = 11;                   // se asigna el pin 11 como entrada del pin ktcsO de la termocupla.
int ktcSC = 12;                    // se asigna el pin 12 como entrada del pin ktcsC de la termocupla.
int ktcCLK = 13;                   // se asigna el pin 13 como entrada del pin ktCLK de la termocupla.

MAX6675 ktc(ktcCLK,ktcSC,ktcSO);     // se llama la funcion que leera la termocupla.
int salida = 22;                     // creamos una variable salida asignada al pin 22, 
int alarma = 9;                      // creamos una variable alarma asignada al pin 9
int alarma_2 =8;                    // creamos una variable alarma_2 asignada al pin 8, 
void setup() {
  
 
lcd.begin(16,2);                   // se inicializa la lcd, y se especifica que es 16x2, primero columnas y luego filas
Serial.begin(9600);               //  se inicia la cominicacion para el monitor serial
delay(500);                       // retardo de medio segundo.

 pinMode(salida, OUTPUT);          // se declara la variable salida, como salida
    pinMode(alarma, OUTPUT);         // se declara la variable alarma, como salida
     pinMode(alarma_2, OUTPUT);         // se declara la variable alarma_2, como salida
}
 
void loop() {                           // lazo del programa principal

  lcd.setCursor(0,0);                   // se pone el cursor en la pocision 0,0 el primero es la columna y el segundo la fila
  lcd.print("CONTROL DE");
 lcd.setCursor(0,1);
 lcd.print("TEMPERATURA");
delay(4000);
lcd.clear();
lcd.setCursor(0,0);
 lcd.print("LA TEMPERATURA");
  lcd.setCursor(0,1);
 lcd.print("SE REGULARA A:");
 delay(3000);

lcd.clear();
lcd.setCursor(0,0);
 lcd.print("40");
    lcd.print( (char)223);
    lcd.print("C");

delay(2000);


while(temp < 600){
  
    
   lcd.setCursor(0,0);
    lcd.print("TEMPERATURA REAL:");
    lcd.setCursor(0,1);
    lcd.print(temp );
    lcd.print( (char)223);
    lcd.print("C");

        delay(500);
  // put your main code here, to run repeatedly:
temp=ktc.readCelsius();  
delay(500);
    
    
if(temp >= 90){

  digitalWrite(alarma,HIGH);
  digitalWrite(alarma_2,LOW);
  digitalWrite(salida,HIGH);
}
if(temp <= 40){

  digitalWrite(alarma,LOW);
  digitalWrite(alarma_2,HIGH);
  digitalWrite(salida,LOW);
}
}
}