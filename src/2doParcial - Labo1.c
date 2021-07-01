/*
 ============================================================================
 Name        : 2doParcial-Labo1.c
 Author      : Brutto, Ezequiel Andrés
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Sistema de gestión de Librería. 2do Parcial - Labo 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"
#include "Libros.h"
#include "LinkedList.h"
#include "Controller.h"

#define EDITORES 6

int main(void)
{
	setbuf(stdout, NULL);
	int validacionMenu = 1;
	int opcionMenu;
	eEditoriales dataEditores[EDITORES];
	char nombreAccesoArchivo[30];
	int flagDescuento = 0;

	inicializarArrayEditoriales(dataEditores,EDITORES);

	LinkedList* listadoLibros = ll_newLinkedList();
	do
	{
		menuPrincipal();
		utn_getNumero(&opcionMenu,"\n\n*Seleccione opción: ","\nERROR. Ha ingresado una opción no válida",1,5,100);
		fflush(stdin);
		switch(opcionMenu)
		{
			case 1:
				if(obtenerNombreArchivo(nombreAccesoArchivo) == 0)
				{
					if(controller_loadFromText(nombreAccesoArchivo,listadoLibros,dataEditores,EDITORES))
					{
						printf("\nSe produjo un error al cargar el archivo.");
						pausa();
					}
				}
			break;
			case 2:
				if(controller_ordenarLibros(listadoLibros))
				{
					printf("\nSe produjo un error al ordenar el archivo.");
					pausa();
				}
			break;
			case 3:
				if(controller_listarLibros(listadoLibros,dataEditores,EDITORES))
				{
					printf("\nSe produjo un error al listar.");
					pausa();
				}
			break;
			case 4:
				if(controller_realizarDescuentos(listadoLibros,dataEditores,EDITORES,&flagDescuento))
				{
					printf("\nSe produjo un error al realizar los descuentos.");
					pausa();
				}
			break;
			case 5:
				cerrarPrograma(&validacionMenu);
			break;
		}
	}while(validacionMenu != 0);

	return EXIT_SUCCESS;
}
