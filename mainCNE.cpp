#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fechaNacimiento{
	int dia;
	int mes;
	int ano;
};
struct elector{
	char nombre[30];
	char direccion[50];
	long int ci;
	fechaNacimiento fechaN;
	elector *prox;

};
struct centroVotacion{
	char nombre[30];
	char direccion[50];
	long int codigo;
	int codigoEstado;
	centroVotacion *prox;
	elector *aba;
};
struct estado{
	char nombre[30];
	char direccion[50];
	char telefono[12];
	int codigo;
	estado *prox;
	centroVotacion *aba;
};



int contarCentroVotacion(estado **p,int codigo){
	FILE *archivo=fopen("centrovotacion.bin","r");
	estado *t=(*p);
	int x,y;
	int n=0;
    if (archivo == NULL)printf("NO ABRIO");
			
		while(feof(archivo)==0){
				centroVotacion *z=new centroVotacion;
				fread(z,sizeof(centroVotacion),1,archivo);  
				z->prox=NULL;
				z->aba=NULL;

				while(t){
					if ((t->codigo == z->codigoEstado)&& (z->codigoEstado==codigo)){
						n++;
					}	
					t=t->prox;
				}
				t=(*p);
		}
		
		fclose(archivo);
		return n;
}
void cargarCentroVotaciones(estado **p,int codigo){
	FILE *archivo=fopen("centrovotacion.bin","r");
	estado *t=(*p);
	int x,y;
    if (archivo == NULL)printf("NO ABRIO");
			
		while(feof(archivo)==0){
				centroVotacion *z=new centroVotacion;
				fread(z,sizeof(centroVotacion),1,archivo);  
				z->prox=NULL;
				z->aba=NULL;

				while(t){
					if ((t->codigo == z->codigoEstado)&& (z->codigoEstado==codigo)){
						if (!t->aba){
						t->aba=z;
						}else{
							z->prox=t->aba;
							t->aba=z;
						}
						break;
					}	
					t=t->prox;
				}
				t=(*p);
		}
		fclose(archivo);
}

void mostrarCentroVotacion(estado *p, int codigo){
	estado *t=p;
	while(t){
		if (t->codigo==codigo){
			printf("---- CENTROS DE VOTACIONES EN %s---- \n\n",t->nombre);
			while(t->aba){
				printf("\n1. NOMBRE DEL CENTRO VOTACION: %s",t->aba->nombre);
				printf("\n2. DIRECCION DEL CENTRO VOTACION: %s",t->aba->direccion);
				printf("\n3. CODIGO DEL CENTRO DE VOTACION: %s",t->aba->codigo);
				printf("\n");
				t->aba=t->aba->prox;
			}
			break;
		}
		t=t->prox;
	}
	if (t==NULL){
	printf("EL CODIGO NO EXISTE");
	}

}
void agregarCentroVotacion(estado *p, int codigo){
	FILE *archivo;
	archivo=fopen("centrovotacion.bin","a");
	estado *t=p;
	int i,n;
	long int codigoCV;
	while(t){
		if (t->codigo==codigo){
			printf("INGRESE CUANTOS CENTROS DE VOTACIONES DESEA AGREGAR EN %s:",t->nombre);
			scanf("%d",&n);
			codigoCV=(t->codigo)*1000+contarCentroVotacion(&p,codigo);
			for (i=1;i<=n;i++){
			printf("------CENTRO DE VOTACION-------\n\n");
			centroVotacion *z=new centroVotacion;
			printf("\n1. NOMBRE DEL CENTRO DE VOTACION:");
			fflush(stdin);
			gets(z->nombre);
			printf("\n2. DIRECCION DEL CENTRO VOTACION:");
			fflush(stdin);
			gets(z->direccion);
			codigoCV++;
			z->codigo=codigoCV;
			printf("%li",z->codigo);
			z->codigoEstado=codigo;
			z->prox=NULL;
			z->aba=NULL;
			fwrite(z,sizeof(centroVotacion),1,archivo);
			if ((t->aba)==NULL){
				t->aba=z;
				}else{
					z->prox=t->aba;
					t->aba=z;
					}
			}
			break;
		}
		t=t->prox;
	}
	if (t==NULL){
	printf("EL CODIGO NO EXISTE");
	}
}
void modificar(estado **p){
	estado *t=(*p);
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
					fflush(stdin);
					gets(t->nombre);
					break;
			case 2: printf( "\n 2. Modificar direccion del registro estatal");
					printf("\nIngrese la nueva direccion del registro estatal");
					fflush(stdin);
					gets(t->direccion);
					break;
			case 3: printf( "\n 3. Modificar telefono del registro estatal");
					printf("\nIngrese el nuevo telefono del registro estatal");
					fflush(stdin);
					gets(t->telefono);
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
void guardarArchivoEstado(estado **p){
	FILE *archivo=fopen("Estados.bin","wt");
	estado *t=(*p);
	while (t){
		fwrite(t,sizeof(estado),1,archivo);
		t=t->prox;
	}
	fclose(archivo);
}
void modificarEstado(estado **p, int codigo){
	estado *t=(*p);
	while(t){
		if (t->codigo == codigo){
			 modificar(&t);
			 guardarArchivoEstado(p);
			break;
		}
		t=t->prox;
	}

}
void eliminarEstado(estado **p, int codigo){
	estado *t=(*p);
	estado *ant=NULL;
	
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
			break;
		}
		ant=t;
		t=t->prox;
		if(t == NULL){
			printf("nose encontro");
			break;
		}
		}
	guardarArchivoEstado(p);
}
void arreglarLista(estado **p){
	estado *t=(*p);
	(*p)=(*p)->prox;
	delete t; 
}

