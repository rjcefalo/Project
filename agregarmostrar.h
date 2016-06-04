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
	//int i=0,x=0;
	FILE *centro;
	centro=fopen("centros.txt","r");		
		while(!feof(centro)){
		int i=0,x=0;
		CentroVentas *aux=*p;
		CentroVentas *t=new CentroVentas;
		fscanf(centro,"%i\n",&x);
		t->codigo=x;
		//printf("2. Nombre del centro:\n");
		fscanf(centro,"%s\n",t->nombre);
		//printf("3. Nombre de la cuidad:\n");
		fscanf(centro,"%s\n",t->ciudad);
		//printf("4. Nombre del estado:\n");
		fscanf(centro,"%s\n",t->estado);
		//printf("5. Direccion del centro:\n");
		fscanf(centro,"%s\n",t->direccion);
		//printf("6. Telefono del centro:\n");
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
