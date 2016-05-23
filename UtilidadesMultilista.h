#include "UtilidadesPila.h"

struct multilista {
	int valor;
	multilista *sig;
	lista *abajo;
};

multilista *crearMulti(int x){
	multilista *t = new multilista;
	t->valor = x;
	t->sig = NULL;
	t->abajo = NULL;
	return t;
}

int vacioMulti(multilista *p){
	return (p==NULL);
}

void nuevoMulti(multilista **p, int x){
	multilista *t = crearMulti(x);
	t->sig = *p;
	t->abajo = NULL;
	*p=t;
}

void nuevoSublista(multilista *p, int y, int x){
	 lista *nuevoSub = new lista;
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
			nuevoSublista(p->sig,y,x);
		}	 
	 }	 
}

int primeroMulti(multilista *p){
	if (!vacioMulti(p))
		return p->valor;
	return 0;
}

void borrarMulti(multilista **p){
	if(!vacioMulti(*p)){
		multilista *aux=*p;
		*p=(*p)->sig;
		delete aux;
	}
}

int buscarMulti(multilista *p, int x){
	if (!vacioMulti(p)){
		if (p->valor == x)
			return 1;
		else 
		return buscarMulti(p->sig,x);
	}
	return 0;
}

/*void buscaEnPrin(multilista *p, multilista **aux, int x){
	if(!vacioMulti(p))
		if (p->valor==x)
			*aux=p;
		else
			buscaEnPrin(p->sig,aux,x);
}*/

void mostrarMulti ( multilista *p){
	multilista *aux = p;
	while ( aux!= NULL ) {
		printf ( "[%i]->",aux->valor);
		aux= aux->sig;
	};
};

void mostrarSub (multilista *p, int y){
	lista *t = p->abajo;
	if (p->valor==y){
		if ( p->abajo!= NULL ) {							
			mostrar(p->abajo);
		}
		else printf ("NULL");
	}
	else mostrarSub(p->sig,y);
}

void mostrarTodo(multilista *p){

}
void buscarXEnSubs(multilista *p, int x){
	lista *t = new lista;
	if(!vacioMulti(p)){
		if(!vacio(p->abajo)){
			t=p->abajo;
			if (buscar(t,x)==1)
				printf("El valor %i se encuentra en la sublista del indice %i\n",x, p->valor);			 
			buscarXEnSubs(p->sig, x);
		}
		else
			buscarXEnSubs(p->sig, x);

	}
}
