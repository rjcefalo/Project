#include "agregarmostrar.h"

void eliminarCentro(CentroVentas **p){
	int x;
	printf("\nIngrese Codigo del Centro a Eliminar:\n");
	scanf("%i",&x);
		CentroVentas *aux=new CentroVentas;
		aux=*p;
		if (aux->codigo==x){
			*p=(*p)->sig;
			if (aux->prox!=NULL){
					while (aux->prox!=NULL){
					productos *aux2=new productos;
					aux2=aux->prox;
					aux->prox=aux2->sig;
					delete aux2;
					}
				}
				if(aux->abajo!=NULL){
					while (aux->abajo!=NULL){
					ventasHechas *aux2=new ventasHechas;
					aux2=aux->abajo;
					aux->abajo=aux2->abajo;
					delete aux2;
					}
				}
			delete aux;
		}
		else{
			while (aux->sig->codigo!=x)
				aux=aux->sig;

			if (aux->sig->codigo==x){
				CentroVentas *t=aux->sig;
				aux->sig=t->sig;
				if (aux->prox!=NULL){
					while (aux->prox!=NULL){
					productos *aux2=new productos;
					aux2=aux->prox;
					aux->prox=aux2->sig;
					delete aux2;
					}
				}
				if(aux->abajo!=NULL){
					while (aux->abajo!=NULL){
					ventasHechas *aux2=new ventasHechas;
					aux2=aux->abajo;
					aux->abajo=aux2->abajo;
					delete aux2;
					}
				}

				delete t;
			}
		}

}
void eliminarcliente(Clientes **p){
	int x;
	printf("\nIngrese Cedula del Cliente a Eliminar:\n");
	scanf("%i",&x);
		Clientes *aux=new Clientes;
		aux=*p;
		if (aux->cedula==x){
			*p=(*p)->sig;
			if (aux->abajo!=NULL){
					while (aux->abajo!=NULL){
					comprasHechas *aux2=new comprasHechas;
					aux2=aux->abajo;
					aux->abajo=aux2->abajo;
					delete aux2;
					}
				}
			delete aux;
		}
		else{
			while (aux->sig->cedula!=x)
				aux=aux->sig;

			if (aux->sig->cedula==x){
				Clientes *t=aux->sig;
				aux->sig=t->sig;
				if (t->abajo!=NULL){
					while (t->abajo!=NULL){
					comprasHechas *aux2=new comprasHechas;
					aux2=t->abajo;
					t->abajo=aux2->abajo;
					delete aux2;
					}
				}
				delete t;
			}
		}

}
void eliminarProductoGlobal(CentroVentas *p,int x){
	if (p){
	productos *aux=new productos;
	if(p->prox)
		printf("%i",p->prox->codigo);
	productos *help=p->prox;
	if(help)
		printf("%i",help->codigo);

	if ((p)&&(p->prox)){	
		
		if(help->codigo==x){		
		p->prox=help->sig;
		delete help;
		}
		else {		
			while(help->sig!=NULL){
				if(help->sig->codigo==x){					
					aux=help->sig;
					help->sig=help->sig->sig;
					aux->sig=NULL;
					delete aux;
					break;
				}
			help=help->sig;
			}
		}

	eliminarProductoGlobal(p->sig,x);
	}
}
	else printf("eliminados");
}
