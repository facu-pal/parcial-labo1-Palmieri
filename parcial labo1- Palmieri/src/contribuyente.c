#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contribuyente.h"

void eContribuyente_Inicializar(eContribuyente array[], int TAM) {
	int i;
	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int eContribuyente_ObtenerID(int *id) {
	int retorno;
	*id += 1;
	retorno = *id;
	return retorno;
}

int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].idContribuyente == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eContribuyente_MostrarUno(eContribuyente Contribuyente) {
	printf("%5d\n", Contribuyente.idContribuyente);
}

int eContribuyente_MostrarTodos(eContribuyente array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\n LISTADO Contribuyente");
	printf("%5s\n\n", "ID"); // %3d         %8s	      %2c          %.2f         %.2f        %.2f)

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eContribuyente_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


int eContribuyente_Alta(eContribuyente array[], int TAM, int *id) {
	int rtn = 0;
	int auxNombre = 0;
	int auxApellido = 0;
	int auxCuit = 0;
	eContribuyente auxContribuyente;

	int index = eContribuyente_ObtenerIndexLibre(array, TAM);

	if (index != -1) {
		auxNombre = utn_getString(auxContribuyente.nombre, 25,
				"Ingrese un nombre", "Error. ingrese un nombre", 2);
		auxApellido = utn_getString(auxContribuyente.apellido, 25,
				"Ingrese un apelido", "Error. ingrese un nombre", 2);
		auxCuit = utn_getCuit(auxContribuyente.cuit, "ingrese cuit",
				"error.cuit", 2);

		auxContribuyente.idContribuyente = eContribuyente_ObtenerID(id);
		auxContribuyente.isEmpty = OCUPADO;

		if (auxNombre != -1 && auxApellido != -1 && auxCuit != -1){

			array[index] = auxContribuyente;

		rtn = 1;
		}
		else{
			rtn = 0;

		}
	}

	return rtn;
}
eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente) {
	eContribuyente auxiliar = Contribuyente;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	utn_getString(auxiliar.nombre, 25, "Ingrese el nuevo nombre",
			"Error. Ingrese el nuevo nombre", 2);
	utn_getString(auxiliar.apellido, 25, "Ingrese el nuevo apellido",
			"Error. Ingrese el nuevo apellido", 2);
	utn_getCuit(auxiliar.cuit, "ingrese el nueve cuit",
			"error.ingrese el nuevo cuit ", 2);

	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eContribuyente_Modificacion(eContribuyente array[], int TAM) {
	int rtn = 0;
	int idContribuyente;
	int index;
	int flag = 0;
	eContribuyente auxiliar;

	//LISTO TODOS LOS Contribuyente
	if (eContribuyente_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Contribuyente DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Contribuyente PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idContribuyente);

		//BUSCO INDEX POR ID EN ARRAY
		while (eContribuyente_BuscarPorID(array, TAM, idContribuyente) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idContribuyente);
		}

		//OBTENGO INDEX DEL ARRAY DE Contribuyente A MODIFICAR
		index = eContribuyente_BuscarPorID(array, TAM, idContribuyente);

		//LLAMO A FUNCION QUE MODIFICA Contribuyente
		auxiliar = eContribuyente_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

