
#include "pirulito.h"
#include <sapi.h>
#include <sapi_gpio.h>

void iniciarPirulito(Pirulito * pt, gpioMap_t pin){
	pt->estado=Pres;
	pt->pin=pin;
}

void controladorPirulito(Pirulito * bn){
	gpioWrite(bn->pin,bn->estado);
}


