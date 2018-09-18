#include<iostream>
#include<conio.h>
#include<stdlib.h>
int menor = 0;
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};
typedef struct Nodo *Tlista;
Nodo fin;
void agregar_pila(Nodo *&pila, int n);
void sacarPila(Nodo *&pila, int &n);

void insertarInicio(Nodo *&pila, int valor){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = valor;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void insertarFinal(Nodo *&pila, int valor){
	Nodo t, q = new(struct Nodo);
	q->dato = valor;
	q->siguiente = NULL;
	fin = q;
	if(pila == NULL){
		pila = q;
	}
	else {
		t = pila;
		while(t->siguiente!=NULL){
			t = pila->siguiente;
		}
		t->siguiente = q;
	}
}

void insertarElementoEn(Nodo *&pila, int valor){
	Nodo t,r,q =new Nodo();
	q->dato = valor ;
	q->siguiente = NULL;
	while(pila->siguiente!=NULL){
		t=pila->siguiente;
		if((valor>=(pila->siguiente))&&(valor<=t->dato)){
			q->siguiente=pila->siguiente;
			pila->siguiente =q;
			return;
		}
		pila = pila->siguiente;
	}
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

void ordenar(Nodo *&pila, int n){
	
	
}

int main(){
	Nodo *pila = NULL;
	int opc= 0;
	int n;
	do{
		system("cls");
		cout<<"\n\t1. Insertar un numero a la pila "<<endl;
		cout<<"\t2. Sacar todos los elementos de la pila"<<endl;
		cout<<"\t3. Salir\n"<<endl;
		cin>>opc;
		
		switch(opc){
			case 1:
				cout<<"\nIngrese un numero: ";
				cin>>n;
				if(lista == NULL){
					insertarFinal(pila,n);			
				}
			else{
				if(n>pila->dato)
					insertarInicio(pila,n);
				else if(n>pila->dato)
				insertarFinal(pila,n);
				else{
					if((n>pila->dato)&&(n<fin->dato)){
						insertarElementoEn(pila,n);
					}
				}
			}
			break;
			case 2:
				cout<<"\n";
				while(pila!=NULL){
					sacarPila(pila,dato);
					if(pila!=NULL){
						cout<<dato<<" , ";
					}
					else{
						cout<<dato<<".\n";
					}
				}
				break;
			case 3:
				break;
			default: cout<<"Opcion erronea"<<endl;
		}
	
	}while(opc!=3);
	return 0;
}
