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