#include<iostream>
#include<stdlib.h>
#include <stdio.h>  
#include <windows.h>  
 
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
using namespace std;
int suma = 0;
struct nodo{
	int numero;
	string nombre;
	float tarifa;
	int hora;
	struct nodo *sgte;
};
typedef struct nodo *Tlista;
void insertar(Tlista &lista, int valor,string nombre,float tarifa, int hora){
	Tlista t, q = new(struct nodo);
	q->nombre = nombre;
	q->hora = hora;
	q->tarifa = tarifa;
	q->numero = valor;
	q -> sgte = NULL;
	if(lista==NULL){
		lista = q;
	}	
	else{
		t= lista;
		while(t->sgte != NULL){
			t= t->sgte;
		}
		t->sgte = q;
	}
}
void mostrar(Tlista lista){
	int i = 0;
	while(lista != NULL){
		gotoxy(5,i+5);cout<<lista->numero;
		gotoxy(15,i+5);cout<<lista->nombre;
		gotoxy(25,i+5);cout<<lista->tarifa;
		gotoxy(35,i+5);cout<<lista->hora;
		lista = lista->sgte;
		i++;
	}
}
void reportar(Tlista lista){
	int i = 0;
		while(lista != NULL){
			if(lista->hora>=20){
				gotoxy(5,i+10);cout<<lista->numero;
				gotoxy(15,i+10);cout<<lista->nombre;
				gotoxy(25,i+10);cout<<lista->tarifa;
				gotoxy(35,i+10);cout<<lista->hora;
			}
			lista = lista->sgte;
			i++;
	}	
}
int main(void){
	int numero, hora;
	string nombre;
	float tarifa;
	int cantidad;
	
	Tlista lista = NULL;
	cout<<"Ingrese la cantidad de alumnos que desee registrar:\n";
	cin>>cantidad;
	for(int i = 0; i<cantidad;i++){
		cout<<i+1<<".- Ingresar numero\n";
		cin>>numero;
		cout<<i+1<<".- Ingresar nombre\n";
		cin>>nombre;
		cout<<i+1<<".- Ingresar tarifa\n";
		cin>>tarifa;
		cout<<i+1<<".- Ingresar horas\n";
		cin>>hora;
		insertar(lista,numero,nombre,tarifa,hora);
	}
	system("cls");
	mostrar(lista);
	reportar(lista);
}
