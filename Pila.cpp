//Miniproyecto 5. Pilas

#include <iostream>
using namespace std;

class Nodo{
	public:
		int dato;
		Nodo *siguientePtr;
};

class Pila{
	private:
		Nodo *topePtr;
		bool estaVacia();
	public:
		Pila();
		~Pila();
		void mete(int valor);
		int saca();
		int nodoInicio();
		void mueve(Pila &p1);
		void muestra();
		int cantidadElementos();
		int nodoMayor();
		void eliminarNodo(int referencia);
		void concatena(Pila &p1);
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

int main(){
  
  return 0;
}






