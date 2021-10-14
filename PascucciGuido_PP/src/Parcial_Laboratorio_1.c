/*
 ============================================================================
 Name        : Parcial_Laboratorio_1.c
 Author      : Pascucci, Guido Gabriel
 Description : Parcial Laboratorio - Parte I
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include "NuevoNexo.h"
#include "ArrayPerros.h"
#include "ArrayEstadias.h"



int main(void) {
	setbuf(stdout, NULL);

	printf("\n\t\t\tGuarderia de Perritos\n\t\t\tBienvenidxs!\n");

	sPerro perritos[MAX_PERROS];
	sEstadiaDiaria estadiaDiaria[MAX_PERROS];

	inicializarPerritos(perritos, MAX_PERROS);
	inicializarEstadias(estadiaDiaria, MAX_PERROS);

	hardcodePerros(perritos, MAX_PERROS);


	mainMenu(estadiaDiaria, perritos, MAX_PERROS);


	printf("\n\nGracias por utilizar nuestros servicios. Nos vemos!\n\n");

	return EXIT_SUCCESS;
}
































