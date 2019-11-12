/*=====[Nombre del programa]===================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*=====[Inclusiones de dependencias de funciones]============================*/

#include "sapi.h"

/*=====[Macros de definición de constantes privadas]=========================*/

/*=====[Definiciones de variables globales externas]=========================*/

/*=====[Definiciones de variables globales publicas]=========================*/

/*=====[Definiciones de variables globales privadas]=========================*/


/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
   // ----- Configuraciones -------------------------
   boardInit();
    gpioConfig( GPIO1, GPIO_OUTPUT );
   	gpioConfig( GPIO2, GPIO_OUTPUT );
   	gpioConfig( GPIO3, GPIO_OUTPUT );
	gpioConfig( GPIO4, GPIO_OUTPUT );
	gpioConfig( GPIO5, GPIO_OUTPUT );
	gpioConfig( GPIO6, GPIO_OUTPUT );

   // ----- Repetir por siempre ---------------------
   while(TRUE) {

	   gpioWrite(GPIO1,0);
	   gpioWrite(GPIO2,0);
	   gpioWrite(GPIO3,0);
	   gpioWrite(GPIO4,0);
	   gpioWrite(GPIO5,1);
       gpioWrite(GPIO6,0);
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}














