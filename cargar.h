#include "modificareliminar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int colapso(CentroVentas *p){
	while(p){
		if (p->prox)
			return 1;
		p=p->sig;
	}
	return 0;
}

void nuevacompra(Clientes *p,int x,int y,int z,int w){
	comprasHechas *t=new comprasHechas;
	t->fecha=x;
	t->Codcentro=y;
	t->Codproducto=z;
	t->precio=w;
	if (p->abajo==NULL){
		t->abajo=NULL;
		p->abajo=t;
	}
	else{
		t->abajo=p->abajo;
		p->abajo=t;
	}
}

void nuevaventa(CentroVentas *p,int x,int y,int z,int w){
	ventasHechas *t=new ventasHechas;
	t->fecha=x;
	t->cedula=y;
	t->Codproducto=z;
	t->precio=w;

	if (p->abajo==NULL){
		t->abajo=NULL;
		p->abajo=t;
	}
	else{
		t->abajo=p->abajo;
		p->abajo=t;
	}
}

void cargartodo(CentroVentas *centro, Clientes *client,int fecha){
	if (centro){
		if ((centro->prox)&&(centro->prox->cantidad==0)){
			productos *eliminar = centro->prox;
			centro->prox=eliminar->sig;
			delete eliminar;
		}
		if (centro->prox){
			if ((client->abajo==NULL)||(client->abajo->fecha!=fecha)||(client->abajo->Codproducto!=centro->prox->codigo)){
				nuevacompra(client,fecha,centro->codigo,centro->prox->codigo,centro->prox->precio);
				nuevaventa(centro,fecha,client->cedula,centro->prox->codigo,centro->prox->precio);
				centro->prox->cantidad=centro->prox->cantidad-1;
			}
		}
		cargartodo(centro->sig,client,fecha);
	}
}	

void cambiacliente(CentroVentas *centro, Clientes *cliente, int fecha){
	if (cliente){
		cargartodo(centro,cliente,fecha);
		cambiacliente(centro,cliente->sig,fecha);
	}
}
	