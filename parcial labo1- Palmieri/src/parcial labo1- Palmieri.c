#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contribuyente.h"
#include "recaudacion.h"

#define TAMESTRUCTA 50

int main(void) {
	setbuf(stdout, NULL);
	int menu;
	int contContribuyente = 0;
	int idContribuyente = 999;
	int idRecaudacion = 99;

	//CREO ARRAY DE ESTRUCTURA
	eContribuyente contribuyente[TAMESTRUCTA];
	eRecaudacion recaudacion[TAMESTRUCTA];

	//INICIALIAZO ARRAY DE ESTRUCTURA
	eContribuyente_Inicializar(contribuyente, TAMESTRUCTA);
	eRecaudacion_Inicializar(recaudacion, TAMESTRUCTA);

	do {
		printf("\n Menu\n");
		printf(" 1. Alta de contribuyente\n");
		printf(" 2. Modificar contribuyente\n");
		printf(" 3. Baja de contribuyente\n");
		printf(" 4. Recaudacion\n");
		printf(" 5. Refinanciar recaudacion \n");
		printf(" 6. Saldar recaudacion\n");
		printf(" 7. Imprimir contribuyente\n");
		printf(" 8. Imprimir recaudacion\n");
		printf(" 9. Salir\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			if (eContribuyente_Alta(contribuyente, TAMESTRUCTA, &idContribuyente)) {
				printf("El contribuyente se a dado de alta correctamente");
				contContribuyente++;
			} else {
				printf(
						"ERROR. El contribuyente no se a dado de alta correctamente");
			}
			break;
		case 2:
			if (contContribuyente != 0) {
				if (eContribuyente_Modificacion(contribuyente, TAMESTRUCTA)) {
					printf("Se modifico correctamente contribuyente\n");
					eContribuyente_MostrarTodos(contribuyente, TAMESTRUCTA);
					contContribuyente--;

				} else {
					puts("No se modifico el contribuyente");
				}
			}

			break;
		case 3:
			eContribuyente_Baja(contribuyente, TAMESTRUCTA );
			contContribuyente--;
			break;
		case 4:
			if (contContribuyente != 0) {
			eContribuyente_MostrarTodos(contribuyente, TAMESTRUCTA);
			eRecaudacion_Alta(recaudacion ,TAMESTRUCTA, &idRecaudacion);
			}
			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:
			break;
		default:
			printf("No elegiste ninguna opcion \n");
		}

	} while (menu != 9);

	return EXIT_SUCCESS;
}
