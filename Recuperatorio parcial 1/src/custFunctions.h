/*
 * custFunctions.h
 *
 *  Created on: 14 may. 2022
 *      Author: Alfonso
 */
#include "Vivienda.h"
#include "Censista.h"
#include "Catastro.h"

#ifndef CUSTFUNCTIONS_H_
#define CUSTFUNCTIONS_H_

#endif /* CUSTFUNCTIONS_H_ */

void ingresarOpcion(int *opcion);

int viviendaVacia(Vivienda *pasajero, int len);

void modificarVivienda(Vivienda* list, int len, int id);

void cargarVivienda(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros);

void menu(Vivienda* list, int len, Censista* censistas, int lenCensistas, int opcion,int *flagOpcion, int *flagPrograma, Catastro* catastros, int lenCatastros);

void showViviendasTipo(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros);

void showViviendasLocalidad(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros);

void cantAvellaneda(Vivienda* list, int len, Catastro* catastros, int lenCatastros);

void viviendasPorCensista(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros);

void cantViviendasCasa(Vivienda* list, int len, Catastro* catastros, int lenCatastros);

void listarCatastros(Catastro* catastros, int lenCatastros);

void cantViviendasDepartamentoLanus(Vivienda* list, int len, Catastro* catastros, int lenCatastros);


