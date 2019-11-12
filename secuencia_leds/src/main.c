/*=====[Nombre del programa]===================================================
 programa de secuencia de leds modularizado, al presionar TEC1 la secuencia sera de izquierda
 a derecha y si presiono la tecla 4 sera al reves , a su vez las teclas TEC2 yTEC3 me cambiaran el tiempo
 mas rapido o mas lento.


/*=====[Inclusiones de dependencias de funciones]============================*/

#include "main.h"
#include "sapi.h"
#include "pulsadores.h"

/*=====[Macros de definición de constantes privadas]=========================*/

#define edu_ciaa_v_1_1_0

/*=====[Definiciones de variables globales externas]=========================*/

/*=====[Definiciones de variables globales publicas]=========================*/

//bool_t tecla1,tecla4;

/*=====[Definiciones de variables globales privadas]=========================*/

//static int var = 0;

/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/

int main (void)
{
   // ----- Configuraciones -------------------------
 	boardInit();
	inicializar_leds();

   // ----- Repetir por siempre ---------------------
   while(TRUE) {
	   actualizar_estados();

   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}






















