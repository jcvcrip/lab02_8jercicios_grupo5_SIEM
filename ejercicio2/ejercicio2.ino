 /* CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 2: Manejo de ciclos de programación con puertos entrada salida
 * Objetivo: Uso de ciclos while, if, for
 *           No necesita librerías
 * Funciones de programación:           
 *           if (condición){instrucciones}
 *           else{intruscciones}
 *           
 *           while(condición){
 *           instrucción
 *           }
 *           
 *           for(inicio de varaible, condición, tipo de aumento)
 *           {instrucciones
 *           
 *           }
 */
#define led1 8 // uso de #define que no su puede alterar su valor
int led2=9;    // variable normal, no recomendable
const int led3=10; //variable constante, recomendable

int i=1; //contador de ciclo if
int j=0; // contador de ciclo while
int k; //contador de ciclo for

void setup() {
pinMode(led1,OUTPUT); // pin8 declarado como salida
pinMode(led2,OUTPUT); // pin9 declarado como salida
pinMode(led3,OUTPUT); // pin10 declarado como salida
}

void loop() {

//ciclo if, el led1 se prende 9 veces cada 500 ms
if(i<10){ //condición de ciclo if
   digitalWrite(led1,HIGH); //Envía 5 voltios a pin 8
   delay(500); // se detiene microncontrolador por medio segundo
   digitalWrite(led1,LOW); //Envía 0 voltios a pin 8
   delay(500); // se detiene microncontrolador por medio segundo
   i++; // aumento de variable i=i+1;
  }

// ciclo while, el led2 se enciende y apaga 10 veces cada 400 ms
while(j<10){ // condición de ciclo while
  j++; //aumento de variable
   digitalWrite(led2,HIGH); //Envía 5 voltios a pin 9
   delay(500); // se detiene microncontrolador por medio segundo
   digitalWrite(led2,LOW); //Envía 0 voltios a pin 9
   delay(500); // se detiene microncontrolador por medio segundo
  }

//ciclo for, led 3 se enciende y apaga 11 veces cada 500 ms
 for(k=0;k<=10;k++){ //condiciones de ciclo for
   digitalWrite(led3,HIGH); //Envía 5 voltios a pin 10
   delay(500); // se detiene microncontrolador por medio segundo
   digitalWrite(led3,LOW);  //Envía 0 voltios a pin 10
   delay(500); // se detiene microncontrolador por medio segundo
  }
}
