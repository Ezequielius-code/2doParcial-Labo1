#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"

int parser_BookFromText(FILE* pFile,LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales)
{
	char buffer[5][128];
	eLibros* auxLibro = NULL;
	int registros = 0;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer + 0),*(buffer + 1),*(buffer + 2),*(buffer + 3),*(buffer + 4));
	while (!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",*(buffer + 0),*(buffer + 1),*(buffer + 2),*(buffer + 3),*(buffer + 4));
		registros++;
		auxLibro = libros_nuevosParametros(*(buffer + 0),*(buffer + 1),*(buffer + 2),*(buffer + 3),pArrayEditoriales,lengthEditoriales,*(buffer + 4));
		ll_add(pArrayLibros,auxLibro);
	}

	return registros;
}
