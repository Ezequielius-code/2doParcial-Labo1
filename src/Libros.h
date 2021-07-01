/*
 * Libros.h
 *
 *  Biblioteca Libros.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef LIBROS_H_
#define LIBROS_H_

#include "Editoriales.h"

typedef struct
{
	int idLibro;
	char titulo[100];
	char autor[50];
	float precio;
	int idEditorial;
}eLibros;

/**
 * \brief Construye un dato de tipo eLibros.
 * \param idStr Recibe el Id del libro.
 * \param tituloStr Recibe el título del libro.
 * \param autorStr Recibe el nombre del autor del libro.
 * \param precio Recibe el precio del libro.
 * \param pArrayEditoriales Recibe el array de la estructura eEditoriales.
 * \param lengthEditoriales Define el tamaño de la cadena eEditoriales.
 * \param idEdStr Recibe el nombre de la editorial del libro.
 * \return Puntero a la estructura creada.
 *
 */
eLibros* libros_nuevosParametros(char* idStr,char* tituloStr,char* autorStr,char* precio,eEditoriales* pArrayEditoriales,int lengthEditoriales,char* idEdStr);

/**
 * \brief Setea un campo dentro de la estructura eLibros.
 * \param this Puntero al espacio de memoria donde seteará el campo.
 * \param id Campo a setear.
 * \return Retorna 0 (ÉXITO) si pudo setear el campo y -1 (ERROR) si no.
 *
 */
int libro_setId(eLibros* this,int id);

/**
 * \brief Setea un campo dentro de la estructura eLibros.
 * \param this Puntero al espacio de memoria donde seteará el campo.
 * \param titulo Campo a setear.
 * \return Retorna 0 (ÉXITO) si pudo setear el campo y -1 (ERROR) si no.
 *
 */
int libro_setTitulo(eLibros* this,char* titulo);

/**
 * \brief Setea un campo dentro de la estructura eLibros.
 * \param this Puntero al espacio de memoria donde seteará el campo.
 * \param autor Campo a setear.
 * \return Retorna 0 (ÉXITO) si pudo setear el campo y -1 (ERROR) si no.
 *
 */
int libro_setAutor(eLibros* this,char* autor);

/**
 * \brief Setea un campo dentro de la estructura eLibros.
 * \param this Puntero al espacio de memoria donde seteará el campo.
 * \param precio Campo a setear.
 * \return Retorna 0 (ÉXITO) si pudo setear el campo y -1 (ERROR) si no.
 *
 */
int libro_setPrecio(eLibros* this,float precio);

/**
 * \brief Setea un campo dentro de la estructura eLibros.
 * \param this Puntero al espacio de memoria donde seteará el campo.
 * \param idEditorial Campo a setear.
 * \param pArrayEditoriales Recibe el array de la estructura eEditoriales.
 * \param lengthEditoriales Define el tamaño de la cadena eEditoriales.
 * \return Retorna 0 (ÉXITO) si pudo setear el campo y -1 (ERROR) si no.
 *
 */
int libro_setEditorial(eLibros* this,char* idEditorial,eEditoriales* pArrayEditoriales,int lengthEditoriales);

/**
 * \brief Obtiene un campo desde la estructura eLibros.
 * \param this Puntero al espacio de memoria desde donde obtendrá el campo.
 * \param id Campo a obtener.
 * \return Retorna 0 (ÉXITO) si pudo obtener el campo y -1 (ERROR) si no.
 *
 */
int libro_getIdLibro(eLibros* this,int* id);

/**
 * \brief Obtiene un campo desde la estructura eLibros.
 * \param this Puntero al espacio de memoria desde donde obtendrá el campo.
 * \param titulo Campo a obtener.
 * \return Retorna 0 (ÉXITO) si pudo obtener el campo y -1 (ERROR) si no.
 *
 */
int libro_getTitulo(eLibros* this,char* titulo);

/**
 * \brief Obtiene un campo desde la estructura eLibros.
 * \param this Puntero al espacio de memoria desde donde obtendrá el campo.
 * \param autor Campo a obtener.
 * \return Retorna 0 (ÉXITO) si pudo obtener el campo y -1 (ERROR) si no.
 *
 */
int libro_getAutor(eLibros* this,char* autor);

/**
 * \brief Obtiene un campo desde la estructura eLibros.
 * \param this Puntero al espacio de memoria desde donde obtendrá el campo.
 * \param precio Campo a obtener.
 * \return Retorna 0 (ÉXITO) si pudo obtener el campo y -1 (ERROR) si no.
 *
 */
int libro_getPrecio(eLibros* this,float* precio);

/**
 * \brief Obtiene un campo desde la estructura eLibros.
 * \param this Puntero al espacio de memoria desde donde obtendrá el campo.
 * \param id Campo a obtener.
 * \return Retorna 0 (ÉXITO) si pudo obtener el campo y -1 (ERROR) si no.
 *
 */
int libro_getIdEditorial(eLibros* this,int* id);

/**
 * \brief Compara los strings de Autores dentro de la estructura eLibros.
 * \param libro1 1er libro a ser comparado.
 * \param libro2 2do libro a ser comparado.
 * \return Retorna 1 si el primer elemento es mayor que el segundo, -1 si el segundo elemento
 * 		   es mayor que el primero y 0 si ambos elementos son iguales.
 *
 */
int ordenarLibrosAutores(void* libro1,void* libro2);

/**
 * \brief Realiza un descuento sobre los precios de los libros según las condiciones puestas.
 * \param libro Elemento void al que se le asigna el tipo dentro de la función.
 */
void realizarDescuentos(void *libro);

#endif /* LIBROS_H_ */
