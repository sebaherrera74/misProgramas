/*=============================================================================
 * Program: delaynobloqueante
 * Date: 2019/09/25
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "delaynobloqueante.h"
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
	
   delay_t led1Delay;
   delayConfig( &led1Delay, 2000 );

   while(TRUE) {
      tec1 = !gpioRead(TEC1);
      gpioWrite( LEDB, tec1 );

      if( delayRead(&led1Delay) ){
         gpioToggle( LED1 );
      }
   }

   return 0;
}



