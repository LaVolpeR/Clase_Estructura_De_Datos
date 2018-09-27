#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include <windows.h>  
using namespace std;
 float retiro_total= 0 , contador = 0;
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
void clientes();

void deposito_1();
void retiro_1();
struct cajero{
	string name;
	float rode;
	cajero *sig;
}*p,*aux,*u;

struct cajero_1{
	float Deposit;
	cajero_1 *sig;
}*q,*aux_1,*v;

struct cajero_2{
	float retirement;
	cajero_2 *sig;
}*w,*aux_2,*x;

void usuario(string nombre, float monto);
void depositar(float deposito);
void aposentadoria(float retiro);
int main(){
	float monto = 500;
	float salario; 
	float deposito;
	int retiro;
	string nombre;
	int opc;
	do{
		system("cls");
	cout<<"\tBienvenido"<<endl;
	cout<<"\nIngrese su nombre"<<endl;
	cin>>nombre;
	cout<<"\nIngrese su salario"<<endl;
	cin>>salario;
		do{
			system("cls");
			cout<<"\t\t\n\nBienvenido "<<nombre<<" Su salario acutal es de "<<salario<<endl;
			cout<<"\t1.-Deposito"<<endl;
			cout<<"\t2.-Retiro"<<endl;
			cout<<"\t3.-Salir"<<endl;
			cout<<"\t4.-Cerrar cajero"<<endl;	
			cout<<"Ingrese una opcion: "<<endl;
			cin>>opc;
			switch(opc){
				case 1:
					cout<<"Ingresar la cantidad que ustede desee depositar";
					cin>>deposito;
					salario += deposito;
					monto += deposito;
					depositar(deposito);
					break;
				case 2:
					do{
					cout<<"Ingrese la cantidad que usted desee retirar (Multiplo de 10)"<<endl;
					cin>>retiro;
					if(retiro>monto)
						cout<<"No hay suficiente dinero en el cajero"<<endl;
					if(retiro>salario)
						cout<<"No cuenta con suficiente dinero para hacer ese tipo de retiro"<<endl;
					}while(retiro%10 != 0 || retiro > monto || retiro> salario);
					monto -=retiro;
					salario -=retiro;
					retiro_total += retiro;
					contador++;
					aposentadoria(retiro);
			}
		}while(opc!=3&&opc!=4);
		usuario(nombre,salario);
	}while(opc!=4);
	system("cls");
	clientes();
	cout<<"\nDeposito"<<endl;
	deposito_1();
	cout<<"\nRetiro"<<endl;
	retiro_1();
	cout<<"\n\nMonto total del cajero: "<<monto;
	cout<<"\n\nEL promedio de retiro es: "<<retiro_total/contador;
	
}

void clientes(){
	int i;
	if(!u){
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux=p;
	while(aux!=NULL){
		cout<<"cliente: "<<aux->name<<endl;
		cout<<"salario: "<<aux->rode<<endl;
		aux=aux->sig;
	}
}

void deposito_1(){

	if(!v){
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux_1=q;
		while(aux_1!=NULL){
		cout<<aux_1->Deposit<<endl;
		aux_1 = aux_1->sig;
		}
}

void retiro_1(){
	
	if(!x){
		cout<<"\n No hay datos en la cola";
		return;
	}
	aux_2=w;
		while(aux_2!=NULL){
		cout<<aux_2->retirement<<endl;
		
		aux_2 = aux_2->sig;
		}
	
}
void depositar(float deposito){
	aux_1= new(cajero_1);
	aux_1->Deposit =deposito;
	if(v){
		v->sig=aux_1;
		aux_1->sig=NULL;
		v = aux_1;
	}
	else{
		q=v=aux_1;
	}
	
}

void aposentadoria(float retirar){
	aux_2 = new(cajero_2);
	aux_2->retirement = retirar;
	if(x){
		x->sig=aux_2;
		aux_2->sig=NULL;
		x = aux_2;
	}
	else{
		w=x=aux_2;
	}
}
void usuario(string nombre, float monto){
	aux = new(cajero);
	aux->name = nombre;
	aux->rode = monto;

	if(u){
		u->sig=aux;
		aux->sig=NULL;
		u = aux;
	}
	else{
		p=u=aux;
	}
	
}
