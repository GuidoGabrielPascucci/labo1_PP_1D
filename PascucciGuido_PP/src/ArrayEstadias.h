

#ifndef ARRAYESTADIAS_H_
#define ARRAYESTADIAS_H_


#include "ArrayPerros.h"


typedef struct
{

	int dia;
	int mes;
	int anio;

} sFecha;


typedef struct
{

 int id;
 char nombreDuenio[21];
 int telefonoContacto;
 int idPerro;
 sFecha fecha;
 int espacioVacio;

} sEstadiaDiaria;



// INICIALIZAR ESTADIAS
void inicializarEstadias(sEstadiaDiaria* listaEstadias, int length);


// BUSCAR ESPACIO LIBRE EN ESTADIAS
int buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int length);




// PEDIR DATOS DE ESTADIA
int pedirTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index);




// MODIFICACIONES
void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index);



// MOSTRAR
void mostrarListaEstadias(sEstadiaDiaria* estadias, int length);
void mostrarEstadia(sEstadiaDiaria* estadias, int index);













#endif
