/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 6: Manejo de display 7 segmentos multiplexados cátodo común con decodificador
 *           7447
 * Objetivo: Se registra las veces que se presiona un pulsador de 0 a 20
 * Funciones : Puertos salida
 */

 const int A=8; // pin 8 conectado a decodificador
 const int B=9; // pin 9 conectado a decodificador
 const int C=10; // pin 10 conectado a decodificador
 const int D=11; // pin 11 conectado a decodificador
 const int dis1=3; // pin de activación display unidades
 const int dis2=2; // pin de activación display decenas
 const int boton=7; //pin 7 configurado como entrada
 int uni=0;
 int dec=0;
 

 int cont=0; //variable de conteo a observar

void setup(){
  pinMode(A,OUTPUT); // pin8 declarado como salida
  pinMode(B,OUTPUT); // pin9 declarado como salida
  pinMode(C,OUTPUT); // pin10 declarado como salida
  pinMode(D,OUTPUT); // pin11 declarado como salida
  pinMode(dis1,OUTPUT); // pin11 declarado como salida
  pinMode(dis2,OUTPUT); // pin11 declarado como salida
  pinMode(boton,INPUT); // pin11 declarado como entrada
}

void loop(){
if(digitalRead(boton)==HIGH){ // condición que active el sw en alto
  delay(200);                 // delay anti-rebotes
  if(cont<=20){               // conteo máximo a visualizar
    cont++;                   //incremento de variable 
    if(cont<10){              // condición de unidades
      uni=cont;               //asignación a variable unidad
      }
      else{                   // condición para variables de decenas y unidades
       uni=cont-dec*10;       //asignar número de unidades a variable adecuada
       dec=cont/10;           //asignar número de decenas a variable adecuada
       
       }
    }
    else                      //concidición límite de conteo 
    cont=0;                   // reinicio de variable
  }
  digitalWrite(dis1,HIGH);    //enceder display unidades
  digitalWrite(dis2,LOW);     //apagar display decenas
  segmentos(uni);             //llamar a método para visualizar número
  delay(200);                 //tiempo de visualización
  digitalWrite(dis1,LOW);     //apagar display unidades
  digitalWrite(dis2,HIGH);    //encender display decenas
  segmentos(dec);             //llamar a método para visualizar número
  delay(200);                 //tiempo de visualización   
}
 
void segmentos (int i){
   switch(i){
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