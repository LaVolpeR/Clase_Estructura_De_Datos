#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregar_pila(Nodo *&pila, int n);
void sacarPila(Nodo *&pila, int &n);

void agregar_pila(Nodo *& pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

int main(){
	Nodo *pila = NULL;
	int opc= 0;
	int dato;
	do{
		system("cls");
		cout<<"\n\t1. Insertar un numero a la pila "<<endl;
		cout<<"\t2. Sacar todos los elementos de la pila"<<endl;
		cout<<"\t3. Salir\n"<<endl;
		cin>>opc;
		
		switch(opc){
			case 1:
				cout<<"\nIngrese un numero: ";
				cin>>dato;
				agregar_pila(pila,dato);
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
