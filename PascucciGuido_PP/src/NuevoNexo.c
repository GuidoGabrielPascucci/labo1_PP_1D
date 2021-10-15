

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NuevoNexo.h"
#include "Inputs.h"
#include "Validations.h"



/**
 * @fn void mainMenu(sEstadiaDiaria*, sPerro*, int)
 * @brief [Menu Principal - Donde se pueden realizar las acciones correspondientes o finalizar el programa]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param length
 */
void mainMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length)
{
	int contadorId = 0;
	int contadorAltas = 0;
	int option;

	do
		{
			option = getIntInMinMaxRange("\n_________________________________________________________________________________________________________________________________\n\n\n"
										 "MENU\n\n"
										 "_________________________________________________________________________________________________________________________________\n\n"
										 "Ingrese una opcion:\n"
										 "---------------------------------------------------------------------------------------------------------------------------------\n\n"
										 "1. Reservar Estadia\n"
										 "2. Modificar Estadia\n"
										 "3. Cancelar Estadia\n"
										 "4. Listar Estadias\n"
										 "5. Listar Perros\n"
										 "6. Promedio De Edad De Los Perros\n\n"
										 "7. EXIT\n\n\n"
										 "_________________________________________________________________________________________________________________________________\n\n",

										 "\nError - motivo: [Entrada invalida]. Ingrese nuevamente una opcion:\n"
										 "_________________________________________________________________________________________________________________________________\n\n"
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
					agregarEstadia(listaEstadias, listaPerros, length, &contadorId, &contadorAltas);
					break;

				case 2:
					modificarEstadia(listaEstadias, listaPerros, length, contadorId, contadorAltas);
					break;

				case 3:
					cancelarEstadia(listaEstadias, listaPerros, length, &contadorAltas);
					break;

				case 4:
					listarEstadias(listaEstadias, listaPerros, length, contadorAltas);
					break;

				case 5:
					listarPerros(listaPerros, length, contadorAltas);
					break;

				case 6:
					calcularPromedioEdadPerros(listaPerros, length, contadorAltas);
					break;

				case 7:
					// Exit
					break;
			}


		} while (option != 7);

}



/**
 * @fn void agregarEstadia(sEstadiaDiaria*, sPerro*, int, int*, int*)
 * @brief [Agregar Estadia - Busca el espacio libre e invoca a la funcion para cargar los datos de la estadia;
 * ademas incrementa el contador de estadias y el contador de ID's]
 *
 * @param listaEstadias
 * @param perritos
 * @param length
 * @param contadorId
 * @param contadorAltas
 */
void agregarEstadia(sEstadiaDiaria* listaEstadias, sPerro* perritos, int length, int* contadorId, int* contadorAltas)
{
	int index;

	if ( (listaEstadias != NULL && perritos != NULL) && (length > -1) )
	{

		index = buscarEspacioLibre(listaEstadias, length);

		if ( (index != -1) && (!cargarDatosDeEstadia(listaEstadias, perritos, length, index, contadorId)) )
		{
			(*contadorId)++;
			(*contadorAltas)++;

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

}



/**
 * @fn int cargarDatosDeEstadia(sEstadiaDiaria*, sPerro*, int, int, int*)
 * @brief [Cargar Datos de Estadia - Carga los datos de la estadia que el usuario ingresa en el sistema]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param length
 * @param index
 * @param contadorId
 * @return Value (Numero Entero): [-1] si hubo un error / [0] si la estadia se cargo correctamente en el sistema.
 */
int cargarDatosDeEstadia(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int index, int* contadorId)
{
	int value = -1;

	if ( (listaEstadias != NULL && listaPerros != NULL) && (length > -1) )
	{

		printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
				"Por favor complete los siguientes datos:\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n");

		listaEstadias[index].id = generarId(*contadorId);
		getString(listaEstadias[index].nombreDuenio, "Nombre del dueño: ", "Error. Por favor reingrese el nombre del dueño: ", MAX_NOMBRE);
		listaEstadias[index].telefonoContacto = pedirTelefonoDeContacto(listaEstadias, length, index);
		pedirFecha(listaEstadias, index);
		listaEstadias[index].idPerro = cargarPerritoPorId(listaPerros, length, index);

		listaEstadias[index].espacioVacio = FALSE;

		value = 0;


		printf("\n\n********************************************************************************************************************************************\n\n"
				"Estadia agregada exitosamente !\n\n"
				"********************************************************************************************************************************************\n\n");

	}


	return value;
}




/**
 * @fn void modificarEstadia(sEstadiaDiaria*, sPerro*, int, int, int)
 * @brief [Modificar Estadia - Si el contador de estadias/altas es mayor a cero, permite la modificacion de los datos de la estadia]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param length
 * @param contadorId
 * @param contadorAltas
 */
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
				mostrarListaEstadias(listaEstadias, listaPerros, length);

				id = getNumeroMayorQueMinimo("Ingrese el ID de la estadia que desea modificar: ", "ERROR !\nEl ID no existe. Por favor reingrese un ID valido: ", ID);
				indexDelId = buscarEstadiaPorId(listaEstadias, length, id);

				if (indexDelId != -1)
				{
					modificarEstadiaMenu(listaEstadias, listaPerros, length, indexDelId);
				}
				else
				{
					printf("ERROR ! El ID ingresado no pertenece a ninguna estadia cargada en el sistema.\n"
							"Por favor vuelva a ingresar otro ID...\n\n\n\n");
				}


				option = getIntInMinMaxRange("Desea seguir realizando modificaciones?:\n"
											 "1. Ingresar otro ID para modificar\n"
											 "2. Volver al menu principal\n\n\n",

											 "lalalalal", 1, 3);

			} while(option != 2);

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


