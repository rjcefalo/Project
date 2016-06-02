#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "primitivas.h"



void main ( ){
	int x=0, y=0, z=0, op= -1;
	char nom[20], ciu[20], est[20], dir[40];
	FILE *principales = fopen("princip.txt","r");
	FILE *subLista = fopen("sub.txt","r");
	/* importante: Crear el puntero cabeza e INICIALIZARLO en NULL */
	//pila *aba = new pila;
	//multipila *principal= NULL;
	CentroVentas *p=NULL;
	Clientes *c=NULL;
	productos *pr=NULL;
	while (op!=0){
		system( "cls");
		printf("\n\n");
		printf( "     MENU MANEJO DE LISTAS DINAMICAS\n\n");
		printf ("1. Crear Nuevo Centro De Ventas\n");
		printf ("2. Mostrar Centros De Venta\n");
		printf ("3. Crear Nuevo Cliente\n");
		printf ("4. Mostrar Clientes\n");
		printf ("5. Crear Nuevo Producto\n");
		printf ("6. Mostrar Producto\n");
		printf ("0. Salir\n");
		scanf_s ("%i", &op);
		system( "cls" );
		printf( "\n\n");
		
		switch (op){
			case 1: 
				agregarcentro(&p);
				break;
			case 2:
				mostrarCentros(p);
				break;
			case 3:
				agregarcliente(&c);
				break;
			case 4:
				mostrarClientes(c);
				break;
			case 5:
				printf("ingrese productos");
				agregarproducto(&pr);
				break;
			case 6:
				 mostrarProductos(pr);
				 break;
			/*case 1 :
				if(principales!=NULL){
					printf ("Archivo princip.txt CARGADO\n");
					while(!feof(principales)){
						fscanf(principales,"%i\n",&x);
						nuevoMulti(&principal,x);
					}
					fclose(principales);
				}
				else{
					printf ("Archivo princip.txt No encontrado\n");
					printf ("1. Insertar elemento en lista\n");
					scanf_s("%i", &x);
					nuevoMulti(&principal,x);
				}
				break;
			case 2:				
				printf ("2. Insertar elemento en Sub-lista\n");
				printf ("Elija Sub-lista a insertar\n");
				scanf_s("%i", &y);

				if(subLista!=NULL){					
					while(!feof(subLista)){
						fscanf(subLista,"%i\n",&x);
						nuevoSubpila(principal,y,x);
					}
					fclose(principales);
					printf ("Archivo sub.txt CARGADO\n");
				}
				else{
					printf ("Archivo sub.txt No encontrado\n");
					printf ("Numero a insertar en sublista\n");
					scanf_s("%i", &x);
					nuevoSubpila(principal,y,x);
				}
				break;
			case 3:
				printf ("3. Lista Principal\n");
				mostrarMulti(principal);
				break;

			case 4:
				printf ("4. Sub-Lista\n");
				printf ("Elija Sub-lista a mostrar\n");
				scanf_s("%i", &y);								
				mostrarSub(principal,y);
				break;

			case 5:
				printf ("5. Buscar X en principal\n");
				scanf_s("%i", &x);
				//buscarXEnSubs(principal,x);
*/
		};
		if ( op!=0) system("pause");
	};
}