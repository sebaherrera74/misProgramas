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

#include "paso_bobinas.h"

#include "sapi.h"


/*=====[Macros de definicion de constantes privadas]=========================*/

/*#define QMC5883L_REG_Y_LSB       0x02
#define MAX_AMOUNT_OF_RGB_LEDS   9*/

/*=====[Macros estilo funcion privadas]======================================*/

//#define rtcConfig rtcInit

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico
//typedef uint32_t gpioRegister_t;

// Tipo de datos de puntero a funcion
//typedef void (*FuncPtrPrivado_t)(void *);

// Tipo de datos enumerado
/*typedef enum {
   GPIO_INPUT_PULLUP, 
   GPIO_INPUT_PULLDOWN,
   GPIO_REPEATER
} gpioLPC4337Modes_t;
*/
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

//int32_t varGlobalPublica = 0;

/*=====[Definiciones de Variables globales privadas]=========================*/

//static void paso_1(void);
//static void paso_2(void);

/*=====[Prototipos de funciones privadas]====================================*/



/*=====[Implementaciones de funciones globales publicas]==============================*/
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






