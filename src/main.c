#include "estadosBoton.h"
#include <sapi.h>
#include "pirulito.h"

void main(void){




boardConfig();
boton bn;
boton boton2;
Pirulito pirulo;
Pirulito pirulo2;


void onPres(void * p){
	((Pirulito *)p)->estado = 1;
}

void onRelease(void * p){
	((Pirulito *)p)->estado = 0;
}

iniciarPirulito(&pirulo, LED2);
iniciarPirulito(&pirulo2, LED1);

inciar(&bn,TEC2,onPres,onRelease, &pirulo);
inciar(&boton2,TEC1,onPres,onRelease, &pirulo2);

while (1){

	 controladorBoton(&bn);
	 controladorBoton(&boton2);
	 controladorPirulito(&pirulo);
	 controladorPirulito(&pirulo2);
	 delay(10);
}

}