/**
 * @fn void modificarEstadiaMenu(sEstadiaDiaria*, sPerro*, int, int)
 * @brief [Modificar Estadia Menu - Despliega un menu de opciones para modificar telefono de contacto, modificar perro, o volver al menu anterior.]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param length
 * @param index
 */
void modificarEstadiaMenu(sEstadiaDiaria* listaEstadias, sPerro* listaPerros, int length, int index)
{
	int option;

	option = getIntInMinMaxRange("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
								 "Que desea modificar?\n"
								 "---------------------------------------------------------------------------------------------------------------------------------\n"
								 "1. Telefono de contacto\n"
								 "2. Perro\n\n"
								 "3. Volver\n\n\n",

								 "---------------------------------------------------------------------------------------------------------------------------------\n"
								 "ERROR ! Opcion invalida\n"
								 "Que desea modificar?\n"
								 "---------------------------------------------------------------------------------------------------------------------------------\n"
								 "1. Telefono de contacto\n"
								 "2. Perro\n\n"
								 "3. Volver al menu\n\n\n", 1, 3);


	switch(option)
	{
		case 1:
			modificarTelefonoDeContacto(listaEstadias, length, index);
			break;

		case 2:
			modificarPerro(listaPerros, listaEstadias, length, index);
			break;

		case 3:
			// Exit Modificaciones
			break;
	}

}





/**
 * @fn void modificarPerro(sPerro*, sEstadiaDiaria*, int, int)
 * @brief [Modificar Perro - Menu de modificacion del perro de la estadia segun opcion elegida por el usuario y posterior carga de la misma en el sistema]
 *
 * @param listaPerros
 * @param listaEstadias
 * @param length
 * @param index
 */
void modificarPerro(sPerro* listaPerros, sEstadiaDiaria* listaEstadias, int length, int index)
{

	if (listaPerros != NULL && listaEstadias != NULL && length > -1 && index > -1)
	{
		int perroSeleccionado = getIntInMinMaxRange("\nCual es el perro que desea registrar en esta estadia?\n"
													"1. Lobo\n"
													"2. Sheila\n"
													"3. Reina\n\n\n",

													"ERROR ! opcion invalida. Por favor reingrese el perro que desea registrar en esta estadia:\n"
													"1. Lobo\n"
													"2. Sheila\n"
													"3. Reina\n\n\n", 1, 3);


		if (verificarModificacionPerro() == 1)
		{
			switch (perroSeleccionado)
			{
				case 1:
					listaEstadias[index].idPerro = listaPerros[0].id;
					break;

				case 2:
					listaEstadias[index].idPerro = listaPerros[1].id;
					break;

				case 3:
					listaEstadias[index].idPerro = listaPerros[2].id;
					break;
			}


			printf("\n********************************************************************************************************************************************\n\n"
					"Los cambios han sido guardados !\n\n"
					"********************************************************************************************************************************************\n\n\n");

			system("pause");

		}
		else
		{
			printf("\n********************************************************************************************************************************************\n\n"
					"Se han restaurado los cambios !\n\n"
					"********************************************************************************************************************************************\n\n\n");

			system("pause");
		}

	}

}




