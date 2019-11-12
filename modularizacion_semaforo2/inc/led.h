/*=====[Module Name]===========================================================
 * Copyright YYYY Author Compelte Name <author@mail.com>
 * All rights reserved.
 * License: license text or at least name and link 
         (example: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Creation Date: YYYY/MM/DD
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _LED_H_
#define _LED_H_

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi.h"
/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/
#define luz_roja     LED2
#define luz_amarilla LED1
#define luz_verde    LED3

#define tiempo_rojo     3000 // ms
#define tiempo_amarillo 1000 // ms
#define tiempo_verde    2000 // ms
/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/
void led_encender(gpioMap_t lampara);
void led_apagar(gpioMap_t lampara);
/*void led_titilar(gpioMap_t lampara, int32_t tiempoON, uint8_ cantVeces );*/


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _MODULE_NAME_H_ */
