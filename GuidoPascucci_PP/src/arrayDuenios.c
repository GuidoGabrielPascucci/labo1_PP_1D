
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayDuenios.h"
#include "NuevoNexo.h"
#include "ArrayPerros.h"
#include "ArrayEstadias.h"
#include "Inputs.h"




void sDuenio_hardcodear(sDuenio* listaDuenios, int length)
{
	int ids[] = {30000, 30001, 30002, 30003, 30004};
	char nombres[][MAX_NOMBRE_DUENIO] = {"Juan", "Pedro", "Lionel", "Martina", "Alejandra"};
	int telefonos[] = {42501265, 1512302562, 42801450, 1580256530, 1130456985};

	for (int i = 0; i < length; ++i)
	{
		listaDuenios[i].id = ids[i];
		strcpy(listaDuenios[i].nombre, nombres[i]);
		listaDuenios[i].telefono = telefonos[i];
	}

}




int seleccionarIdDelDuenio(sDuenio* listaDuenios, int length)
{
	int idDuenio = -1;

	if (listaDuenios != NULL && length > -1)
	{
		mostrarListaDuenios(listaDuenios, length);
		idDuenio = getIntInMinMaxRange("Seleccione ID del duenio: ", "Error, ID de duenio invalida. Por favor seleccione otro: ", 30000, 30004);

	}
	else
	{
		printf("Error en la carga. Intente nuevamente\n\n\n");
	}


	return idDuenio;
}




void mostrarDuenio(sDuenio* duenios, int index)
{
	printf("%-20d %-40s %-30d\n", duenios[index].id, duenios[index].nombre, duenios[index].telefono);
}




void mostrarListaDuenios(sDuenio* duenios, int length)
{

		if (duenios != NULL && length > -1)
		{
			printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
					"Listado de duenios\n"
					"---------------------------------------------------------------------------------------------------------------------------------\n"
					"%-20s %-40s %-30s", "ID", "Nombre", "Telefono\n"
					"---------------------------------------------------------------------------------------------------------------------------------\n");

			for (int i = 0; i < length; ++i)
			{
					mostrarDuenio(duenios, i);
			}

			printf("\n\n\n");
		}

}
































