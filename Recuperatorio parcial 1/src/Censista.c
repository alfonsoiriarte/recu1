/*
 * Censista.c
 *
 *  Created on: 23 jun. 2022
 *      Author: Alfonso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censista.h"

void printCensistas(Censista* list, int length){ //Listo censistas
	printf("\n\n\n--------------------LISTA DE CENSISTAS--------------------");
	for(int i=0;i<length;i++){
		printf("\n\n--Censista N°%d", i);
		printf("\n--Legajo: %d", (list+i)->legajoCensista);
		printf("\n--Nombre: %s", (list+i)->nombre);
		printf("\n--Edad: %d", (list+i)->edad);
		printf("\n--Telefono: %s", (list+i)->telefono);
	}

}
