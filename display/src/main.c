/*==================[inlcusiones]============================================*/

#include "sapi.h"        // <= Biblioteca sAPI

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/

/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/
void menuPrincipal(void);
void menuLampara(void);
void menutiempoEnsayo(void);
void menuinicioEnsayo(void);
void teclaPulsada(void);
void teclaPulsada_2(void);
bool_t ejecucion_ensayo(int64_t);
void termino_ensayo(void);
/*==================[declaraciones de funciones externas]====================*/
/*==================[funcion principal]======================================*/

// Definir caracteres personalizados: https://omerk.github.io/lcdchargen/

typedef enum {
	menu_principal,
	menu_lampara,
	menu_tiempoEnsayo,
	menu_inicioEnsayo,
	menu_ejecucion_ensayo,

} estados_menus_MEF;

estados_menus_MEF menuDisplay;

int16_t muestra = 0;
float voltaje;
int16_t contPulsados=0;
bool_t x=TRUE;
// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{
	// ---------- CONFIGURACIONES ------------------------------

	// Inicializar y configurar la plataforma
	boardInit();
	i2cInit( I2C0, 100000 );
	menuDisplay=menu_principal;
	delay( LCD_STARTUP_WAIT_MS );   // Wait for stable power (some LCD need that)

	// Inicializar LCD de 20x4 (caracteres x lineas) con cada caracter de 5x2 pixeles
	lcdInit( 20, 4, 5, 8 );

	lcdCursorSet( LCD_CURSOR_OFF ); // Apaga el cursor
	lcdClear();                     // Borrar la pantalla


	// ---------- REPETIR POR SIEMPRE --------------------------
	while( TRUE ) {

		switch(menuDisplay) {

		case menu_principal:
			teclaPulsada();
			menuPrincipal();

			if(!gpioRead(TEC2)){
				if (contPulsados==1){
					menuDisplay=menu_lampara;
				}
			}
			if(!gpioRead(TEC2)){
				if (contPulsados==2){
					menuDisplay=menu_tiempoEnsayo;
				}
			}
			if(!gpioRead(TEC2)){
				if (contPulsados==3){
					menuDisplay=menu_inicioEnsayo;
				}
			}

			break;

		case menu_lampara :
			teclaPulsada();
			menuLampara();
			if(!gpioRead(TEC2)){
				if(contPulsados==1){
					gpioWrite(LED1,1);//prendo led 1 solo para probar la idea es que guarde en una memoria este dato
				}                     //va ha ser el dato que me diga que seleccione la luz ultavioleta

				if(contPulsados==2){
					gpioWrite(LED2,1);//prendo led 2 solo para probar la idea es que guarde en una memoria este dato
				}                                 //va ha ser el dato que me diga que seleccione la luz visible


				if (contPulsados==3){

					menuDisplay=menu_principal;
					gpioWrite(LED1,0);
					gpioWrite(LED2,0);
				}
			}
			break;

		case menu_tiempoEnsayo :
			teclaPulsada();
			menutiempoEnsayo();
			if(!gpioRead(TEC2)){
				if(contPulsados==1){
					gpioWrite(LEDB,1);//prendo led azul solo para probar la idea es que guarde en una memoria este dato
				}                     //va ha ser el dato que me diga que seleccione la luz ultavioleta

				if(contPulsados==2){
					gpioWrite(LEDR,1);//prendo led rojo solo para probar la idea es que guarde en una memoria este dato
				}

				if (contPulsados==3){
					menuDisplay=menu_principal;
					gpioWrite(LEDB,0);
					gpioWrite(LEDR,0);
				}
			}
			break;

			/*cuando selecciono tanto lampara y duracion del ensayo, ojo que se puden reescribir los datos  */


		case menu_inicioEnsayo :
			teclaPulsada_2();
			menuinicioEnsayo();
			if(!gpioRead(TEC2)){
				if (contPulsados==3){                     /*pongo esto porque el contador me queda en tres revisar */
					menuDisplay=menu_ejecucion_ensayo;
					lcdClear();
				}

				if (contPulsados==1){
					menuDisplay=menu_ejecucion_ensayo;
					lcdClear();
				}

				if (contPulsados==2){
					menuDisplay=menu_principal;
					lcdClear();
				}
			}
			break;
		case menu_ejecucion_ensayo:
           if (x){
			x=ejecucion_ensayo(20);
            }
           else{

        	   termino_ensayo();
        	   lcdClear();
        	   menuDisplay=menu_principal;
        	   x=TRUE;
           }
           break;
		}
	}


	return 0;
}

/*==================[definiciones de funciones internas]=====================*/

