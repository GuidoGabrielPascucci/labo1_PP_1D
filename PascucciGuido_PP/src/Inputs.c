
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"
#include "Validations.h"



/**
 * @fn int getIntInMinMaxRange(char*, char*, int, int)
 * @brief [GET INT IN MIN MAX RANGE - Permite al usuario ingresar un numero entero en un rango de un numero minimo y un numero maximo]
 *
 * @param message
 * @param errorMessage
 * @param min
 * @param max
 * @return Retorna el NUMERO ENTERO luego de pasar por su respectiva validacion
 */
int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max)
{
	int enterIntNumber;

	if (message != NULL && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enterIntNumber);

		while ( (validacionNumerica(enterIntNumber)) || (enterIntNumber < min || enterIntNumber > max) )
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%d", &enterIntNumber);
		}

	}

	return enterIntNumber;
}


/**
 * @fn int getNumeroMayorQueMinimo(char*, char*, int)
 * @brief [GET NUMERO MAYOR QUE MINIMO - Permite al usuario ingresar un numero entero que sea mayor a un numero minimo establecido]
 *
 * @param message
 * @param errorMessage
 * @param min
 * @return Retorna el NUMERO ENTERO luego de pasar por su respectiva validacion
 */
int getNumeroMayorQueMinimo(char* message, char* errorMessage, int min)
{
	int enterIntNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &enterIntNumber);

	while (enterIntNumber < min) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%d", &enterIntNumber);
	}

	return enterIntNumber;
}





/**
 * @fn void getString(char*, char*, char*, int)
 * @brief [GET STRING - Permite al usuario ingresar una cadena de caracteres que no supere la cantidad maxima de caracteres establecida]
 *
 * @param string
 * @param message
 * @param errorMessage
 * @param max
 */
void getString(char* string, char* message, char* errorMessage, int max)
{
	char notValidateString[200];
	int length;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", notValidateString);
	length = strlen(notValidateString);

	while (length > max || stringValidation(notValidateString, length) )
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%[^\n]", notValidateString);
		length = strlen(notValidateString);
	}


	strcpy(string, notValidateString);
}




















/*
int pedirDatos(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId)
{
	int valorDeFuncion = -1;
	int index;

	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{

		index = buscarEspacioLibre(listaEstadias, length);

		if (index != -1)
		{
			printf("\n\n------------------------------------------------------------------------------------------------\n"
					"Por favor complete los siguientes datos:\n"
					"------------------------------------------------------------------------------------------------\n");




			listaEstadias[index].id = generarId(*contadorId);
			getString(listaEstadias[index].nombreDuenio, "Nombre del dueño: ", "Error. Por favor reingrese el nombre del dueño: ", MAX_NOMBRE); // MAXIMO DEL NOMBRE DEL DUEÑO?
			listaEstadias[index].telefonoContacto = pedirTelefonoDeContacto(listaEstadias, length, index);
			pedirFecha(listaEstadias, index);
			listaEstadias[index].espacioVacio = FALSE;

			valorDeFuncion = 0;

			printf("\n\n************************************************************************************************\n"
					"Estadia agregada exitosamente !\n"
					"************************************************************************************************\n\n");
			system("pause");

		}
		else
		{
			printf("\n\nERROR !\nNo hay espacio disponible para agregar perros.\n\n\n");
			system("pause");
		}

	}
	else
	{
		printf("\nERROR !\nDatos invalidos. Por favor intente nuevamente\n\n\n\n");
		system("pause");
	}


	return valorDeFuncion;
}
*/











/*
void cargarPerrito(sPerro* listaPerritos, int length, int index)
{

	getString(listaPerritos[index].nombre, "Ingrese nombre del perrito: ", "ERROR ! Ese nombre no es valido. Por favor reingrese un nombre: ", MAX_NOMBRE);
	getString(listaPerritos[index].raza, "Ingrese la raza: ", "ERROR ! Esa raza no es valida. Por favor reingrese la raza: ", MAX_NOMBRE);
	listaPerritos[index].edad = getIntInMinMaxRange("Ingrese la edad: ", "ERROR ! Esa edad no es valida. Por favor reingrese la edad: ", 0, 20);

	listaPerritos[index].id;

	listaPerritos[index].espacioVacio = FALSE;

}
*/


















































