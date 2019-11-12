/*=============================================================================
 * Program: blinky
 * Date: 2019/09/24
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/


#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   // ----- Repeat for ever -------------------------
   while(1) {
     gpioWrite(LEDR,ON);
      delay(500);
      gpioWrite(LEDR,OFF);
      delay(500);

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   
   }
return 0;
}
