#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fechaN{
	int dia;
	int mes;
	int ano;
};
struct elector{
	 char nombre[30];
	 char direccion[50];
	 long int ci;
	 fechaN *fechaNac;
	 elector *prox;
};
struct centroVotacion{
	char nombre[30];
	char direccion[50];
	char codigo[6];
	centroVotacion *prox;
	elector *aba;
};
struct registroEstatal{
	char nombre[30];
	char direccion[50];
	char telefono[15];
	int codigo;
	registroEstatal *prox;
	centroVotacion *aba;
};
int validarcodigo(char a[6], char b[6]){
 int i,n=6,x;
 for (i=1;i<=n;i++){
 	if (a[i] == b[i])
 	x=1;
 	
 	if (a[i] != b[i])
 	return 0;
}
	 if (x=1){
	 	return 1;
	 
 }
 
	
}
void elect(elector **p){
	elector *t=(*p);
	long int ci;
	int x,y,z;
	
	int op=-1;	
		while ( op != 0 ) {
		system( "cls" );
		printf( "\n\n Modificar Elector: %s", t->nombre);
		printf( "\n 1. Modificar nombre del elector");
		printf( "\n 2. Modificar direccion del elector");
		printf( "\n 3. Modificar cedula de identidad del elector ");
		printf( "\n 4. Modificar fecha de nacimineto");
		printf( " Salir : 0 \n\n");
        printf( "Indique opcion (1-3)");
		op=0;
		scanf("%i", &op);
		system( "cls");
        printf( "\n\n");
		switch (op){
			case 1: printf( "\n 1. Modificar nombre del centro de votacion");
					printf("\nIngrese el nuevo nombre del centro de votacion");
					scanf("%s",t->nombre);
					break;
			case 2: printf( "\n 2. Modificar direccion del centro de votacion");
					printf("\nIngrese la nueva direccion del centro de votacion");
					scanf("%s",t->direccion);
					break;
			case 3: printf( "\n 3. Modificar telefono del centro de votacion");
					printf("\nIngrese el nuevo telefono del centro de votacion");
					scanf("%li",&ci);
					t->ci=ci;
					break;
			case 4: printf( "\n 4. Modificar fecha de nacimiento");
					printf("\nIngrese la nueva fecha de nacimiento");
					scanf("%d %d %d",&x,&y,&z);
					t->fechaNac->dia=x;
					t->fechaNac->mes=y;
					t->fechaNac->ano=z;
					break;
		}
	if (op) {
		printf( "\n\n");
		system("pause");
		system("cls");}
	}
}
void mdEl(elector *p){
	elector *t=p;
	long int x;
	printf("Dame tu cedula \n:");
	scanf("%li",&x);
	while (t){
		if (x==t->ci){
			printf("HOLA");
			elect(&t);
			break;
		}
		t=t->prox;
	}
}
void modEle(centroVotacion *p){
			centroVotacion *t=p;
	char codigoCV[6];
	int n=6,i,x;
	printf("Codigo CV \n");
			scanf("%s",codigoCV);
	while(t){
	
		printf("%s",t->codigo);
		printf("%s",codigoCV);   
		if (validarcodigo(t->codigo,codigoCV) == 1){
			printf("Mostrar %s",t->nombre);
			mdEl(t->aba);
			break;
			
		} 	
		else
		printf("negative");
		
		t=t->prox;
	}



	
}
void modificarElector(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	while (t->codigo != codigo){
		t=t->prox;
	}
	if (t->codigo == codigo){
	modEle(t->aba);}
	else{
		printf("codigo invalido");
	}
	
}
void mEle(elector *p){
	elector *t=p;
	while (t){
		printf("------Elector-------\n");
		printf("1. Nombre del centro de votacion: %s\n",t->nombre);
		printf("2. Direccion del centro de votacion: %s \n",t->direccion);
		printf("3. Codigo del centro de votacion: %li \n",t->ci);
		printf("4. Fecha de nacimiento: %i / %i / %i",t->fechaNac->dia,t->fechaNac->mes,t->fechaNac->ano);
		t=t->prox;
	}
}
void mosEle(centroVotacion *p){
		centroVotacion *t=p;
	char codigoCV[6];
	int n=6,i,x;
	printf("Codigo CV \n");
			scanf("%s",codigoCV);
	while(t){
	
		printf("%s",t->codigo);
		printf("%s",codigoCV);   
		if (validarcodigo(t->codigo,codigoCV) == 1){
			printf("Mostrar %s",t->nombre);
			mEle(t->aba);
			break;
			
		} 	
		else
		printf("negative");
		
		t=t->prox;
	}



	
}
void mostrarElectores(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	while (t->codigo != codigo){
		t=t->prox;
	}
	if (t->codigo == codigo){
	mosEle(t->aba);}
	else{
		printf("codigo invalido");
	}
	
}
void agregarEle(elector **p, int n){
	int i;
	long int ci;
	int x,y,o;
	
	for (i=1;i<=n;i++){
		printf("------Elector-------\n");
		elector *t=new elector;
		printf("1. Nombre del elector:\n");
		scanf("%s",t->nombre);
		printf("2. Direccion del elector:\n");
		scanf("%s",t->direccion);
		printf("3. C.I del elector \n");
		scanf("%li",&ci);
		printf("bandera %d",ci);
		t->ci=ci;
		printf("4. Fecha de nacimiento");
		fechaN *z=new fechaN;
		scanf("%i %i %i",&x,&y,&o);
		z->dia=x;
		z->mes=y;
		z->ano=o;
		t->fechaNac=z;
		t->prox=NULL;
		
		if ((*p)==NULL){
			(*p)=t;
		}
		else{
			t->prox=(*p);
			(*p)=t;
		}
	}
	
	
}

