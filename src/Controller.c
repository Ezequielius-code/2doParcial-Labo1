#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Editoriales.h"
#include "Libros.h"
#include "menu.h"

int controller_loadFromText(char* path,LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales)
{
	int retorno = -1;
	int registros;
	FILE *file;

	file = fopen(path,"r");
	if (file != NULL)
	{
		registros = parser_BookFromText(file,pArrayLibros,pArrayEditoriales,lengthEditoriales);
		if(registros)
		{
			fclose(file);
			printf("\nEl archivo se ha cargado exitosamente.");
			pausa();
			retorno = 0;
		}
	}

	return retorno;
}

int controller_listarLibros(LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales)
{
	int retorno = -1;
	int i;
	eLibros* auxLibro;
	int auxIdLibro;
	char auxTitulo[100];
	char auxAutor[50];
	float auxPrecio;
	int auxIdEdit;
	char auxNombreEditorial[20];

	if(pArrayLibros != NULL && ll_isEmpty(pArrayLibros) == 0)
	{
		encabezadoListadoLibros();
		for(i = 0;i < ll_len(pArrayLibros);i ++)
		{
			auxLibro = ll_get(pArrayLibros,i);

			if(auxLibro != NULL)
			{
				libro_getIdLibro(auxLibro,&auxIdLibro);
				libro_getTitulo(auxLibro,auxTitulo);
				libro_getAutor(auxLibro,auxAutor);
				libro_getPrecio(auxLibro,&auxPrecio);
				libro_getIdEditorial(auxLibro,&auxIdEdit);
				obtenerNombreEditorial(pArrayEditoriales,lengthEditoriales,auxIdEdit,auxNombreEditorial);
				printf("\n|%2d|%50s |%16s | $%8.2f|%18s |",auxIdLibro,auxTitulo,auxAutor,auxPrecio,auxNombreEditorial);
			}
		}
		pieListadoLibros();
		pausa();

		retorno = 0;
	}
	else
	{
		printf("\nNo hay datos ingresados que mostrar.");
		pausa();
		retorno = 0;
	}

	return retorno;
}

int controller_ordenarLibros(LinkedList* pArrayLibros)
{
	int retorno = -1;

	if(pArrayLibros != NULL && ll_isEmpty(pArrayLibros) == 0)
	{
		ll_sort(pArrayLibros,ordenarLibrosAutores,1);
		retorno = 0;
		printf("\nEl archivo se ha ordenado exitosamente.");
		pausa();
	}
	else
	{
		printf("\nNo hay datos disponibles para ordenar.");
		pausa();
		retorno = 0;
	}

	return retorno;
}

int controller_saveAsText(char* path,LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales)
{
	int retorno = -1;
	char respuesta;
	FILE *file;
	int i;
	eLibros* auxLibro;
	int auxIdLibro;
	char auxTitulo[100];
	char auxAutor[50];
	float auxPrecio;
	int auxIdEditorial;
	char auxNombreEditorial[20];

	printf("\n¿Desea realizar descuentos y guardar los cambios? (s)i - (n)o: ");
	fflush(stdin);
	scanf("%c",&respuesta);

	if(respuesta == 's')
	{
		file = fopen(path,"w");
		if (file != NULL)
		{
			fprintf(file,"idLibro,Titulo,Autor,Precio,idEditorial\n");

			for(i = 0;i < ll_len(pArrayLibros);i ++)
			{
				auxLibro = ll_get(pArrayLibros,i);
				libro_getIdLibro(auxLibro,&auxIdLibro);
				libro_getTitulo(auxLibro,auxTitulo);
				libro_getAutor(auxLibro,auxAutor);
				libro_getPrecio(auxLibro,&auxPrecio);
				libro_getIdEditorial(auxLibro, &auxIdEditorial);
				obtenerNombreEditorial(pArrayEditoriales,lengthEditoriales,auxIdEditorial,auxNombreEditorial);
				fprintf(file,"%d,%s,%s,%.2f,%s\n",auxIdLibro,auxTitulo,auxAutor,auxPrecio,auxNombreEditorial);
			}

			retorno = 0;
		}

		fclose(file);
	}

	return retorno;
}

int controller_realizarDescuentos(LinkedList* pArrayLibros,eEditoriales* pArrayEditoriales,int lengthEditoriales,int* flag)
{
	int retorno = -1;
	LinkedList* nuevoPrecio = NULL;

	if(ll_isEmpty(pArrayLibros) == 0 && pArrayLibros != NULL)
	{
		if(*flag == 0)
		{
			nuevoPrecio = ll_map(pArrayLibros,realizarDescuentos);
			controller_saveAsText("mapeado.csv",nuevoPrecio,pArrayEditoriales,lengthEditoriales);
			ll_deleteLinkedList(nuevoPrecio);
			*flag = 1;
			printf("\nSe han realizado los descuentos exitosamente.");
			pausa();
		}
		else
		{
			printf("\nYa se han realizado los descuentos correspondientes.");
			pausa();
		}

		retorno = 0;
	}
	else
	{
		printf("\nNo hay datos ingresados.");
		pausa();

		retorno = 0;
	}

	return retorno;
}
