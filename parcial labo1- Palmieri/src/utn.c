#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int myGets(char *cadena, int longitud) {
	int retorno = -1;
	char bufferString[4096];

	if (cadena != NULL && longitud > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= longitud) {
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int getInt(int *pResultado) {
	int retorno = -1;
	char bufferString[50];
	if (pResultado != NULL && myGets(bufferString, sizeof(bufferString)) == 0
			&& esNumerica(bufferString, sizeof(bufferString))) {
		retorno = 0;
		*pResultado = atoi(bufferString);

	}
	return retorno;
}

int esNumerica(char *cadena, int limite) {
	int retorno = 1;
	int i;
	for (i = 0; i < limite && cadena[i] != '\0'; i++) {
		if (i == 0 && (cadena[i] == '+' || cadena[i] == '-')) {
			continue;
		}
		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char *mensaje, char *errorMensaje,int minimo, int maximo, int reintentos) {
	int retorno = -1;
	int bufferInt;
	do {
		printf("%s :", mensaje);
		if (getInt(&bufferInt) == 0 && bufferInt >= minimo
				&& bufferInt <= maximo) {
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s :", errorMensaje);
		reintentos--;
	} while (reintentos >= 0);

	return retorno;
}

int getFloat(float *pResultado) {
	int retorno = -1;
	char bufferString[50];
	if (pResultado != NULL && myGets(bufferString, sizeof(bufferString)) == 0 && esFlotante(bufferString)) {
		retorno = 0;
		*pResultado = atof(bufferString);

	}
	return retorno;

	return retorno;
}

int esFlotante(char *cadena) {
	int retorno = 1; // VERDADERO
	int i;
	int contPuntos = 0;

	if (cadena != NULL && strlen(cadena) > 0) {
		for (i = 0; cadena[i] != '\0'; i++) {
			if (i == 0 && (cadena[i] == '-' || cadena[i] == '+')) {
				continue;
			}
			if (cadena[i] < '0' || cadena[i] > '9') {
				if (cadena[i] == '.' && contPuntos == 0) {
					contPuntos++;

				} else {
					retorno = 0;
					break;
				}
			}
		}

	}

	return retorno;
}

int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *errorMensaje,float minimo, float maximo, int reintentos) {
	int retorno = -1;
	float bufferFloat;

	while (reintentos >= 0) {
		reintentos--;
		printf("%s :", mensaje);
		if (getFloat(&bufferFloat) == 0) {
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s :", errorMensaje);
	}

	return retorno;
}

int utn_getChar(char *pPalabra, char mensaje[], char errorMensaje[], int intentos) {
	int ret = -1;
	char aux;
	char buffer;
	int i;
	if (pPalabra != NULL && mensaje != NULL && errorMensaje != NULL && intentos >= 0) {

		printf("\n %s :", mensaje);
		fflush(stdin);
		scanf("%c", &buffer);
		for (i = 0; i < intentos; ++i) {
			aux = isdigit(buffer);
			if (aux == 0) {

				*pPalabra = buffer;
				ret = 0;
				break;
			} else {
				printf("\n %s :", errorMensaje);
				fflush(stdin);
				scanf("\n %c", &buffer);
			}
		}
	}
	return ret;
}

int utn_getCharOpciones(char *input, char mensaje[], char errorMensaje[], char opcionA, char opcionB, int intentos) {
	int ret = -1;
	char aux;
	char buffer;
	int i;
	if (input != NULL && mensaje != NULL && errorMensaje != NULL && opcionA != opcionB && intentos >= 0) {
		printf("\n %s :", mensaje);
		fflush(stdin);
		scanf("%c", &buffer);
		for (i = 0; i < intentos; ++i) {
			aux = isdigit(buffer);
			if (buffer >= opcionA && buffer <= opcionB && aux == 0) {
				*input = buffer;
				ret = 0;
				break;
			} else {
				printf("\n %s :", errorMensaje);
				fflush(stdin);
				scanf("\n %c", &buffer);
			}
		}
	}

	return ret;

}

int utn_getString(char array[], int tamArray, char mensaje[], char errorMensaje[],int intentos) {
	int ret = -1;
	int aux;
	char buffer[tamArray];
	int i;
	if (array != NULL && tamArray > 0 && mensaje != NULL && errorMensaje != NULL
			&& intentos >= 0) {
		printf("\n %s :", mensaje);
		fflush(stdin);
		gets(buffer);
		for (i = 0; i < intentos; ++i) {
			aux = strlen(buffer);

			if (aux <= tamArray) {
				strcpy(array, buffer);
				ret = 0;
				break;
			} else {
				printf("\n %s :", errorMensaje);
				fflush(stdin);
				gets(buffer);

			}
		}

	}

	return ret;

}

void Formato_NombreApellido(char *pNombre, char *pApellido, char *pFormatoNombreApellido) {

	strcpy(pFormatoNombreApellido, pApellido);
	strcat(pFormatoNombreApellido, ", ");
	strcat(pFormatoNombreApellido, pNombre);

	strlwr(pFormatoNombreApellido);

	if (strlen(pNombre) > 0 && strlen(pApellido) > 0) {
		for (int i = 0; i < strlen(pFormatoNombreApellido); i++) {
			if (i == 0 && isspace(pFormatoNombreApellido[i]) == 0) {
				pFormatoNombreApellido[0] = toupper(pFormatoNombreApellido[0]);

			} else {
				if (isspace(pFormatoNombreApellido[i]) && i < strlen(pFormatoNombreApellido) - 1) {
					pFormatoNombreApellido[i + 1] = toupper(pFormatoNombreApellido[i + 1]);
				}
			}
		}
	}
}
int esCuit(char* cadena)
{
	int ret;
	int i;
	int contadorDigito=0;
	int contadorGuion=0;

	if(cadena!=NULL)
	{
		for(i=0;cadena[i]!='\0';i++)
		{
			if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
			{
				if(cadena[i]=='-')
				{
					contadorGuion++;
				}
				else
				{
					ret=-1;
					break;
				}
			}
		}
		if(contadorDigito==11 && contadorGuion==2)
		{
			ret=0;
		}
	}
	return ret;
}

int utn_getCuit(char input[],char mensaje[],char eMensaje[],int reintentos)
{
	int ret;
	char buffer[14];
	int i;
	int aux;

		if(input!=NULL && mensaje!= NULL && eMensaje!= NULL && reintentos>0)
		{
			for(i=reintentos;i>0;i--)
			{
				printf("\n %s",mensaje); //Se le pide el tipo de dato a ingresar al usuario
				fflush(stdin);
				fgets(buffer,14,stdin);
				aux=esCuit(buffer);
				if(aux==0)
				{
					if(buffer[2]=='-' && buffer[11]=='-')
					{
						strcpy(input,buffer);
						ret=0;
						break;
					}
				}
				else
				{
					printf("\n %s\n",eMensaje);
				}
			}
		}
		if(reintentos==0)
		{
			ret=-1;
		}
	return ret;
}
