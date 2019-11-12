/*=====[Nombre del programa]===================================================*/



#include "sapi.h"
#include "main.h"

typedef enum{
	tecla_1,
	tecla_2,
	tecla_3,
	tecla_4,
}mef_teclas_puls;

static mef_teclas_puls teclaPulsada;

//int32_t cont=0;
//int32_t numero;
bool_t valor;

int main (void)
{
   // ----- Configuraciones -------------------------

	boardInit();
 teclaPulsada=tecla_2;

    // ----- Repetir por siempre ---------------------
   while(TRUE) {

	switch(teclaPulsada){

	case tecla_1:
		if (!gpioRead(TEC1)){
			gpioWrite (LEDB ,ON);
		}
    break;

	case tecla_2:
			if (!gpioRead(TEC2)){
				gpioWrite (LED1 ,ON);
				gpioWrite (LEDB ,OFF);
			}
	    break;


	}

   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;

}






















