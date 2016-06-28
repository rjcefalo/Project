
#include "UtilidadesPila.h"

struct multipila {
	int valor;
	multipila *sig;
	pila *abajo;
};

struct aux {
	char nombre[20];
	int cedula;
	int codigo;
	int cont;
	aux *sig;
};

struct CentroVentas{
	int codigo;
	char telf[20];
	char nombre[20], ciudad[20], estado[20], direccion[40];
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

void ordenarComprasHechas(Clientes *cliente){
	
		comprasHechas *p=cliente->abajo;
			int x;
		while (p->abajo){
			comprasHechas *t=p->abajo;
			while (t){
				if ((p->Codproducto)<(t->Codproducto)){
					
					//swap(p->Codcentro,t->Codcentro);
					x=p->Codcentro;
					p->Codcentro=t->Codcentro;
					t->Codcentro=x;

					//swap(p->Codproducto,t->Codproducto);
					x=p->Codproducto;
					p->Codproducto=t->Codproducto;
					t->Codproducto=x;

					//swap(p->fecha,t->fecha);
					x=p->fecha;
					p->fecha=t->fecha;
					t->fecha=x;

					//swap(p->precio,t->precio);
					x=p->precio;
					p->precio=t->precio;
					t->precio=x;
				}
				t=t->abajo;

			}
			p=p->abajo;
				t=p->abajo;
		}
	}
void ordenarconsultaporcliente(ordenar *o){
	
		ordenar *p=o;
			int x;
		while (p->abajo){
			ordenar *t=p->abajo;
			while (t){
				if ((p->valor)<(t->valor)){
					
					//swap(p->Codcentro,t->Codcentro);
					x=p->valor;
					p->valor=t->valor;
					t->valor=x;

					//swap(p->Codproducto,t->Codproducto);
					x=p->cedula;
					p->cedula=t->cedula;
					t->cedula=x;
				}
				t=t->abajo;

			}
			p=p->abajo;
				t=p->abajo;
		}
	}

void ordenaCompraClientes(Clientes*p){
	if (p){
		ordenarComprasHechas(p);
		ordenaCompraClientes(p->sig);
	}
}
void ordenarcodcentro(Clientes *cliente){
	comprasHechas *p=cliente->abajo;
			int x;
		while (p->abajo){
			comprasHechas *t=p->abajo;
			while (t){
				if ((p->Codcentro)<(t->Codcentro)){
					
					//swap(p->Codcentro,t->Codcentro);
					x=p->Codcentro;
					p->Codcentro=t->Codcentro;
					t->Codcentro=x;

					//swap(p->Codproducto,t->Codproducto);
					x=p->Codproducto;
					p->Codproducto=t->Codproducto;
					t->Codproducto=x;

					//swap(p->fecha,t->fecha);
					x=p->fecha;
					p->fecha=t->fecha;
					t->fecha=x;

					//swap(p->precio,t->precio);
					x=p->precio;
					p->precio=t->precio;
					t->precio=x;
				}
				t=t->abajo;

			}
			p=p->abajo;
			t=p->abajo;
		}
	}


void ordenaclientecentro(Clientes*p){
	if (p){
		ordenarcodcentro(p);
		ordenaclientecentro(p->sig);
	}
}