int cargarEstado(estado **p){
	FILE *archivo=fopen("Estados.bin","r");
	int n=0;
	if (archivo == NULL){
	printf("EL ARCHIVO NO HA SIDO ENCONTRADO");
	}
	while(feof(archivo)==0){
		estado *t=new estado;
		fread(t,sizeof(estado),1,archivo);
		t->prox=NULL;
		t->aba=NULL;
		if((*p)==NULL)(*p)=t;
		else{
		t->prox=(*p);
		(*p)=t;
		}
		
		n++;
	}
	n=n-1;
	arreglarLista(p);
	return n;
}
void mostrarEstadoArchivo(){
	FILE *archivo=fopen("Estados.bin","r");
	char str[50];
	int cont=1;
	fflush(stdout);
	fgets(str,50,archivo);
	if (archivo == NULL)printf("EL ARCHIVO NO SE CREO CORRECTAMENTE");
	while(feof(archivo)==0){
		if (cont == 1){printf("\n========================================================");printf("\n%d.NOMBRE DEL REGISTRO ESTATAL: %s",cont,str);}
			else if (cont == 2)printf("\n%d.DIRECCION DEL REGISTRO ESTATAL: %s",cont,str);
			else if (cont == 3)printf("\n%d.TELEFONO DEL REGISTRO ESTATAL: %s",cont,str);
			else{
				printf("\n%d.CODIGO DEL REGISTRO ESTATAL: %s",cont,str);
				printf("========================================================\n");
				cont=0;
			}
			cont++;
	fflush(stdout);
	fgets(str,50,archivo);
	}
	system("pause");

}
void mostrarEstado(estado *p){
	estado *t=p;
	printf("---- ESTADOS ---- \n\n");
	while(t){
		printf("\n1. NOMBRE DEL REGISTRO ESTATAL: %s",t->nombre);
		printf("\n2. DIRECCION DEL REGISTRO ESTATAL: %s",t->direccion);
		printf("\n3. TELEFONO DEL REGISTRO ESTATAL: %s",t->telefono);
		printf("\n4. CODIGO DEL REGISTRO ESTATAL: %d",t->codigo);
		printf("\n\n");
		t=t->prox;
	}
}
void agregarEstado(estado **p, int n, int cont){
	FILE *archivo;
	archivo=fopen("Estados.bin","a");
	cont++;
	int i;
	for (i=1;i<=n;i++){
		printf("---- REGISTRO ESTATAL ----\n\n");
		estado *t=new estado;
		printf("\n1. NOMBRE DEL REGISTRO ESTATAL");
		fflush(stdin);
		gets(t->nombre);
		printf("\n2. DIRECCION DEL REGISTRO ESTATAL");
		fflush(stdin);
		gets(t->direccion);
		printf("\n3. TELEFONO DEL REGISTRO ESTATAL");
		fflush(stdin);
		gets(t->telefono);
		t->codigo=cont;
		t->prox=NULL;
		t->aba=NULL;
		fwrite(t,sizeof(estado),1,archivo);
		cont++;
		if ( (*p) == NULL){
			(*p)=t;
		}else{
			t->prox=(*p);
			(*p)=t;
		}

	}

	fclose(archivo);
}
void mostrarElectores(estado *p, int codigo){
	estado *t=p;
	long int codigoCV;
	while(t){
		if (t->codigo==codigo){
			mostrarCentroVotacion(p,codigo);
			cargarCentroVotaciones(&p,codigo);
			printf("INTRODUZCA EL CODIGO DEL CENTRO DE VOTACION");
			scanf("%li",&codigoCV);
			while(t->aba){
				if (t->aba->codigo == codigoCV){
					while(t->aba->aba){
						printf("\n---- ELECTOR ----\n\n");
						printf("\n1. NOMBRE DEL ELECTOR: %s",t->aba->aba->nombre);
						printf("\n2. DIRECCION DEL ELECTOR: %s",t->aba->aba->direccion);
						printf("\n3. CEDULA DE IDENTIDAD DEL ELECTOR: %li",t->aba->aba->ci);
						printf("\n4. FECHA DE NACIMIENTO DEL ELECTOR: %d/%d/%d",t->aba->aba->fechaN.dia,t->aba->aba->fechaN.mes,t->aba->aba->fechaN.ano);
						t->aba->aba=t->aba->aba->prox;
					}
					break;
				}
				t->aba=t->aba->prox;
			}
			break;
		}	
		t=t->prox;
	}



}
void agregarElector(estado *p, int codigo){
	FILE *archivo=fopen("Electores.bin","a");;
	estado *t=p;
	long int codigoCV;
	int i,n,dia,mes,ano;
	long int ci;
	system("cls");
	while(t){
		if (t->codigo == codigo){
			mostrarCentroVotacion(p,codigo);
			cargarCentroVotaciones(&p,codigo);
			printf("\nIngrese el codigo de votacion:");
			scanf("%li",&codigoCV);
			while (t->aba){
				if (t->aba->codigo == codigoCV){
					system("cls");
					printf("INGRESE CUANTOS ELECTORES DESEA AGREGAR EN %s",t->aba->nombre);
					scanf("%d",&n);
						for (i=0;i<=n;i++){
						elector *z=new elector;
						z->prox=NULL;
						printf("\n---- ELECTOR ----\n\n");
						printf("\n1. NOMBRE DEL ELECTOR:");
						fflush(stdin);
						gets(z->nombre);
						printf("\n2. DIRECCION DEL ELECTOR: ");
						fflush(stdin);
						gets(z->direccion);
						printf("\n3. CEDULA DE IDENTIDAD");
						scanf("%li",&ci);
						z->ci=ci;
						printf("\n4. FECHA DE NACIMIENTO(POR EJEMPLO, 22/01/1997):");
						scanf("%d %d %d",&dia,&mes,&ano);
						z->fechaN.dia=dia;
						z->fechaN.mes=mes;
						z->fechaN.ano=ano;
							if (t->aba->aba == NULL){
								t->aba->aba=z;
							}else{
								z->prox=t->aba->aba;
								t->aba->aba=z;
							}
								
						
						}
				}
			t->aba=t->aba->prox;
			}
			if (t->aba == NULL) printf("CODIGO ERRONEO");
		}
		t=t->prox;
	}
fclose(archivo);
}
int main(){
	int  op= -1, n = 0,contEst=0;
    estado *p = NULL;
	while ( op != 0 ) {
		system( "cls" );
		printf( "\n\n BASE DE DATOS DEL CNE \n");
		printf( "\n 1.  AGREGAR ESTADO ");
		printf( "\n 2.  MOSTRAR ESTADOS ");
		printf( "\n 3.  MODIFICAR ESTADOS");
		printf( "\n 4.  ELIMINAR ESTADOS");
		printf( "\n 5.  AGREGAR CENTRO DE VOTACION");
		printf( "\n 6.  MOSTRAR CENTRO DE VOTACION");
		printf( "\n 7.  CARGAR ESTADOS DESDE EL ARCHIVO");
		
		printf( " SALIR : 0 \n\n");
        printf( "INDIQUE OPCION (1-18)");
		op=0;
		scanf("%i", &op);
		system( "cls");
        printf( "\n\n");
		switch (op){
			case 1:	printf("1. AGREGAR ESTADO\n\n");
					printf("INSERTE EL NUMERO DE ESTADOS A INSERTAR:");
					scanf("%d",&n);
					agregarEstado(&p,n,contEst);
					break;
			case 2:	printf("2. MOSTRAR ESTADO\n\n");
					mostrarEstado(p);
					break;
			case 3: printf("3. MODIFICAR ESTADO\n\n");
					printf("INGRESE EL CODIGO DE ESTADO A MODIFICAR:");
					scanf("%d",&n);
					modificarEstado(&p,n);
					break;
			case 4:printf("4. ELIMINAR ESTADO\n\n");
					printf("INGRESE EL CODIGO DE ESTADO A ELIMINAR:");
					scanf("%d",&n);
					eliminarEstado(&p,n);
					break;
			case 5:printf("5. AGREGAR CENTRO DE VOTACION\n\n");
					printf("INGRESE EL CODIGO DE ESTADO:");
					scanf("%d",&n);
					agregarCentroVotacion(p,n);
					if (p!=NULL)guardarArchivoEstado(&p);
					break;
			case 6:printf("5. MOSTRAR CENTRO DE VOTACION\n\n");
					printf("INGRESE EL CODIGO DE ESTADO:");
					scanf("%d",&n);
					cargarCentroVotaciones(&p,n);
					mostrarCentroVotacion(p,n);
					break;

			case 7:contEst=cargarEstado(&p);
					printf("\nSe cargaron %d estadoss",contEst);
					break;
			case 8:	printf("INGRESE EL CODIGO DE REGISTRO ESTATAL");
					scanf("%d",&n);
					cargarCentroVotaciones(&p,n);
					break;
			case 9: printf("INGRESE EL CODIGO DE REGISTRO ESTATAL");
					scanf("%d",&n);
					cargarCentroVotaciones(&p,n);
					agregarElector(p,n);
					break;
		}
	if (op) {
		printf( "\n\n");
		system("pause");
		system("cls");}
	}
	return 0;
}