/**
 * @fn void cancelarEstadia(sEstadiaDiaria*, sPerro*, int, int*)
 * @brief [Cancelar Estadia - Si el contador de estadias/altas es mayor a cero, permite la eliminacion de una estadia cargada en el sistema. Posee su propio submenu]
 *
 * @param listaEstadias
 * @param listaPerros
 * @param length
 * @param contadorAltas
 */
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
				mostrarListaEstadias(listaEstadias, listaPerros, length);
				id = getNumeroMayorQueMinimo("Ingrese el ID de la estadia que desea cancelar: ", "ERROR !\nEl ID no existe. Por favor reingrese un ID valido: ", ID);
				indexDelId = buscarEstadiaPorId(listaEstadias, length, id);

				if (indexDelId != -1)
				{
					if ( (!removerEstadia(listaEstadias, length, id)) && (verificarCancelacionDeEstadia(listaEstadias, length, indexDelId)) )
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




/**
 * @fn void mostrarEstadia(sEstadiaDiaria*, sPerro*, int, int, int)
 * @brief [Mostrar Estadia - Muestra la carga individual de una estadia en particular segun subindices de los arrays de cada estructura]
 *
 * @param estadias
 * @param listaPerritos
 * @param length
 * @param i
 * @param j
 */
void mostrarEstadia(sEstadiaDiaria* estadias, sPerro* listaPerritos, int length, int i, int j)
{

	printf("%-20d %-25s %-30d %-20s %d/%d/%d\n", estadias[i].id,
												 estadias[i].nombreDuenio,
												 estadias[i].telefonoContacto,
												 listaPerritos[j].nombre,
												 estadias[i].fecha.dia,
												 estadias[i].fecha.mes,
												 estadias[i].fecha.anio);

}




/**
 * @fn void mostrarListaEstadias(sEstadiaDiaria*, sPerro*, int)
 * @brief [Mostrar Lista Estadias - Muestra el total de estadias cargadas en el sistema]
 *
 * @param estadias
 * @param listaPerritos
 * @param length
 */
void mostrarListaEstadias(sEstadiaDiaria* estadias, sPerro* listaPerritos, int length)
{
	if (estadias != NULL && length > -1)
	{
		printf("\n\n---------------------------------------------------------------------------------------------------------------------------------\n"
				"Listado de estadias\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n"
				"%-20s %-25s %-30s %-20s %-20s", "ID", "Nombre Duenio", "Telefono de contacto", "Perro", "Fecha\n"
				"---------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0; i < length; ++i)
		{
			if (estadias[i].espacioVacio == FALSE)
			{
				for (int j = 0; j < length; ++j)
				{
					if (estadias[i].idPerro == listaPerritos[j].id)
					{
						mostrarEstadia(estadias, listaPerritos, length, i, j);
						break;
					}
				}
			}
		}
	}

	printf("\n\n\n");
}





/**
 * @fn void listarEstadias(sEstadiaDiaria*, sPerro*, int, int)
 * @brief [Listar Estadias - Si el contador de estadias/altas es mayor que cero, ofrece el listado de las estadias ordenado]
 *
 * @param estadias
 * @param listaPerros
 * @param length
 * @param contadorAltas
 */
void listarEstadias(sEstadiaDiaria* estadias, sPerro* listaPerros, int length, int contadorAltas)
{

	if (contadorAltas > 0)
	{
		if (estadias != NULL && length > -1)
		{
			listarEstadiasPorFechaDescendente(estadias, length);
			mostrarListaEstadias(estadias, listaPerros, length);
		}
	}
	else
	{
		printf("\nERROR! No hay estadias cargadas.\n\n");
		system("pause");
	}

}






/**
 * @fn int generarId(int)
 * @brief [Generar ID - Genera un ID a partir del DEFINE ID y de la cantidad de ID's registrados]
 *
 * @param contadorId
 * @return El ID generado (NUMERO ENTERO)
 */
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
























