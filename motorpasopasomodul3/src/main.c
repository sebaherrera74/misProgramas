/*=====[motor paso-paso]===================================================
 * Copyright Sebastian Herrera <sebastianh74@hotmail.com.ar.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 * Version: 0.0.1
 * Fecha de creacion: 2019/10/10
  /*========================================================================================================
  * Programa que realiza lo siguiente, al pulsar la tecla 1 de la edu-ciaa activa las cuatro bobinas de un
  * motor paso a paso, al mismo tiempo toma muestras de entrada analogica del CH01.
  * Esto lo realiza en el lapso de 10 segundos (En el proyecto este tiempo debe durar 2 minutos)
  ===============================================================================================  */
/*=====[Inclusiones de dependencias de funciones]============================*/
#include "sapi.h"
#include "secuencia_giro.h"
#include "tecla.h"
#include "adc.h"
/*=====[Macros de definición de constantes privadas]=========================*/

/*=====[Definiciones de variables globales externas]=========================*/

/*=====[Definiciones de variables globales publicas]=========================*/

/*=====[Definiciones de variables globales privadas]=========================*/


/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
	// ----- Configuraciones -------------------------

	boardInit();                            //Inicializo placa edu ciaa,tecla 1,bobinas del motor paso a paso
	inicializar_bobinas_MEF();             //y lecturas analogicas
	inicializar_tecla ();
	inicializar_lectura_analogica();

	// ----- Repetir por siempre ---------------------

	while(TRUE) {
		actualizar_tecla();
		actualizar_bobinas_MEF();
		actualiza_lectura_analogica();

	}



	// NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
	// directamenteno sobre un microcontrolador y no es llamado por ningun
	// Sistema Operativo, como en el caso de un programa para PC.
	return 0;
}



















