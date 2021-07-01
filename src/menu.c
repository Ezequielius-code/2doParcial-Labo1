#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "utn.h"

void menuPrincipal()
{
	printf("\n|===============<MENÚ>===============|"
		   "\n|          1.Cargar archivo          |"
		   "\n|   2.Ordenar libros por autor (ASC) |"
		   "\n|    3.Imprimir listado de libros.   |"
		   "\n|        4.Aplicar descuentos:       |"
		   "\n|       _20p/c Planeta desde $300    |"
		   "\n|       _10p/c SIGLO XXI hasta $200  |"
		   "\n|  (generar archivo : 'mapeado.csv') |"
		   "\n|               5.SALIR              |"
		   "\n|====================================|");
}

void pausa()
{
	printf("\n\nPulse una tecla para continuar...\n");
	fflush(stdin);
	getchar();
}

void encabezadoListadoLibros()
{
	printf("\n=========================================================================================================");
	printf("\n|%s|%50s |%16s | %s |%18s |","ID"," TITULO                      "," AUTOR     "," PRECIO ","EDITORIAL    ");
	printf("\n=========================================================================================================");
}

void pieListadoLibros()
{
	printf("\n=========================================================================================================");
}

void cerrarPrograma(int *validacion)
{
	char respuesta;

	utn_getCaracter(&respuesta,"\n¿Esta seguro que desea cerrar el programa?\n"
			        "           (s)i - (n)o        Repuesta: ","\nERROR. Respuesta no valida.",'s','n',100);
	pausa();
	if(respuesta == 's')
	{
		printf("\n\n\t EL PROGRAMA SE HA CERRADO EXITOSAMENTE.");
		*validacion = 0;
	}
	else
	{
		*validacion = 1;
	}
}

int obtenerNombreArchivo(char* nombreArchivo)
{
	int retorno = -1;
	char auxNombre[30];

	if(nombreArchivo != NULL)
	{
		printf("\nIngrese el nombre del archivo a cargar.\nSugerencia: 'libros.csv' _____ ");
		fgets(auxNombre,30,stdin);

		auxNombre[strcspn(auxNombre,"\n")] = 0;
		strcpy(nombreArchivo,auxNombre);
		retorno = 0;
	}

	return retorno;
}
