#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Editoriales.h"

int inicializarArrayEditoriales(eEditoriales* pArrayEditoriales,int lengthEditoriales)
{
	int retorno = -1;

	if(pArrayEditoriales != NULL && lengthEditoriales > 0)
	{
		pArrayEditoriales[0].idEditorial = 1;
		strncpy(pArrayEditoriales[0].nombreEditorial,"Planeta",sizeof(pArrayEditoriales[0].nombreEditorial));

		pArrayEditoriales[1].idEditorial = 2;
		strncpy(pArrayEditoriales[1].nombreEditorial,"SIGLO XXI EDITORES",sizeof(pArrayEditoriales[1].nombreEditorial));

		pArrayEditoriales[2].idEditorial = 3;
		strncpy(pArrayEditoriales[2].nombreEditorial,"Pearson",sizeof(pArrayEditoriales[2].nombreEditorial));

		pArrayEditoriales[3].idEditorial = 4;
		strncpy(pArrayEditoriales[3].nombreEditorial,"Minotauro",sizeof(pArrayEditoriales[3].nombreEditorial));

		pArrayEditoriales[4].idEditorial = 5;
		strncpy(pArrayEditoriales[4].nombreEditorial,"SALAMANDRA",sizeof(pArrayEditoriales[4].nombreEditorial));

		pArrayEditoriales[5].idEditorial = 6;
		strncpy(pArrayEditoriales[5].nombreEditorial,"PENGUIN BOOKS",sizeof(pArrayEditoriales[5].nombreEditorial));

		retorno = 0;
	}

	return retorno;
}

int obtenerIdEditorial(eEditoriales* pArrayEditoriales,int lengthEditoriales,char* idStr)
{
	int retorno = 0;
	int i;

	if(pArrayEditoriales != NULL && lengthEditoriales > 0 && idStr != NULL)
	{
		for(i = 0;i < lengthEditoriales;i ++)
		{
			if(strcmp(idStr,pArrayEditoriales[i].nombreEditorial) == 0)
			{
				retorno = pArrayEditoriales[i].idEditorial;
				break;
			}
		}
	}

	return retorno;
}

int obtenerNombreEditorial(eEditoriales* pArrayEditoriales,int lengthEditoriales,int idEditorial,char* nombreEditorial)
{
	int retorno = -1;
	int i;

	if(pArrayEditoriales != NULL && lengthEditoriales > 0 && idEditorial > 0)
	{
		for(i = 0;i < lengthEditoriales;i ++)
		{
			if(idEditorial == pArrayEditoriales[i].idEditorial)
			{
				strcpy(nombreEditorial,pArrayEditoriales[i].nombreEditorial);
				break;
			}
		}

		retorno = 0;
	}

	return retorno;
}
