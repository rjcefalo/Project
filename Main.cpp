#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargar.h"



void main ( ){
	int x=0, y=0, z=0, op= -1;
	int fecha=1;
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
		printf ("1. Cargar Centros De Venta Desde Archivo\n");
		printf ("2. Agregar Centros De Venta Manualmente\n");
		printf ("3. Mostrar Centros De Venta\n");
		printf ("4. Eliminar Centro de Codigo X\n");
		printf ("5. Cargar Clientes Desde Archivo\n");
		printf ("6. Agregar Nuevo Cliente Manual\n");
		printf ("7. Mostrar Clientes\n");
		printf ("8. Eliminar Cliente de Cedula X\n");
		printf ("9. Cargar Producto Desde Archivo a Centro de Codigo X\n");
		printf ("10. Crear Nuevo Producto Manual\n");
		printf ("11. Mostrar Productos de Centro X\n");
		printf ("12. Eliminar Producto Global\n");
		printf ("0. Salir\n");
		scanf_s ("%i", &op);
		system( "cls" );
		printf( "\n\n");
		
		switch (op){
			case 1: 
				agregarcentro(&p);
				break;
			case 2:
				agregarCentroManual(&p);
				break;
			case 3:
				mostrarCentros(p);
				break;
			case 4:
				eliminarCentro(&p);
				break;
			case 5:
				agregarcliente(&c);
				break;
			case 6:
				agregarclientemanual(&c);
				break;
			case 7:
				mostrarClientes(c);
				break;
			case 8:
				eliminarcliente(&c);
				break;
			case 9:
				agregarproducto(p,&pr);
				break;
			case 10:

				agregarproductomanual(p);
				break;

			case 11:
				printf("ingrese centro a mostrar sus productos");
				scanf("%i",&x);
				mostrarCenPro (p,x);
				break;
			case 12:
				printf("ingrese codigo del producto que desee eliminar");
				scanf("%i",&x);
				eliminarProductoGlobal(p,x);
				break;
			case 13:
				while (colapso){
				cargartodo(p,c,fecha);
				fecha=fecha+1;
				}
				break;
			case 14:
				printf("%i",colapso(p));
				break;

		};
		if ( op!=0) system("pause");
	};
}