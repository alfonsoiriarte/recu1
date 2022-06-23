/*
 * custFunctions.c
 *
 *  Created on: 14 may. 2022
 *      Author: Alfonso
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vivienda.h"
#include "Censista.h"
#include "Catastro.h"

void ingresarOpcion(int *opcion){ //Muestro menu y pido ingreso de opcion numerica
	printf("\n\n----------------------------------------------Menu----------------------------------------------");
	printf("\n\n1. Alta vivienda \n2. Modificar vivienda \n3. Baja vivienda\n4. Listar viviendas.\n5. Listar censistas.\n6. Listar viviendas por tipo de vivienda.\n7. Listar viviendas por localidad \n8. Cantidad de viviendas censadas en Avellaneda. \n9. Listar viviendas por censista. \n11. Cantidad de departamentos censados en Lanús. \n12. Listar Catastro ordenado por localidad \nIngrese el numero de la opcion correspondiente:");
	fflush(stdin);
	scanf("%d", &*opcion);
	while(*opcion < 1 || *opcion > 12) {
		printf("ERROR: Ingrese un numero de opcion valido.");
		printf("\n\n1. Alta vivienda \n2. Modificar vivienda \n3. Baja vivienda\n4. Listar censistas.\n5. Listar censistas. \nIngrese el numero de la opcion correspondiente:");
		fflush(stdin);
		scanf("%d", &*opcion);
	}
}

int viviendaVacia(Vivienda *vivienda, int len){ //retorna posicion de la vivienda vacia
	for(int i=0;i<len;i++){
		if(vivienda[i].isEmpty == 1){
			return  i;
		}
	}
	return -1;
}

void modificarVivienda(Vivienda* list, int len, int id){ //Pido seleccion de dato a modificar y pido reingreso del dato
	int opcion;
	printf("\n\n1. Modificar calle \n2. Modificar cantidad de personas \n3. Modificar cantidad de habitaciones \n4. Modificar tipo de vivienda\nIngrese el numero de la opcion correspondiente:");
	fflush(stdin);
	scanf("%d", &opcion);
	while(opcion < 1 || opcion > 4) {
		printf("\nERROR: Ingrese un numero de opcion valido.");
		printf("\n\n1. Modificar calle \n2. Modificar cantidad de personas \n3. Modificar cantidad de habitaciones \n4. Modificar tipo de vivienda\nIngrese el numero de la opcion correspondiente:");
		fflush(stdin);
		scanf("%d", &opcion);
	}

	int auxPos;
	for(int i=0;i<len;i++){
		if((list+i)->idVivienda == id){
			auxPos=i;
		}
	}
	switch(opcion){
		case 1:
			printf("Ingrese la calle: ");
			fflush(stdin);
			gets((list+auxPos)->calle);
			break;
		case 2:
			printf("Ingrese la cantidad de personas: ");
			fflush(stdin);
			scanf("%d", &(list+auxPos)->cantidadPersonas);
			break;
		case 3:
			printf("Ingrese la cantidad de habitaciones: ");
			scanf("%d", &(list+auxPos)->cantidadHabitaciones);
			break;
		case 4:
			printf("Tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ");
			scanf("%d", &(list+auxPos)->tipoVivienda);
			break;
	}
}

void cargarVivienda(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros){ //Pido datos de vivienda, valido legajo, catastro y seteo id
	Vivienda viviendaACargar;

	printf("\nIngrese calle: ");
	fflush(stdin);
	gets(viviendaACargar.calle);
	printf("\nIngrese la cantidad de personas: ");
	fflush(stdin);
	scanf("%d", &viviendaACargar.cantidadPersonas);
	printf("\nIngrese la cantidad de habitaciones: ");
	scanf("%d", &viviendaACargar.cantidadHabitaciones);
	printf("\nTipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ");
	scanf("%d", &viviendaACargar.tipoVivienda);

	printf("\nIngrese legajo censista (debe existir): ");
	fflush(stdin);
	scanf("%d", &viviendaACargar.legajoCensista);
																					//Valido legajo
	int legajoExistente = 0;
	for(int i=0;i<lenCensistas;i++){
		if(viviendaACargar.legajoCensista == (censistas+i)->legajoCensista){
			legajoExistente=1;
		}
	}
	while(legajoExistente != 1){
		printf("\n\n--ERROR - Ingrese legajo censista EXISTENTE: ");
		fflush(stdin);
		scanf("%d", &viviendaACargar.legajoCensista);
		for(int i=0;i<lenCensistas;i++){
			if(viviendaACargar.legajoCensista == (censistas+i)->legajoCensista){
				legajoExistente=1;
			}
		}
	}

	printf("Ingrese el id del catastro (debe existir): ");
	scanf("%d", &viviendaACargar.idCatastro);
																					//Valido catastro
	int catastroExistente = 0;
	for(int i=0;i<lenCatastros;i++){
		if(viviendaACargar.idCatastro == (catastros+i)->idCatastro){
			catastroExistente=1;
		}
	}
	while(catastroExistente != 1){
		printf("\n\n--ERROR - Ingrese un id de catastro EXISTENTE: ");
		fflush(stdin);
		scanf("%d", &viviendaACargar.idCatastro);
		for(int i=0;i<lenCatastros;i++){
			if(viviendaACargar.idCatastro == (catastros+i)->idCatastro){
				catastroExistente=1;
			}
		}
	}
																					//Seteo id de vivienda
	for(int i=0;i<len;i++){
		if((list+i)->isEmpty == 1){
			viviendaACargar.idVivienda = (list+i-1)->idVivienda + 1;
			if(i==0){
				viviendaACargar.idVivienda = 20000;
			}
			break;
		}
	}

	addVivienda(list, len, viviendaACargar.idVivienda, viviendaACargar.calle, viviendaACargar.cantidadPersonas, viviendaACargar.cantidadHabitaciones, viviendaACargar.tipoVivienda, viviendaACargar.legajoCensista,  viviendaACargar.idCatastro);
}

void showViviendasTipo(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros){ //Listo viviendas por tipo
	int auxTipo = 0;
	printf("Ingrese el tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ");
	scanf("%d", &auxTipo);
	while(auxTipo < 1 || auxTipo > 4){
		printf("ERROR - VIVIENDA INVALIDA | Ingrese el tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ");
		scanf("%d", &auxTipo);
	}

	printf("\n\n----------------------Viviendas por tipo----------------------");
	for(int i=0;i<len;i++){
		if((list+i)->isEmpty == 0 && auxTipo == (list+i)->tipoVivienda){
			printf("\n\nID: %d", (list+i)->idVivienda);
			printf("\nCalle: %s", (list+i)->calle);
			printf("\nCantidad de personas: %d", (list+i)->cantidadPersonas);
			printf("\nCantidad de habitaciones: %d", (list+i)->cantidadHabitaciones);
			switch((list+i)->tipoVivienda){
				case 1:
					printf("\nTipo de vivienda: Casa");
					break;
				case 2:
					printf("\nTipo de vivienda: Departamento");
					break;
				case 3:
					printf("\nTipo de vivienda: Casilla");
					break;
				case 4:
					printf("\nTipo de vivienda: Rancho");
					break;
			}
			printf("\nLegajo: %d", (list+i)->legajoCensista);
			printf("\nId catastro: %d", (list+i)->idCatastro);

			for(int j=0;j<lenCensistas;j++){
				if((censistas+j)->legajoCensista == (list+i)->legajoCensista){
					printf("\n---Censista: %s", (censistas+j)->nombre);
				}
			}
			for(int j=0;j<lenCatastros;j++){
				if((catastros+j)->idCatastro == (list+i)->idCatastro){
					printf("\nLocalidad: %s", (catastros+j)->localidad);
					printf("\nManzana: %d", (catastros+j)->manzana);
					printf("\nParcela: %d", (catastros+j)->parcela);
				}
			}

		}
	}
	printf("\n\n------------------------------------------------------------------");
}

void showViviendasLocalidad(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros){ //Listo viviendas por localidad
	char auxTipo[16];
	printf("Ingrese la localidad (Avellaneda, Lanus, Quilmes, La Plata, Lomas de Zamora): ");
	scanf("%s", auxTipo);
	while(strcmp(auxTipo, "Avellaneda") != 0 && strcmp(auxTipo, "Lanus") != 0 && strcmp(auxTipo, "Quilmes") != 0 && strcmp(auxTipo, "La Plata") != 0 && strcmp(auxTipo, "Lomas de Zamora") != 0){
		printf("ERROR - VIVIENDA INVALIDA | Ingrese la localidad (Avellaneda, Lanus, Quilmes, La Plata, Lomas de Zamora): ");
		scanf("%s", auxTipo);
	}

	printf("\n\n----------------------Viviendas por localidad----------------------");
	printf("\n\n-----------%s", auxTipo);
	for(int i=0;i<len;i++){
		for(int k=0;k<lenCatastros;k++){
			if((list+i)->idCatastro == (catastros+k)->idCatastro && strcmp(auxTipo, (catastros+k)->localidad) == 0 && (list+i)->isEmpty == 0){
				printf("\n\nID: %d", (list+i)->idVivienda);
				printf("\nCalle: %s", (list+i)->calle);
				printf("\nCantidad de personas: %d", (list+i)->cantidadPersonas);
				printf("\nCantidad de habitaciones: %d", (list+i)->cantidadHabitaciones);
				switch((list+i)->tipoVivienda){
					case 1:
						printf("\nTipo de vivienda: Casa");
						break;
					case 2:
						printf("\nTipo de vivienda: Departamento");
						break;
					case 3:
						printf("\nTipo de vivienda: Casilla");
						break;
					case 4:
						printf("\nTipo de vivienda: Rancho");
						break;
				}
				printf("\nLegajo: %d", (list+i)->legajoCensista);
				printf("\nId catastro: %d", (list+i)->idCatastro);

				for(int j=0;j<lenCensistas;j++){
					if((censistas+j)->legajoCensista == (list+i)->legajoCensista){
						printf("\nNombre del censista: %s", (censistas+j)->nombre);
					}
				}
			}
		}
	}
	printf("\n\n------------------------------------------------------------------");
}

void cantAvellaneda(Vivienda* list, int len, Catastro* catastros, int lenCatastros){ //Informo la cantidad de viviendas en avellaneda

	char auxTipo[10] = "Avellaneda";
	int count = 0;
	for(int i=0;i<len;i++){
		for(int k=0;k<lenCatastros;k++){
			if((list+i)->idCatastro == (catastros+k)->idCatastro && strcmp(auxTipo, (catastros+k)->localidad) == 0 && (list+i)->isEmpty == 0){
				count++;
			}
		}
	}
	printf("\n-Cantidad de viviendas censadas en avellaneda: %d", count);

}

void viviendasPorCensista(Vivienda* list, int len, Censista* censistas, int lenCensistas, Catastro* catastros, int lenCatastros){ //Listo las viviendas por nombre de censista
	char auxCensista[51];
	int salirFlag = 0;
	printf("\n\nCensistas: \n");
	for(int i=0;i<lenCensistas;i++){
		printf("\n-- %s", (censistas+i)->nombre);
	}
	printf("Ingrese el nombre del censista: ");
	scanf("%s", auxCensista);
	for(int j=0;j<lenCensistas;j++){
		if(strcmp(auxCensista, (censistas+j)->nombre) == 0){
			salirFlag=1;
		}
	}
	while(salirFlag==0){
		printf("ERROR - Ingrese un nombre de censista correcto: ");
		scanf("%s", auxCensista);
		for(int j=0;j<lenCensistas;j++){
			if(strcmp(auxCensista, (censistas+j)->nombre) == 0){
				salirFlag=1;
			}
		}
	}


	printf("\n\n----------------------Viviendas por censista----------------------");
		for(int i=0;i<len;i++){
			for(int k=0;k<lenCensistas;k++){
				if((list+i)->isEmpty == 0 && strcmp(auxCensista, (censistas+k)->nombre) == 0 && (list+i)->legajoCensista == (censistas+k)->legajoCensista){
					printf("\n\nID: %d", (list+i)->idVivienda);
					printf("\nCalle: %s", (list+i)->calle);
					printf("\nCantidad de personas: %d", (list+i)->cantidadPersonas);
					printf("\nCantidad de habitaciones: %d", (list+i)->cantidadHabitaciones);
					switch((list+i)->tipoVivienda){
						case 1:
							printf("\nTipo de vivienda: Casa");
							break;
						case 2:
							printf("\nTipo de vivienda: Departamento");
							break;
						case 3:
							printf("\nTipo de vivienda: Casilla");
							break;
						case 4:
							printf("\nTipo de vivienda: Rancho");
							break;
					}
					printf("\nLegajo: %d", (list+i)->legajoCensista);
					printf("\nId catastro: %d", (list+i)->idCatastro);

					for(int j=0;j<lenCensistas;j++){
						if((censistas+j)->legajoCensista == (list+i)->legajoCensista){
							printf("\n---Censista: %s", (censistas+j)->nombre);
						}
					}
					for(int j=0;j<lenCatastros;j++){
						if((catastros+j)->idCatastro == (list+i)->idCatastro){
							printf("\nLocalidad: %s", (catastros+j)->localidad);
							printf("\nManzana: %d", (catastros+j)->manzana);
							printf("\nParcela: %d", (catastros+j)->parcela);
						}
					}
				}
			}
		}
		printf("\n\n------------------------------------------------------------------");
}

void cantViviendasCasa(Vivienda* list, int len, Catastro* catastros, int lenCatastros){ //Informo la cantidad de viviendas tipo casa
	int count = 0;
	for(int i=0;i<len;i++){
		if((list+i)->tipoVivienda == 1 && (list+i)->isEmpty == 0){
			count++;
		}
	}
	printf("Cantidad de viviendas tipo casa: %d", count);
}

void cantViviendasDepartamentoLanus(Vivienda* list, int len, Catastro* catastros, int lenCatastros){ // Informo cantidad de viviendas tipo departamento en lanus
	int count = 0;
	for(int i=0;i<len;i++){
		if((list+i)->tipoVivienda == 2 && (list+i)->isEmpty == 0){
			for(int j=0;j<lenCatastros;j++){
				if((list+i)->idCatastro == (catastros+j)->idCatastro && strcmp("Lanus", (catastros+j)->localidad) == 0){
					count++;
				}
			}
		}
	}
	printf("Cantidad de departamentos censados en Lanus: %d", count);
}

void listarCatastros(Catastro* catastros, int lenCatastros){ //Listo catastros
	printf("\n\n--------------------Catastros por localidad--------------------");
	for(int i=0;i<lenCatastros;i++){
		printf("\nId de catastro: %d", (catastros+i)->idCatastro);
		printf("\nLocalidad: %s", (catastros+i)->localidad);
		printf("\nManzana: %d", (catastros+i)->manzana);
		printf("\nParcela: %d", (catastros+i)->parcela);
	}
	printf("\n\n---------------------------------------------------------------\n");
}

void menu(Vivienda* list, int len, Censista* censistas, int lenCensistas, int opcion,int *flagOpcion, int *flagPrograma, Catastro* catastros, int lenCatastros){ //Menu del programa con llamadas a las funciones correspondientes

	int idAModificar = 0;
	int flagIdValido = 0;


	switch(opcion){
		case 1:
			cargarVivienda(list, len, censistas, lenCensistas, catastros, lenCatastros);
			*flagOpcion = 1;
			break;
		case 2:
			if(*flagOpcion >= 1){
				printf("\n\nIngrese el id de la vivienda que quiera modificar");
				scanf("%d", &idAModificar);
				for(int i=0;i<len;i++){
					if(idAModificar == (list+i)->idVivienda){
						flagIdValido = 1;
						break;
					}
				}
				while(flagIdValido != 1){
					printf("\n\nID INVALIDO");
					printf("\nIngrese el id de la vivienda que quiera modificar");
					scanf("%d", &idAModificar);
					for(int i=0;i<len;i++){
						if(idAModificar == (list+i)->idVivienda){
							flagIdValido = 1;
							break;
						}
					}
				}
				modificarVivienda(list, len, idAModificar);
				*flagOpcion = 2;
			} else{
				printf("\n\nPara poder modificar una vivienda debe haber ingresado una anteriormente.");
			}
			break;
		case 3:
			if(*flagOpcion >= 1){
				printf("\n\nIngrese el id de la vivienda que quiera eliminar");
				scanf("%d", &idAModificar);
				for(int i=0;i<len;i++){
					if((list+i)->idVivienda == idAModificar){
						flagIdValido = 1;
					}
				}
				while(flagIdValido != 1){
					printf("\n\nID INVALIDO");
					printf("\nIngrese el id de la vivienda que quiera eliminar");
					scanf("%d", &idAModificar);
					for(int i=0;i<len;i++){
						if((list+i)->idVivienda == idAModificar){
							flagIdValido = 1;
						}
					}
				}
				removeVivienda(list, len,  idAModificar);
				*flagOpcion = 3;
			} else printf("\n\nPara poder dar de baja una vivienda debe haber ingresado una anteriormente.");
			break;
		case 4:
			if(*flagOpcion >= 1){
				printViviendas(list, len, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder listar las viviendas debe haber ingresado una anteriormente.");

			break;
		case 5:
				printCensistas(censistas, lenCensistas);
			break;
		case 6:
			if(*flagOpcion >= 1){
				showViviendasTipo(list,  len, censistas, lenCensistas, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder listar por tipo de vivienda debe haber ingresado una anteriormente.");

			break;
		case 7:
			if(*flagOpcion >= 1){
				showViviendasLocalidad(list,  len, censistas, lenCensistas, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder listar por localidad debe haber ingresado una anteriormente.");
			break;
		case 8:
			if(*flagOpcion >= 1){
				cantAvellaneda(list, len, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder informar la cantidad de viviendas en Avellaneda debe haber ingresado una anteriormente.");
			break;
		case 9:
			if(*flagOpcion >= 1){
				viviendasPorCensista(list, len, censistas, lenCensistas, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder listar las viviendas por censista debe haber ingresado una anteriormente.");
			break;
		case 10:
			if(*flagOpcion >= 1){
				cantViviendasCasa(list, len, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder informar la canstidad de viviendas censadas debe haber ingresado una anteriormente.");
			break;
		case 11:
			if(*flagOpcion >= 1){
				cantViviendasDepartamentoLanus(list, len, catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder informar la canstidad de departamentos censados en Lanus debe haber ingresado una vivienda anteriormente.");
			break;
		case 12:
			if(*flagOpcion >= 1){
				listarCatastros(catastros, lenCatastros);
				*flagOpcion = 4;
			} else printf("\n\nPara poder informar la canstidad de departamentos censados en Lanus debe haber ingresado una vivienda anteriormente.");
			break;
	}
}

