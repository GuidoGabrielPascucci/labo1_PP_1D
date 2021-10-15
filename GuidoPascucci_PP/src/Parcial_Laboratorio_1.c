/*
 ============================================================================
 Name        : Parcial_Laboratorio_1.c
 Author      : Pascucci, Guido Gabriel
 Description : Parcial Laboratorio - Parte I
 ============================================================================
*/

/*
			Parte 2 (Refactorización e Informes)

Para esta instancia del parcial, deberá agregar la siguiente estructura y relacionarla de
manera adecuada con la/s estructura/s de la parte 1. Eliminando de las anteriores los
campos que sobren.

Duenio:
● id (comienza en 30000)
● nombre(máximo 41 caracteres)
● telefono (int)

Hardcodear por lo menos 5 dueños.

Nota importante: Deberá impactar este cambio en las funcionalidades solicitadas en la
parte 1. Recordar que al dar de alta una estadía, se deberá verificar que el dueño ingresado
exista.

Agregar los siguientes informes:
7. El perro que tiene más estadías reservadas.
8. Listado de perros con sus estadías diarias reservadas.

*/


#include <stdio.h>
#include <stdlib.h>

#include "NuevoNexo.h"
#include "ArrayPerros.h"
#include "ArrayEstadias.h"
#include "ArrayDuenios.h"


int main(void) {
	setbuf(stdout, NULL);

	printf("\n\t\t\t\t\tGuarderia de Perritos\n\t\t\t\t\t     Bienvenidxs!\n");

	sPerro perritos[MAX_PERROS];
	sEstadiaDiaria estadias[MAX_PERROS];
	sDuenio duenios[MAX_DUENIOS];

	inicializarPerritos(perritos, MAX_PERROS);
	inicializarEstadias(estadias, MAX_PERROS);

	sPerro_hardcodeo(perritos, MAX_PERROS);

	sDuenio_hardcodear(duenios, MAX_DUENIOS);


	mainMenu(estadias, perritos, MAX_PERROS, duenios, MAX_DUENIOS);



	printf("\n\n\t\t\t\tGracias por utilizar nuestros servicios. Nos vemos!\n\n");

	return EXIT_SUCCESS;
}






