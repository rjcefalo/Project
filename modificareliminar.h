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

void modificarProductosGlobal(CentroVentas **p,int x, int y, int z, int w){
	FILE *centro;
	if (y == 0){
		int n=1;
			printf("\nA continuacion puede editar los datos del producto de codigo %i\n",x);
			printf("\nIndique el nuevo codigo que desee asignar\n");
			scanf("%i",&y);
			printf("\nIndique el nuevo precio que desee asignar\n");
			scanf("%i",&z);
			printf("\nIndique la nueva cantidad que desee asignar\n");
			scanf("%i",&w);
	}
	if (*p){
	if((*p)->prox)
		printf("\n%i",(*p)->prox->codigo);
	productos *help=(*p)->prox;
	if(help)
		printf("\n%i",help->codigo);

	if (((*p))&&((*p)->prox)){

		if(help->codigo==x){
			while(y!=0){
			help->codigo=y;
			help->precio=z;
			help->cantidad=w;
			break;
			}
		
		}
		else {	
				while(help->sig!=NULL){
				help=help->sig;
				if(help->codigo==x){
					while(y!=0){
				help->codigo=y;
				help->precio=z;
				help->cantidad=w;
				break;
				
				}
			}
		}
		}
		
	}
	centro=fopen("modificacion.txt","a");

				fprintf(centro,"\n-----EL PRODUCTO DE CODIGO %i SE MODIFICO CON LOS SEGUIENTE DATOS, EN EL CENTRO %i:-----\n",x,(*p)->codigo);
				fprintf(centro,"Nuevo Codigo:%i\n",y);
				fprintf(centro,"Nuevo Precio:%i\n",z);
				fprintf(centro,"Nueva Cantidad:%i\n",w);
				fclose(centro);	
	modificarProductosGlobal(&((*p)->sig),x,y,z,w);
	}
	printf("\nMODIFICADO");
				
}
void modificarCentrosVenta(CentroVentas **p,int x,int y){
	if (*p){
		if ((*p)->codigo==x){
			printf("\nA CONTINUACION PUEDE MODIFICAR EL CENTRO\n");
			printf("\nIngrese el nuevo codigo del centro\n");
			scanf("%i",&y);
				((*p)->codigo)=y;
			printf("\nIngrese el nuevo nombre del centro\n");
			scanf("%s",(*p)->nombre);
			printf("\nIngrese la nueva ciudad del centro\n");
			scanf("%s",(*p)->ciudad);
			printf("\nIngrese el nuevo estado del centro\n");
			scanf("%s",(*p)->estado);
			printf("\nIngrese la nueva direccion del centro\n");
			scanf("%s",(*p)->direccion);
		}	 
		else 
			modificarCentrosVenta(&(*p)->sig,x,y);
	}
	else 
		if (!(*p))
			printf("\n NO SE ENCONTRO EL CENTRO DESEADO \n");
}
void modificarcliente(Clientes **p,int x,int y){
	if (*p){
		if ((*p)->cedula==x){
			printf("\nA CONTINUACION PUEDE MODIFICAR EL CLIENTE\n");
			printf("\nIngrese la nueva cedula del cliente\n");
			scanf("%i",&y);
				((*p)->cedula)=y;
			printf("\nIngrese el nuevo nombre del cliente\n");
			scanf("%s",(*p)->nombre);
			printf("\nIngrese la nueva direccion del cliente\n");
			scanf("%s",(*p)->direccion);
		}	 
		else 
			modificarcliente(&(*p)->sig,x,y);
	}
	else 
		if (!(*p))
			printf("\n NO SE ENCONTRO EL CLIENTE DESEADO \n");
}