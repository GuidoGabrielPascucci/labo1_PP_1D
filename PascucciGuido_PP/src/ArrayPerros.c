
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






















