/*
 * Vivienda.h
 *
 *  Created on: 22 jun. 2022
 *      Author: Alfonso
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include "Catastro.h"

struct {
	int idVivienda;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int idCatastro;
	int isEmpty;
}typedef Vivienda;



int addVivienda(Vivienda* list, int len, int id, char calle[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista, int idCatastro);

int findViviendaById(Vivienda* list, int len,int id);

int removeVivienda(Vivienda* list, int len, int id);

int printViviendas(Vivienda* list, int length, Catastro* catastros, int lenCatastros);

void initEmpty(Vivienda* list, int length);


#endif /* VIVIENDA_H_ */
