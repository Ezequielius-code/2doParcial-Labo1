/*
 * menu.h
 *
 *  Biblioteca Menu.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * \brief Despliega el menú ppal. del programa.
 */
void menuPrincipal();

/**
 * \brief Hace una pausa en la operación del programa, y solicita el pulsado
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
 * \brief Pregunta si se quiere cerrar el programa y cambia, o no, el valor de validación para hacerlo.
 * \param validacion Recibe por puntero el valor de validación.
 */
void cerrarPrograma(int *validacion);

/**
 * \brief Obtiene el nombre del archivo .csv a cargar.
 * \param nombreArchivo Puntero a dirección de memoria donde guarda el nombre del archivo con su extensión.
 * \return Retorna 0 (ÉXITO) si obtuvo el nombre del archivo y -1 (ERROR) si no.
 *
 */
int obtenerNombreArchivo(char* nombreArchivo);

#endif /* MENU_H_ */
