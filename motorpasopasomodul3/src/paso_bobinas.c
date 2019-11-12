/*=====[motor paso-paso]===================================================
 * Copyright Sebastian Herrera <sebastianh74@hotmail.com.ar.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 * Version: 0.0.1
 * Fecha de creacion: 2019/10/10*/

/*=====[Inclusion de su propia cabecera]=====================================*/
#include "paso_bobinas.h"
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

/*=====[Implementaciones de funciones globales publicas]==============================*/

/*Activacion de bobinas secuencia de encendido del tipo wave drive */
void paso_inicial(void){
	gpioWrite(GPIO1,OFF);
	gpioWrite(GPIO2,OFF);
	gpioWrite(GPIO3,OFF);
	gpioWrite(GPIO4,OFF);
}
void paso_1(void){
	gpioWrite(GPIO1,ON);
	gpioWrite(GPIO2,OFF);
	gpioWrite(GPIO3,OFF);
	gpioWrite(GPIO4,OFF);
}
void paso_2(void){
	gpioWrite(GPIO1,OFF);
	gpioWrite(GPIO2,ON);
	gpioWrite(GPIO3,OFF);
	gpioWrite(GPIO4,OFF);
}
void paso_3(void){
	gpioWrite(GPIO1,OFF);
	gpioWrite(GPIO2,OFF);
	gpioWrite(GPIO3,ON);
	gpioWrite(GPIO4,OFF);
}
void paso_4(void){
	gpioWrite(GPIO1,OFF);
	gpioWrite(GPIO2,OFF);
	gpioWrite(GPIO3,OFF);
	gpioWrite(GPIO4,ON);
}



/*=====[Implementaciones de funciones de interrupcion publicas]==============*/






