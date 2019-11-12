/*=============================================================================
 * Program: prueba
 * Date: 2019/09/25
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "prueba.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )

{
   boardConfig();
   bool_t tec1 = 0;
   uint32_t contador = 0;

   while(TRUE) {
      tec1 = !gpioRead(TEC1);
      gpioWrite( LEDB, tec1 );

      delay(1);
      contador++;
      if( contador >= 5000 ){
         gpioToggle( LED3 );
         delay(250);
         gpioToggle( LED2 );
         delay(250);
         gpioToggle( LED1 );
         delay(250);
         contador = 0;
      }
   }
   





   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
