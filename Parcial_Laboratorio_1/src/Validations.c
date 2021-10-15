

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "ArrayEstadias.h"
#include "Inputs.h"
#include "NuevoNexo.h"




/**
 * @fn int verificarCancelacionDeEstadia(sEstadiaDiaria*, int, int)
 * @brief [Verificar Cancelacion de Estadia - Validacion de seguridad para confirmar la cancelacion de la estadia o para deshacer los cambios]
 *
 * @param listaEstadias
 * @param length
 * @param indexDelId
 * @return Retorna un NUMERO ENTERO: [-1] si se confirma la cancelacion / [0] si no se cancela la estadia
 */
int verificarCancelacionDeEstadia(sEstadiaDiaria* listaEstadias, int length, int indexDelId)
{
	int value = -1;
	int option;

	option = getIntInMinMaxRange("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
								"Verificacion de seguridad\n"
								"Confirmas que quieres cancelar esta estadia?\n"
								"---------------------------------------------------------------------------------------------------------------------------------\n"
								"1. SI, confirmar la cancelacion de la estadia\n"
								"0. NO, Deshacer los cambios y volver atras\n\n",

								"\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
								"ERROR !\n"
								"La opcion ingresada es invalida. Por favor reingrese una opcion\n"
								"Verificacion de seguridad\n"
								"Confirmas que quieres cancelar esta estadia?\n"
								"---------------------------------------------------------------------------------------------------------------------------------\n"
								"1. SI, confirmar la cancelacion de la estadia\n"
								"0. NO, deshacer los cambios y volver atras\n\n", 0, 1);


	if (option)
	{
		printf("Has cancelado la estadia !\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n\n\n");
	}
	else
	{
		listaEstadias[indexDelId].espacioVacio = FALSE;
		printf("No has hecho cambios en las estadias\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n\n\n");
		value = 0;
	}


	return value;
}






/**
 * @fn int verificarModificacionPerro(void)
 * @brief [Verificar Modificacion Perro - Validacion de seguridad para confirmar la modificacion del perro en una estadia]
 *
 * @return Retorna un NUMERO ENTERO: [1] si se realiza la modificacion / [2] si no se realiza la modificacion
 */
int verificarModificacionPerro(void)
{
	int verificacion;

	verificacion = getIntInMinMaxRange("\n---------------------------------------------------------------------------------------------------------------------------------\n"
									   "Verificacion de seguridad:\n"
									   "Confirmas que quieres realizar la modificacion?\n"
									   "---------------------------------------------------------------------------------------------------------------------------------\n"
									   "1. SI, deseo realizar la modificacion y guardar los cambios\n"
									   "2. NO, deshacer los cambios y volver atras\n\n\n",

									   "ERROR ! Esa opcion es invalida. Por favor vuelve a ingresar la opcion correspondiente\n"
									   "Confirmas que quieres realizar la modificacion?\n\n"
									   "1. SI, deseo realizar la modificacion y guardar los cambios\n"
									   "2. NO, deshacer los cambios y volver atras\n\n\n", 1, 2);

	return verificacion;
}





/**
 * @fn int validacionNumerica(int)
 * @brief [Validacion Numerica - Valida que solo se puedan ingresar numeros]
 *
 * @param number
 * @return Retorna un NUMERO ENTERO: [-1] si hay error / [0] si el numero ingresado es un digito del 0 al 9
 */
int validacionNumerica(int number)
{
	int value = -1;

	if (!isdigit(number))
	{
		value = 0;
	}


	return value;
}






/**
 * @fn int stringValidation(char*, int)
 * @brief [String Validation - Valida que la cadena de caracteres contenga solo letras del alfabeto, y no contenga simbolos ni numeros]
 *
 * @param string
 * @param length
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / [0] si la cadena ingresada son letras.
 */
int stringValidation(char* string, int length)
{
	int functionValue = 0;


	for (int i = 0; i < length; ++i)
	{
		if ( (isdigit(string[i])) || string[i] < 32 || (string[i] > 32 && string[i] < 65) || (string[i] > 90 && string[i] < 97) || string[i] > 122 )
		{
			functionValue = -1;
			break;
		}
	}


	if (functionValue != -1)
	{
		for (int i = 0; i < length; ++i)
		{
			if (i == 0)
			{
				string[i] = toupper(string[i]);
			}
			else
			{
				string[i] = tolower(string[i]);
			}
		}
	}


	return functionValue;
}




















