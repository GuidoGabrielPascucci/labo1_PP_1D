
#ifndef NUEVONEXO_H_
#define NUEVONEXO_H_


#include "ArrayEstadias.h"
#include "ArrayPerros.h"
#include "ArrayDuenios.h"



void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, sDuenio* listaDuenios, int lengthDuenios);
//void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length);

void agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId, int* contadorAltas, sDuenio* listaDuenios, int lengthDuenios);
//void agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId, int* contadorAltas);

int cargarDatosDeEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, sDuenio* listaDuenios, int lengthDuenios, int index, int* contadorId);
//int cargarDatosDeEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int index, int* contadorId);


void modificarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int contadorId, int contadorAltas);
void modificarEstadiaMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int index);
void modificarPerro(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, int length, int index);

void cancelarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int* contadorAltas);


void mostrarEstadia(sEstadiaDiaria* estadias, sPerro* listaPerritos, int length, int i, int j, sDuenio* listaDuenios, int lengthDuenios);


void mostrarListaEstadias(sEstadiaDiaria* estadias, sPerro* listaPerritos, int length, sDuenio* listaDuenios, int lengthDuenios);

void listarEstadias(sEstadiaDiaria* estadias, sPerro* listaPerros, int length, int contadorAltas, sDuenio* listaDuenios, int lengthDuenios);

int generarId(int contadorId);




#endif
