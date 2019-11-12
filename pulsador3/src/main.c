/*=====[Nombre del programa]===================================================
 Lee un pulsador, en este caso el TEC1 ,cada vez que se pulsa prende led 3 y cuenta las veces que fue pulsado,
 cuando se logro pulsar tres veces titila los led rgb
 */



#include "sapi.h"
#include "main.h"

//int32_t cont=0;
//int32_t numero;
bool_t valor1,valor2;
bool_t estado1=FALSE,estado2=FALSE;
int main (void)
{
   // ----- Configuraciones -------------------------

	boardInit();

    // ----- Repetir por siempre ---------------------
   while(TRUE) {
	 valor1=!gpioRead(TEC1);
     valor2=!gpioRead(TEC2);
	 if (valor1){
		 estado1=!estado1;
		 gpioWrite(LED1,estado1);
		 delay(250);
	 }
	 if (valor2){
	 		 estado2=!estado2;
	 		 gpioWrite(LED2,estado2);
	 		 delay(250);
	 	 }

   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;

}






















