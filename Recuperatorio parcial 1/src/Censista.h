/*
 * Censista.h
 *
 *  Created on: 22 jun. 2022
 *      Author: Alfonso
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

struct {
	int legajoCensista;
	char nombre[51];
	int edad;
	char telefono[9];
}typedef  Censista;


void printCensistas(Censista* list, int length);

#endif /* CENSISTA_H_ */
