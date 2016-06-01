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


void nuevoCentro(CentroVentas **p, int x,int y,char nom[20],char ciu[20],char est[20],char dir[40]){
	CentroVentas *aux=CrearCentroVentas(x,y,nom,ciu,est,dir);
	CentroVentas *t=*p;
	int i=0;
	if (!t)
		*p=aux;
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
			aux->sig=*p;
			*p=aux;
		}
	}
}

void nuevoCliente(Clientes **p,char nom[20], int x,char dir[40]){
	Clientes *aux=CrearCliente(nom,x,dir);
	Clientes *t=*p;
	int i=0;
	if (!t)
		*p=aux;
	else{
		while (t){
			if (t->cedula!=aux->cedula)
				t=t->sig;
			else{
				i++;
				t=t->sig;
			}
		}	
		if (i==0){
			aux->sig=*p;
			*p=aux;
		}
	}
}

void nuevoProductos(productos **p,int cod, int prec,int cant){
	productos *aux=CrearProductos(cod,prec,cant);
	productos *t=*p;
	int i=0;
	if (!t)
		*p=aux;
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
			aux->sig=*p;
			*p=aux;
		}
	}
}

void mostrarCentros(CentroVentas *p){
	if (p){
		printf("Codigo		: %i\n", p->codigo);
		/*printf("Telefono	: %i\n", p->telf);
		printf("Nombre		: %s\n", p->nombre);
		printf("Ciudad		: %s\n", p->ciudad);
		printf("Estado		: %s\n", p->estado);
		printf("Direccion	: %s\n", p->direccion);*/
		mostrarCentros(p->sig);
	}
}

void mostrarClientes(Clientes *p){
	if (p){
		printf("Cedula		: %i\n", p->cedula);
		/*printf("Telefono	: %i\n", p->telf);
		printf("Nombre		: %s\n", p->nombre);
		printf("Ciudad		: %s\n", p->ciudad);
		printf("Estado		: %s\n", p->estado);
		printf("Direccion	: %s\n", p->direccion);*/
		mostrarClientes(p->sig);
	}
}

void mostrarProductos(productos *p){
	if (p){
		printf("Codigo		: %i\n", p->codigo);
		printf("Precio      : %i BSF \n", p->precio);
		printf("Cantidad	: %i\n", p->cantidad);
		mostrarProductos(p->sig);
	}
}