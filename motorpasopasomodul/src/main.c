/*=====[motor paso-paso]===================================================
 * Copyright Sebastian Herrera <sebastianh74@hotmail.com.ar.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.1
 * Fecha de creacion: 2019/10/10
 */

/*=====[Inclusiones de dependencias de funciones]============================*/
#include "sapi.h"
#include "secuencia_giro.h"
#include "tecla.h"
/*=====[Macros de definición de constantes privadas]=========================*/
#define tiempo_giro_inverso 300
/*=====[Definiciones de variables globales externas]=========================*/
int i;
/*=====[Definiciones de variables globales publicas]=========================*/

/*=====[Definiciones de variables globales privadas]=========================*/


/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
	// ----- Configuraciones -------------------------
	boardInit();
	inicializar_bobinas_MEF();
	inicializar_tecla ();
	// ----- Repetir por siempre ---------------------
	while(TRUE) {
		actualizar_tecla();
		actualizar_bobinas_MEF();

	}



	// NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
	// directamenteno sobre un microcontrolador y no es llamado por ningun
	// Sistema Operativo, como en el caso de un programa para PC.
	return 0;
}



















