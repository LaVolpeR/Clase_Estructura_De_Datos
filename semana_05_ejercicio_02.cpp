#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int menor= 99999999;
string nombre,ppp;
struct nodo
{
	string nombre;
	int duracion;
	struct nodo *sgte;
	struct nodo *ant;
};
nodo *pila=NULL;
void agregar(nodo*&pila)
{
	
	nodo *num=new nodo();
	cout<<"\nIngrese nombre: ";cin>>num->nombre;
	cout<<"Ingrese duracion: ";cin>>num->duracion;
	num->sgte=pila;
	pila=num;
}
void ordenar(nodo*&pila)
{
	nodo *ordenar,*aux=new nodo();
	int p;
	string o;
	ordenar=pila;
	while(ordenar!=NULL)
	{
		aux=ordenar->sgte;
		while(aux!=NULL)
		{
			if(ordenar->duracion > aux->duracion)
			{
				p=ordenar->duracion;
				ordenar->duracion=aux->duracion;
				aux->duracion=p;
				
				o = ordenar->nombre;
				ordenar->nombre = aux->nombre;
				aux->nombre = o;
			}
			aux=aux->sgte;
		}
		ordenar=ordenar->sgte;
	}
}
void mostrar(nodo*&pila,int &aux, string &name)
{
	nodo *mostrar=pila;
	aux= mostrar->duracion;
	name = mostrar->nombre;
	pila=mostrar->sgte;
	delete mostrar;
}
int main()
{
	int cantidad, numero, aux;
	string name;
	cout<<"Indique la cantidad de numero que desee registrar"<<endl;
	cin>>cantidad;
	for(int i = 0; i<cantidad; i++){
		agregar(pila);
		ordenar(pila);
	}
	system("cls");
	while(pila!=NULL)
	{
	mostrar(pila,aux, name);
	cout<<"Nombre: "<<name<<endl;
	cout<<"Duracion: "<<aux<<endl;
	if(aux <= menor){
		menor = aux;
		nombre = name;
	}
	}getch();
	cout<<"\n\n==========================================\n"<<endl;
	cout<<"EL Producto que usted debe vender es :"<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Duracion: "<<menor<<endl;
}


//http://arantxa.ii.uam.es/~cantador/slides/prog2-tema2-Pilas.pdf
