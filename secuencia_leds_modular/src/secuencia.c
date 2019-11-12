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

#include "secuencia.h"

/*=====[Inclusiones de dependencias de funciones privadas]===================*/

#include "sapi.h"


/*=====[Macros de definicion de constantes privadas]=========================*/

#define tiempo_pulso  1000 //tiempo de pulsacion
#define tiempo_lento  750
#define tiempo_rapido 150
/*=====[Macros estilo funcion privadas]======================================*/

static void secuencia_lenta(void);
static void secuencia_rapida(void);


/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico

// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
	estado_inicial,
	estado_secuencia_lenta,
	estado_secuencia_rapida,
} estados_secuencia_leds;

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales privadas]=========================*/
static estados_secuencia_leds  estadoPulsadores;
static delay_t delayInicial;
static delay_t delayPulsador;
static delay_t delayLento;
static bool_t valor1,valor2;



/*=====[Prototipos de funciones privadas]====================================*/


/*=====[Implementaciones de funciones publicas]==============================*/

void inicializar_secuencia(void){
	estadoPulsadores=estado_inicial;
	delayWrite(&delayPulsador,tiempo_pulso);

}

void actualizar_secuencia_mef (void){
	static bool_t flagStateInit = FALSE;
	static bool_t flagestadosecuencialenta = FALSE;
	static bool_t flagestadoseceunciarapida= FALSE;

	switch (estadoPulsadores){

	case estado_inicial :
		gpioWrite(LEDB,ON);
		gpioWrite(LED1,ON);
		gpioWrite(LED2,ON);
		gpioWrite(LED3,ON);

		if (delayRead(&delayPulsador)){
			//if (!gpioRead(TEC1)){
				estadoPulsadores=estado_secuencia_lenta;

		}
		break;

	case estado_secuencia_lenta:
		if( flagestadosecuencialenta== FALSE ){
		            flagestadosecuencialenta = TRUE;

		         }

		secuencia_lenta();
     	  if(!gpioRead(TEC2)){
     		  estadoPulsadores=estado_secuencia_rapida;
		}

     	 if( estadoPulsadores != estado_secuencia_lenta ){
     	             flagestadosecuencialenta = FALSE;

     	          }

		break;

	case estado_secuencia_rapida:
		secuencia_rapida();
			if(!gpioRead(TEC1)){
				estadoPulsadores=estado_secuencia_lenta;
		}
		break;

	default:
		inicializar_secuencia();
		break;
	}
}

/*=====[Implementaciones de funciones de interrupcion publicas]==============*/



/*=====[Implementaciones de funciones privadas]==============================*/
static void secuencia_lenta(void){

	gpioWrite(LEDB,ON);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,OFF);
	delay(750);


	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,ON);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,OFF);
	delay(750);


	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,ON);
	gpioWrite(LED3,OFF);
	delay(750);

	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,ON);
	delay(750);

}
static void secuencia_rapida(void){
	gpioWrite(LEDB,ON);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,OFF);
	delay(150);
	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,ON);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,OFF);
	delay(150);
	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,ON);
	gpioWrite(LED3,OFF);
	delay(150);
	gpioWrite(LEDB,OFF);
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,OFF);
	gpioWrite(LED3,ON);
	delay(150);


}
