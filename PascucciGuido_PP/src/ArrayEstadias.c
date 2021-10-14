

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEstadias.h"
#include "ArrayPerros.h"
#include "Inputs.h"
#include "ArrayPerros.h"




// INICIALIZAR ESTADIAS
void inicializarEstadias(sEstadiaDiaria* listaEstadias, int length)
{

	if (listaEstadias != NULL && length > -1)
	{

		for (int i = 0; i < length; ++i)
		{
			listaEstadias[i].espacioVacio = TRUE;
		}

	}
	else
	{
		printf("ERROR !\nInvalid length or null pointer\n\n");
		system("pause");
	}

}






// BUSCAR ESPACIO LIBRE EN ESTADIAS
int buscarEspacioLibre(sEstadiaDiaria* listaEstadias, int length)
{
	int index = -1;

	for (int i = 0; i < length; ++i)
	{
		if (listaEstadias[i].espacioVacio == TRUE)
		{
			index = i;
			break;
		}
	}

	return index;
}









// PEDIR DATOS DE ESTADIA
int pedirTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index)
{
	int option;
	int numeroDeTelefono;

	option = getIntInMinMaxRange("Ingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n\n",

								 "ERROR ! La opcion ingresada no es valida. Reingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n\n", 1, 2);


	if (option == 1)
	{
		for (int i = 0; i < length; ++i)
		{
			if (i == index)
			{
				numeroDeTelefono = getIntInMinMaxRange("Ingrese el telefono de contacto: ", "ERROR !\nPor favor reingrese otro telefono de contacto: ", 10000000, 99999999);
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < length; ++i)
				{
					if (i == index)
					{
						numeroDeTelefono = getIntInMinMaxRange("Ingrese el telefono de contacto: ", "ERROR !\nPor favor reingrese otro telefono de contacto: ", 1000000000, 1999999999);
						break;
					}
				}
	}


	return numeroDeTelefono;
}








// MODIFICACIONES
void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index)
{
	int option;

	option = getIntInMinMaxRange("Ingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n\n",

								 "ERROR ! La opcion ingresada no es valida. Reingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n\n", 1, 2);


	if (option == 1)
	{
		for (int i = 0; i < length; ++i)
		{
			if (i == index)
			{
				listaEstadias[i].telefonoContacto = getIntInMinMaxRange("Ingrese el telefono de contacto: ", "ERROR !\nPor favor reingrese otro telefono de contacto: ", 10000000, 99999999);
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < length; ++i)
				{
					if (i == index)
					{
						listaEstadias[i].telefonoContacto = getIntInMinMaxRange("Ingrese el telefono de contacto: ", "ERROR !\nPor favor reingrese otro telefono de contacto: ", 1000000000, 1999999999);
						break;
					}
				}
	}

}





// ------------------------------------------------------------------------------------------------------------------------------------------------------
// MOSTRAR ESTADIAS:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarListaEstadias(sEstadiaDiaria* estadias, int length)
{
	if (estadias != NULL && length > -1)
	{
		printf("\n-------------------------------------------------------------------------------------\n"
				"Listado de estadias\n"
				"-------------------------------------------------------------------------------------\n"
				"%-20s %-20s %-25s %-20s", "ID", "Nombre Duenio", "Telefono de contacto", "Fecha\n"
				"-------------------------------------------------------------------------------------\n");

		for (int i = 0; i < length; ++i)
		{
			if (estadias[i].espacioVacio == FALSE)
			{
				mostrarEstadia(estadias, i);
			}
		}
	}

	printf("\n\n\n");
}



void mostrarEstadia(sEstadiaDiaria* estadias, int index)
{
	printf("%-20d %-20s %-25d %-20d/%d/%d\n", estadias[index].id, estadias[index].nombreDuenio, estadias[index].telefonoContacto, estadias[index].fecha.dia, estadias[index].fecha.mes, estadias[index].fecha.anio);
}



























