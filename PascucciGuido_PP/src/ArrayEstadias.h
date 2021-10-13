

#ifndef ARRAYESTADIAS_H_
#define ARRAYESTADIAS_H_


#include "ArrayPerros.h"



typedef struct
{
 int id;
 char nombreDuenio[21];
 int telefonoContacto;
 int idPerro;
 int fecha;
 int espacioVacio;
} sEstadiaDiaria;




void inicializarEstadias(sEstadiaDiaria* listaEstadias, int length);





#endif
