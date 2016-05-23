struct lista {
	int valor;
	lista *abajo;
};

int vacio(lista *p){
	return (p==NULL);
}

void apilar (lista **p, int x){
	lista *t = new lista;
	t->valor = x;
	t->abajo = *p;
	*p=t;
}

int tope(lista *p){
	if (!vacio(p))
		return p->valor;
	return 0;
}

void desapilar(lista **p){
	if(!vacio(*p)){
		lista *aux=*p;
		*p=(*p)->abajo;
		delete aux;
	}
}

int buscar(lista *p, int x){
	if (!vacio(p)){
		if (p->valor == x)
			return 1;
		else 
		return buscar(p->abajo,x);
	}
	return 0;
}

void mostrar ( lista *p){	
	if ( p!= NULL ) {		
		printf ("[%i]->",p->valor);		
		mostrar(p->abajo);
	}
	
	else printf ("NULL");
};
