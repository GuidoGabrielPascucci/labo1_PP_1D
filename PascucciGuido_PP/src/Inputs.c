
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Inputs.h"




int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max) {
	int enterIntNumber;

	printf("%s", message);
	fflush(stdin);
	scanf("%d", &enterIntNumber);

	while (enterIntNumber < min || enterIntNumber > max) {
		printf("%s", errorMessage);
		fflush(stdin);
		scanf("%d", &enterIntNumber);
	}

	return enterIntNumber;
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




float getFloatInMinMaxRange(char* message, char* errorMessage, int min, int max) {
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


	for (int i = 0; i < length; ++i)
	{
		if (i == 0)
		{
			notValidateString[i] = toupper(notValidateString[i]);
		}
		else
		{
			notValidateString[i] = tolower(notValidateString[i]);
		}
	}


	strcpy(string, notValidateString);
}




int stringValidation(char* string, int length)
{
	int functionValue = -1;

	for (int i = 0; i < length; ++i)
	{

		if ( (string[i] > 64 && string[i] < 91) || (string[i] > 96 && string[i] < 123) )
		{
			functionValue = 0;
		}

	}


	return functionValue;
}






