void agregarE(centroVotacion *p){
	centroVotacion *t=p;
	char codigoCV[6];
	int n=6,i,x;
	printf("Codigo CV \n");
			scanf("%s",codigoCV);
	while(t){
	
		printf("%s",t->codigo);
		printf("%s",codigoCV);   
		if (validarcodigo(t->codigo,codigoCV) == 1){
			printf("CUANTOS ELECTORES DESEA AGREGAR EN %s",t->nombre);
			scanf("%d",&x);
			agregarEle(&t->aba,x);
			break;
			
		} 	
		else
		printf("negative");
		
		t=t->prox;
	}



}
void agregarElector(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	while(t->codigo != codigo){
		t=t->prox;
	}
	if (t->codigo == codigo){
		agregarE(t->aba);
	}
	else{
		printf("el codigo no existe");
	}
	}
	
void elCen(centroVotacion **p){
	centroVotacion *t=(*p);
	centroVotacion *ant=NULL;
	char codigoCV[6];
	int x;
	printf("codigo cv:");
	scanf("%s",codigoCV);
	
	while(t){
		printf("%s",t->codigo);
		x=validarcodigo(t->codigo,codigoCV);
		if(x == 1){
			printf("bandera %s\n",t->codigo);
			printf("bandera 2%s",codigoCV);
			if (ant==NULL){
				(*p)=(*p)->prox;
				delete t;
				break;	
			}
			else{
				printf("entro");
				ant->prox=t->prox;
				delete t;
				break;
			}	
		}else{
		
		ant=t;
		t=t->prox;
	}
	}
}	
void eliminarCentroVotacion(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	while(t->codigo != codigo){
		t=t->prox;
	}
	if (t->codigo == codigo){
		elCen(&(t->aba));
	}
	else{
		printf("el codigo no existe");
	}
}


