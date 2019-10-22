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


/*=====[Macros estilo funcion privadas]======================================*/



/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion

// Tipo de datos enumerado

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales publicas]=========================*/

/*=====[Definiciones de Variables globales privadas]=========================*/

/*=====[Prototipos de funciones privadas]====================================*/

/*=====[Implementaciones de funciones publicas]==============================*/


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


/*=====[Implementaciones de funciones privadas]==============================*/
void secuencia_lenta(){
	gpioWrite(LED1,ON);
	gpioWrite(LED2,ON);
}
void apagar_leds(){
	gpioWrite(LED1,OFF);
	gpioWrite(LED2,OFF);
	}

