#include "UtilidadesPila.h"

struct multipila {
	int valor;
	multipila *sig;
	pila *abajo;
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
void ordenarcomprastoltales(Clientes *cliente){
	Clientes *p=cliente;
			int x;
			char u[40],k[20];
		while (p){
			Clientes *t=p;
			while (t){
				if ((p->direccion)<(t->direccion)){
					
					//swap(p->Codcentro,t->Codcentro);
					u=p->direccion;
					p->direccion=t->direccion;
					t->direccion=u;

					//swap(p->Codproducto,t->Codproducto);
					x=p->cedula;
					p->cedula=t->cedula;
					t->cedula=x;

					//swap(p->fecha,t->fecha);
					k=p->nombre;
					p->nombre=t->nombre;
					t->nombre=k;

				}
				t=t->sig;

			}
			p=p->sig;
			t=p->sig;
		}
}


