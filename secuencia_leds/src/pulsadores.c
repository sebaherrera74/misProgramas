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


#include "pulsadores.h"
#include "sapi.h"
//#include <dependencia.h>

/*=====[Macros de definicion de constantes privadas]=========================*/

#define tiempo_inicial 1000 //tiempo al inicio del programa que prenda los 4 leds de 1 seg
//#define tiempo_lento   750 //secuencia lenta 750 mili segundo
//defitiempo_rapido  150 //secuencia rapida 150 mili segundos

/*=====[Macros estilo funcion privadas]======================================*/

//#define rtcConfig rtcInit

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico


// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
	estado_inicial,
	secuencia_horaria,
	secuencia_antihoraria,
} mef_estados_puls;

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales publicas]=========================*/

/*=====[Definiciones de Variables globales privadas]=========================*/

static mef_estados_puls  estadoPulsadores;
static delay_t delayInicial;
static bool_t valor1,valor2;
/*=====[Prototipos de funciones privadas]====================================*/
void secuencia_lenta(void);
void secuencia_rapida(void);
/*=====[Implementaciones de funciones publicas]==============================*/

void inicializar_leds(void) {
      estadoPulsadores=estado_inicial;
      delayWrite(&delayInicial,tiempo_inicial);
}
void actualizar_estados (void){
       int cont;
	   switch (estadoPulsadores) {

       case estado_inicial:
    	   encender_led(luz_azul);
    	   encender_led(luz_roja);
    	   encender_led(luz_amarilla);
    	   encender_led(luz_verde);

           if (!gpioRead(TEC1)) {
        	    	   estadoPulsadores=secuencia_horaria;
           }
       break;


       case secuencia_horaria:
    	   apagar_led(luz_azul);
    	   apagar_led(luz_roja);
    	   apagar_led(luz_amarilla);
    	   apagar_led(luz_verde);
    	   valor1=!gpioRead(TEC2);
    	   valor2=!gpioRead(TEC3);

    	   if(valor1){

    		 secuencia_lenta();

    	   }
    	   if(valor2) {
    		   secuencia_rapida();
    	   }

        break;

       case secuencia_antihoraria:

        break;

       default:
       inicializar_leds();
       	break;

       }


}

void secuencia_lenta(void){
	 encender_led(luz_azul);
	 delay(750);
	 apagar_led(luz_azul);
	 encender_led(luz_roja);
	 	 delay(750);
	 	 apagar_led(luz_roja);
	 	encender_led(luz_amarilla);
	 		 delay(750);
	 		 apagar_led(luz_amarilla);
	 		encender_led(luz_verde); // @suppress("Symbol is not resolved")
	 			 delay(750);
	 			 apagar_led(luz_verde); // @suppress("Symbol is not resolved")
}
void secuencia_rapida(void){
	 encender_led(luz_azul);
	 delay(150);
	 apagar_led(luz_azul);
	 encender_led(luz_roja);
	 	 delay(150);
	 	 apagar_led(luz_roja);
	 	encender_led(luz_amarilla);
	 		 delay(150);
	 		 apagar_led(luz_amarilla);
	 		encender_led(luz_verde);
	 			 delay(150);
	 			 apagar_led(luz_verde);
}




/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


/*=====[Implementaciones de funciones privadas]==============================*/

