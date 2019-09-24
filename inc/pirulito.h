/*
 * pirulito.h
 *
 *  Created on: 21 sep. 2019
 *      Author: nahuel
 */

#ifndef PROGRAMS_PIRULITO_INC_PIRULITO_H_
#define PROGRAMS_PIRULITO_INC_PIRULITO_H_
#include <sapi.h>
#include <sapi_gpio.h>

enum EstadoDePirlito{
	Pres,Release
};

typedef struct pirulito{
	int estado;
	gpioMap_t pin;
}Pirulito;

void iniciarPirulito(Pirulito * pt, gpioMap_t pin);
void controladorPirulito(Pirulito * bn);


#endif /* PROGRAMS_PIRULITO_INC_PIRULITO_H_ */
