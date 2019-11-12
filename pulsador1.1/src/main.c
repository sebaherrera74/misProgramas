#include "sapi.h"

typedef enum {
   BOTTON_UP,
   BOTTON_DOWN,
   BOTTON_FALLING,
   BOTTON_RISING
} fsmButtonState_t;

void fsmButtonError( void );
void fsmButtonInit( void );
void fsmButtonUpdate( gpioMap_t tecla );
void buttonPressed( void );
void buttonReleased( void );

fsmButtonState_t fsmButtonState;

int main(void){
   boardConfig();
   fsmButtonInit();
   while(TRUE){
      fsmButtonUpdate(TEC1);


      delay(1);
   }
   return 0;
}

void buttonPressed( void )
{
   static uint8_t cont = 0;
   gpioWrite(LEDR, OFF);
   gpioWrite(LEDG, OFF);
   gpioWrite(LEDB, ON);
   if(cont>5){
      gpioWrite(LEDR, OFF);
      gpioWrite(LEDG, ON);
      gpioWrite(LEDB, OFF);
   }
   cont++;
}

void buttonReleased( void )
{
   static uint8_t cont = 0;
   gpioWrite(LEDR, ON);
   gpioWrite(LEDG, OFF);
   gpioWrite(LEDB, OFF);
   if(cont>10){
      gpioWrite(LEDR, OFF);
      gpioWrite(LEDG, OFF);
      gpioWrite(LEDB, OFF);
   }
   cont++;
}

void fsmButtonError( void )
{
   fsmButtonState = BOTTON_UP;
}

void fsmButtonInit( void )
{
   fsmButtonState = BOTTON_UP;  // Set initial state
}

// FSM Update Sate Function
void fsmButtonUpdate( gpioMap_t tecla )
{
   static bool_t flagFalling = FALSE;
   static bool_t flagRising = FALSE;

   static uint8_t contFalling = 0;
   static uint8_t contRising = 0;

   switch( fsmButtonState ){

      case BOTTON_UP:
         /* CHECK TRANSITION CONDITIONS */
         if( !gpioRead(tecla) ){
            fsmButtonState = BOTTON_FALLING;
         }
      break;

      case BOTTON_DOWN:
         /* CHECK TRANSITION CONDITIONS */
         if( gpioRead(tecla) ){
            fsmButtonState = BOTTON_RISING;
         }
      break;

      case BOTTON_FALLING:
         /* ENTRY */
         if( flagFalling == FALSE ){
            flagFalling = TRUE;
            gpioWrite(LED1, ON);
         }
         /* CHECK TRANSITION CONDITIONS */
         if( contFalling >= 40 ){
            if( !gpioRead(tecla) ){
               fsmButtonState = BOTTON_DOWN;
               buttonPressed();
            } else{
               fsmButtonState = BOTTON_UP;
            }
            contFalling = 0;
         }
         contFalling++;
         /* LEAVE */
         if( fsmButtonState != BOTTON_FALLING ){
            flagFalling = FALSE;
            gpioWrite(LED1, OFF);
         }
      break;

      case BOTTON_RISING:
         /* ENTRY */
         if( flagRising == FALSE ){
            flagRising = TRUE;
            gpioWrite(LED2, ON);
         }
         /* CHECK TRANSITION CONDITIONS */

         if( contRising >= 40 ){
            if( gpioRead(tecla) ){
               fsmButtonState = BOTTON_UP;
               buttonReleased();
            } else{
               fsmButtonState = BOTTON_DOWN;
            }
            contRising = 0;
         }
         contRising++;

         /* LEAVE */
         if( fsmButtonState != BOTTON_RISING ){
            flagRising = FALSE;
            gpioWrite(LED2, OFF);
         }
      break;

      default:
         fsmButtonError();
      break;
   }
}







