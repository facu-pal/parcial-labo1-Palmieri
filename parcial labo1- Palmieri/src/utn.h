/*
 * utn.h
 *
 *  Created on: 13 may. 2021
 *      Author: facun
 */

#ifndef UTN_H_
#define UTN_H_
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char*cadena, int longitud);
/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getInt(int* pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
 int esNumerica(char* cadena, int limite);
 /**
  * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  */
int utn_getNumero(int* pResultado, char* mensaje, char* errorMensaje, int minimo, int maximo, int reintentos);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
 int getFloat(float* pResultado);

 /**
  * \brief Verifica si la cadena ingresada es flotante
  * \param cadena Cadena de caracteres a ser analizada
  * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
  *
  */
  int esFlotante(char* cadena);

 /**
  * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
  *
  */
 int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* errorMensaje, float minimo, float maximo, int reintentos);


 /*Brief: Solicita el ingreso por teclado de un char
  * 1er parametro es puntero donde se guardará el char ingresado
  * 2do parametro es el mensaje de solicitud del dato al usuario
  * 3er parametro es el mensaje de error ante un intento erroneo de ingreso del char
  * 4to parametro es la cantidad de intentos que se le da al usuario
  * retorna 0 si se ingreso correctamente
  * retorna -1 si no pudo ingresar correctamente el char
  */
 int utn_getChar(char* pPalabra,char mensaje[],char errorMensaje[],int intentos);

 /*Brief: Solicita el ingreso por teclado de un char
  * 1er parametro es puntero donde se guardará el char ingresado
  * 2do parametro es el mensaje de solicitud del dato al usuario
  * 3er parametro es el mensaje de error ante un intento erroneo de ingreso del char
  * 4to parametro es el la opcion 1
  * 5to parametro es el la opcion 2
  * 6to parametro es la cantidad de intentos que se le da al usuario
  * retorna 0 si se ingreso correctamente
  * retorna -1 si no pudo ingresar correctamente el char
  */
 int utn_getCharOpciones(char* input,char mensaje[],char errorMensaje[],char opcionA,char opcionB,int intentos);

 /*Brief: Solicita el ingreso por teclado de un string
  * 1er parametro es el array donde se guardará el texto ingresado
  * 2do parametro es el tamaño del array
  * 3er parametro es el mensaje de solicitud del dato al usuario
  * 4to parametro es el mensaje de error ante un intento erroneo de ingreso del texto
  * 5to parametro es la cantidad de intentos que se le da al usuario
  * retorna 0 si se ingreso correctamente
  * retorna -1 si no pudo ingresar correctamente un string
  */
 int utn_getString(char array[],int tamArray,char mensaje[],char errorMensaje[],int intentos);



 /*brief: solicita el nombre y el apellido, y lo deja apellido coma nombre con las primeras letras en mayuscula
  *1er parametro el nombre
  *2do parametro el apellido
  *3er parametro donde se guarda el apellido y nombre*/
 void Formato_NombreApellido(char *pNombre, char *pApellido, char *pFormatoNombreApellido);

 int esCuit(char* cadena);

 int utn_getCuit(char input[],char mensaje[],char eMensaje[],int reintentos);


#endif /* UTN_H_ */
