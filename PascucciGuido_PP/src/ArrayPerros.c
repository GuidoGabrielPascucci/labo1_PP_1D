
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPerros.h"
#include "ArrayEstadias.h"
#include "Inputs.h"




// INICIALIZAR PERRITOS
void inicializarPerritos(sPerro* perritos, int length)
{

	if (perritos != NULL && length > -1)
	{

		for (int i = 0; i < length; ++i)
		{
			perritos[i].espacioVacio = TRUE;
		}

	}
	else
	{
		printf("ERROR !\nInvalid length or null pointer\n\n");
		system("pause");
	}

}







// HARDCODE PERROS
void hardcodePerros(sPerro* perritos, int length)
{
	int ids[] = {7000, 7001, 7002};
	char nombres[][MAX_NOMBRE] = {"Lobo", "Sheila", "Reina"};
	char razas[][MAX_NOMBRE] = {"Sharpei", "Golden", "Galgo"};
	int edades[] = {2, 12, 13};

	for (int i = 0; i < length-7; ++i)
	{
		perritos[i].id = ids[i];
		strcpy(perritos[i].nombre, nombres[i]);
		strcpy(perritos[i].raza, razas[i]);
		perritos[i].edad = edades[i];
		perritos[i].espacioVacio = FALSE;
	}

}









// MODIFICACIONES
void modificarPerroMenu(sPerro* listaPerros, int length, int index)
{

	int option;

	option = getIntInMinMaxRange("\n\n------------------------------------------------------------------------------------------------\n"
								 "Modificar Perrito"
								 "Que dato desea modificar?:\n"
								 "------------------------------------------------------------------------------------------------\n"
								 "1. Nombre\n"
								 "2. Raza\n"
								 "3. Edad\n\n"
								 "4. Volver al Menu Principal\n\n\n",

								 "\n\n------------------------------------------------------------------------------------------------\n"
								 "ERROR ! Opcion ingresada invalida. Por favor reingrese la opcion correspondiente."
								 "Que dato desea modificar?:\n"
								 "------------------------------------------------------------------------------------------------\n"
								 "1. Nombre\n"
								 "2. Raza\n"
								 "3. Edad\n\n"
								 "4. Volver al Menu Principal\n\n\n", 1, 4);




	switch(option)
	{
		case 1:
			modificarNombrePerrito(listaPerros, length, index);
			break;

		case 2:
			modificarRazaPerrito(listaPerros, length, index);
			break;

		case 3:
			modificarEdadPerrito(listaPerros, length, index);
			break;

		case 4:
			// Exit Modificar Perro
			break;
	}

}




void modificarNombrePerrito(sPerro* listaPerros, int length, int index)
{

	for (int i = 0; i < length; ++i)
	{
		if (i == index)
		{
			getString(listaPerros[i].nombre, "Ingrese el nombre del perrito: ", "Nombre invalido. Por favor reingrese el nombre del perrito: ", MAX_NOMBRE);
			printf("Has modificado el nombre del perrito");
			break;
		}
	}

}



void modificarRazaPerrito(sPerro* listaPerros, int length, int index)
{

	for (int i = 0; i < length; ++i)
	{
		if (i == index)
		{
			getString(listaPerros[i].raza, "Ingrese la raza del perrito: ", "Raza invalida. Por favor reingrese la raza del perrito: ", MAX_NOMBRE);
			printf("Has modificado la raza del perrito");
			break;
		}
	}

}




void modificarEdadPerrito(sPerro* listaPerros, int length, int index)
{

	for (int i = 0; i < length; ++i)
	{
		if (i == index)
		{
			listaPerros[i].edad = getIntInMinMaxRange("Ingrese la edad del perrito: ", "Edad invalida. Por favor reingrese la edad del perrito: ", 0, 20);
			printf("Has modificado la edad del perrito");
			break;
		}
	}

}




// ------------------------------------------------------------------------------------------------------------------------------------------------------
// LISTAR PERROS:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
void mostrarListaPerros(sPerro* perritos, int length)
{
	if (perritos != NULL && length > -1)
	{
		printf("\n-------------------------------------------------------------------------------------\n"
				"Listado de perritos\n"
				"-------------------------------------------------------------------------------------\n"
				"%-20s %-20s %-20s %-20s", "ID", "Nombre", "Raza", "Edad\n"
				"-------------------------------------------------------------------------------------\n");

		for (int i = 0; i < length; ++i)
		{
			if (perritos[i].espacioVacio == FALSE)
			{
				mostrarPerro(perritos, i);
			}
		}
	}

	printf("\n\n\n");
}



void mostrarPerro(sPerro* perritos, int index)
{
	printf("%-20d %-20s %-20s %-20d\n", perritos[index].id, perritos[index].nombre, perritos[index].raza, perritos[index].edad);
}








// PROMEDIO DE EDAD PERRITOS

int promedioEdadPerros(sPerro* perritos, int length, int contadorAltas)
{
	int value = -1;
	int acumuladorEdad = 0;
	int contadorPerritos = 0;
	float promedioEdad;

	if (contadorAltas > 0)
	{
		if (perritos != NULL && length > -1)
		{
			for (int i = 0; i < length; ++i)
			{
				if (perritos[i].espacioVacio == FALSE)
				{
					acumuladorEdad = acumuladorEdad + perritos[i].edad;
					contadorPerritos++;
				}
			}

			promedioEdad = (float)acumuladorEdad / contadorPerritos;
			printf("\nPROMEDIO DE EDAD DE LOS PERRITOS: %.2f", promedioEdad);

		}
		else
		{
			printf("ERROR !\nDatos invalidos. Intente nuevamente\n\n\n");
			system("pause");
		}

	}
	else
	{
		printf("\nERROR !\nNo se puede sacar el promedio porque no hay datos cargados\n\n\n");
		system("pause");
	}


	return value;
}































