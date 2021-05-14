#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "recaudacion.h"

void eRecaudacion_Inicializar(eRecaudacion array[], int TAM) {
	int i;
	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int eRecaudacion_ObtenerID(int *id) {
	int retorno;
	*id += 1;
	retorno = *id;
	return retorno;
}

int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int TAM) {
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
int eRecaudacion_BuscarPorID(eRecaudacion array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].idRecaudacion == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eRecaudacion_MostrarUno(eRecaudacion Recaudacion) {
	switch (Recaudacion.tipo) {
	case 1:
		printf("%3d               %3d	     %5.2f	    %3d          ARBA \n",
				Recaudacion.idRecaudacion, Recaudacion.idContribuyente,
				Recaudacion.importe, Recaudacion.mes);
		break;
	case 2:
		printf("%3d               %3d	     %5.2f	    %3d          IIBB \n",
				Recaudacion.idRecaudacion, Recaudacion.idContribuyente,
				Recaudacion.importe, Recaudacion.mes);
		break;
	case 3:
		printf("%3d               %3d	     %5.2f	    %3d          GANACIA \n",
				Recaudacion.idRecaudacion, Recaudacion.idContribuyente,
				Recaudacion.importe, Recaudacion.mes);
		break;
	}

}

int eRecaudacion_MostrarTodos(eRecaudacion array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\n LISTADO Recaudacion\n");
	printf("idRecaudacion        nombre        apellido        cuit        \n"); // %3d         %8s	      %2c          %.2f         %.2f        %.2f)

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eRecaudacion_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eRecaudacion_Alta(eRecaudacion array[], int TAM, int *id) {
	int rtn = 0;
	int auxIdContribuyente;
	int auxMes;
	int auxTipo;
	float auxImporte;

	eRecaudacion auxRecaudacion;

	int index = eRecaudacion_ObtenerIndexLibre(array, TAM);

	if (index != -1) {

		auxIdContribuyente = utn_getNumero(&auxRecaudacion.idContribuyente,"Ingrese un id de contribuyente","error. ingrese un id de contribuyente",1000,1500,2);
		auxMes = utn_getNumero(&auxRecaudacion.mes, "ingrese el mes",
				"Error.ingrese el mes", 1, 12, 2);
		auxTipo = utn_getNumero(&auxRecaudacion.tipo, "ingrese el tipo (1-ARBA,2-IIBB,3-GANANCIA)",
						"Error.ingrese el tipo (1-ARBA,2-IIBB,3-GANANCIA)", 1, 3, 2);
		auxImporte =  utn_getNumeroFlotante(&auxRecaudacion.importe,"ingrese el importe \n","Error.Ingrese el importe",0,999999,2);

		auxRecaudacion.idRecaudacion = eRecaudacion_ObtenerID(id);
		auxRecaudacion.isEmpty = OCUPADO;

		if (auxIdContribuyente == 0 && auxMes == 0 && auxTipo == 0 && auxImporte == 0) {
			array[index] = auxRecaudacion;
			rtn = 1;
		} else {
			rtn = 0;

		}
	}

	return rtn;
}


