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



/*=====[Macros de definición de constantes privadas]=========================*/



/*=====[Definiciones de variables globales externas]=========================*/

int var;

/*=====[Definiciones de variables globales publicas]=========================*/

int var = 0;

/*=====[Definiciones de variables globales privadas]=========================*/

//static int var = 0;

/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/



/*==================[inclusions]=============================================*/

#include "sapi.h"              // <= sAPI header

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/* FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET. */
int main(void){

   /* ------------- INICIALIZACIONES ------------- */

   /* Inicializar la placa */
   boardConfig();

   /* Variable de Retardo no bloqueante */
   delay_t delay;

   /* Inicializar Retardo no bloqueante con tiempo en milisegundos
      (500ms = 0,5s) */
   delayConfig( &delay, 500 );

   int8_t i = 3;
   uint8_t sequence = 0;

   /* ------------- REPETIR POR SIEMPRE ------------- */
   while(1) {

      if ( !gpioRead( TEC1 ) ){
         sequence = 0;
      }
      if ( !gpioRead( TEC2 ) ){
         /* Velocidad Rapida */
         delayWrite( &delay, 150 );
      }
      if ( !gpioRead( TEC3 ) ){
         /* Velocidad Lenta */
         delayWrite( &delay, 750 );
      }
      if ( !gpioRead( TEC4 ) ){
         sequence = 1;
      }

      /* delayRead retorna TRUE cuando se cumple el tiempo de retardo */
      if ( delayRead( &delay ) ){
         if ( !sequence ){
            i--;
         }
         else{
            i++;
         }
      }

      if ( i == 0 ){
         gpioWrite( LEDB, ON );
         gpioWrite( LED1, OFF );
         gpioWrite( LED2, OFF );
         gpioWrite( LED3, OFF );
      }
      if ( i == 1 ){
         gpioWrite( LEDB, OFF );
         gpioWrite( LED1, ON );
         gpioWrite( LED2, OFF );
         gpioWrite( LED3, OFF );
      }
      if ( i == 2 ){
         gpioWrite( LEDB, OFF );
         gpioWrite( LED1, OFF );
         gpioWrite( LED2, ON );
         gpioWrite( LED3, OFF );
      }
      if ( i == 3 ){
         gpioWrite( LEDB, OFF );
         gpioWrite( LED1, OFF );
         gpioWrite( LED2, OFF );
         gpioWrite( LED3, ON );
      }

      if ( i < 0 ){
         i = 3;
      }
      if ( i > 3 ){
         i = 0;
      }

   }

   /* NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa no es llamado
      por ningun S.O. */
   return 0 ;
}

/*==================[end of file]============================================*/

















