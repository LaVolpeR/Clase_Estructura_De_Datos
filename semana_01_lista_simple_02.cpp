#include <iostream>
#include <stdlib.h>

using namespace std;
struct nodo{
	float nro;
	struct nodo *sgte;	
};
typedef struct nodo *Tlista;
Tlista fin;

void menu1(){
	cout<<"\n\n\t\t[\tEjercicios Lista Simple\t]\n";
	cout<<"\t\t---------------------------------\n\n";
	cout<<" Ejercicio 2: Almacenar una lista de reales y odenarlos"<<endl<<endl;
	cout<<" 1. Insertar Elemento "<<endl;
	cout<<" 2. Mostrar Lista Ordenada"<<endl;
	cout<<" 3. Salir"<<endl;
	cout<<"\n Ingrese Opcion: ";
}

void insertarInicio(Tlista &lista, float valor){
	Tlista q = new(struct nodo);
	q->nro = valor;
	q->sgte = lista;
	lista = q;
}

void insertarFinal(Tlista &lista, float valor){
	Tlista t, q = new(struct nodo);
	q->nro = valor;
	q->sgte = NULL;
	fin = q;
	if(lista==NULL){
		lista = q; 
	}
	else{
		t=lista;
		while(t->sgte!=NULL){
			t=t->sgte;
		}
		t->sgte = q;
	}
}

void insertarElementoEn(Tlista lista, float n){
	Tlista t,r,q=new(struct nodo);
	q->nro=n;
	q->sgte=NULL;
	while(lista->sgte!=NULL){
		t=lista->sgte;
		if((n>lista->nro)&&(n<t->nro)){
			q->sgte=lista->sgte;
			lista->sgte=q;
			return;
		}
		lista=lista->sgte;
	}
}

void reportarLista(Tlista lista){
	int i = 0;
	while(lista != NULL){
		cout<<' '<<i+1<<") "<<lista->nro<<endl;
		lista=lista->sgte;
		i++;
	}
}

int main(void){
	Tlista lista = NULL;
	int op;
	float n;
	system("color 0a");
	do{
		menu1();
		cin>>op;
		switch(op){
			case 1:
				cout<<"\n Numero a Insertar: ";
				cin>>n;
				if((lista==NULL)){
					insertarFinal(lista,n);
				}
				else{
					if(n<lista->nro){
						insertarInicio(lista,n);
					}
					else if(n>lista->nro){
						insertarFinal(lista,n);
					}
					else{
						if((n>=lista->nro)&&(n<=fin->nro)){
							insertarElementoEn(lista,n);
						}
					}
				}
				break;
			case 2:
				cout<<endl<<"La lista Ordenada es: "<<endl;
				reportarLista(lista);
				break;
			case 3: 
				return 0;
			default: 
				cout<<"Ingrese una Opcion Valida...!"<<endl;
		}
		cout<<endl<<endl;
		system("pause");
		system("cls");	
	}while(op!=3);
	system("pause");
	return 0;
}
