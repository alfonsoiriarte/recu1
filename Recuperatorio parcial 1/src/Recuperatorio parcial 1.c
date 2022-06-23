/*
 ============================================================================
 Name        : TP2-Alfonso-Iriarte.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "custFunctions.h"
#include "Vivienda.h"
#include "Censista.h"
#include "Catastro.h"

#define LENGTH 3

int main(void) {
	setbuf(stdout, NULL);

	Censista censistas[3] = {{100, "Ana", 34, "1203-2345"}, {101, "Juan", 24, "4301-5467"}, {102, "Sol", 47, "5902-3748"}};
	Catastro catastros[5] = {{1000, "Avellaneda", 28, 1540}, {1001, "Lanus", 43, 1789}, {1002, "Quilmes", 32, 1624}, {1003, "La Plata", 67, 1677}, {1004, "Lomas de Zamora", 32, 1923}};

	Vivienda viviendas[LENGTH];

	int flagPrograma = 1;
	int flagOpcion = 0;
	int opcion = 0;

	//Inicializo campo isEmpty de viviendas
	initEmpty(viviendas, LENGTH);

	while(flagPrograma == 1){

		ingresarOpcion(&opcion);
		menu(viviendas, LENGTH, censistas, 3, opcion, &flagOpcion, &flagPrograma, catastros, 5);
	}

	return EXIT_SUCCESS;
}

