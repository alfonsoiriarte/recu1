/*
 * Vivienda.c
 *
 *  Created on: 22 jun. 2022
 *      Author: Alfonso
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vivienda.h"
#include "Catastro.h"



int addVivienda(Vivienda* list, int len, int id, char calle[], int cantidadPersonas, int cantidadHabitaciones, int tipoVivienda, int legajoCensista, int idCatastro){

	for(int i=0;i<len;i++){
		if(list[i].isEmpty == 1){
			(list+i)->idVivienda = id;
			strcpy((list+i)->calle, calle);
			(list+i)->cantidadPersonas = cantidadPersonas;
			(list+i)->cantidadHabitaciones = cantidadHabitaciones;
			(list+i)->tipoVivienda = tipoVivienda;
			(list+i)->legajoCensista = legajoCensista;
			(list+i)->idCatastro = idCatastro;
			(list+i)->isEmpty = 0;
			break;
		}
	}

	printf("\n\n--Vivienda añadida exitosamente.");
	return 0;
}

int findViviendaById(Vivienda* list, int len,int id){
	for(int i=0;i<len;i++){
		if(list[i].idVivienda == id){
			return i;
		}
	}
	return -1;
}

int removeVivienda(Vivienda* viviendas, int len, int id){
	int pos = findViviendaById(viviendas, len, id);

	(viviendas+pos)->idVivienda = id;
	strcpy((viviendas+pos)->calle, "");
	(viviendas+pos)->cantidadHabitaciones = -1;
	(viviendas+pos)->tipoVivienda = -1;
	(viviendas+pos)->legajoCensista = 000;
	(viviendas+pos)->idCatastro = -1;
	(viviendas+pos)->isEmpty = 1;

	printf("Censista eliminado correctamente.");
	return 0;
}

int printViviendas(Vivienda* list, int length, Catastro* catastros, int lenCatastros){
	printf("\n\n------------------Viviendas------------------ ");

	for(int i=0;i<length;i++){
		if(list[i].isEmpty == 0){
			printf("\n\nVivienda N°%d", i);
			printf("\nID: %d", list[i].idVivienda);
			printf("\nCalle: %s", list[i].calle);
			printf("\nCantidad de personas: %d", list[i].cantidadPersonas);
			printf("\nCantidad de habitaciones: %d", list[i].cantidadHabitaciones);
			switch(list[i].tipoVivienda){
				case 1:
					printf("\nTipo de vivienda: Casa");
					break;
				case 2:
					printf("\nTipo de vivienda: Departamento");
					break;
				case 3:
					printf("\nTipo de vivienda: Rancho");
					break;
				case 4:
					printf("\nTipo de vivienda: Rancho");
					break;
			}
			printf("\nLegajo: %d", list[i].legajoCensista);
			printf("\nCatastro: %d", list[i].idCatastro);
			for(int j=0;j<lenCatastros;j++){
				if((catastros+j)->idCatastro == (list+i)->idCatastro){
					printf("\nLocalidad: %s", (catastros+j)->localidad);
					printf("\nManzana: %d", (catastros+j)->manzana);
					printf("\nParcela: %d", (catastros+j)->parcela);
				}
			}
		}
	}
	return 0;
}

void initEmpty(Vivienda* list, int length){
	for(int i=0;i<length;i++){
		(list+i)->isEmpty = 1;
	}
}
