/*=====[Nombre del programa]===================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 * sirve para entender las estructuras de maquinas de estado anidadas
 * consiste en mientras se mantiene apretado el pulsador TEC1 , los leds rojo y verde
 * parpadean alternativamente (dado como diagrama de estados de ejemplo
 */

/*=====[Inclusiones de dependencias de funciones]============================*/

#include "sapi.h"

/*=====[Macros de definición de constantes privadas]=========================*/

#define retardo 50000

typedef enum {
	nada,
	verde,
	rojo,
}estados_leds ;

int main (void)
{
	// ----- Configuraciones -------------------------
	boardInit();

	static estados_leds estadoLeds;
	static estados_leds estado_actual=nada;
	static estados_leds proximo_estado=nada;
	int8_t fin_tiempo;
	volatile int32_t temporizando;

	fin_tiempo=0;
	temporizando=0;




	// ----- Repetir por siempre ---------------------
	while(TRUE) {
		//Tarea 1

		if (temporizando>0){
			temporizando--;
			fin_tiempo=0;
		}
		else
			fin_tiempo=1;

		switch (estado_actual){
		case nada:
			gpioWrite(LED1,OFF);
			gpioWrite(LED2,OFF);

			if (!gpioRead(TEC1)){
				proximo_estado=verde;
			}
			break;
		case verde:
			gpioWrite(LED1,OFF);
			gpioWrite(LED2,ON);
			if (gpioRead(TEC1)){
				proximo_estado=nada;
			}
			else if (fin_tiempo) {
				proximo_estado=rojo;
			}
			break;
		case rojo:
			gpioWrite(LED1,ON);
			gpioWrite(LED2,OFF);
			if (gpioRead(TEC1)){
				proximo_estado=nada;
			}
			else if (fin_tiempo) {
				proximo_estado=verde;
			}
			break;
		}

if (estado_actual!=proximo_estado){
	if (proximo_estado!=nada){
		temporizando=retardo;
	}
		estado_actual=proximo_estado;
}
}




// NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
// directamenteno sobre un microcontrolador y no es llamado por ningun
// Sistema Operativo, como en el caso de un programa para PC.
return 0;
}






















