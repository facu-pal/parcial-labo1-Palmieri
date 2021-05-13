/*
 * Contribuyente.h
 *
 *  Created on: 13 may. 2021
 *      Author: facun
 */

#ifndef Contribuyente_H_
#define Contribuyente_H_

//define
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//struct
typedef struct {
	int idContribuyente;
	char nombre[25];
	char apellido[25];
	char cuit[14];
	int isEmpty;
} eContribuyente;

void eContribuyente_Inicializar(eContribuyente array[], int TAM);
int eContribuyente_ObtenerID(int *id);
int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM);
int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID);
void eContribuyente_MostrarUno(eContribuyente Contribuyente);
int eContribuyente_MostrarTodos(eContribuyente array[], int TAM);
int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM);

//ABM
eContribuyente eContribuyente_CargarDatos(void);
eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente);
int eContribuyente_Alta(eContribuyente array[], int TAM,int *id);
int eContribuyente_Baja(eContribuyente array[], int TAM);
int eContribuyente_Modificacion(eContribuyente array[], int TAM);

#endif /* Contribuyente_H_ */
