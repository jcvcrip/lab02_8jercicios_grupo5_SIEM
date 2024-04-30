/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 4: Manejo de ciclos de programación con puertos entrada-salida
 * Objetivo: Encender y apagar leds en dependencia con botones y switchs
 *           en relación a ciclos de programación.
 */
#define sw 5 // uso de #define para entrada digital del pin 7
#define boton 7// uso de #define para entrada digital del pin 7

const int leds [6]={8,9,10,11,12,13};

int i=0; //contador de ciclo for
int j=0; // contador de ciclo if
int bin=0;

// metodo de incialización
void setup() {
//configuración de pines como salida
for(i=0;i<6;i++){
    pinMode(leds[i],OUTPUT);
  }
i=0;  
pinMode(boton,INPUT); // entrada digital del pin 7
pinMode(sw,INPUT); // entrada digital del pin 6
}

//ciclo infinito mientras el arduino este funcionando
void loop() {
 while(digitalRead(sw)==HIGH){ // condición que active el sw en alto
  //Los leds se encienden y apagan secuencialmente
    for(i=0;i<6;i++){ // ciclo de juego de leds, recorre desde 0 a 5, son 6 posiciones
        digitalWrite(leds[i],HIGH); //Envía 5v en la posición de i
        delay(200); // se detiene microncontrolador por medio segundo
        digitalWrite(leds[i],LOW); //Envía 0v en la posición de i
        delay(200); // se detiene microncontrolador por medio segundo
      }
  }

//contador binario de 6 bits ->64 en decimal
  if(digitalRead(boton)==LOW){ // condición que active el boton en bajo
    delay(300); // delay antirebotes
     bin=0; // condición de variable binaria
      j++; // contador binario
      PORTB=bin|j; // función AND asginada a puerto B.
      }
}