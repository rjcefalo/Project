#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cargar.h"



void main ( ){
	int x=0, y=0, z=0, w=0, cc=0, op= -1;
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
	ventasHechas *t=NULL;
	comprasHechas *h=NULL;
	ordenar *o=NULL;
	aux *a=NULL;
	while (op!=0){
		system( "cls");
		printf("\n\n");
		printf( "     MENU MANEJO DE LISTAS DINAMICAS\n\n");
		printf ("1. Cargar Centros De Venta Desde Archivo\n");
		printf ("2. Agregar Centros De Venta Manualmente\n");
		printf ("3. Mostrar Centros De Venta\n");
		printf ("4. Mostrar Ventas Por Centro de Ventas X\n");
		printf ("5. Eliminar Centro de Codigo X\n");
		printf ("6. Modificar Centro de Venta X\n");
		printf ("7. Cargar Clientes Desde Archivo\n");
		printf ("8. Agregar Nuevo Cliente Manual\n");
		printf ("9. Mostrar Clientes\n");
		printf ("10. Mostrar Compras Hechas de Cliente X\n");
		printf ("11. Eliminar Cliente de Cedula X\n");
		printf ("12. Modificar cliente X\n");
		printf ("13. Cargar Producto Desde Archivo a Centro de Codigo X\n");
		printf ("14. Crear Nuevo Producto Manual\n");
		printf ("15. Mostrar Productos de Centro X\n");
		printf ("16. Eliminar Producto Global\n");
		printf ("17. Modificar Producto Global X\n");
		printf ("18. Empezar Ventas\n");
		printf ("19. Cargar Datos Anteriores\n");
		printf ("20. Mostrar compras\n");
		printf ("21. Mostrar ventas\n");
		printf ("22. Consulta por centro de venta X, compras totales por cliente\n");
		printf ("23. Consulta por por cliente, COMPRAS TOTALES\n");
		printf ("24. Consulta nombres similares\n");
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
				ventasPorCentro(p,t);
				break;
			case 5:
				eliminarCentro(&p);
				break;
			case 6:
				printf("\nIngrese el codigo del centro que quiere modificar\n");
				scanf("%i",&x);
				modificarCentrosVenta(&p,x,y);
				break;
			case 7:
				agregarcliente(&c);
				break;
			case 8:
				agregarclientemanual(&c);
				break;
			case 9:
				mostrarClientes(c);
				break;
			case 10:
				mostrarCompras(c,h);
				break;
			case 11:
				eliminarcliente(&c);
				break;
			case 12:
				printf("\nIngrese la cedula del cliente que quiere modificar\n");
				scanf("%i",&x);
				modificarcliente(&c,x,y);
				break;
			case 13:
				agregarproducto(p,&pr);
				break;
			case 14:
				agregarproductomanual(p);
				break;
			case 15:
				printf("Ingrese centro a mostrar sus productos\n");
				scanf("%i",&x);
				mostrarCenPro (p,x);
				break;
			case 16:
				printf("Ingrese codigo del producto que desee eliminar\n");
				scanf("%i",&x);
				eliminarProductoGlobal(p,x);
				break;
			case 17:
				printf("Ingrese codigo del producto que desee modificar\n");
				scanf("%i",&x);
				modificarProductosGlobal(&p,x,y,z,w);
				break;
			case 18:
				while (colapso(p)){
					cambiacliente(p,c,fecha);
				if (colapso(p)==0)
					printf("Fecha de colapso: %i\n",fecha);
				else
					fecha=fecha+1;
				}
				ordenaCompraClientes(c);
				crearArchivoCentros(p);
				crearArchivoClientes(c);
				break;

			case 19:
				cargaranterior(&p,&c);
				ordenaCompraClientes(c);
				break;

			case 20:
				scanf("%i",&x);
				mostrarcompras(c,x);
				break;

			case 21:
				scanf("%i",&x);
				mostrarventas(p,x);
				break;
			case 22:
				ordenaclientecentro(c);
				printf("Ingrese codigo del centro que desea consultar\n");
				scanf("%i",&cc);
				pasacliente(c,h,cc,y);
				ordenaCompraClientes(c);
				break;
			case 23:
				consultaporcliente(c,&o);
				break;
			case 24:
				printf("Ingrese el nombre que desea consultar\n");
				scanf("%s",&nom);
				consultanombreiguales(c,nom,y);
				break;	
		}
		if ( op!=0) system("pause");
	}
}