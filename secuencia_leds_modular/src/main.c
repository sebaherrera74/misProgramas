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

#include "main.h"
#include "sapi.h"
#include "secuencia.h"
/*=====[Macros de definición de constantes privadas]=========================*/


/*=====[Definiciones de variables globales externas]=========================*/



/*=====[Definiciones de variables globales publicas]=========================*/



/*=====[Definiciones de variables globales privadas]=========================*/

static int var = 0;

/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
   // ----- Configuraciones -------------------------
   boardInit();
   inicializar_secuencia();
   // ----- Repetir por siempre ---------------------

   while(TRUE) {
   actualizar_secuencia_mef();


   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
























