
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"



int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max)
{
	int enterIntNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &enterIntNumber);

	while ( (validacionNumerica(enterIntNumber)) || (enterIntNumber < min || enterIntNumber > max) )
	{
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%d", &enterIntNumber);
	}

	return enterIntNumber;
}



int validacionNumerica(int number)
{
	int value = -1;

	if (!isdigit(number))
	{
		value = 0;
	}


	return value;
}




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




float getFloatInMinMaxRange(char* message, char* errorMessage, int min, int max)
{
	float enterFloatNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%f", &enterFloatNumber);

	while (enterFloatNumber < min || enterFloatNumber > max) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%f", &enterFloatNumber);
	}

	return enterFloatNumber;
}




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

	printf("La cadena es: %s\n\n", notValidateString);

	strcpy(string, notValidateString);
}




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

	printf("\n\nfunction Value = %d\n\n", functionValue);

	return functionValue;
}































