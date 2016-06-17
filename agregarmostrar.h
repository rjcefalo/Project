#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UtilidadesMultilista.h"

 
void mostrarCentros(CentroVentas *p){
	if (p){
		printf("Codigo		: %i\n", p->codigo);
		printf("Telefono	: %s\n", p->telf);
		printf("Nombre		: %s\n", p->nombre);
		printf("Ciudad		: %s\n", p->ciudad);
		printf("Estado		: %s\n", p->estado);
		printf("Direccion	: %s\n", p->direccion);
		printf("\n--------------------------------\n");
		mostrarCentros(p->sig);
	}
}
void agregarcentro(CentroVentas **p){
	FILE *centro;
	centro=fopen("centros.txt","r");		
		while(!feof(centro)){
		int i=0,x=0;
		CentroVentas *aux=*p;
		CentroVentas *t=new CentroVentas;
		fscanf(centro,"%i\n",&x);
		t->codigo=x;
		fscanf(centro,"%s\n",t->nombre);
		fscanf(centro,"%s\n",t->ciudad);
		fscanf(centro,"%s\n",t->estado);
		fscanf(centro,"%s\n",t->direccion);
		fscanf(centro,"%s\n",t->telf);
		if (!aux){
			t->sig=NULL;
			t->abajo=NULL;
			t->prox=NULL;
			*p=t;}
	    else{
		while (aux){
			if (t->codigo!=aux->codigo)
				aux=aux->sig;
			else{
				i++;
				aux=aux->sig;
			}
		}	
		if (i==0){
			t->sig=*p;
			t->abajo=NULL;
			t->prox=NULL;
			*p=t;
		}
		else
			printf("El centro de codigo %i esta repetido en el archivo\n", t->codigo);
		}
		}
		fclose(centro);
}
void agregarCentroManual(CentroVentas **p){
	int i=0,x=0;
		CentroVentas *aux=*p;
		CentroVentas *t=new CentroVentas;
		printf("1. Codigo del centro:\n");
		scanf("\n%i",&x);
		t->codigo=x;
		printf("2. Nombre del centro:\n");
		scanf("\n%s",t->nombre);
		printf("3. Nombre de la cuidad:\n");
		scanf("\n%s",t->ciudad);
		printf("4. Nombre del estado:\n");
		scanf("\n%s",t->estado);
		printf("5. Direccion del centro:\n");
		scanf("\n%s",t->direccion);
		printf("6. Telefono del centro:\n");
		scanf("\n%s",t->telf);
		if (!aux){
			t->sig=NULL;
			t->abajo=NULL;
			t->prox=NULL;
			*p=t;}
	    else{
		while (aux){
			if (t->codigo!=aux->codigo)
				aux=aux->sig;
			else{
				i++;
				aux=aux->sig;
			}
		}	
		if (i==0){
			t->sig=*p;
			t->abajo=NULL;
			t->prox=NULL;
			*p=t;
		}
		else
			printf("El centro de codigo %i ya existe\n", t->codigo);
		}
		}
