/* Ejemplo de lectura e interpretación de comandos
 *  para el control remoto http://bit.ly/1lUhInA
 *  based on code by Ken Shirriff - http://arcfn.com
 */

#include "IRremote.h"

/*-----( Declarar constantes )-----*/
int receiver = 11; // Pin del IR receiver para el pin digital del Arduino digital 11

/*-----( Declarar objetos )-----*/
IRrecv irrecv(receiver);           // crea la instancia de 'irrecv'
decode_results results;            // crea la instancia de 'decode_results'
/*-----( Declarar variables )-----*/


void setup()   /*----( SETUP: Se ejecuta una vez )----*/
{
  Serial.begin(9600);
  Serial.println("Ejercicio IR para leer y decodificar datos");
  irrecv.enableIRIn(); // Inicia el receptor

}/*--(end setup )---*/


void loop()   /*----( LOOP: Se ejecuta constantemente )----*/
{
  if (irrecv.decode(&results)) // Verifica si se han recibido señales IR

  {
//    Serial.println(results.value, HEX);  Se descomenta para ver los valores en formato RAW
    translateIR(); 
    irrecv.resume(); // Recibe el siguiente valor
  }  
}/* --(end main loop )-- */

/*-----( Declare funciones del usuario )-----*/
void translateIR() // toma acciones basadas en el codigo del IR

// describe los códigos del control remoto

{

  switch(results.value)

  {

  case 0xFF22DD:  
    Serial.println(" PREV           "); 
    break;

  case 0xFF02FD:  
    Serial.println(" NEXT           "); 
    break;

  case 0xFFC23D:  
    Serial.println(" PLAY/PAUSE     "); 
    break;

  default: 
    Serial.println(" por favor ingrese otro comando    ");

  }

  delay(500);


} //END translateIR



/* ( THE END ) */
