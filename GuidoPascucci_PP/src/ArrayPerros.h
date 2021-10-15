
#ifndef ARRAYPERROS_H_
#define ARRAYPERROS_H_


#define ID 100000
#define MAX_PERROS 10
#define MAX_NOMBRE 21
#define TRUE 1
#define FALSE 0

#define MAX_NOMBRE_DUENIO 41
#define MAX_DUENIOS 5


typedef struct
{

 int id;
 char nombre[MAX_NOMBRE];
 char raza[MAX_NOMBRE];
 int edad;
 int espacioVacio;

} sPerro;




void inicializarPerritos(sPerro* perritos, int length);
void sPerro_hardcodeo(sPerro* perritos, int length);
void mostrarPerro(sPerro* perritos, int index);
void mostrarListaPerros(sPerro* perritos, int length);
void listarPerros(sPerro* listaPerros, int length, int contadorAltas);
int cargarPerritoPorId(sPerro* listaPerritos, int length, int index);
int calcularPromedioEdadPerros(sPerro* perritos, int length, int contadorAltas);








#endif