void teclaPulsada(void){
	if(!gpioRead(TEC1)){
		contPulsados=contPulsados+1;
		delay(250);
		if (contPulsados>3){
			contPulsados=1;
		}
	}
	if (contPulsados==1){
		lcdGoToXY(0,0);
		lcdSendStringRaw( "->" );
		lcdGoToXY(0,1);
		lcdSendStringRaw( "  " );
		lcdGoToXY(0,2);
		lcdSendStringRaw( "  " );
	}
	if (contPulsados==2){
		lcdGoToXY(0,1);
		lcdSendStringRaw( "->" );
		lcdGoToXY(0,0);
		lcdSendStringRaw( "  " );
		lcdGoToXY(0,2);
		lcdSendStringRaw( "  " );
	}
	if (contPulsados==3){
		lcdGoToXY(0,2);
		lcdSendStringRaw( "->" );
		lcdGoToXY(0,0);
		lcdSendStringRaw( "  " );
		lcdGoToXY(0,1);
		lcdSendStringRaw( "  " );
	}
}
void teclaPulsada_2(void){

	if(!gpioRead(TEC1)){
		contPulsados++;
		delay(250);
		if (contPulsados>2){
			contPulsados=1;
		}
	}
	if (contPulsados==1){
		lcdGoToXY(0,2);
		lcdSendStringRaw( "->" );
		lcdGoToXY(0,3);
		lcdSendStringRaw( "  " );
	}
	if (contPulsados==2){
		lcdGoToXY(0,3);
		lcdSendStringRaw( "->" );
		lcdGoToXY(0,2);
		lcdSendStringRaw( "  " );
	}
}

void menuPrincipal(void){
	lcdGoToXY( 2, 0 );
	lcdSendStringRaw( "Selecc lampara" );
	lcdGoToXY(16,0);
	lcdSendStringRaw( "   " );
	lcdGoToXY(2,1);
	lcdSendStringRaw( "Tiempo ensayo" );
	lcdGoToXY(2,2);
	lcdSendStringRaw( "Inicio Ensayo" );
	lcdGoToXY(0,3);
	lcdSendStringRaw( "        " );

	lcdGoToXY(19,3);
	lcdSendInt( contPulsados );
}

void menuLampara(void){
	lcdGoToXY( 2, 0 );
	lcdSendStringRaw( "luz ultravioleta" );
	lcdGoToXY(2,1);
	lcdSendStringRaw( "luz visible" );
	lcdGoToXY(13,1);
	lcdSendStringRaw( "  " );
	lcdGoToXY(2,2);
	lcdSendStringRaw( "Salir" );
	lcdGoToXY(7,2);
	lcdSendStringRaw( "        " );
	lcdGoToXY(19,3);
	lcdSendInt( contPulsados );

}

void menutiempoEnsayo(void){
	lcdGoToXY( 2, 0 );
	lcdSendStringRaw( "1 Minuto" );
	lcdGoToXY( 10, 0 );
	lcdSendStringRaw( "          " );
	lcdGoToXY(2,1);
	lcdSendStringRaw( "2 Minutos" );
	lcdGoToXY( 11, 1 );
	lcdSendStringRaw( "  " );
	lcdGoToXY(13,1);
	lcdSendStringRaw( "  " );
	lcdGoToXY(2,2);
	lcdSendStringRaw( "Salir" );
	lcdGoToXY(7,2);
	lcdSendStringRaw( "        " );
	lcdGoToXY(19,3);
	lcdSendInt( contPulsados );
}

void menuinicioEnsayo(void){
	lcdGoToXY( 0, 0 );
	lcdSendStringRaw( "Valor Analogico" );

	lcdGoToXY(0,1);
	lcdSendStringRaw( "Duracion" );

	lcdGoToXY(2,2);
	lcdSendStringRaw( "Inicio" );
	lcdGoToXY(2,3);
	lcdSendStringRaw( "Salir" );
	lcdGoToXY(19,3);
	lcdSendInt( contPulsados );

}


bool_t ejecucion_ensayo(int64_t a){
	int64_t i;
		for(i=0;i<a;i++){
		lcdGoToXY( 0, 0 );
		lcdSendStringRaw( "Val Muestra" );
		lcdGoToXY(0,1);
		lcdSendStringRaw( "Duracion" );
		lcdSendIntFormXY(i,12,1);
		delay(1000);
		lcdClear();
	}
        return FALSE;
	}

void termino_ensayo(void){
int64_t i;
int64_t j;
for (i=0;i<=3;i++){
	for(j=0;j<=19;j++){
		lcdGoToXY(j,i);
		delay(100);
		lcdSendStringRaw( "-" );
	}

}
	}



/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
