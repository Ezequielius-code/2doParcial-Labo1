/*
 * menu.h
 *
 *  Biblioteca Menu.
 *      Author: Brutto, Ezequiel Andr�s
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * \brief Despliega el men� ppal. del programa.
 */
void menuPrincipal();

/**
 * \brief Hace una pausa en la operaci�n del programa, y solicita el pulsado
 * de una tecla para continuar ejecutando.
 */
void pausa();

/**
 * \brief Despliega el encabezado de la lista de Trabajos.
 */
void encabezadoListadoLibros();

/**
 * \brief Despliega el cierre de la lista de Trabajos.
 */
void pieListadoLibros();

/**
 * \brief Pregunta si se quiere cerrar el programa y cambia, o no, el valor de validaci�n para hacerlo.
 * \param validacion Recibe por puntero el valor de validaci�n.
 */
void cerrarPrograma(int *validacion);

/**
 * \brief Obtiene el nombre del archivo .csv a cargar.
 * \param nombreArchivo Puntero a direcci�n de memoria donde guarda el nombre del archivo con su extensi�n.
 * \return Retorna 0 (�XITO) si obtuvo el nombre del archivo y -1 (ERROR) si no.
 *
 */
int obtenerNombreArchivo(char* nombreArchivo);

#endif /* MENU_H_ */
