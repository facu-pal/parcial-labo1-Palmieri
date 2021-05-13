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
	*id+= 1;
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

eContribuyente eContribuyente_CargarDatos(void) {
	eContribuyente auxiliar;

	utn_getString(auxiliar.nombre, 25,"Ingrese un nombre","Error. ingrese un nombre",2);
	utn_getString(auxiliar.apellido , 25,"Ingrese un apelido","Error. ingrese un nombre",2);
	utn_getCuit(auxiliar.cuit,"ingrese cuit","error.cuit",2);

	return auxiliar;
}

int eContribuyente_Alta(eContribuyente array[], int TAM,int *id) {
	int rtn = 0;
	eContribuyente auxContribuyente;


	int index = eContribuyente_ObtenerIndexLibre(array, TAM);


	if (index != -1) {

		auxContribuyente = eContribuyente_CargarDatos();

		auxContribuyente.idContribuyente = eContribuyente_ObtenerID(id);

		auxContribuyente.isEmpty = OCUPADO;

		array[index] = auxContribuyente;

		rtn = 1;
	}

	return rtn;
}
