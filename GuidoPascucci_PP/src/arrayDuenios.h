

#ifndef ARRAYDUENIOS_H_
#define ARRAYDUENIOS_H_


#include "ArrayPerros.h"


typedef struct
{

	int id;
	char nombre[MAX_NOMBRE_DUENIO];
	int telefono;

} sDuenio;



void sDuenio_hardcodear(sDuenio* listaDuenios, int length);
void mostrarListaDuenios(sDuenio* duenios, int length);
void mostrarDuenio(sDuenio* duenios, int index);
int seleccionarIdDelDuenio(sDuenio* listaDuenios, int length);




#endif
