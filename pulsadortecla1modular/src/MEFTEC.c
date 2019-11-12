/*=====[Nombre del modulo]=====================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*=====[Inclusion de su propia cabecera]=====================================*/

#include "../inc/MEFTEC.h"

#include "sapi.h"


/*=====[Macros de definicion de constantes privadas]=========================*/

#define tiempo_antirebote  40      // tiempo de 40 milisegundos

/*=====[Macros estilo funcion privadas]======================================*/



/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
	tecla_up,
	tecla_down,
	tecla_falling,
	tecla_rising
} MEF_tecla_t;

// Tipo de datos estructua, union o campo de bits
/*=====[Definiciones de Variables globales publicas externas]================*/
/*=====[Definiciones de Variables globales publicas]=========================*/

MEF_tecla_t estadoTecla;
delay_t delayTecla;

/*=====[Definiciones de Variables globales privadas]=========================*/
/*=====[Prototipos de funciones privadas]====================================*/
static void teclapresionada();
static void teclaliberada();
//static void funPrivada(void);
/*=====[Implementaciones de funciones publicas]==============================*/
void mefTeclaInit(void){
	estadoTecla=tecla_up;
	delayWrite(&delayTecla,tiempo_antirebote);
}

void mefTeclaactual(gpioMap_t tecla){
	static bool_t flagfalling=FALSE;
	static bool_t flagrising=FALSE;

	switch (estadoTecla){

	case tecla_up:
		/* check condiciones transicion*/
		if (!gpioRead(tecla)){
			estadoTecla=tecla_falling ;
		}
		break;

	case tecla_down:
		/* check condiciones transicion*/
		if (gpioRead(tecla)){
			estadoTecla=tecla_rising ;
		}
		break;

	case tecla_falling:
		/*entrada*/
		if (flagfalling==FALSE){
			flagfalling=TRUE;
			gpioWrite(LEDR,1);
		}
		/* check condiciones transicion*/
		if (delayRead(&delayTecla)){
			if (!gpioRead(tecla)){
				estadoTecla=tecla_down;
				teclapresionada();
			}else {
				estadoTecla=tecla_up;
			}
			delayWrite(&delayTecla,tiempo_antirebote);
		}
		/*salida*/
		if (estadoTecla!=tecla_falling){
			flagfalling=FALSE;
			gpioWrite(LEDR,0);
		}
		break;

	case tecla_rising:
		/*entrada*/
		if (flagrising==FALSE){
			flagrising=TRUE;
			gpioWrite(LEDB,1);
		}
		/* check condiciones transicion*/
		if (delayRead(&delayTecla)){
			if (gpioRead(tecla)){
				estadoTecla=tecla_up;
				teclaliberada();
			}else {
				estadoTecla=tecla_down;
			}
			delayWrite(&delayTecla,tiempo_antirebote);
		}
		/*salida*/
		if (estadoTecla!=tecla_rising){
			flagrising=FALSE;
			gpioWrite(LEDB,0);
		}

		break;
	}
}

/*=====[Implementaciones de funciones de interrupcion publicas]==============*/

/*=====[Implementaciones de funciones privadas]==============================*/

void teclapresionada(void){
	gpioWrite(LED1,1);
	gpioToggle(LED2);
}

void teclaliberada(void){
	gpioWrite(LED1,0);
}