void modCV(centroVotacion *p){
	centroVotacion *t=p;
	int op=-1,x;	
		while ( op != 0 ) {
		system( "cls" );
		printf( "\n\n Modificar centro de votacion %s", t->nombre);
		printf( "\n 1. Modificar nombre del centro de votacion");
		printf( "\n 2. Modificar direccion del centro de votacion");
		printf( "\n 3. Modificar codigo del centro de votacion");
		printf( " Salir : 0 \n\n");
        printf( "Indique opcion (1-3)");
		op=0;
		scanf("%i", &op);
		system( "cls");
        printf( "\n\n");
		switch (op){
			case 1: printf( "\n 1. Modificar nombre del centro de votacion");
					printf("\nIngrese el nuevo nombre del centro de votacion");
					scanf("%s",t->nombre);
					break;
			case 2: printf( "\n 2. Modificar direccion del centro de votacion");
					printf("\nIngrese la nueva direccion del centro de votacion");
					scanf("%s",t->direccion);
					break;
			case 3: printf( "\n 3. Modificar telefono del centro de votacion");
					printf("\nIngrese el nuevo telefono del centro de votacion");
					scanf("%s",t->codigo);
					break;
		}
	if (op) {
		printf( "\n\n");
		system("pause");
		system("cls");}
	}
}
void mCV(centroVotacion *p){
	centroVotacion *t=p;
	char codigoCV[6];
	int n=6,i,x;
	printf("Codigo CV \n");
			scanf("%s",codigoCV);
	while(t){
	
		printf("%s",t->codigo);
		printf("%s",codigoCV);   
		if (validarcodigo(t->codigo,codigoCV) == 1){
			printf("%s",t->nombre);
			modCV(t);
			break;
			
		} 	
		else
		printf("negative");
		
		t=t->prox;
	}

}
void modificarCentroVotacion(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	while(t->codigo != codigo){
		t=t->prox;
	}
	if (t->codigo == codigo){
		mCV(t->aba);
	}
	else{
		printf("el codigo no existe");
	}	
}
void mostrarCV(centroVotacion *p){
	centroVotacion *t=p;
	while (t){
			printf("------Centro de votaciones-------\n");
		printf("1. Nombre del centro de votacion: %s\n",t->nombre);
		printf("2. Direccion del centro de votacion: %s \n",t->direccion);
		printf("3. Codigo del centro de votacion: %s \n",t->codigo);
		t=t->prox;
		
	}
}
void mostrarCentroVotacion(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	while (t){
		if(t->codigo == codigo){
			mostrarCV(t->aba);
			break;
		}
		t=t->prox;
	}
}
void agregarCV(centroVotacion **p, int n){
	int i,x;
	char codigoCV[5];
	for (i=1;i<=n;i++){
		printf("------Registro Estatal-------\n");
		centroVotacion *t=new centroVotacion;
		printf("1. Nombre del centro de votacion:\n");
		scanf("%s",t->nombre);
		printf("2. Direccion del centro de votacion\n");
		scanf("%s",t->direccion);
		printf("3. Codigo del centro de votacion\n");
		scanf("%s",t->codigo);
				
		t->prox=NULL;
		t->aba=NULL;
		if ((*p)==NULL){
			(*p)=t;
		}else{
			t->prox=(*p);
			(*p)=t;
		}
	}
}

void agregarCentroVotacion(registroEstatal *p, int codigo){
	registroEstatal *t=p;
	int x;
	while(t){
		if (t->codigo==codigo){
			printf("Cuantos centro de votaciones desea agregar en %s ?",t->nombre);
			scanf("%d",&x);
			agregarCV(&t->aba,x);
			break;
		}
		t=t->prox;
	}
	
}






void modificar(registroEstatal **p){
	registroEstatal *t=(*p);
	int op=-1,x;
		while ( op != 0 ) {
		system( "cls" );
		printf( "\n\n Modificar registro estatal");
		printf( "\n 1. Modificar nombre del registro estatal");
		printf( "\n 2. Modificar direccion del registro estatal");
		printf( "\n 3. Modificar telefono del registro estatal");
		printf( "\n 4. Modificar codigo del registro estatal");
		printf( " Salir : 0 \n\n");
        printf( "Indique opcion (1-4)");
		op=0;
		scanf("%i", &op);
		system( "cls");
        printf( "\n\n");
		switch (op){
			case 1: printf( "\n 1. Modificar nombre del registro estatal");
					printf("\nIngrese el nuevo nombre del registro estatal");
					scanf("%s",t->nombre);
					break;
			case 2: printf( "\n 2. Modificar direccion del registro estatal");
					printf("\nIngrese la nueva direccion del registro estatal");
					scanf("%s",t->direccion);
					break;
			case 3: printf( "\n 3. Modificar telefono del registro estatal");
					printf("\nIngrese el nuevo telefono del registro estatal");
					scanf("%s",t->telefono);
					break;
			case 4:printf( "\n 4. Modificar codigo del registro estatal");
					printf("\n Ingrese el nuevo codigo del registro estatal");
					scanf("%d",&x);
					t->codigo=x;
					break;
		}
	if (op) {
		printf( "\n\n");
		system("pause");
		system("cls");}
	}
}
void modificarRegistroEstatal(registroEstatal **p, int codigo){
	registroEstatal *t=(*p);
	int op=-1,x;
	while (t){
		if (t->codigo==codigo){
			modificar(&t);
			break;
		}
		t=t->prox;
		if(t == NULL){
			printf("nose encontro");
			break;
		}
		}
		
		
	
		
	 }	
