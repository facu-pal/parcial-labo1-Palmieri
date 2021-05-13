/*
 * recaudacion.h
 *
 *  Created on: 13 may. 2021
 *      Author: facun
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_

//define
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
//struct
typedef struct {
	int idRecaudacion;
	int idContribuyente;
	int mes;
	int tipo;
	float importe;
	int isEmpty;
} eRecaudacion;

void eRecaudacion_Inicializar(eRecaudacion array[], int TAM);
int eRecaudacion_ObtenerID(int *id);
int eRecaudacion_ObtenerIndexLibre(eRecaudacion array[], int TAM);
int eRecaudacion_BuscarPorID(eRecaudacion array[], int TAM, int ID);
void eRecaudacion_MostrarUno(eRecaudacion Recaudacion);
int eRecaudacion_MostrarTodos(eRecaudacion array[], int TAM);
int eRecaudacion_MostrarDadosDeBaja(eRecaudacion array[], int TAM);

//ABM
eRecaudacion eRecaudacion_CargarDatos(void);
eRecaudacion eRecaudacion_ModificarUno(eRecaudacion Recaudacion);
int eRecaudacion_Alta(eRecaudacion array[], int TAM);
int eRecaudacion_Baja(eRecaudacion array[], int TAM);
int eRecaudacion_Modificacion(eRecaudacion array[], int TAM);

#endif /* RECAUDACION_H_ */
