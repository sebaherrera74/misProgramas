/*
 * Copyright Sebastian Herrera <sebastianh74@hotmail.com.ar.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 * Version: 0.0.1
 * Fecha de creacion: 2019/10/10*/

/*=====[Inclusion de su propia cabecera]=====================================*/

#include "debouncetecla.h"

#include "sapi.h"
#include "FreeRTOS.h"


/*=====[Macros de definicion de constantes privadas]=========================*/
#define tiempo_antirebote  40      // tiempo de 40 milisegundos
             // defino tecla1 como pulsadorde incio

/*=====[Macros estilo funcion privadas]======================================*/


/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
	estado_up,
	estado_raising,
	estado_down,
	estado_falling,
} mef_tec_estado;


// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/


/*=====[Definiciones de Variables globales publicas]=========================*/


/*=====[Definiciones de Variables globales privadas]=========================*/

mef_tec_estado estadoTecla;
TickType_t tiempo_down;
TickType_t tiempo_up;
TickType_t tiempo_diff;



/*=====[Prototipos de funciones privadas]====================================*/

static void botonPresionado(void);
static void botonLiberado(void);



/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


/*=====[Implementaciones de funciones publicas]==============================*/

TickType_t get_diff(){
	return tiempo_diff;
}
void clear_diff(){
	tiempo_diff=0;
}

// accion de el evento de tecla pulsada
static void botonPresionado(void){
	tiempo_down=xTaskGetTickCount();

}

static void botonLiberado(void){
	tiempo_up=xTaskGetTickCount();
	tiempo_diff=tiempo_up-tiempo_down;
}


void mefbotonInit(void) {
	estadoTecla=estado_up; //inicializo el estado de teclas
}
void mefbotonError(void){
	estadoTecla=estado_up;
}


void actualizacionTecla(gpioMap_t tecla){
	static bool_t flagRising=FALSE;
	static uint8_t contfalling=0;
	static uint8_t contrising=0;



	switch (estadoTecla){

	case estado_up:
		if (!gpioRead(tecla)){
			estadoTecla=estado_falling;
		}
		break;

	case estado_falling :
		if (contfalling>=tiempo_antirebote){
			if (!gpioRead(tecla)){
				estadoTecla=estado_down;
				/*accion del evento*/
				botonPresionado();
			}
			else{
				estadoTecla=estado_up;
			}
			contfalling=0;
		}
		contfalling++;
		break;

	case estado_down :
		if (gpioRead(tecla)){
			estadoTecla=estado_raising;

		}
		break;

	case estado_raising:
		if (contrising<=tiempo_antirebote){
			if (gpioRead(tecla)){
				estadoTecla=estado_up;
				/*accion del evento*/
				botonLiberado();
			}
			else{
				estadoTecla=estado_down;
			}
			contrising=0;
		}
		contrising++;
		break;

	default:
		 mefbotonError();

	}
}
