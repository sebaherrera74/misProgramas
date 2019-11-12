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

#include "led.h"
#include "sapi.h"
/*=====[Inclusiones de dependencias de funciones privadas]===================*/


/*=====[Macros de definicion de constantes privadas]=========================*/


/*=====[Macros estilo funcion privadas]======================================*/


/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico
// Tipo de datos enumerado

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/


/*=====[Definiciones de Variables globales publicas]=========================*/



/*=====[Definiciones de Variables globales privadas]=========================*/


/*=====[Prototipos de funciones privadas]====================================*/

static void toggleled(gpioMap_t lampara);

/*=====[Implementaciones de funciones publicas]==============================*/
void led_encender(gpioMap_t lampara){
	 gpioWrite(lampara,ON);
}
void led_apagar(gpioMap_t lampara){
	 gpioWrite(lampara,OFF);
}
/*void led_titilar(gpioMap_t lampara,int32_t tiempoON,uint8_ cantVeces){
	uint8_t i;
	for (i=0;i<cantveces;i++){
	     toggleled(lampara);
	     delay(tiempoON);

}*/


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


/*=====[Implementaciones de funciones privadas]==============================*/

void toogleled(gpioMap_t lampara){

}
