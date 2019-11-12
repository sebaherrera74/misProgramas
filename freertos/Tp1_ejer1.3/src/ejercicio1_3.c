
/*==================[inlcusiones]============================================*/

// Includes de FreeRTOS
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "debouncetecla.h"
// sAPI header
#include "sapi.h"

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

DEBUG_PRINT_ENABLE;

/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/
TickType_t get_diff();
void clear_diff();

// Prototipo de funcion de la tarea
void tarea_led( void* taskParmPtr );
void tarea_tecla( void* taskParmPtr );
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
			tarea_led,                     // Funcion de la tarea a ejecutar
			(const char *)"tarea_led",     // Nombre de la tarea como String amigable para el usuario
			configMINIMAL_STACK_SIZE*2, // Cantidad de stack de la tarea
			0,                          // Parametros de tarea
			tskIDLE_PRIORITY+1,         // Prioridad de la tarea
			0                           // Puntero a la tarea creada en el sistema
	);

	xTaskCreate(
			tarea_tecla,                     // Funcion de la tarea a ejecutar
			(const char *)"tarea_tecla",     // Nombre de la tarea como String amigable para el usuario
			configMINIMAL_STACK_SIZE*2, // Cantidad de stack de la tarea
			0,                          // Parametros de tarea
			tskIDLE_PRIORITY+1,         // Prioridad de la tarea
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


// Implementacion de funcion de la tarea led
void tarea_led( void* taskParmPtr )
{
	// ---------- CONFIGURACIONES ------------------------------

	// ---------- REPETIR POR SIEMPRE --------------------------
	while(TRUE) {

		TickType_t dif=get_diff();
		if (dif==0){
			vTaskDelay(40/portTICK_RATE_MS);
		}
		else{
			gpioWrite(LEDB,1);
			vTaskDelay(dif);
			gpioWrite(LEDB,0);
			clear_diff();

		}
	}
}
void tarea_tecla( void* taskParmPtr )
{
	mefbotonInit();

	// ---------- REPETIR POR SIEMPRE --------------------------
	while(TRUE) {

		actualizacionTecla(TEC1);
		vTaskDelay(1/portTICK_RATE_MS);
	}
}

/*==================[fin del archivo]========================================*/