void mostrarClientes(Clientes *p){
	if (p){
		printf("Cedula		: %i\n", p->cedula);
		printf("Nombre		: %s\n", p->nombre);
		printf("Direccion	: %s\n", p->direccion);
		printf("\n--------------------------------\n");
		mostrarClientes(p->sig);
	}
}
void agregarcliente(Clientes **p){
	FILE *cliente;
	cliente=fopen("listaclientes.txt","r");		
	while(!feof(cliente)){
	int i=0,x=0;
	Clientes *aux=*p;
		//printf("Agrege nuevo cliente\n");
		Clientes *t=new Clientes;
		//printf("1. Cedula del cliente:\n");
		fscanf(cliente,"%i",&x);
		t->cedula=x;
		//printf("2. Nombre del cliente:\n");
		fscanf(cliente,"%s",t->nombre);
		//printf("3. Direccion del cliente:\n");
		fscanf(cliente,"%s",t->direccion);
		if (!aux){
			t->sig=NULL;
			t->abajo=NULL;
			*p=t;}
	    else{
		while (aux){
			if (t->cedula!=aux->cedula)
				aux=aux->sig;
			else{
				i++;
				aux=aux->sig;
			}
		}	
		if (i==0){
			t->sig=*p;
			t->abajo=NULL;
			*p=t;
		}
		else
			printf("El cliente de cedula %i esta repetido en el archivo\n", t->cedula);
	}
	}
	fclose(cliente);
}
void agregarclientemanual(Clientes **p){
	int i=0,x=0;
	Clientes *aux=*p;
		printf("Agrege nuevo cliente\n");
		Clientes *t=new Clientes;
		printf("1. Cedula del cliente:\n");		
		scanf("\n%i",&x);
		t->cedula=x;
		printf("2. Nombre del cliente:\n");
		scanf("\n%s",t->nombre);
		printf("3. Direccion del cliente:\n");
		scanf("\n%s",t->direccion);
		if (!aux){
			t->sig=NULL;
			t->abajo=NULL;
			*p=t;}
	    else{
		while (aux){
			if (t->cedula!=aux->cedula)
				aux=aux->sig;
			else{
				i++;
				aux=aux->sig;
			}
		}	
		if (i==0){
			t->sig=*p;
			t->abajo=NULL;
			*p=t;
		}
		else
			printf("El cliente de cedula %i ya existe\n", t->cedula);
	}
	}
void mostrarProductos(productos *p){
	if (p){
		printf("Codigo		 : %i\n", p->codigo);
		printf("Precio       : %i BSF \n", p->precio);
		printf("Cantidad	 : %i\n", p->cantidad);
		printf("\n--------------------------------\n");
		mostrarProductos(p->sig);
	}
}
void agregarproducto(CentroVentas *centro, productos **p){
	char archivo[20];
	FILE *listaproductos;
	printf("Indique Nombre del Archivo +.txt (Ex. archivo.txt)\n");
	scanf("%s",archivo);
	listaproductos=fopen(archivo,"r");		
	while(!feof(listaproductos)){
	int i=0,x=0,y=0,z=0, codigoCentro;
	productos *aux=*p;	
		productos *t=new productos;
		fscanf(listaproductos,"%i",&x);
		t->codigo=x;
		fscanf(listaproductos,"%i",&z);
		t->precio=z;
		fscanf(listaproductos,"%i",&y);
		t->cantidad=y;	
		if (!aux){
			t->sig=NULL;
			*p=t;}
	    else{
		while (aux){
			if (t->codigo!=aux->codigo)
				aux=aux->sig;
			else{
				i++;
				aux->cantidad+=t->cantidad;
				aux=aux->sig;

			}
		}	
		if (i==0){
			t->sig=*p;
			*p=t;
		} 
		else
			printf("el producto de Codigo %i ya existe en el archivo, se han agregado la cantidad de ambos:\n",t->codigo);
	}
	}
	fclose(listaproductos);
	int codigoCentro;
	mostrarCentros(centro);
	printf("Indique Codigo del Centro a Enlazar Lista de Productos:\n");
	scanf("%i",&codigoCentro);
		CentroVentas *aux2=new CentroVentas;
		aux2=centro;
		while(codigoCentro!=aux2->codigo)
			aux2=aux2->sig;
		if(codigoCentro==aux2->codigo){
			if(aux2->prox!=NULL){
			productos *ultimo = new productos;
			ultimo=*p;
			while (ultimo->sig!=NULL)
				ultimo=ultimo->sig;
			ultimo->sig=aux2->prox;
			}
			aux2->prox=*p;
		}
	
	mostrarProductos(*p);
	*p=NULL;
}
void agregarproductomanual(CentroVentas *centro){
	int i=0,x=0,y=0,z=0, codigoCentro;	
		productos *t=new productos;
		scanf("%i",&x);
		t->codigo=x;
		scanf("%i",&z);
		t->precio=z;
		scanf("%i",&y);
		t->cantidad=y;	
		
		t->sig=NULL;
		mostrarCentros(centro);
		printf("Indique Codigo del Centro al que desea agregar el Producto:\n");
		scanf("\n%i",&codigoCentro);
		CentroVentas *aux2=new CentroVentas;
		aux2=centro;
		while(codigoCentro!=aux2->codigo)
			aux2=aux2->sig;
		if(codigoCentro==aux2->codigo){
			productos *existe=new productos;
			existe=aux2->prox;
			while (existe!=NULL){
				if(t->codigo!=existe->codigo)
					existe=existe->sig;
				else{
					i++;
					existe->cantidad+=t->cantidad;
					existe=existe->sig;
				}
			}
			if (i==0){
				t->sig=aux2->prox;
				aux2->prox=t;
			}
		}
}	
void mostrarCenPro (CentroVentas *p, int x){
	productos *t = p->prox;
	if (p->codigo==x){
		printf("Productos de Centro de Ventas Numero: %i",x);
		while (t!=NULL){
			printf("\nCodigo: %i",t->codigo);
			printf("\nPrecio: %i",t->precio);
			printf("\nCantidad: %i\n",t->cantidad);
			t=t->sig;
		}
	}
	else mostrarCenPro(p->sig,x);
}
void mostrarcompras(Clientes *p,int x){
	comprasHechas *t=p->abajo;
	if (p->cedula==x){
		printf("Compras Hechas Por el Cliente de Ccedula %i: ",p->cedula);
		while(t){
			printf("\nFecha: %i",t->fecha);
			printf("\nCod. Centro: %i",t->Codcentro);
			printf("\nCod. Producto: %i",t->Codproducto);
			printf("\nPrecio: %i",t->precio);
			t=t->abajo;
		}
	}
	else
		mostrarcompras(p->sig,x);
}

