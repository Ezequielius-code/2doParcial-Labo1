/*
 * parser.h
 * 	Biblioteca parser.
 *      Author: Brutto, Ezequiel Andrés
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Editoriales.h"

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayLibros LinkedList*
 * \return int
 *
 */
int parser_BookFromText(FILE* pFile,LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales);

#endif /* PARSER_H_ */
