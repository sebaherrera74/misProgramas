/*=====[motor paso-paso]===================================================
 * Copyright Sebastian Herrera <sebastianh74@hotmail.com.ar.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 * Version: 0.0.1
 * Fecha de creacion: 2019/10/10*/

/*=====[Inclusion de su propia cabecera]=====================================*/

#include "adc.h"
#include "sapi.h"

/*=====[Macros de definicion de constantes privadas]=========================*/
#define tiempo_ensayo_lectura 10000

/*=====[Macros estilo funcion privadas]======================================*/

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico

// Tipo de datos de puntero a funcion


// Tipo de datos enumerado
typedef enum {
	lectura_inicial,
	lectura_muestra,

} estados_adc_MEF;

// Tipo de datos estructua, union o campo de bits

/*=====[Definiciones de Variables globales publicas externas]================*/

/*=====[Definiciones de Variables globales publicas]=========================*/
estados_adc_MEF estadolectura=lectura_inicial;
int16_t muestra = 0;
int8_t fin_tiempo_lectura;

/*=====[Definiciones de Variables globales privadas]=========================*/
estados_adc_MEF  estadoProximo=lectura_inicial;
delay_t tiempoMuestra;
delay_t Tiempolectura;
/*=====[Prototipos de funciones privadas]====================================*/

/*=====[Implementaciones de funciones publicas]==============================*/

void inicializar_lectura_analogica(void){
	adcConfig( ADC_ENABLE ); /* ADC */
	delayInit(&tiempoMuestra,tiempo_ensayo_lectura);
}

void actualiza_lectura_analogica(void){
	if (delayRead(&tiempoMuestra)){
		fin_tiempo_lectura=1;
	}
	else
		fin_tiempo_lectura=0;

	switch (estadolectura){
	case lectura_inicial:
		if (!gpioRead(TEC1)){
			estadoProximo=lectura_muestra;
		}
		break;

	case lectura_muestra :
        muestra = adcRead( CH1 );
		printf("valor analogico \r\n : ");
		printf("%i",muestra);
       if (fin_tiempo_lectura){
    	   estadoProximo=lectura_inicial;
       }
		break;
	}
	if (estadolectura!=estadoProximo){         //cambio las condiciones del switch case
		estadolectura=estadoProximo;
	}
	if (estadoProximo==lectura_inicial){
		delayInit(&tiempoMuestra,tiempo_ensayo_lectura);

	}



}


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/


/*=====[Implementaciones de funciones privadas]==============================*/

