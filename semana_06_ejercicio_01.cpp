#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

float total = 0;

struct datos{
	float dato;
	string name;
	float espera;
	datos *sig;
}*p,*aux,*u;
void insertar(float dat, string nam, float esp);
void listar();

int main(){
	int numero,opc;
	float tiempo = 0; 
	float ocup = 0;
	string nombre;
	cout<<"\t\t\tBienvenido";
	cout<<"\n\n\t\tIngrese la cantidad de usuarios que hay en el banco"<<endl;
	cin>>numero;
	
	for(int i = 0; i<numero; i++){
		system("cls");
		ocup+=tiempo;
		tiempo = 0;
		
		cout<<"\n\t\tIngrese el nombre de la "<<i+1<<" persona:"<<endl;
		cin>>nombre;
		do{
			system("cls");
			cout<<"BIENVENIDO "<<nombre<<endl;
			cout<<"MENU"<<endl;
			cout<<"1.- Retiro"<<endl;
			cout<<"2.- Deposito"<<endl;
			cout<<"3.- Consulta"<<endl;
			cout<<"4.- Actualizacion"<<endl;
			cout<<"5.- Pagos"<<endl;
			cout<<"6.- Salir"<<endl;
			cout<<"Elegir transaccion que desa realizar ";cin>>opc;	
			switch(opc){
				case 1:
					tiempo += 4;
					cout<<"-->>Ha pasado 4 minutos";
					getch();
					break;
				case 2:
					tiempo += 2;
					cout<<"-->>Ha pasado 2 minutos";
					getch();
					break;
				case 3:
					tiempo += 3.5;
					cout<<"-->>Ha pasado 3.5 minutos";
					getch();
					break;
				case 4:
					tiempo += 5;
					cout<<"-->>Ha pasado 5 minutos";
					getch();
					break;
				case 5:
					tiempo += 2;
					cout<<"-->>Ha pasado 2 minutos";
					getch();
					break;	
				case 6:
					cout<<"Usted estuvo "<<tiempo<<" minutos";
					insertar(tiempo,nombre,ocup);
					getch();
				break;
			}			
		}while(opc!=6);
	}
	system("cls");
	listar();
	cout<<"\n\nEl cajero estuvo operando "<<total<<"min.";
}
void listar(){
	int i;
	if(!u){
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux=p;
	while(aux){
		if(aux->espera!=0)
		cout<<"La persona "<<aux->name<<" estuvo esperando "<<aux->espera<<"min y sus transacciones duraron un total de "<<aux->dato<<"min."<<endl;
		else{
			cout<<"La persona "<<aux->name<<" fue la primera en ser atendida y demoro "<<aux->dato<<"min."<<endl;
		}
		total += aux->dato;
		aux=aux->sig;
	}
}
void insertar(float dat, string nam, float esp){
	aux=new(datos);
	aux->dato=dat;
	aux->name = nam;
	aux->espera =esp;
	if(u){
		u->sig=aux;
		aux->sig=NULL;
		u = aux;
	}
	else{
		p=u=aux;
	}
}
