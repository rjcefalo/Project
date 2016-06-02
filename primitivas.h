#include "crear.h"

/*int vacio(productos *p){
        return (!(p));
    };
int buscar(productos *p,int x){
        productos (*aux)=(p);
        while (aux){
            if (aux->valor==x)
                return 1;
			else
				return 0;
            aux=aux->sig;
        }
    };
void apilar(productos **p,int x,int y,int z){
        productos (*t)=new productos;
         t->codigo=x;
         t->precio=y;
		 t->cantidad=z;
		 t->sig=*p;
         *p=t;
    };
void mostrar (productos *p){
    if(!(vacio(p))){
        while (p){
            printf("|%i|\n",p->codigo);
			printf("|%i|->\n",p->precio," BS ");
			printf("|%i|\n",p->cantidad);
            p=p->sig;
        }
}
};
int multiplo(int x, int y){
	if (((x%y)==0)||((y%x)==0))
	 return 1;
	else
	 return 0;
}

int contar(productos **p){ 
    int k;
    if (!(vacio(*p))){
        k=tope(*p);
        desapilar(p);
        int w=contar(p);
        apilar(p,k);
        return w+1;}
    return 0;					
}
void eliminarrep(productos **p,int x){
	if (!(vacio(*p))){
	int tapa=tope(*p);
	desapilar(p);
	eliminarrep(p,x);
	if (tapa != x)
	apilar(p,tapa);
	}
}
int repetidocentrodeventas(centroDeVentas **p, int x){
	if 
}*/


/*void nuevoCentro(CentroVentas **p, int x,int y,char nom[20],char ciu[20],char est[20],char dir[40]){
	CentroVentas *aux=agregarcentro(p);
	CentroVentas *t=*p;
	int i=0;
	if (!t)
		*p=t;
	else{
		while (t){
			if (t->codigo!=aux->codigo)
				t=t->sig;
			else{
				i++;
				t=t->sig;
			}
		}	
		if (i==0){
			t->sig=*p;
			*p=t;
		}
	}
}*/ 
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
		}
		}
		fclose(centro);
		mostrarCentros(*p);
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
	}
	}
	fclose(cliente);
	mostrarClientes(*p);
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

void agregarproducto(productos **p){
	FILE *listaproductos;
	listaproductos=fopen("%s.txt","r");		
	while(!feof(listaproductos)){
	int i=0,x=0,y=0,z=0;
	productos *aux=*p;	
		productos *t=new productos;
		scanf("%i",&x);
		t->codigo=x;
		scanf("%i",&z);
		t->precio=z;
		scanf("%i",&y);
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
				aux=aux->sig;
			}
		}	
		if (i==0){
			t->sig=*p;
			*p=t;
		}
	}
	}
	fclose(listaproductos);
	mostrarProductos(*p);
}
