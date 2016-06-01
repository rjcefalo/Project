#include "UtilidadesPila.h"

struct multipila {
	int valor;
	multipila *sig;
	pila *abajo;
};
struct CentroVentas{
	int codigo;
	int telf;
	int nombre[20];
	int ciudad[20];
	int estado[20];
	int direccion[40];
	CentroVentas *sig;
	ventasHechas *abajo;
	productos *prox;
};

struct Clientes{
	char nombre[20];
	int cedula;
	char direccion[40];
	Clientes *sig;
	comprasHechas *abajo;
};

multipila *crearMulti(int x){
	multipila *t = new multipila;
	t->valor = x;
	t->sig = NULL;
	t->abajo = NULL;
	return t;
}

int vacioMulti(multipila *p){
	return (p==NULL);
}

void nuevoMulti(multipila **p, int x){
	multipila *t = crearMulti(x);
	t->sig = *p;
	t->abajo = NULL;
	*p=t;
}

void nuevoSubpila(multipila *p, int y, int x){
	 pila *nuevoSub = new pila;
	 if(!vacioMulti(p)){
		if (p->valor==y){
			if (vacio(p->abajo)){
				nuevoSub->valor=x;
				nuevoSub->abajo = NULL;
				p->abajo = nuevoSub;
			}
			else{
				nuevoSub->valor=x;
				nuevoSub->abajo = p->abajo;
				p->abajo = nuevoSub;
			}
		}
		else{
			nuevoSubpila(p->sig,y,x);
		}	 
	 }	 
}

int primeroMulti(multipila *p){
	if (!vacioMulti(p))
		return p->valor;
	return 0;
}

void borrarMulti(multipila **p){
	if(!vacioMulti(*p)){
		multipila *aux=*p;
		*p=(*p)->sig;
		delete aux;
	}
}

int buscarMulti(multipila *p, int x){
	if (!vacioMulti(p)){
		if (p->valor == x)
			return 1;
		else 
		return buscarMulti(p->sig,x);
	}
	return 0;
}

/*void buscaEnPrin(multipila *p, multipila **aux, int x){
	if(!vacioMulti(p))
		if (p->valor==x)
			*aux=p;
		else
			buscaEnPrin(p->sig,aux,x);
}*/

void mostrarMulti ( multipila *p){
	multipila *aux = p;
	while ( aux!= NULL ) {
		printf ( "[%i]->",aux->valor);
		aux= aux->sig;
	};
};

void mostrarSub (multipila *p, int y){
	pila *t = p->abajo;
	if (p->valor==y){
		if ( p->abajo!= NULL ) {							
			mostrar(p->abajo);
		}
		else printf ("NULL");
	}
	else mostrarSub(p->sig,y);
}

void mostrarTodo(multipila *p){

}
/*void buscarXEnSubs(multipila *p, int x){
	pila *t = new pila;
	if(!vacioMulti(p)){
		if(!vacio(p->abajo)){
			t=p->abajo;
			if (buscar(t,x)==1)
				printf("El valor %i se encuentra en la subpila del indice %i\n",x, p->valor);			 
			buscarXEnSubs(p->sig, x);
		}
		else
			buscarXEnSubs(p->sig, x);

	}
}*/
/*void moverDeAaB(multipila *p, int x, int y, int z){
	pila *t = new pila;
	pila *aux = new pila;
	if (!vacioMulti(p)){
			t=p->abajo;
			if (p->abajo->valor==z){
				p->abajo=t->sig;
				nuevoSubpila(p,y,t->valor);

			}
			else if ((p->abajo->valor!=z) && (buscar(t->sig,x)==1) && (t->sig->sig!=NULL)){
				aux=t->sig;
				t->sig = t->sig->sig;
				nuevoSubpila(p,y,aux->valor);					
			}
			else{
				bu
			}
											 			
		}
	}
*/