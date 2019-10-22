/*=====[Nombre del programa]===================================================
 Lee un pulsador, en este caso el TEC1 ,cada vez que se pulsa prende led 3 y cuenta las veces que fue pulsado,
 cuando se logro pulsar tres veces titila los led rgb
 */



#include "sapi.h"
#include "main.h"

//int32_t cont=0;
//int32_t numero;
bool_t valor;

int main (void)
{
   // ----- Configuraciones -------------------------

	boardInit();
	delay_t ledDelay;

	delayConfig( &ledDelay, 500 );

    // ----- Repetir por siempre ---------------------
   while(TRUE) {
	   valor = !gpioRead( TEC1 );
	   	        gpioWrite( LED1, valor );

	   if( delayRead(&ledDelay) ){
	          gpioToggle( LED2 );
 
      }
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;

}






















