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
#include "secuencia_giro.h"


/*=====[Macros de definición de constantes privadas]=========================*/

#define PI 3.1415f
//#define tiempo_ensayo 300
/*=====[Definiciones de variables globales externas]=========================*/

int i;

/*=====[Definiciones de variables globales publicas]=========================*/

int var = 0;

/*=====[Definiciones de variables globales privadas]=========================*/

//static delay_t tiempoEnsayo;

/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
   // ----- Configuraciones -------------------------
   boardInit();
   inicializar_bobinas_MEF();
   // ----- Repetir por siempre ---------------------
   while(TRUE) {

   actualizar_bobinas_MEF();
   }



   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}



















