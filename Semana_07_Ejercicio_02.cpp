#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
float ganancia_total;
int mayor_vendido=0,menor_vendido=1000000;
string mayn,menn;
struct productos
{
	string nombre;
	string codigo;
	int cantidad;
	float precio;
	productos *sgte;
}*inicio,*final,*aux;
void ingreso(string n1,string n2,int c1,float p1)
{
	aux=new productos();
	aux->nombre=n1;
	aux->codigo=n2;
	aux->cantidad=c1;
	aux->precio=p1;
	if(inicio==NULL)
	{
		inicio=final=aux;
	}
	else
	{
		final->sgte=aux;
		aux->sgte=NULL;
		final=aux;
	}
}
void imprimir()
{
	system("cls");
	aux=inicio;
	while(aux!=NULL)
	{
		cout<<"Nombre: "<<aux->nombre<<endl;
		cout<<"Codigo: "<<aux->codigo<<endl;
		cout<<"Cantidad: "<<aux->cantidad<<endl;
		cout<<"Precio: "<<aux->precio<<endl;
		cout<<"\n";
		ganancia_total=ganancia_total+aux->precio;
		if(mayor_vendido<aux->cantidad)
		{
			mayor_vendido=aux->cantidad;
			mayn=aux->nombre;
		}
		if(menor_vendido>aux->cantidad)
		{
			menor_vendido=aux->cantidad;
			menn=aux->nombre;
		}
		aux=aux->sgte;
	}
	cout<<"Ganancia total: "<<ganancia_total<<endl;
	cout<<"Articulo que mas se vendio: "<<mayn<<endl;
	cout<<"Unidades vendidas: "<<mayor_vendido<<endl;
	cout<<"Articulo que menos se vendio: "<<menn<<endl;
	cout<<"Unidades vendidas: "<<menor_vendido<<endl;
}
int main()
{
	string n1,n2;
	int c1,cant_prod;
	float p1;
	cout<<"Ingrese cant de productos: ";cin>>cant_prod;
	for(int i=1;i<=cant_prod;i++)
	{
		cout<<"Producto "<<i<<endl;
		cout<<"Ingrese nombre: ";cin>>n1;
		cout<<"Ingrese codigo: ";cin>>n2;
		cout<<"Ingrese cantidad: ";cin>>c1;
		cout<<"Ingrese precio: ";cin>>p1;
		ingreso(n1,n2,c1,p1);
	}
	imprimir();
}
