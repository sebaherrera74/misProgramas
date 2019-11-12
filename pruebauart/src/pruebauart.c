/*=============================================================================
 * Program: pruebauart
 * Date: 2019/09/25
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "pruebauart.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   printf("hola\r\n"); // Recordar poner el \r\n para que envíe
   boardInit();
   while(true){
      gpioToggle( LEDB );
      printf("hola\r\n");
      delay(100); // tiempo en ms
   }
   return 0;
}
