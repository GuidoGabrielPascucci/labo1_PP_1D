

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NuevoNexo.h"
#include "ArrayPerros.h"
#include "ArrayEstadias.h"
#include "Inputs.h"


// ------------------------------------------------------------------------------------------------------------------------------------------------------
// MENU PRINCIPAL:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length)
{
	int contadorId = 0;
	int contadorAltas = 0;
	int option;

	do
		{
			option = getIntInMinMaxRange("\n_______________________________________________________________________________________________\n\n\n"
										 "MENU\n\n"
										 "_______________________________________________________________________________________________\n\n"
										 "Ingrese una opcion:\n"
										 "------------------------------------------------------------------------------------------------\n\n"
										 "1. Reservar Estadia\n"
										 "2. Modificar Estadia\n"
										 "3. Cancelar Estadia\n"
										 "4. Listar Estadias\n"
										 "5. Listar Perros\n"
										 "6. Promedio De Edad De Los Perros\n\n"
										 "7. EXIT\n\n\n"
										 "_______________________________________________________________________________________________\n\n",

										 "\nError - motivo: [Entrada invalida]. Ingrese nuevamente una opcion:\n"
										 "_______________________________________________________________________________________________\n\n"
										 "1. Reservar Estadia\n"
										 "2. Modificar Estadia\n"
										 "3. Cancelar Estadia\n"
										 "4. Listar Estadias\n"
										 "5. Listar Perros\n"
										 "6. Promedio De Edad De Los Perros\n\n"
										 "7. EXIT\n\n\n", 1, 7);


			switch (option)
			{
				case 1:
					reservarEstadia(listaEstadias, listaPerros, length, &contadorId, &contadorAltas);
					break;

				case 2:
					modificarEstadia(listaEstadias, listaPerros, length, contadorId, contadorAltas);
					break;

				case 3:
					cancelarEstadia(listaEstadias, listaPerros, length, &contadorAltas);
					break;

				case 4:
					mostrarListaEstadias(listaEstadias, length);
					break;

				case 5:
					mostrarListaPerros(listaPerros, length);
					break;

				case 6:
					promedioEdadPerros(listaPerros, length, contadorAltas);
					break;

				case 7:
					// Exit
					break;
			}


		} while (option != 7);

}




// ------------------------------------------------------------------------------------------------------------------------------------------------------
// RESERVAR ESTADIA:
// ------------------------------------------------------------------------------------------------------------------------------------------------------


// RESERVAR ESTADIA MODIFICADO
void reservarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId, int* contadorAltas)
{

	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{

		if (!pedirDatos(listaEstadias, perritos, length, contadorId))
		{
			(*contadorId)++;
			(*contadorAltas)++;
		}

	}
	else
	{
		printf("ERROR !\nDatos Inválidos. Intente más tarde.\n\n\n\n");
	}

}


