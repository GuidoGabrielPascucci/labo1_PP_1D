
#ifndef INPUTS_H_
#define INPUTS_H_



int getIntInMinMaxRange(char* message, char* errorMessage, int min, int max);
int getNumeroMayorQueMinimo(char* message, char* errorMessage, int min);
float getFloatInMinMaxRange(char* message, char* errorMessage, int min, int max);
void getString(char* string, char* message, char* errorMessage, int max);
int stringValidation(char* string, int length);

int validacionNumerica(int number);


#endif
