
#ifndef NUEVONEXO_H_
#define NUEVONEXO_H_


#include "ArrayPerros.h"
#include "ArrayEstadias.h"
#include "Inputs.h"



// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MENU PRINCIPAL:
void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------





// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// RESERVAR ESTADIA:
void reservarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId, int* contadorAltas);


int pedirDatos(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId);


int agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int idResultante, char* nombreDuenio, int telefonoContacto, int fecha);
int buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int length);
int generarId(int contadorId);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------





// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MODIFICAR ESTADIA:
void modificarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int contadorId, int contadorAltas);
int menuDeModificacion(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int index);
//void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------






// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// CANCELAR ESTADIA:
void cancelarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int* contadorAltas);
int verificacionDeSeguridad(sEstadiaDiaria* listaEstadias, int length, int indexDelId);
int removerEstadia(sEstadiaDiaria* listaEstadias, int length, int id);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------






// SEARCH BY ID
int buscarEstadiaPorId(sEstadiaDiaria* listaEstadias, int length, int id);






// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// MOSTRAR LISTADOS
//void mostrarEstadia(sEstadiaDiaria* estadias, int index);
//void mostrarListaEstadias(sEstadiaDiaria* estadias, int length);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//void mostrarPerro(sPerro* perritos, int index);
//void mostrarListaPerros(sPerro* perritos, int length);
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------








#endif
