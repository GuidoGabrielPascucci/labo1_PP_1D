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

	printf("\n\t\t\t\t\tGuarderia de Perritos\n\t\t\t\t\t     Bienvenidxs!\n");

	sPerro perritos[MAX_PERROS];
	sEstadiaDiaria estadias[MAX_PERROS];

	inicializarPerritos(perritos, MAX_PERROS);
	inicializarEstadias(estadias, MAX_PERROS);

	sPerro_hardcodeo(perritos, MAX_PERROS);


	mainMenu(estadias, perritos, MAX_PERROS);



	printf("\n\n\t\t\t\tGracias por utilizar nuestros servicios. Nos vemos!\n\n");

	return EXIT_SUCCESS;
}