void mostrarComprasHechas(Clientes *c,comprasHechas *t){
	if (t==NULL)
		t=c->abajo;
	if (c->abajo){
		int codigo=t->Codproducto,cantidadproducto=0;	
		while(t){
			if(codigo==t->Codproducto){
				cantidadproducto=cantidadproducto+1;
			}
			t=t->abajo;
			if (t==NULL)//(p->cedula==t->cedula)&&(codigo!=t->Codproducto))
				break;
			else if(codigo!=t->Codproducto)
				break;
		}
		if (cantidadproducto!=0)
			printf("Producto %i comprados :%i \n",codigo,cantidadproducto);
		else
			printf("\n");
	 }  if(t!=NULL)
		mostrarComprasHechas(c,t);
	}

void mostrarCompras(Clientes *c,comprasHechas *t){
	if (c){
	printf("\nCompras Hechas Por el Cliente de Cedula %i: \n",c->cedula);
	mostrarComprasHechas(c,t);
	mostrarCompras(c->sig,t);
}
}

void mostrarVentasHechas(CentroVentas *c,ventasHechas *t){
	if (t==NULL)
		t=c->abajo;
	if (c->abajo){
		int codigo=t->Codproducto,cantidadproducto=0;	
		while(t){
			if(codigo==t->Codproducto){
				cantidadproducto=cantidadproducto+1;
			}
			t=t->abajo;
			if (t==NULL)//(p->cedula==t->cedula)&&(codigo!=t->Codproducto))
				break;
			else if(codigo!=t->Codproducto)
				break;
		}
		if (cantidadproducto!=0)
			printf("Producto %i comprados :%i \n",codigo,cantidadproducto);
		else
			printf("\n");
	 }  if(t!=NULL)
		mostrarVentasHechas(c,t);
}

void ventasPorCentro(CentroVentas *c,ventasHechas *t){
	if (c){
		printf("\nVentas totales por el centro de Codigo %i: \n",c->codigo);
	mostrarVentasHechas(c,t);
	ventasPorCentro(c->sig,t);
}
}

