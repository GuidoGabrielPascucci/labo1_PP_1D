

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "ArrayEstadias.h"
#include "NuevoNexo.h"
#include "Inputs.h"



/**
 * @fn void inicializarEstadias(sEstadiaDiaria*, int)
 * @brief [Inicializar Estadias - Pone a todos los campos 'espacio vacio' de la estructura Estadias en VERDADERO(1)]
 *
 * @param listaEstadias
 * @param length
 */
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





/**
 * @fn int buscarEspacioLibre(sEstadiaDiaria*, int)
 * @brief [Buscar Espacio Libre - busca el espacio vacio en el campo 'espacio vacio' del array de estadias]
 *
 * @param listaEstadias
 * @param length
 * @return Retorna el INDEX (NUMERO ENTERO) del primer espacio vacio que encuentra en el array de estadias
 */
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





/**
 * @fn int pedirTelefonoDeContacto(sEstadiaDiaria*, int, int)
 * @brief [Pedir Telefono de Contacto - Pide el telefono de contacto al usuario a traves de un submenu donde se ingresa telefono de linea o telefono celular]
 *
 * @param listaEstadias
 * @param length
 * @param index
 * @return Retorna un NUMERO ENTERO que es el numero de telefono del usuario.
 */
int pedirTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index)
{
	int option;
	int numeroDeTelefono;

	option = getIntInMinMaxRange("\nQue telefono de contacto desea ingresar?\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n",

								 "ERROR ! La opcion ingresada no es valida. Reingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n", 1, 2);


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



/**
 * @fn void pedirFecha(sEstadiaDiaria*, int)
 * @brief [Pedir Fecha - Pide el dia, mes y anio de la estadia al usuario para cargarla en sistema]
 *
 * @param listaEstadias
 * @param index
 */
void pedirFecha(sEstadiaDiaria* listaEstadias, int index)
{

	listaEstadias[index].fecha.dia = getIntInMinMaxRange("\nIngrese el dia de estadia: ", "ERROR ! Fecha no valida. Por favor reingrese el dia de estadia: ", 1, 31);
	listaEstadias[index].fecha.mes = getIntInMinMaxRange("Ingrese el mes de estadia: ", "ERROR ! Mes no valido. Por favor reingrese el mes de estadia: ", 1, 12);
	listaEstadias[index].fecha.anio = getIntInMinMaxRange("Ingrese el anio de estadia: ", "ERROR ! Anio no valido. Por favor reingrese el anio de estadia: ", 2021, 2030);

}




/**
 * @fn void modificarTelefonoDeContacto(sEstadiaDiaria*, int, int)
 * @brief [Modificar Telefono de Contacto - Modifica el telefono del usuario a traves de un submenu para seleccionar telefono de linea o telefono celular]
 *
 * @param listaEstadias
 * @param length
 * @param index
 */
void modificarTelefonoDeContacto(sEstadiaDiaria* listaEstadias, int length, int index)
{
	//int option;
/*
	option = getIntInMinMaxRange("Ingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n\n",

								 "ERROR ! La opcion ingresada no es valida. Reingrese la opcion correspondiente:\n"
								 "1. Telefono de linea\n"
								 "2. Celular\n\n\n", 1, 2);*/

/*
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
	*/

	printf("\n********************************************************************************************************************************************\n\n"
		   "Has cambiado el telefono de contacto!\n\n"
		   "********************************************************************************************************************************************\n\n\n");

	system("pause");

}






/**
 * @fn int removerEstadia(sEstadiaDiaria*, int, int)
 * @brief [Remover Estadia - Realiza la baja logica de la estadia poniendo en VERDADERO(1) un determinado subindice del campo 'espacio vacio' del array de estadias]
 *
 * @param listaEstadias
 * @param length
 * @param id
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / [0] si realizo la baja logica
 */
int removerEstadia(sEstadiaDiaria* listaEstadias, int length, int id)
{
	int value = -1;

	for (int i = 0; i < length; ++i)
	{
		if (id == listaEstadias[i].id)
		{
			listaEstadias[i].espacioVacio = TRUE;
			value = 0;
			break;
		}
	}


	return value;
}



/**
 * @fn int buscarEstadiaPorId(sEstadiaDiaria*, int, int)
 * @brief [Buscar Estadia Por ID - Realiza una busqueda de la estadia que contenga el ID ingresado por el usuario]
 *
 * @param listaEstadias
 * @param length
 * @param id
 * @return Retorna un NUMERO ENTERO: [-1] si hubo un error / index n° [x] si encontro la posicion en el array del ID
 */
int buscarEstadiaPorId(sEstadiaDiaria* listaEstadias, int length, int id)
{
	int index = -1;

	if (listaEstadias != NULL && length > -1)
	{
		for (int i = 0; i < length; ++i)
		{
			if (id == listaEstadias[i].id)
			{
				index = i;
				break;
			}
		}

	}
	else
	{
		printf("ERROR !\nDATOS INVALIDOS.\n\n\n");
	}


	return index;
}





/**
 * @fn void listarEstadiasPorFechaDescendente(sEstadiaDiaria*, int)
 * @brief [Listar Estadias Por Fecha Descendente - Realiza un ordenamiento de los datos cargados en sistema de las estadias por fecha descendente.
 * En caso de que la fecha sea exactamente la misma se ordenara por nombre del duenio]
 *
 * @param estadias
 * @param length
 */
void listarEstadiasPorFechaDescendente(sEstadiaDiaria* estadias, int length)
{
	int auxInt;

	int limite = length - 1;
	int flagSwap;


	do
	{
		flagSwap = 0;

		for (int i = 0; i < limite; ++i)
		{

			if ( (estadias[i].espacioVacio == FALSE && estadias[i+1].espacioVacio == FALSE) )
			{

				if ( (estadias[i].fecha.anio < estadias[i+1].fecha.anio) )
				{
					auxInt = estadias[i].fecha.anio;
					estadias[i].fecha.anio = estadias[i+1].fecha.anio;
					estadias[i+1].fecha.anio = auxInt;

					auxInt = estadias[i].fecha.mes;
					estadias[i].fecha.mes = estadias[i+1].fecha.mes;
					estadias[i+1].fecha.mes = auxInt;

					auxInt = estadias[i].fecha.dia;
					estadias[i].fecha.dia = estadias[i+1].fecha.dia;
					estadias[i+1].fecha.dia = auxInt;

					ordenarEstadia(estadias, i);

					flagSwap = 1;
				}

				else
				{

					if ( (estadias[i].fecha.anio == estadias[i+1].fecha.anio && estadias[i].fecha.mes < estadias[i+1].fecha.mes) )
					{
						auxInt = estadias[i].fecha.mes;
						estadias[i].fecha.mes = estadias[i+1].fecha.mes;
						estadias[i+1].fecha.mes = auxInt;

						auxInt = estadias[i].fecha.dia;
						estadias[i].fecha.dia = estadias[i+1].fecha.dia;
						estadias[i+1].fecha.dia = auxInt;

						ordenarEstadia(estadias, i);

						flagSwap = 1;
					}

					else
					{

						if ( (estadias[i].fecha.anio == estadias[i+1].fecha.anio)
								&& (estadias[i].fecha.mes == estadias[i+1].fecha.mes)
								&& (estadias[i].fecha.dia < estadias[i+1].fecha.dia) )

						{
							auxInt = estadias[i].fecha.dia;
							estadias[i].fecha.dia = estadias[i+1].fecha.dia;
							estadias[i+1].fecha.dia = auxInt;

							ordenarEstadia(estadias, i);
							flagSwap = 1;
						}

						else
						{

							if ( (estadias[i].fecha.anio == estadias[i+1].fecha.anio)
									&& (estadias[i].fecha.mes == estadias[i+1].fecha.mes)
									&& (estadias[i].fecha.dia == estadias[i+1].fecha.dia)
									&& (strcmp(estadias[i].nombreDuenio, estadias[i+1].nombreDuenio) == 1) )

							{
								ordenarEstadia(estadias, i);
								flagSwap = 1;
							}

						}

					}

				}

			}

		}

		limite--;

	} while (flagSwap);

}



/**
 * @fn void ordenarEstadia(sEstadiaDiaria*, int)
 * @brief [Ordenar Estadia - Modularizacion para no repetir codigo en el ordenamiento de las estadias]
 *
 * @param estadias
 * @param i
 */
void ordenarEstadia(sEstadiaDiaria* estadias, int i)
{
	int auxInt;
	char auxChar[MAX_NOMBRE];


	auxInt = estadias[i].id;
	estadias[i].id = estadias[i+1].id;
	estadias[i+1].id = auxInt;

	strcpy(auxChar, estadias[i].nombreDuenio);
	strcpy(estadias[i].nombreDuenio, estadias[i+1].nombreDuenio);
	strcpy(estadias[i+1].nombreDuenio, auxChar);

	auxInt = estadias[i].telefonoContacto;
	estadias[i].telefonoContacto = estadias[i+1].telefonoContacto;
	estadias[i+1].telefonoContacto = auxInt;

	auxInt = estadias[i].idPerro;
	estadias[i].idPerro = estadias[i+1].idPerro;
	estadias[i+1].idPerro = auxInt;

}




















