//Miniproyecto 5. Pilas

#include <iostream>
#include <cstdlib>

using namespace std;

class Nodo{
	public:
		char dato;	//int dato
		Nodo *siguientePtr;
};

class Pila{
	private:
		Nodo *topePtr;
		bool estaVacia();
	public:
		Pila();
		~Pila();
		void mete(char valor);	//(int valor)
		int saca();
		int nodoInicio();
		void mueve(Pila &p1);
		void muestra();
		int cantidadElementos();
		int nodoMayor();
		void eliminarNodo(int referencia);
		void concatena(Pila &p1);
		void convertirPostfija();
};

Pila::Pila(){
	topePtr = NULL;
}

Pila::~Pila(){
	while(!estaVacia()){
		saca();
	}
}

bool Pila::estaVacia(){
	return topePtr == NULL;
}

void Pila::mete(char valor){	//(int valor)
	Nodo *nuevoPtr = new Nodo();
	nuevoPtr->dato = valor;
	nuevoPtr->siguientePtr = topePtr;
	topePtr = nuevoPtr;
}

int Pila::saca(){
	if(estaVacia()){
		cout<<"\nLa pila esta vacia\n\n";
		exit(1);
	}
	char x = topePtr->dato;	//int x = topePtr->dato
	Nodo *tempPtr = topePtr;
	topePtr = topePtr->siguientePtr;
	delete tempPtr;
	return x;
}

int Pila::nodoInicio(){
	if(topePtr==NULL){
		cout<<"\nLa pila esta vacia\n\n";
		exit(1);
	}
	return topePtr->dato;
}

void Pila::mueve(Pila &p1){
	char x;	//char
	while(!p1.estaVacia()){
		x = p1.saca();
		mete(x);
	}
}

int Pila::cantidadElementos(){
	if(estaVacia()){
		cout<<"\nLa pila esta vacia\n\n";
		exit(1);
	}
	int cont = 0;
	char x;	//int x
	Pila aux;
	while(!estaVacia()){
		x = saca();
		cont = cont + 1;
		aux.mete(x);
	}
	mueve(aux);
	return cont;	
}

int Pila::nodoMayor(){
	if(estaVacia()){
		cout<<"\nLa pila esta vacia\n\n";
		exit(1);
	}
	char x;	//int x
	int mayor = 0;
	Pila aux;
	while(!estaVacia()){
		x = saca();
		if(x>mayor){
			mayor = x;
		}
		aux.mete(x);
	}
	mueve(aux);
	return mayor;
}

void Pila::eliminarNodo(int referencia){
	if(estaVacia()){
		cout<<"\nLa pila esta vacia\n\n";
		system("pause");
		return;
	}
	Pila aux;
	char x;	//int x
	while(!estaVacia()){
		x = saca();
		if(x!=referencia){
			aux.mete(x);
		}else{
			cout<<"\nElemento "<<x<<" eliminado\n";
		}
	}
	mueve(aux);
	return;
}

void Pila::muestra(){
	if(estaVacia()){
		cout<<"\nLa pila esta vacia\n\n";
		system("pause");
		return;
	}
	Pila aux;
	char x;	//int x
	cout<<"\nLos elementos de la pila son: ";
	while(!estaVacia()){
		x = saca();
		cout<<x<<" -> ";
		aux.mete(x);
	}
	mueve(aux);
	cout<<"\n\n";
	system("pause");
}

void menu(){
	system("cls");
	cout<<"\n..[         PILAS          ]..";
	cout<<"\n..[........................]..\n\n";
	cout<<"[ 1] Insertar un elemento\n";
	cout<<"[ 2] Muestra los elementos de la pila\n";
	cout<<"[ 3] Sacar el primer elemento elemento\n";
	cout<<"[ 4] Primer elemento de la lista\n";
	cout<<"[ 5] Mueve los elementos de la pila p1 a la pila principal(9, 2, 7, 3)\n";
	cout<<"[ 6] Contar la cantidad de elementos\n";
	cout<<"[ 7] Muestra el elemento mayor\n";
	cout<<"[ 8] Eliminar un elemento por referencia\n";
	cout<<"[ 9] Miniproyecto 5\n";
	cout<<"[10] Salir\n";
	cout<<"\nIngresa tu eleccion: ";
}



//-------------------------------------------------------------------------
//Miniproyecto 5. Pilas

/*Usando el codigo previamente hecho de Pilas, 
esta seccion es una implementacion para realizar 
lo que las indicaciones del proyecto solicita*/


void Pila::convertirPostfija(){
	Pila pilaCaracteres;	//guarda los caracteres
	Pila pilaFinal;			//guarda los caracteres en orden postfijo
	char charAnalis;		//guarda la variable para analizar
	for(int c=0;c<cantidadElementos();c++){
		//DESDE AQUI FALTA LA IMPLEMENTACION DEL RESTO DEL CODIGO
	}
}

