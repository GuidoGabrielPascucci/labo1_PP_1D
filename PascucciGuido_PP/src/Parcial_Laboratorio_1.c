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

	printf("Guarderia para perros\nBienvenido!\n\n\n");

	sPerro perritos[MAX_PERROS];
	sEstadiaDiaria estadiaDiaria[MAX_PERROS];

	inicializarPerritos(perritos, MAX_PERROS);
	inicializarEstadias(estadiaDiaria, MAX_PERROS);

	hardcodePerros(perritos, MAX_PERROS);


	mainMenu(estadiaDiaria, perritos, MAX_PERROS);


	printf("\n\nGracias por utilizar nuestros servicios. Nos vemos!\n\n");

	return EXIT_SUCCESS;
}




/*
Desarrollar en ANSI C:
Se necesita gestionar una guardería de perros. Para eso se deberá desarrollar lo siguiente:

ENTIDADES:

Perro:
● id
● nombre (máximo 21 caracteres)
● raza (máximo 21 caracteres)
● edad

EstadiaDiaria:
● id (comienza en 100000, autoincremental)
● nombreDuenio (cadena de caracteres) Validar
● telefonoContacto (sólo números) Validar
● idPerro (debe existir) Validar
● fecha (Validar día, mes y año)


DATOS PREVIOS:
El array de perros será hardcodeado.
Perros
1) 7000, Lobo, Sharpei, 2
2) 7001, Sheila, Golden, 12
3) 7002, Reina, Galgo, 13


MENÚ DE OPCIONES:
1. RESERVAR ESTADIA
2. MODIFICAR ESTADIA: Se ingresará el id, permitiendo en un submenú modificar:
● El teléfono de contacto
● El perro
3. CANCELAR ESTADÍA: Se ingresará el id de la estadía y se realizará una baja lógica.
4. LISTAR ESTADÍAS: Hacer un listado de las estadías ordenadas por fecha (las más
nuevas irán primero). Ante igualdad de fechas, se ordenará por el nombre del dueño.
5. LISTAR PERROS
6. Promedio de edad de los perros.


NOTAS:
I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las funciones Alta, Baja, Modificar y Listar.
II. Las validaciones (input), deberán estar en una biblioteca aparte.
III. Tener en cuenta que no se podrá ingresar a los casos Modificar, Baja, Listar e Informes; sin antes haber realizado al
menos un Alta (utilizar banderas y/o contadores).
IV. El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas de
estilo de la cátedra.
*/






























