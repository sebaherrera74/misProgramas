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

#include "tecla.h"
#include "sapi.h"


/*=====[Macros de definicion de constantes privadas]=========================*/
#define tiempo_antirebote  40  // tiempo de 40 milisegundos
#define tecla TEC1
#define estado_inicial  estado_up
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

mef_tec_estado estadoTecla=estado_up;
delay_t delayTecla;


/*=====[Prototipos de funciones privadas]====================================*/
static void botonPresionado(void);
static void botonLiberado(void);
/*=====[Implementaciones de funciones publicas]==============================*/


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


/*=====[Implementaciones de funciones privadas]==============================*/

void inicializar_tecla (void) {
	estadoTecla=estado_inicial;
	delayWrite(&delayTecla,tiempo_antirebote);
}


void actualizar_tecla(void){

	switch (estadoTecla){

	case estado_up:
		if (!gpioRead(tecla)){
			estadoTecla=estado_falling;
		}
		break;

	case estado_falling :
		if (delayRead(&delayTecla)){
			if (!gpioRead(tecla)){
				estadoTecla=estado_down;
				delayWrite(&delayTecla,tiempo_antirebote);
				botonPresionado();
			}
			else
				estadoTecla=estado_up;
		}
		break;

	case estado_down :
		if (gpioRead(tecla)){
			estadoTecla=estado_raising;
			delayWrite(&delayTecla,tiempo_antirebote);
		}
		break;

	case estado_raising:
		if (delayRead(&delayTecla)){
			if (gpioRead(tecla)){
				estadoTecla=estado_up;
				botonLiberado();
			}
			else
				estadoTecla=estado_down;
		}
		break;

	}
}
static void botonPresionado(void){
	gpioToggle(LEDR);


}
static void botonLiberado(void){

	gpioToggle(LED2);
}