// PEDIR DATOS MODIFICADO.
int pedirDatos(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId)
{
	int valorDeFuncion = -1;
	int index;

	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{

		index = buscarEspacioLibre(listaEstadias, length);

		if (index != -1)
		{
			printf("Por favor complete los siguientes datos:\n\n");

			listaEstadias[index].id = generarId(*contadorId);
			getString(listaEstadias[index].nombreDuenio, "Nombre del dueño: ", "Error. Por favor reingrese el nombre del dueño: ", MAX_NOMBRE); // MAXIMO DEL NOMBRE DEL DUEÑO?
			listaEstadias[index].telefonoContacto = pedirTelefonoDeContacto(listaEstadias, length, index);

			// Poner en una funcion
			listaEstadias[index].fecha.dia = getIntInMinMaxRange("Ingrese el dia de estadia: ", "ERROR ! Fecha no valida. Por favor reingrese el dia de estadia: ", 1, 31);
			listaEstadias[index].fecha.mes = getIntInMinMaxRange("Ingrese el mes de estadia: ", "ERROR ! Mes no valido. Por favor reingrese el mes de estadia: ", 1, 12);
			listaEstadias[index].fecha.anio = getIntInMinMaxRange("Ingrese el anio de estadia: ", "ERROR ! Anio no valido. Por favor reingrese el anio de estadia: ", 2021, 2030);
			//

			listaEstadias[index].espacioVacio = FALSE;

			valorDeFuncion = 0;
			printf("\nEstadia agregada exitosamente\n\n\n");
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










/*
void reservarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId, int* contadorAltas)
{

	int idResultante;
	char nombreDuenio[MAX_NOMBRE];
	int telefonoContacto;
	int fecha;


	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{

		if (!pedirDatos(listaEstadias, perritos, length, &idResultante, contadorId, nombreDuenio, &telefonoContacto, &fecha))
		{
			if (!agregarEstadia(listaEstadias, perritos, length, idResultante, nombreDuenio, telefonoContacto, fecha))
			{
				(*contadorId)++;
				(*contadorAltas)++;
			}

		}

	}
	else
	{
		printf("ERROR !\nDatos Inválidos. Intente más tarde.\n\n\n\n");
	}

}
*/


/*
int pedirDatos(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* idResultante, int* contadorId, char* nombreDuenio, int* telefonoContacto, int* fecha)
{
	int valorDeFuncion = -1;
	int index;

	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{

		index = buscarEspacioLibre(listaEstadias, length);

		if (index != -1)
		{
			printf("Por favor complete los siguientes datos:\n\n");

			*idResultante = generarId(*contadorId);
			getString(nombreDuenio, "Nombre del dueño: ", "Error. Por favor reingrese el nombre del dueño: ", MAX_NOMBRE); // MAXIMO DEL NOMBRE DEL DUEÑO?

			//telefonoContacto = getIntInMinMaxRange("Telefono de contacto: ", "Error. Por favor reingrese el telefono de contacto: ", 30000000, 1599999999);

			modificarTelefonoDeContacto(listaEstadias, length, index);



			*fecha = getIntInMinMaxRange("Fecha de estadia: ", "Error. Por favor reingrese la fecha de estadia: ", 1, 30);

			valorDeFuncion = 0;

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
int agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int idResultante, char* nombreDuenio, int telefonoContacto, int fecha)
{
	int valorDeFuncion = -1;
	int index;

	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{
		index = buscarEspacioLibre(listaEstadias, length);

		if (index != -1)
		{
			listaEstadias[index].id = idResultante;
			strcpy(listaEstadias[index].nombreDuenio, nombreDuenio);
			listaEstadias[index].telefonoContacto = telefonoContacto;
			listaEstadias[index].fecha = fecha;
			listaEstadias[index].espacioVacio = FALSE;

			valorDeFuncion = 0;
			printf("\nEstadia agregada exitosamente\n\n\n");
			system("pause");
		}

	}
	else
	{
		printf("Ingreso de datos cancelado. No se ha podido cargar la estadia. Intentelo nuevamente.\n\n\n\n");
		system("pause");
	}


	return valorDeFuncion;
}
*/





// ------------------------------------------------------------------------------------------------------------------------------------------------------
// MODIFICAR ESTADIA:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
void modificarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int contadorId, int contadorAltas)
{
	int id;
	int indexDelId;
	int option;


	if (listaEstadias != NULL && length > -1)
	{

		if (contadorAltas > 0)
		{
			do
			{
				mostrarListaEstadias(listaEstadias, length);
				id = getNumeroMayorQueMinimo("Ingrese el ID que desea modificar: ", "ERROR !\nEl ID no existe. Por favor reingrese un ID valido: ", ID);
				indexDelId = buscarEstadiaPorId(listaEstadias, length, id);

				if (indexDelId != -1)
				{
					option = menuDeModificacion(listaEstadias, listaPerros, length, indexDelId);
				}
				else
				{
					printf("El id que intenta buscar no existe. Por favor intentelo nuevamente.\n\n\n");
				}

			} while(option != 3);

		}
		else
		{
			printf("\nERROR !\n"
				   "No se puede hacer modificaciones porque no hay datos cargados.\n\n\n");
			system("pause");
		}

	}
	else
	{
		printf("ERROR !\nDatos inválidos. Intentelo nuevamente\n\n\n");
		system("pause");
	}

}



int menuDeModificacion(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int index)
{
	int option;

	option = getIntInMinMaxRange("\n\n------------------------------------------------------------------------------------------------\n"
								 "Que desea modificar?\n"
								 "------------------------------------------------------------------------------------------------\n"
								 "1. Telefono de contacto\n"
								 "2. Perro\n\n"
								 "3. Volver al menu\n\n\n",

								 "------------------------------------------------------------------------------------------------\n"
								 "ERROR ! Opcion invalida\n"
								 "Que desea modificar?\n"
								 "------------------------------------------------------------------------------------------------\n"
								 "1. Telefono de contacto\n"
								 "2. Perro\n\n"
								 "3. Volver al menu\n\n\n", 1, 3);


	switch(option)
	{
		case 1:
			modificarTelefonoDeContacto(listaEstadias, length, index);
			printf("Has cambiado el telefono de contacto!\n\n");
			break;

		case 2:
			modificarPerroMenu(listaPerros, length, index);
			break;

		case 3:
			// Exit Modificaciones
			break;
	}


	return option;
}




// ------------------------------------------------------------------------------------------------------------------------------------------------------
// CANCELAR ESTADIA:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
void cancelarEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int* contadorAltas)
{
	int id;
	int indexDelId;
	int opcion;


	if (listaEstadias != NULL && length > -1)
	{
		do
		{
			if (*contadorAltas > 0)
			{
				mostrarListaEstadias(listaEstadias, length);
				id = getNumeroMayorQueMinimo("Ingrese el ID de la estadia que desea cancelar: ", "ERROR !\nEl ID no existe. Por favor reingrese un ID valido: ", ID);
				indexDelId = buscarEstadiaPorId(listaEstadias, length, id);

				if (indexDelId != -1)
				{
					if ( (!removerEstadia(listaEstadias, length, id)) && (verificacionDeSeguridad(listaEstadias, length, indexDelId)) )
					{
						(*contadorAltas)--;
					}

					opcion = getIntInMinMaxRange("1. Volver al Menu Principal\n"
												 "0. Seguir cancelando estadias\n\n",

												 "1. Volver al Menu Principal\n"
												 "0. Seguir cancelando estadias\n\n", 0, 1);

				}

			}
			else
			{
				printf("\nERROR !\nNo se pueden realizar cancelaciones porque no hay datos cargados.\n\n\n");
				system("pause");
				break;
			}

		} while(!opcion);

	}
	else
	{
		printf("ERROR !\nDATOS NO VALIDOS.\n\n\n");
	}

}



int removerEstadia(sEstadiaDiaria* listaEstadias, int length, int id) // DEBERIA INCLUIR EL LISTADO DE PERROS Y HACER LA BAJA LOGICA TAMBIEN
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



int verificacionDeSeguridad(sEstadiaDiaria* listaEstadias, int length, int indexDelId) // DEBERIA INCLUIR EL LISTADO DE PERROS Y DESHACER LA BAJA LOGICA TAMBIEN
{
	int value = -1;
	int option;

	option = getIntInMinMaxRange("\n\n------------------------------------------------------------------------------------------------\n"
								"Verificacion de seguridad\n"
								"Desea cancelar estadia?\n"
								"------------------------------------------------------------------------------------------------\n"
								"1. Confirmar\n"
								"2. Deshacer cambios y volver\n\n",

								"\n\n------------------------------------------------------------------------------------------------\n"
								"ERROR !\n"
								"La opcion ingresada es invalida. Por favor reingrese una opcion\n"
								"Verificacion de seguridad\n"
								"Desea cancelar estadia?\n"
								"------------------------------------------------------------------------------------------------\n"
								"1. Confirmar\n"
								"0. Deshacer cambios y volver\n\n", 0, 1);


	if (option)
	{
		printf("Has cancelado la estadia\n\n\n");
	}
	else
	{
		listaEstadias[indexDelId].espacioVacio = FALSE;
		printf("No has hecho cambios en las estadias\n\n\n");
		value = 0;
	}


	return value;
}






// ------------------------------------------------------------------------------------------------------------------------------------------------------
// GENERAR ID:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
int generarId(int contadorId)
{
	int generatedId;

	if (contadorId == 0)
	{
		generatedId = ID;
	}
	else
	{
		generatedId = ID + contadorId;
	}

	return generatedId;
}





// ------------------------------------------------------------------------------------------------------------------------------------------------------
// BUSCAR ESTADIA POR ID:
// ------------------------------------------------------------------------------------------------------------------------------------------------------
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

		if (index == -1)
		{
			printf("\n------------------------------------------------------------------------------------------------\n"
					"Error - Reason: [Employee not found]\n"
					"------------------------------------------------------------------------------------------------\n\n\n");
		}

	}
	else
	{
		printf("ERROR !\nDATOS INVALIDOS.\n\n\n");
	}


	return index;
}


























