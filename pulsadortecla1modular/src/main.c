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

#include "../inc/MEFTEC.h"
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
   mefTeclaInit(); // inicializacion de MEF tecla 1

   // ----- Repetir por siempre ---------------------
   while(TRUE) {
	   mefTeclaactual(TEC1); //actualiza tecla 1
	   //mefTeclaactual(TEC2);
   }


   return 0;
}





















