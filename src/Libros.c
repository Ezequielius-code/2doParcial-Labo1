#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Libros.h"
#include "Editoriales.h"

eLibros* libros_nuevosParametros(char* idStr,char* tituloStr,char* autorStr,char* precio,eEditoriales* pArrayEditoriales,int lengthEditoriales,char* idEdStr)
{
	eLibros* libro;
	libro = (eLibros*)malloc(sizeof(eLibros));

	if(libro != NULL)
	{
		libro_setId(libro,atoi(idStr));
		libro_setTitulo(libro,tituloStr);
		libro_setAutor(libro,autorStr);
		libro_setPrecio(libro,atof(precio));
		libro_setEditorial(libro,idEdStr,pArrayEditoriales,lengthEditoriales);
	}

	return libro;
}

int libro_setId(eLibros* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->idLibro = id;
		retorno = 0;
	}

	return retorno;
}

int libro_setTitulo(eLibros* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL)
	{
		strncpy(this->titulo,titulo,sizeof(this->titulo));
		retorno = 0;
	}

	return retorno;
}

int libro_setAutor(eLibros* this,char* autor)
{
	int retorno = -1;

	if(this != NULL)
	{
		strncpy(this->autor,autor,sizeof(this->autor));
		retorno = 0;
	}

	return retorno;
}

int libro_setPrecio(eLibros* this,float precio)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

int libro_setEditorial(eLibros* this,char* idEditorial,eEditoriales* pArrayEditoriales,int lengthEditoriales)
{
	int retorno = -1;
	int auxId;

	if(this != NULL)
	{
		auxId = obtenerIdEditorial(pArrayEditoriales,lengthEditoriales,idEditorial);
		this->idEditorial = auxId;
		retorno = 0;
	}

	return retorno;
}

int libro_getIdLibro(eLibros* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->idLibro;
		retorno = 0;
	}

	return retorno;
}

int libro_getTitulo(eLibros* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 0;
	}

	return retorno;
}

int libro_getAutor(eLibros* this,char* autor)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(autor,this->autor);
		retorno = 0;
	}

	return retorno;
}

int libro_getPrecio(eLibros* this,float* precio)
{
	int retorno = -1;

	if(this != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

	return retorno;
}

int libro_getIdEditorial(eLibros* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int ordenarLibrosAutores(void* libro1,void* libro2)
{
	int retorno = 0;
	eLibros* auxLibro1 = libro1;
	eLibros* auxLibro2 = libro2;

	if(strcmp(auxLibro1->autor,auxLibro2->autor) > 0)
	{
		retorno = 1;
	}
	if(strcmp(auxLibro1->autor,auxLibro2->autor) < 0)
	{
		retorno = -1;
	}

	return retorno;
}

void realizarDescuentos(void *libro)
{
	float auxPrecio;
	int auxEditorial;

	if(libro != NULL)
	{
		auxPrecio = (*(eLibros*)(libro)).precio;
		auxEditorial = (*(eLibros*)(libro)).idEditorial;

		 if(auxEditorial == 1 && auxPrecio >= 300)
		 {
			 auxPrecio = auxPrecio - (auxPrecio*0.20);

			 (*(eLibros*)(libro)).precio = auxPrecio;
		 }
		 else
		 {
			 if(auxEditorial == 2 && auxPrecio <= 200)
			 {
				 auxPrecio = auxPrecio - (auxPrecio*0.10);
				 (*(eLibros*)(libro)).precio = auxPrecio;
			 }
		 }
	}
}
