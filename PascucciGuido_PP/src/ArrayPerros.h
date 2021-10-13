
#ifndef ARRAYPERROS_H_
#define ARRAYPERROS_H_

#define ID 100000
#define MAX_PERROS 10
#define MAX_NOMBRE 21
#define TRUE 1
#define FALSE 0

#include "ArrayEstadias.h"


typedef struct
{
 int id;
 char nombre[MAX_NOMBRE];
 char raza[MAX_NOMBRE];
 int edad;
 int espacioVacio;
} sPerro;




void inicializarPerritos(sPerro* perritos, int length);
void hardcodePerros(sPerro* perritos, int length);

int promedioEdadPerros(sPerro* perritos, int length, int contadorAltas);



#endif




