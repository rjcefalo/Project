#include "modificareliminar.h"


int colapso(CentroVentas *p){
	while(p){
		if (p->prox)
			return 1;
		p=p->sig;
	}
	return 0;
}

void nuevacompra(Clientes *p,int x){
	comprasHechas *t=new comprasHechas;
	t->fecha=x;
	t->Codcentro=NULL;
	t->Codproducto=NULL;
	t->precio=NULL;
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


void cargartodo(CentroVentas *centros, Clientes *client,int fecha){

	if (client!=NULL){
			int x=0;
		while (centros!=NULL){
			nuevacompra(client,fecha);
			if (centros->prox!=NULL){
				if (centros->prox->cantidad==0){
					productos *eliminar = centros->prox;
					centros->prox=eliminar->sig;
					delete eliminar;
				}

				if (client->abajo->Codproducto!=centros->prox->codigo){
					nuevaventa(centros,fecha,client->cedula,centros->prox->codigo,centros->prox->precio);
					client->abajo->Codcentro=centros->codigo;
					client->abajo->Codproducto=centros->prox->codigo;
					client->abajo->precio=centros->prox->precio;
					centros->prox->cantidad=centros->prox->cantidad-1;
					x=x+1;
				}
					centros=centros->sig;
				
			}
			else
				centros=centros->sig;
			
		}
		cargartodo(centros,client->sig,fecha);			
	}
}