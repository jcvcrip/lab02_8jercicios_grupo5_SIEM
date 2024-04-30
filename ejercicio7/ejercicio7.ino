/*
 * CAPÍTULO II: PUERTOS DIGITALES
 * CÓDIGO 7: Manejo de LCD y envío de mensajes 
 * Objetivo: Se usa métodos para imprimir mensajes y ciclos condicionales
 * Funciones : librería LiquidCrystial.h
 *             LiquidCrystal ( )       Inicializa la interfaz de la pantalla LCD
 *             begin(columnas, filas)  Configura uso de LCD
 *             print(data)             Imprime texto en la LCD   
 *             setCursor(columa, fila) Posiciona el cursos en la LCD
 */

 #include <LiquidCrystal.h> // Librería LCD

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);  // selección de pines para LCD

const char vector [7]={'y','a',' ','v','a','l','e'}; // vector de impresión en LCD
int i;     // variable que recorre el vector
void setup() {
  lcd.begin(16, 2);   // inicializa la LCD
}

void loop() {
  lcd.setCursor(0, 0);       //selecciona posición en LCD
  lcd.print("HOLA");         //imprime dato 
  for(i=0;i<7;i++){          //ciclo de recorrido en vector
    lcd.setCursor(i,1);      //selecciona posición en LCD
    lcd.print(vector[i]);    //imprime posición del vector seleccionado
    delay(200);              // tiempo de visualización
    }
    lcd.clear();             //borrar LCD
}