#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct nodo
{
	int dato;
	struct nodo *sgte;
};
nodo *pila=NULL;

void agregar(nodo*&pila)
{
	
	nodo *num=new nodo();
	cout<<"\nIngrese nro: ";cin>>num->dato;
	num->sgte=pila;
	pila=num;
}

void ordenar(nodo*&pila)
{
	nodo *ordenar,*aux=new nodo();
	int p;
	ordenar=pila;
	while(ordenar!=NULL)
	{
		aux=ordenar->sgte;
		while(aux!=NULL)
		{
			if(ordenar->dato > aux->dato)
			{
				p=ordenar->dato;
				ordenar->dato=aux->dato;
				aux->dato=p;
			}
			aux=aux->sgte;
		}
		ordenar=ordenar->sgte;
	}
}

void mostrar(nodo*&pila,int &aux)
{
	nodo *sacar=pila;
	aux=sacar->dato;
	pila=sacar->sgte;
	delete sacar;
}

int main()
{
	int cantidad, numero, aux;
	cout<<"Indique la cantidad de numero que desee registrar"<<endl;
	cin>>cantidad;
	
	for(int i = 0; i<cantidad; i++){
		agregar(pila);
		ordenar(pila);
	}
	system("cls");
	while(pila!=NULL)
	{
	mostrar(pila,aux);
	cout<<"Nro: "<<aux<<endl;						
	}getch();
}