void menuProyecto(string notacion){
//	Menu de opciones del proyecto
	system("cls");
	cout<<"\n..[       Miniproyecto 5         ]..";
	cout<<"\n..[  Notacion Infija a Postfija  ]..\n\n";
	cout<<"     "<<notacion<<'\n';	//Muestra la notacion si es que existe
	cout<<"[ 1] Insertar/Modificar notacion infija\n";	//La primera opcion es para ingresar la notacion
	cout<<"[ 2] Convertir la notacion en Postfija\n";	//
	cout<<"[10] Regresar al menu principal\n";
	cout<<"\nIngresa tu eleccion: ";
}

bool comprobarSintaxis(string notacion){
//	Metodo basico para comprobrar si la sintaxis de la notacion fue escrita de manera cuando menos correcta
	bool correcta = false;
	int corcheteAbierto = 0;
	for(int c=0;c<notacion.size();c++){
		if(int(notacion[c])>64&&int(notacion[c])<91){
			correcta = true;
		}else if(notacion[c]=='('){
			corcheteAbierto = corcheteAbierto + 1;
		}else if(notacion[c]==')'){
			corcheteAbierto = corcheteAbierto - 1;
		}else if(notacion[c]=='+'||notacion[c]=='-'||notacion[c]=='*'||notacion[c]=='/'||notacion[c]=='^'){
			correcta = true;
		}else{
			c = notacion.size();
			correcta = false;
		}
	}
	if(corcheteAbierto!=0){
		correcta = false;
	}
	return correcta;
}

void minipro(){
	int opcion;
	bool correct = false;
	string notacion, inv;	//la variable 'inv' es solo para igualar la variable 'notacion' a algo nulo, por eso 'inv' no se modifica en nungun momento
	Pila pilaNotacion;
	do{
		menuProyecto(notacion);	//menu del proyecto
		cin>>opcion;			//ingresar la opcion
		switch(opcion){
			case 1:
				cout<<"\nNota: las variables deben ser indicadas en mayusculas\nIngresa la formula a continuacion infija\n\n";
				cin>>notacion;
				correct = comprobarSintaxis(notacion);
				if(correct){
					cout<<"\nNotacion guardada\n\n";
					system("pause");
				}else{
					cout<<"\nError de sintaxis, vuelve a intentar\n";
					notacion = inv;
					system("pause");
				}
			break;
			case 2:
				if(!correct){
					cout<<"\nError, aun no se ingresa una notacion correcta o completa\n";
					system("pause");
				}else{
					Pila pilatemp;
					char dato;
					for(int c=0;c<notacion.size();c++){
						dato = notacion[c];
						pilatemp.mete(dato);
					}
					pilaNotacion.mueve(pilatemp);//Desde aqui el string ha sido convertido en Pila, caracter por caracter
					pilaNotacion.convertirPostfija();
//					pilaNotacion.muestra();
					system("pause");
					notacion = inv;
				}
			break;
		}
	}while(opcion!=10);
	return;
}



//--------------------------------------------------------------------------------------



int main(){
	int opcion, valor, referencia;
	Pila pilaEnteros;
	Pila p1;
	system("color 73");
	do{
		menu();
		cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"\nIngrese valor entero: ";
				cin>>valor;
				pilaEnteros.mete(valor);
				pilaEnteros.muestra();
			break;
			case 2:
				pilaEnteros.muestra();
			break;
			case 3:
				cout<<"\nSe saco el elemento: "<<pilaEnteros.saca();
				pilaEnteros.muestra();
			break;
			case 4:
				cout<<"\nEl valor de inicio es: "<<pilaEnteros.nodoInicio();
				pilaEnteros.muestra();
			break;
			case 5:
				p1.mete('3');
				p1.mete('7');
				p1.mete('2');
				p1.mete('9');
				cout<<"\nPila p1 ";
				p1.muestra();
				pilaEnteros.mueve(p1);
				cout<<"\nPila principal ";
				pilaEnteros.muestra();
			break;
			case 6:
				cout<<"\nHay "<<pilaEnteros.cantidadElementos()<<" elementos en la pila principal\n";
				pilaEnteros.muestra();
			break;
			case 7:
				cout<<"El nodo mayor es: "<<char(pilaEnteros.nodoMayor());
				pilaEnteros.muestra();
			break;
			case 8:
				cout<<"\nIngrese valor referencia: ";
				cin>>referencia;
				pilaEnteros.eliminarNodo(referencia);
				pilaEnteros.muestra();
			break;
			case 9:
				minipro();
			break;
		}
	}while(opcion!=10);
	return 0;
}






