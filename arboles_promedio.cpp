#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int mayor =0;
float promedio_total = 0,i = 0;
string nombre_mayor;
struct Nodo{
	string nombre;
	int nota_1;
	int nota_2;
	float promedio;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

Nodo *arbol = NULL;
//Prototipos
void menu();
Nodo *crearNodo(string,int,int,float ,Nodo *);
void insertarNodo(Nodo *&,string,int,int,float, Nodo *);
void mostrarArbol(Nodo *arbol, int cont);
void inOrden(Nodo *);
int main(){
	menu();
	getch();
	return 0;
}
void menu(){
	int num1,num2;
	float prom;
	string name;
	int opcion=0 , contador=0;
	do{
	cout<<"\t\t.:MENU:."<<endl;
	cout<<"1. Insertar dato"<<endl;
	cout<<"2. Mostrar arbol"<<endl;
	cout<<"3. salir"<<endl;
	cout<<"Opcion: ";
	cin>>opcion;
	switch(opcion){
		case 1:	i++;
				cout<<"Ingresar nombre del estudiante: ";
				cin>>name;
				cout<<"Ingresar la nota numero 1: ";
				cin>>num1;
				cout<<"Ingresar la nota numero 2: ";
				cin>>num2;
				prom = (num1 + num2)/2;
				promedio_total += prom;
				if(prom>mayor){
					mayor = prom;
					nombre_mayor = name;
				}
				cout<<"El promedio de estudiante "<<name<<" es de "<<prom<<endl;
				insertarNodo(arbol,name,num1,num2,prom, NULL);
				cout<<"\n";
				system("pause");
			break;
		case 2: cout<<"\nMostrando el arbol completo: \n\n";
					mostrarArbol(arbol,contador);
					cout<<"\n"<<endl;
					inOrden(arbol);
					cout<<"\n\n";
					cout<<"El promedio total de los estudiantes del aula es de "<<promedio_total/i<<endl;
					cout<<"El estudiante con mayor nota es "<<nombre_mayor<<" con un total de "<<mayor<<endl;
					system("pause");
				break;
			
		}
		system("cls");
	}while(opcion != 3);
}
void insertarNodo(Nodo *&arbol,string nom,int not1,int not2,float prom, Nodo *padre){
	if(arbol==NULL){///Si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(nom,not1,not2,prom , padre);
		arbol = nuevo_nodo;
	}
	else{//Si el arbol tiene un NODO o mas
		int valorRaiz = arbol->promedio;//Obtenemos el valor de la raiz
		if(prom<valorRaiz){//Si el elemento es menor ala raiz, insertamos en izq
			insertarNodo(arbol->izq,nom,not1,not2,prom , arbol);
		}
		else{//Si el elemento es mayor ala raiz, insertamos en der
			insertarNodo(arbol->der,nom,not1,not2,prom , arbol);
		}
	}
}
//funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol, int cont){
	if(arbol== NULL){ //Si el arbol esta vacio
		return ;
	}
	else{
		mostrarArbol(arbol->der,cont +1);
		for(int i=0;i<cont;i++){
			cout<<"\t\t";
		}
		cout<<arbol->promedio;
		cout<<"("<<arbol->nombre<<")"<<endl;
		mostrarArbol(arbol->izq,cont +1);
	}
}
//funcion para crear un nuevo nodo
Nodo *crearNodo(string nom,int not1,int not2,float prom, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->nombre = nom;
	nuevo_nodo->nota_1 = not1;
	nuevo_nodo->nota_2 = not2;
	nuevo_nodo->promedio = prom;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	return nuevo_nodo;
}
void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		if(arbol->promedio>15)
			cout<<arbol->nombre<<" - "<<arbol->promedio<<endl;
		inOrden(arbol->izq);
		inOrden(arbol->der);
	}
}
