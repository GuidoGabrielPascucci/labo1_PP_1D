

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEstadias.h"
#include "ArrayPerros.h"
#include "Inputs.h"
#include "ArrayPerros.h"





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



















