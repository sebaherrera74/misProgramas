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

#define PI 3.1415f

/*=====[Definiciones de variables globales externas]=========================*/

int var;

/*=====[Definiciones de variables globales publicas]=========================*/

int var = 0;

/*=====[Definiciones de variables globales privadas]=========================*/

//static int var = 0;

/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
	// ----- Configuraciones -------------------------
	boardInit();
	gpioConfig( GPIO1, GPIO_OUTPUT );
	gpioConfig( GPIO2, GPIO_OUTPUT );
	gpioConfig( GPIO3, GPIO_OUTPUT );
	gpioConfig( GPIO4, GPIO_OUTPUT );
	// ----- Repetir por siempre ---------------------
	while(TRUE) {
		gpioWrite(GPIO1,ON);
		gpioWrite(GPIO2,OFF);
		gpioWrite(GPIO3,OFF);
		gpioWrite(GPIO4,OFF);
		delay(150);
		gpioWrite(GPIO1,OFF);
		gpioWrite(GPIO2,ON);
		gpioWrite(GPIO3,OFF);
		gpioWrite(GPIO4,OFF);
		delay(150);
		gpioWrite(GPIO1,OFF);
		gpioWrite(GPIO2,OFF);
		gpioWrite(GPIO3,ON);
		gpioWrite(GPIO4,OFF);
		delay(150);
		gpioWrite(GPIO1,OFF);
		gpioWrite(GPIO2,OFF);
		gpioWrite(GPIO3,OFF);
		gpioWrite(GPIO4,ON);
		delay(150);
	}

	// NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
	// directamenteno sobre un microcontrolador y no es llamado por ningun
	// Sistema Operativo, como en el caso de un programa para PC.
	return 0;
}


