void crearVentasCentros(CentroVentas*p){
	FILE *archivo= fopen("SAVEDATACentros.txt","a");
	ventasHechas *ventas;
	if(p){
		if (p->abajo)
			ventas=p->abajo;
		while (ventas){
			fprintf(archivo,"$ %i %i %i %i\n", ventas->fecha,ventas->cedula,ventas->Codproducto,ventas->precio);
			ventas=ventas->abajo;
		}
fclose(archivo);
	}
	
}
void crearArchivoCentros(CentroVentas *p){
	FILE *archivo= fopen("SAVEDATACentros.txt","a");
	if(p){
		fprintf(archivo,"@ %i %s %s %s %s %s\n", p->codigo, p->nombre,p->telf,p->ciudad,p->estado,p->direccion);		
		fclose(archivo);
		crearVentasCentros(p);

		crearArchivoCentros(p->sig);
	}
}

void crearComprasClientes(Clientes *p){
	FILE *archivo= fopen("SAVEDATAClientes.txt","a");
	comprasHechas *compras;
	if(p){
		//EN EL ARCHIVO QUEDA EN ORDEN DEBAJO DE LOS CLIENTES COMO
		//FECHA, CODIGO DEL PRODUCTO, CODIGO DEL CENTRO, PRECIO DEL PRODUCTO
		if (p->abajo)
			compras=p->abajo;
		while (compras){
			fprintf(archivo,"$ %i %i %i %i\n", compras->fecha,compras->Codproducto, compras->Codcentro, compras->precio);
			compras=compras->abajo;
		}
fclose(archivo);
	}
	
}

void crearArchivoClientes(Clientes *p){
	FILE *archivo= fopen("SAVEDATAClientes.txt","a");
	if(p){
		//EN EL ARCHIVO QUEDA IMPRESO EN ORDEN ARRIBA DE LAS COMPRAS COMO
		//NOMBRE, CEDULA, DIRECCION

		fprintf(archivo,"@ %s %i %s\n", p->nombre, p->cedula,p->direccion);		
		fclose(archivo);
		crearComprasClientes(p);
		crearArchivoClientes(p->sig);
	}
}

void cargarcentrosanterior(CentroVentas **p){
	FILE *centros;
	centros=fopen("SAVEDATACentros.txt","r");		
		while(!feof(centros)){
			CentroVentas *t=new CentroVentas;
			ventasHechas *aux= new ventasHechas;
			char op=NULL;
			int x,y,w,z,q;
			fscanf(centros,"%c",&op);
			if (op=='@'){
				fscanf(centros,"%i",&x);
				t->codigo=x;
				fscanf(centros,"%s",t->telf);
				fscanf(centros,"%s",t->nombre);
				fscanf(centros,"%s",t->ciudad);
				fscanf(centros,"%s",t->estado);
				fscanf(centros,"%s\n",t->direccion);
				if (!aux){
					t->sig=NULL;
					t->abajo=NULL;
					t->prox=NULL;
					*p=t;}
				else{
					t->sig=*p;
					t->abajo=NULL;
					t->prox=NULL;
					*p=t;
				}
			}
			else {
				fscanf(centros,"%i",&x);
				aux->fecha=x;
				fscanf(centros,"%i",&y);
				aux->cedula=y;
				fscanf(centros,"%i",&z);
				aux->Codproducto=z;
				fscanf(centros,"%i\n",&w);
				aux->precio=w;
				if (!(*p)->abajo){
					aux->abajo=NULL;
					(*p)->abajo=aux;
				}
				else{
					aux->abajo=(*p)->abajo;
					(*p)->abajo=aux;
				}
			}
		}
		fclose(centros);


}
void cargarclientesanterior(Clientes**c){
		FILE *clien;
		clien=fopen("SAVEDATAClientes.txt","r");		
		while(!feof(clien)){
			Clientes *t=new Clientes;
			comprasHechas *aux= new comprasHechas;
			char op=NULL;
			int x,y,w,z,q;
			fscanf(clien,"%c",&op);
			if (op=='@'){
				fscanf(clien,"%s",t->nombre);
				fscanf(clien,"%i",&x);
				t->cedula=x;				
				fscanf(clien,"%s\n",t->direccion);
				if (!aux){
					t->sig=NULL;
					t->abajo=NULL;
					*c=t;}
				else{
					t->sig=*c;
					t->abajo=NULL;
					*c=t;
				}
			}
			else {
				fscanf(clien,"%i",&x);
				aux->fecha=x;
				fscanf(clien,"%i",&y);
				aux->Codproducto=y;
				fscanf(clien,"%i",&z);
				aux->Codcentro=z;
				fscanf(clien,"%i\n",&w);
				aux->precio=w;
				if (!(*c)->abajo){
					aux->abajo=NULL;
					(*c)->abajo=aux;
				}
				else{
					aux->abajo=(*c)->abajo;
					(*c)->abajo=aux;
				}
			}
		}
		fclose(clien);
}
void cargaranterior(CentroVentas **p,Clientes**c){
	cargarcentrosanterior(p);
	cargarclientesanterior(c);

}
void mostrarventas(CentroVentas *p,int x){
	ventasHechas *t=p->abajo;
	if (p->codigo==x){
		printf("Ventas Hechas Por el Centro de Codigo %i: ",p->codigo);
		while(t){
			printf("\nFecha: %i",t->fecha);
			t=t->abajo;
		}
	}
	else
		mostrarventas(p->sig,x);
}