void eliminarRegistroEstatal(registroEstatal **p, int codigo){
	registroEstatal *t=(*p);
	registroEstatal *ant=NULL;
	
		while (t){
		if (t->codigo==codigo){
			if (ant==NULL){
				(*p)=(*p)->prox;
				delete t;	
			}
			else if (t->prox==NULL){
			
				delete t;
				ant->prox=NULL;
			}
			else{
			ant->prox=t->prox;
			delete t;
			}
		}
		ant=t;
		t=t->prox;
		if(t == NULL){
			printf("nose encontro");
			break;
		}
		}
}
void mostrarRegistroEstatal(registroEstatal *p){
registroEstatal *t=p;
while (t){
		printf("------Registro Estatal-------\n");	
		printf("1. Nombre del registro Estatal: %s \n",t->nombre);
		printf("2. Direccion del registro estatal: %s\n", t->direccion);
		printf("3. Telefono del registro estatal: %s\n", t->telefono);
		printf("4. Codigo del registro estatal: %d\n", t->codigo);
		t=t->prox;
}

}
void agregarRegistroEstatal(registroEstatal **p,int n){
	FILE *archivoRegistroEstatal;
	archivoRegistroEstatal=fopen("Estatal.txt","a");
	int i,x;
	for (i=1;i<=n;i++){
		printf("------Registro Estatal-------\n");
		registroEstatal *t=new registroEstatal;
		printf("1. Nombre del registro Estatal:\n");
		scanf("%s",t->nombre);
		printf("2. Direccion del registro estatal:\n");
		scanf("%s",t->direccion);
		printf("3. Telefono del registro estatal\n");
		scanf("%s",t->telefono);
		printf("4. Codigo del registro estatal\n");
		scanf("%d",&x);
		t->codigo=x;
		/*fwrite(*t,sizeof(registroEstatal),sizeof(registroEstatal)*/
		if (t==NULL){
			t->prox=NULL;
			t->aba=NULL;
			(*p)=t;
		}
		else{
			t->aba=NULL;
			t->prox=(*p);
			(*p)=t;
			
		}
	}
	fclose(archivoRegistroEstatal);
}
	
int main(){
	int  op= -1, n = 0;
    registroEstatal *p = NULL;
	while ( op != 0 ) {
		system( "cls" );
		printf( "\n\n Proyecto 1 \n");
		printf( "\n 1. Agregar registro estatal ");
		printf( "\n 2. Mostrar registro estatal ");
		printf( "\n 3. Modificar registro estatal");
		printf( "\n 4. Eliminar registro estatal");
		printf( "\n 5. Agregar centro de Votacion");
		printf( "\n 6. Mostrar centro de votacion");
		printf( "\n 7. Modificar centro de votacion");
		printf( "\n 8. Eliminar centro de votacion");
		printf( " Salir : 0 \n\n");
        printf( "Indique opcion (1-4)");
		op=0;
		scanf("%i", &op);
		system( "cls");
        printf( "\n\n");
		switch (op){
			case 1: printf( "\n\n1. AGREGAR REGISTRO ESTATAL \n\n");
                    printf("CUANTOS REGISTRO ESTATALES DESEA HACER?");
                    scanf( "%i", &n);
                    agregarRegistroEstatal(&p,n);
					break;
			case 2:  printf( "\n\n2. MOSTRAR REGISTRO ESTATAL \n\n");
					mostrarRegistroEstatal(p);
					break;
			case 3: printf( "\n\n1. MODIFICAR REGISTRO ESTATAL\n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL QUE DESEA MODIFICAR");
					scanf("%d",&n);
					modificarRegistroEstatal(&p,n);
			
					break;
			case 4: printf( "\n\n ELIMINAR REGISTRO ESTATAL \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL QUE DESEA MODIFICAR");
					scanf("%d",&n);
					eliminarRegistroEstatal(&p,n);
					break;
			case 5: printf( "\n\n AGREGAR CENTRO DE VOTACION \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL EN QUE DESEA AGREGAR UN CENTRO DE VOTACION:");
					scanf("%d",&n);
					agregarCentroVotacion(p,n);
					break;
			case 6: printf( "\n\n MOSTRAR CENTRO DE VOTACION \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL");
					scanf("%d",&n);
					mostrarCentroVotacion(p,n);
					break;
			case 7: printf( "\n\n MODIFICAR CENTRO DE VOTACION \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL");
					scanf("%d",&n);
					modificarCentroVotacion(p,n);
					break;
			case 8: printf( "\n\n ELIMINARR CENTRO DE VOTACION \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL");
					scanf("%d",&n);
					eliminarCentroVotacion(p,n);
					break;
			case 9: printf( "\n\n AGREGAR ELECTOR \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL");
					scanf("%d",&n);
					agregarElector(p,n);
					break;
			case 10: printf( "\n\n MOSTRAR ELECTORES \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL");
					scanf("%d",&n);
					mostrarElectores(p,n);
					break;
			case 11: printf( "\n\n MODIFICAR ELECTORES \n\n");
					printf("INGRESE EL CODIGO DEL REGISTRO ESTATAL");
					scanf("%d",&n);
					modificarElector(p,n);
					break;
		}
	if (op) {
		printf( "\n\n");
		system("pause");
		system("cls");}
	}
	return 0;
}