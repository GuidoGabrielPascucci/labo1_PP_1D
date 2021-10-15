

#ifndef ARRAYESTADIAS_H_
#define ARRAYESTADIAS_H_


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




void inicializarEstadias(sEstadiaDiaria* listaEstadias, int length);
int buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int length);
int pedirTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index);
void pedirFecha(sEstadiaDiaria* listaEstadias, int index);
void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index);
int removerEstadia(sEstadiaDiaria* listaEstadias, int length, int id);
int buscarEstadiaPorId(sEstadiaDiaria* listaEstadias, int length, int id);
void listarEstadiasPorFechaDescendente(sEstadiaDiaria* estadias, int length);
void ordenarEstadia(sEstadiaDiaria* estadias, int i);











#endif
