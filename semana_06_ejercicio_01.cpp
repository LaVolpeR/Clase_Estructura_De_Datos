#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
float time = 0;
struct datos{
	float dato;
	datos *sig;
}*p,*aux,*u;
void insertar(float dat);
void listar();

int main(){
	string name;
	float tiempo;
	int opc;
	
	
	cout<<"INGRESE NOMBRE: ";cin>>name;
	do{
		system("cls");
		tiempo = 0;
	cout<<"BIENVENIDO "<<name<<endl;
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
		tiempo = 4;
		insertar(tiempo);
		cout<<"-->> Ha pasado "<<tiempo<<"Min";
		getch();
		break;
	case 2:
		tiempo = 2;
		insertar(tiempo);
		cout<<"-->> Ha pasado "<<tiempo<<"Min";
		getch();
		break;
	case 3:
		tiempo = 3.5;
		insertar(tiempo);
		cout<<"-->> Ha pasado "<<tiempo<<"Min";
		getch();
		break;
	case 4:
		tiempo = 5;
		insertar(tiempo);
		cout<<"-->> Ha pasado "<<tiempo<<"Min";
		getch();
		break;
	case 5:
		tiempo = 2;
		insertar(tiempo);
		cout<<"-->> Ha pasado "<<tiempo<<"Min";
		getch();
		break;
	case 6:
		listar();
	cout<<"Usted estuvo: "<<time<<" min.";
		exit(1);
	default: cout<<"\n Opcion no valida!!";break;
	}
}while(opc);

}

void listar(){
	int i;
	if(!u){
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux=p;
	while(aux){
		time += aux->dato;
		aux=aux->sig;
	}
}

void insertar(float dat){
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
