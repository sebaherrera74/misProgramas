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
/*=====[Inclusiones de dependencias de funciones privadas]===================*/

#include "sapi.h"
//#include <dependencia.h>

/*=====[Macros de definicion de constantes privadas]=========================*/
#define tiempo_inicial 1000 //tiempo inicial
#define tiempo_giro 250 //tiempo de cada paso del motor
#define tiempo_ensayo   10000 // tiempo del ensayo a realizar

/*=====[Macros estilo funcion privadas]======================================*/

//#define rtcConfig rtcInit

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico
//typedef uint32_t gpioRegister_t;

// Tipo de datos de puntero a funcion
//typedef void (*FuncPtrPrivado_t)(void *);

// Tipo de datos enumerado
typedef enum {
	estado_inicial,
	estado_1,
	estado_2,
	estado_3,
	estado_4,
} estados_bobinas_MEF;

// Tipo de datos estructua, union o campo de bits
/*typedef struct {
   uint8_t scuPort;
   uint8_t scuPin;
   uint8_t func;
   uint8_t gpioPort;
   uint8_t gpioPin;
} gpioLpc4337_t;*/

/*=====[Definiciones de Variables globales publicas externas]================*/

//extern int32_t varGlobalExterna;

/*=====[Definiciones de Variables globales publicas]=========================*/
uint8_t fin_tiempo;


/*=====[Definiciones de Variables globales privadas]=========================*/

static estados_bobinas_MEF  estadoBobinas;
static estados_bobinas_MEF  estadoProximo;

static delay_t delayTiempoInicial;
static delay_t delayTiempoGiro;
static delay_t delayTiempoEnsayo;

/*=====[Prototipos de funciones privadas]====================================*/

//static void funPrivada(void);

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

}

void actualizar_bobinas_MEF(){
	if (!gpioRead(TEC2)){
		fin_tiempo=1;
	}
	else
		fin_tiempo=0;

	switch(estadoBobinas){

	case estado_inicial:  //pongo en estado OFF todas las bobinas
		paso_inicial();
		if (!gpioRead(TEC1 )){
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
	case estado_3 :
			paso_3();
			if (delayRead(&delayTiempoGiro)){
				estadoProximo=estado_4;
			}
			if (fin_tiempo){
				estadoProximo=estado_inicial;
			}
			break;
	case estado_4 :
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
	if (estadoBobinas!=estadoProximo){
		if(estadoProximo==estado_inicial){
			estadoBobinas=estadoProximo;
		}
		estadoBobinas=estadoProximo;
	}
}


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/

/*void UART0_IRQHandler(void)
{
   // ...
}*/

/*=====[Implementaciones de funciones privadas]==============================*/

/*static void funPrivada(void)
{
   // ...
}*/

