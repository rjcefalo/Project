struct pila {
	int valor;
	pila *abajo;
};

struct productos{
	int codigo;
	int precio;
	int cantidad;
	productos *sig;
};

struct ventasHechas{
	int fecha;
	int cedula;
	int Codproducto;
	int precio;
	ventasHechas *abajo;
};

struct comprasHechas{
	int fecha;
	int Codproducto;
	int Codcentro;
	int precio;
	comprasHechas *abajo;
};

int vacio(pila *p){
	return (p==NULL);
}

void apilar (pila **p, int x){
	pila *t = new pila;
	t->valor = x;
	t->abajo = *p;
	*p=t;
}

int tope(pila *p){
	if (!vacio(p))
		return p->valor;
	return 0;
}

void desapilar(pila **p){
	if(!vacio(*p)){
		pila *aux=*p;
		*p=(*p)->abajo;
		delete aux;
	}
}

int buscar(pila *p, int x){
	if (!vacio(p)){
		if (p->valor == x)
			return 1;
		else 
		return buscar(p->abajo,x);
	}
	return 0;
}

void mostrar ( pila *p){	
	if ( p!= NULL ) {		
		printf ("[%i]->",p->valor);		
		mostrar(p->abajo);
	}
	
	else printf ("NULL");
};