/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 5: Manejo de display 7 segmentos ánodo común con decodificador
 *           7447
 * Objetivo: Representar los números del 0 al 9 en un display 7 segmentos.
 * Funciones : Puertos salida
 */

 const int A=8; // pin 8 conectado a decodificador 
 const int B=9; // pin 9 conectado a decodificador
 const int C=10; // pin 10 conectado a decodificador
 const int D=11; // pin 11 conectado a decodificador

 int cont; //varaible de conteo a observar

void setup(){
  pinMode(A,OUTPUT); // pin8 declarado como salida
  pinMode(B,OUTPUT); // pin9 declarado como salida
  pinMode(C,OUTPUT); // pin10 declarado como salida
  pinMode(D,OUTPUT); // pin11 declarado como salida
}

void loop(){

  for(cont=0;cont<10;cont++){ //conteo de 0 al 9
    delay(1000); // tiempo de visualización
     switch(cont){
        case 0:
          digitalWrite(A,LOW); //Envía 0 voltios a pin 8
          digitalWrite(B,LOW); //Envía 0 voltios a pin 9
          digitalWrite(C,LOW); //Envía 0 voltios a pin 10
          digitalWrite(D,LOW); //Envía 0 voltios a pin 11
        break;
        case 1:
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 2:
          digitalWrite(A,LOW);  //Envía 0 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 3:
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 4:
          digitalWrite(A,LOW);  //Envía 0 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 5:
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 6:
          digitalWrite(A,LOW);  //Envía 0 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 7:
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
        break;
        case 8:
          digitalWrite(A,LOW); //Envía 0 voltios a pin 8
          digitalWrite(B,LOW); //Envía 0 voltios a pin 9
          digitalWrite(C,LOW); //Envía 0 voltios a pin 10
          digitalWrite(D,HIGH); //Envía 5 voltios a pin 11
        break;
        case 9:
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,HIGH); //Envía 5 voltios a pin 11
        break;
      }
    }
    
}