// * CAPÍTULO II: PUERTOS DIGITALES
//* CÓDIGO 3: Manejo de ciclos de programación con puertos entrada salida
// * Objetivo: Encender y apagar leds en dependencia con botones y switchs
// *           No necesita librerías
//* Funciones de programación:           
//*           pinMode(pin, MODO) 
// *                        MODO-> INPUT/OUTPUT
//*           digitalRead(pin)             
//*           delay(ms)
// *                 ms-> tiempo en milisegundos
//*/
#define led1 8  // uso de #define que no su puede alterar su valor
#define boton1 2 // uso de #define para entrada digital del pin 7
#define boton2 3 // uso de #define para entrada digital del pin 6

int led2=9;    // variable normal, no recomendable
const int led3=10; //variable constante, recomendable
const int sw = 4; // uso de constante para entrada digital del pin 5

int i=0; //contador de ciclo if

void setup() {
pinMode(led1,OUTPUT); // pin8 declarado como salida
pinMode(led2,OUTPUT); // pin9 declarado como salida
pinMode(led3,OUTPUT); // pin10 declarado como salida
pinMode(boton1,INPUT); // entrada digital del pin 7
pinMode(boton2,INPUT); // entrada digital del pin 6
pinMode(sw,INPUT); // entrada digital del pin 5
}

void loop() {
// programa que enciende un led mediante la activación de un switch
if(digitalRead(sw)==HIGH){ // condición que active el sw en alto
  digitalWrite(led1,HIGH); // Envía 5 voltios a pin 8
  }else{
    digitalWrite(led1,LOW); // Envía 0 voltios a pin 8
  }

//enciende un led al presionat el botón y se apaga al presionar nuevamente el botón
if(digitalRead(boton1)==LOW){ // condición que active el boton en bajo
  delay(200); // delay antirebotes
  i=1-i; // condicón booleana 
  if(i==0) 
    digitalWrite(led2,HIGH); // Envía 5 voltios a pin 9
  }else{
    digitalWrite(led2,LOW); // Envía 0 voltios a pin 9
 }

//enciende un led al presionat el botón y se apaga al presionar nuevamente el botón
 if(digitalRead(boton2)==HIGH){ // condición que active el boton en alto
   delay(200);  // delay antirebotes
    digitalWrite(led3, !digitalRead(led3)); //Función de toggle
    }
  
}