void consultaporcentro(Clientes *c,comprasHechas *t,int cc){
	FILE *h;
	int cant=0;
	if (t==NULL)
		t=c->abajo;
	if (c->abajo){
		int codigo=t->Codproducto,cantidadproducto=0;	
		while(t){
			if(t->Codcentro==cc){
				cantidadproducto=cantidadproducto+1;
			}
			t=t->abajo;
			if (t==NULL)
				break;
			else if(t->Codcentro!=cc)
				break;
		}
		if (cantidadproducto){
			//cant+=cantidadproducto;
			printf("Este cliente compro %i productos\n",cantidadproducto);
			h=fopen("consultas.txt","a");
				fprintf(h,"Este cliente compro %i productos\n",cantidadproducto);
				fclose(h);
		}
		else
			printf("");
	}  if(t!=NULL)
		consultaporcentro(c,t,cc);
	}

void pasacliente(Clientes *c,comprasHechas *t, int cc,int y){
	FILE *h;
	if (y==0){
		printf("\n -----CONSULTA EN EL CENTRO DE VENTAS %i , COMPRAS TOTALES POR CLIENTE----\n",cc);
	h=fopen("consultas.txt","a");
				fprintf(h,"\n -----CONSULTA EN EL CENTRO DE VENTAS %i , COMPRAS TOTALES POR CLIENTE----\n",cc);
				fclose(h);
	}
				
	if (c){
		printf("\n Total Compras Hechas Por el Cliente %s de Cedula %i:\n",c->nombre,c->cedula);
		h=fopen("consultas.txt","a");
		fprintf(h,"\n Total Compras Hechas Por el Cliente %s de Cedula %i:\n",c->nombre,c->cedula);
				fclose(h);
	consultaporcentro(c,t,cc);
	pasacliente(c->sig,t,cc,1);
}
}
void preconsultaporcliente(Clientes *c, ordenar **o){
	int x=0;
	if (c){
		comprasHechas *t=c->abajo;

		while (t){
			x=x+1;	
			t=t->abajo;
		}
		ordenar *aux= new ordenar;
		aux->cedula=c->cedula;
		aux->valor=x;
		if (!*o){
			aux->abajo=NULL;
			*o=aux;
		}
		else{
			aux->abajo=*o;
			*o=aux;
		}

		preconsultaporcliente(c->sig,o);
	}
	
}
void consultaporcliente(Clientes *c, ordenar **o){
	preconsultaporcliente(c,o);
	ordenarconsultaporcliente(*o);
	ordenar *t=*o;
	while (t){
		printf("El cliente de cedula %i compro %i veces\n",t->cedula,t->valor);
		t=t->abajo;
	}

}

void consultanombreiguales(Clientes *c, char nombre[20]){
	if (c){
		if (nombre==c->nombre){
			printf("Si entro en el if");
			printf("\nNombre:	%s\n",c->nombre);
			printf("Cedula:	%i\n",c->cedula);
			printf("Direccion:	%s\n",c->direccion);
		}
		printf("\%s",nombre);
		printf("no entro en el if\n");

		consultanombreiguales(c->sig,nombre);
	}	
}