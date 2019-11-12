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

#include "secuencia_giro.h"
#include "paso_bobinas.h"
#include "tecla.h"

/*=====[Inclusiones de dependencias de funciones privadas]===================*/
#include "sapi.h"

/*=====[Macros de definicion de constantes privadas]=========================*/
#define tiempo_inicial 1000   //tiempo inicial
#define tiempo_giro 100       //tiempo de cada paso del motor
#define tiempo_ensayo  10000  // tiempo del ensayo a realizar,asignado en 10 seg
#define tiempo_giro_inverso  20000

/*=====[Macros estilo funcion privadas]======================================*/

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico

// Tipo de datos de puntero a funcion

// Tipo de datos enumerado
typedef enum {
	estado_inicial,
	estado_1,
	estado_2,
	estado_3,
	estado_4,
	estado_5,
} estados_bobinas_MEF;

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales publicas]=========================*/
int8_t fin_tiempo;

/*=====[Definiciones de Variables globales privadas]=========================*/

static estados_bobinas_MEF  estadoBobinas;
static estados_bobinas_MEF  estadoProximo=estado_inicial;
static delay_t delayTiempoGiro;
static delay_t delayTiempoEnsayo;
static delay_t delayTiempoGiroinverso;

/*=====[Prototipos de funciones privadas]====================================*/

/*=====[Implementaciones de funciones publicas]==============================*/
void inicializar_bobinas_MEF(){
	estadoBobinas=estado_inicial;
	estadoProximo=estado_inicial;
	gpioConfig( GPIO1, GPIO_OUTPUT );
	gpioConfig( GPIO2, GPIO_OUTPUT );
	gpioConfig( GPIO3, GPIO_OUTPUT );
	gpioConfig( GPIO4, GPIO_OUTPUT );
	delayInit(&delayTiempoGiro,tiempo_giro);
	delayInit(&delayTiempoEnsayo,tiempo_ensayo);
	delayInit(&delayTiempoGiroinverso,tiempo_giro_inverso);
}

void actualizar_bobinas_MEF(){
	if (delayRead(&delayTiempoEnsayo)){
		fin_tiempo=1;
	}
	else
		fin_tiempo=0;

	switch(estadoBobinas){

	case estado_inicial:  //pongo en estado OFF todas las bobinas
		paso_inicial();

		// al pulsar tecla 1 arranca el motor paso a paso

		if(!gpioRead(TEC1)){
			estadoProximo=estado_1;
		}
		break;
	case estado_1:
		paso_1();
		if (delayRead(&delayTiempoGiro)){
			estadoProximo=estado_2;
		}
		if (fin_tiempo){
			estadoProximo=estado_inicial;
		}
		break;
	case estado_2 :
		paso_2();
		if (delayRead(&delayTiempoGiro)){
			estadoProximo=estado_3;
		}
		if (fin_tiempo){
			estadoProximo=estado_inicial;
		}
		break;
	case estado_3:
		paso_3();
		if (delayRead(&delayTiempoGiro)){
			estadoProximo=estado_4;
		}
		if (fin_tiempo){
			estadoProximo=estado_inicial;
		}
		break;
	case estado_4:
		paso_4();
		if (delayRead(&delayTiempoGiro)){
			estadoProximo=estado_1;
		}
		if (fin_tiempo){
			estadoProximo=estado_inicial;
		}
		break;
	default:
		inicializar_bobinas_MEF();
		break;
	}
	if (estadoBobinas!=estadoProximo){         //cambio las condiciones del switch case
		estadoBobinas=estadoProximo;
	}
	if (estadoProximo==estado_inicial){
		delayInit(&delayTiempoEnsayo,tiempo_ensayo);

	}

}


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/

/*=====[Implementaciones de funciones privadas]==============================*/

/*void giro_inverso(void)
{
	  	  switch(estadoBobinas){

			case estado_inicial:  //pongo en estado OFF todas las bobinas
				paso_inicial();

				if (delayRead(&delayTiempoGiro)){
					estadoProximo=estado_4;
				}
			break;
			case estado_4:
				paso_4();
				if (delayRead(&delayTiempoGiro)){
					estadoProximo=estado_3;
				}
				 break;
			case estado_3 :
				paso_3();
				if (delayRead(&delayTiempoGiro)){
					estadoProximo=estado_2;
				}

				break;
			case estado_2:
				paso_2();
				if (delayRead(&delayTiempoGiro)){
					estadoProximo=estado_1;
				}
				 break;
			case estado_1:
				paso_1();
				if (delayRead(&delayTiempoGiro)){
					estadoProximo=estado_4;
				}
				 break;
			default:
				inicializar_bobinas_MEF();
				break;
			}


	}

 */
