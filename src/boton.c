#include "estadosBoton.h"
#include <sapi.h>

void inciar(boton * bn,gpioMap_t botonn,buttonhander onPressP,buttonhander onReleaseP, void * modelo){
	bn->estado = Button_up;
	bn->ultimoCambio=tickRead();
	bn->boton=botonn;
	bn->onPress=onPressP;
	bn->onRelease=onReleaseP;
	bn->modelo=modelo;
}



void controladorBoton(boton * bn){
	int tickActual = tickRead();
	int tiempoPasado1 = tickActual - bn->ultimoCambio;

	switch(bn->estado){
		case Button_up :{
			if(gpioRead(bn->boton) == 0){
				bn->estado=Button_falling;
				bn->quePaso=0;
				bn->ultimoCambio=tickActual;
			}else{
				bn->estado = Button_up;
			}
			break;
		}
		case Button_falling :{
			if(tiempoPasado1 >= 40 ){
				if(gpioRead(bn->boton) == 0){
					bn->estado = Button_down;
					bn->onPress(bn->modelo);
				}else{
					bn->estado= Button_up;
				}

				bn->ultimoCambio=tickActual;
			}
			break;
		}
		case Button_down:{
				if(gpioRead(bn->boton) == 1){
					bn->estado = Button_rising;
					bn->quePaso=1;
				}
				break;
			}
		case Button_rising:{
					if(tiempoPasado1 >= 40 ){
						if(gpioRead(bn->boton) == 1){
							bn->estado = Button_up;
							bn->onRelease(bn->modelo);
						}else{
							bn->estado= Button_down;
						}
						bn->ultimoCambio=tickActual;
					}
					break;
				}

	}
}




