/*=============================================================================
 * Program: ejemploMEF
 * Date: 2019/09/25
 *===========================================================================*/



#include "ejemploMEF.h"
#include "sapi.h"


typedef enum{
	ROJO,
	ROJO_AMARILLO,
	VERDE,
	AMARILLO
} mefEstadoSemaforo_T;

void mefsemaforoinicial( void );
void mefsemaforoactualizar( void );

mefEstadoSemaforo_T  mefEstadoSemaforo;

int main( void )
{
	boardConfig();
	mefsemaforoinicial();
	while(TRUE){
		mefsemaforoactualizar();
		delay(1);
	}
	return 0;
}

void mefsemaforoinicial( void )
{
	mefEstadoSemaforo = ROJO;
}

void mefsemaforoactualizar( void )
{
	static uint16_t contSemaforo = 0;

	switch( mefEstadoSemaforo ){

	case ROJO:
		gpioWrite( LED1, ON );
		gpioWrite( LED2, OFF );
		gpioWrite( LED3, OFF );
		if( contSemaforo >= 1000 ){
			mefEstadoSemaforo = ROJO_AMARILLO;
			contSemaforo = 0;
		}
		contSemaforo++;
		break;

	case ROJO_AMARILLO:
		gpioWrite( LED1, ON );
		gpioWrite( LED2, ON );
		gpioWrite( LED3, OFF );
		if( contSemaforo >= 500 ){
			mefEstadoSemaforo = VERDE;
			contSemaforo = 0;
		}
		contSemaforo++;
		break;

	case VERDE:
		gpioWrite( LED1, OFF );
		gpioWrite( LED2, OFF );
		gpioWrite( LED3, ON );
		if( contSemaforo >= 1200 ){
			mefEstadoSemaforo = AMARILLO;
			contSemaforo = 0;
		}
		contSemaforo++;
		break;

	case AMARILLO:
		gpioWrite( LED1, OFF );
		gpioWrite( LED2, ON );
		gpioWrite( LED3, OFF );
		if( contSemaforo >= 500 ){
			mefEstadoSemaforo = ROJO;
			contSemaforo = 0;
		}
		contSemaforo++;
		break;

	default:
		mefEstadoSemaforo = ROJO;
		break;
	}
}

