

/*==================[inlcusiones]============================================*/

// Includes de FreeRTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"

// sAPI header
#include "sapi.h"

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

int16_t tiempo_led=100;
/*==================[definiciones de datos externos]=========================*/

DEBUG_PRINT_ENABLE;

/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/

// Prototipo de funcion de la tarea
void Tarea1( void* taskParmPtr );
void Tarea2( void* taskParmPtr );

/*==================[funcion principal]======================================*/

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main(void)
{
   // ---------- CONFIGURACIONES ------------------------------
   // Inicializar y configurar la plataforma
   boardConfig();

   // UART for debug messages
   debugPrintConfigUart( UART_USB, 115200 );
   debugPrintlnString( "Blinky con freeRTOS y sAPI." );
   // Led para dar señal de vida
   gpioWrite( LED3, ON );


   // Crear tarea en freeRTOS
   xTaskCreate(
      Tarea1,                     // Funcion de la tarea a ejecutar
      (const char *)"ejer1.2",     // Nombre de la tarea como String amigable para el usuario
      configMINIMAL_STACK_SIZE*2, // Cantidad de stack de la tarea
      0,                          // Parametros de tarea
      tskIDLE_PRIORITY+1,         // Prioridad de la tarea
      0                           // Puntero a la tarea creada en el sistema
   );
   xTaskCreate(
         Tarea2,                     // Funcion de la tarea a ejecutar
         (const char *)"ejer1.1.2",     // Nombre de la tarea como String amigable para el usuario
         configMINIMAL_STACK_SIZE*2, // Cantidad de stack de la tarea
         0,                          // Parametros de tarea
         tskIDLE_PRIORITY+2,         // Prioridad de la tarea
         0                           // Puntero a la tarea creada en el sistema
      );

   // Iniciar scheduler
   vTaskStartScheduler();

   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
      // Si cae en este while 1 significa que no pudo iniciar el scheduler
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

// Implementacion de funcion de la tarea
void Tarea1( void* taskParmPtr )
{
   // ---------- CONFIGURACIONES ------------------------------
   printf( "Blinky con freeRTOS y sAPI.\r\n" );

   gpioWrite( LED1, ON );
   // Envia la tarea al estado bloqueado durante 1 s (delay)
   vTaskDelay( 1000 / portTICK_RATE_MS );
   gpioWrite( LED1, OFF ); 

   // Tarea periodica cada 1000 ms
   portTickType xPeriodicity =  1000 / portTICK_RATE_MS;
   portTickType xLastWakeTime = xTaskGetTickCount(); //funcion que da el valor del contador interno del tick
                                                     //,referencia del tiempo que toma el while (TRUE)
   
   // ---------- REPETIR POR SIEMPRE --------------------------
   while(TRUE) {
	  if(tiempo_led<=900){
      gpioWrite(LED2,1);
      vTaskDelay( tiempo_led / portTICK_RATE_MS );
      gpioWrite(LED2,0);
      tiempo_led=tiempo_led+100;

	 }
	 else{
	  tiempo_led=100;
	}/* Copyright 2017-2018, Eric Pernia
 * All rights reserved.
 *
 * This file is part of sAPI Library.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
	  // Envia la tarea al estado bloqueado durante xPeriodicity (delay periodico)
	        vTaskDelayUntil( &xLastWakeTime, xPeriodicity );  //
   }
}

void Tarea2( void* taskParmPtr )
{
   // ---------- CONFIGURACIONES ------------------------------
   // Envia la tarea al estado bloqueado durante 1 s (delay)

   // Tarea periodica cada 1000 ms
   portTickType xPeriodicity =  1000 / portTICK_RATE_MS;
   portTickType xLastWakeTime = xTaskGetTickCount(); //funcion que da el valor del contador interno del tick
                                                     //,referencia del tiempo que toma el while (TRUE)

   // ---------- REPETIR POR SIEMPRE --------------------------
   while(TRUE) {
      gpioWrite(LEDB,1);
      vTaskDelay( 50 / portTICK_RATE_MS );
      gpioWrite(LEDB,0);

	   // Envia la tarea al estado bloqueado durante xPeriodicity (delay periodico)
	        vTaskDelayUntil( &xLastWakeTime, xPeriodicity );  //
   }


}


/*==================[fin del archivo]========================================*/
