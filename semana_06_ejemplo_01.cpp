#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct datos{
	int dato;
	datos *sig;
}*p,*aux,*u;
void insertar(int dat);
void borrar();
void listar();

int main(){
	int opc,y;
	do{
		system("cls");
		cout<<"\n1. Insertar";
		cout<<"\n2. Borrar";
		cout<<"\n3. Listar";
		cout<<"\n4. Salir";
		cout<<"\n Ingrese opcion: ";cin>>opc;
		switch(opc){
			case 1: 
				cout<<"Ingrese dato: ";
				cin>>y;
				insertar(y);
				cout<<"\nDato insertado!!";
				getch();
				break;
			case 2:
				borrar();
				getch();
				break;
			case 3:
				listar();
				getch();
				break;
			case 4:
				exit(1);
				getch();
			default: cout<<"\n Opcion no valida!!";break;
		}
	}while(opc);
}

void insertar(int dat){
	aux=new(datos);
	aux->dato=dat;
	if(u){
		u->sig=aux;
		aux->sig=NULL;
		u = aux;
	}
	else{
		p=u=aux;
	}
}

void borrar(){
	if(p){
		aux=p;
		cout<<"\nElimino a "<<p->dato;
		p=aux->sig;
		delete(aux);
	}
	else{
		cout<<"\n No hay datos";
		
	}
}

void listar(){
	int i;
	if(!u){
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux=p;
	while(aux){
		cout<<"\n"<<++i<<" - "<<aux->dato;
		aux=aux->sig;
	}
}
