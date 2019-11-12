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

#include "semaforo.h"

/*=====[Inclusiones de dependencias de funciones privadas]===================*/

#include "led.h"


/*=====[Macros de definicion de constantes privadas]=========================*/

#define tiempo_inicial 1000
#define tiempo_rojo    3000
#define tiempo_rojo_amarillo 1000
#define tiempo_verde    2000
#define tiempo_amarillo 1000

/*=====[Macros estilo funcion privadas]======================================*/



/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
   estado_inicial,
   estado_rojo,
   estado_rojo_amarillo,
   estado_verde,
   estado_amarillo
} ESTADOSEMAFORO_t;

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales publicas]=========================*/

/*=====[Definiciones de Variables globales privadas]=========================*/

static ESTADOSEMAFORO_t estadoSemaforo;
static delay_t  delaySemaforo;



/*=====[Prototipos de funciones privadas]====================================*/



/*=====[Implementaciones de funciones publicas]==============================*/

void inicializarSemaforo_MEF(){
	estadoSemaforo=estado_inicial;
	delayWrite(&delaySemaforo,tiempo_inicial);
}

void actualizarSemaforo_MEF (){

	switch(estadoSemaforo){

	case estado_inicial:  //para probar que funcionan las lamparas
		led_encender(luz_roja);
		led_encender(luz_amarilla);
		led_encender(luz_verde);
		if (delayRead(&delaySemaforo)){
			estadoSemaforo=estado_rojo;
			delayWrite(&delaySemaforo,tiempo_rojo);
		}
	break;
	case estado_rojo:
		led_encender(luz_roja);
		led_apagar(luz_amarilla);
		led_apagar(luz_verde);
		if (delayRead(&delaySemaforo)){
			estadoSemaforo=estado_rojo_amarillo;
			delayWrite(&delaySemaforo,tiempo_rojo_amarillo);
		}

	break;

	case estado_rojo_amarillo:
			led_encender(luz_roja);
			led_encender(luz_amarilla);
			led_apagar(luz_verde);
			if (delayRead(&delaySemaforo)){
				estadoSemaforo=estado_verde;
				delayWrite(&delaySemaforo,tiempo_verde);
			}

		break;

	case estado_verde:
			led_apagar(luz_roja);
			led_apagar(luz_amarilla);
			led_encender(luz_verde);
			if (delayRead(&delaySemaforo)){
				estadoSemaforo=estado_amarillo;
				delayWrite(&delaySemaforo,tiempo_amarillo);

			}

		break;

	case estado_amarillo:
	led_apagar(luz_roja);
    led_encender(luz_amarilla);
	led_apagar(luz_verde);
		if (delayRead(&delaySemaforo)){
			estadoSemaforo=estado_rojo;
			delayWrite(&delaySemaforo,tiempo_rojo);
			}

		break;
	default:
	inicializarSemaforo_MEF();
	break;
			}
		}

void nomalSemaforo(void){
	 uint8_t contadorLocal=0;

	 led_encender(luz_roja);
	 delay(tiempo_rojo);
     led_apagar(luz_roja);

     led_encender(luz_amarilla);
     delay(tiempo_amarillo);
     led_apagar(luz_amarilla);

     led_encender(luz_verde);
     delay(tiempo_verde);
     led_apagar(luz_verde);

     led_encender(luz_amarilla);
     delay(tiempo_amarillo);
     led_apagar(luz_amarilla);
    }






		/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


		/*=====[Implementaciones de funciones privadas]==============================*/


