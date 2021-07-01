/*
 * Editoriales.h
 *
  *  Biblioteca Editoriales.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef EDITORIALES_H_
#define EDITORIALES_H_

typedef struct
{
	int idEditorial;
	char nombreEditorial[20];
}eEditoriales;

/**
 * \brief Setea los valores de cada posición del array de tipo eEditoriales.
 * \param pArrayEditoriales Recibe el array de la estructura eEditoriales.
 * \param lengthEditoriales Define el tamaño de la cadena.
 * \return Retorna 0 (ÉXITO) si inicializa el array y -1 (ERROR) si no.
 *
 */
int inicializarArrayEditoriales(eEditoriales* pArrayEditoriales,int lengthEditoriales);

/**
 * \brief Obtiene desde un string el número de Id de los editoriales.
 * \param pArrayEditoriales Recibe el array de la estructura eEditoriales.
 * \param lengthEditoriales Define el tamaño de la cadena.
 * \param idStr Recibe el string a analizar.
 * \return Retorna el número de Id del editorial, en caso de no encontrarlo 0.
 *
 */
int obtenerIdEditorial(eEditoriales* pArrayEditoriales,int lengthEditoriales,char* idStr);

/**
 * \brief Obtiene desde un entero el nombre de la editorial.
 * \param pArrayEditoriales Recibe el array de la estructura eEditoriales.
 * \param lengthEditoriales Define el tamaño de la cadena.
 * \param idEditorial Recibe el número de Id de la editorial.
 * \param nombreEditorial Puntero al espacio de memoria donde guardará el nombre de la editorial.
 * \return Retorna 0 (ÉXITO) si puede convertir el entero a string y -1 (ERROR) si no.
 *
 */
int obtenerNombreEditorial(eEditoriales* pArrayEditoriales,int lengthEditoriales,int idEditorial,char* nombreEditorial);

#endif /* EDITORIALES_H_ */
