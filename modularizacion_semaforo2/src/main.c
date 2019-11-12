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
#include "main.h"
#include "semaforo.h"

/*=====[Macros de definición de constantes privadas]=========================*/

//EDU-CIAA NXP V1.1 primer tirada
#define edu_ciaa_v_1_1_0

/*=====[Definiciones de variables globales externas]=========================*/


/*=====[Definiciones de variables globales publicas]=========================*/
uint32_t contadorGlobal=0;


/*=====[Definiciones de variables globales privadas]=========================*/



/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
   // ----- Configuraciones -------------------------

	boardInit();
	inicializarSemaforo_MEF();

    // ----- Repetir por siempre ---------------------
   while(TRUE) {
   actualizarSemaforo_MEF();

   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}























