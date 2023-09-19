#include"Nodo.h"
#include"Mail.h"
using namespace std;

template<class T>
class ListaEnviados {
private:
	Nodo<T>* tope;
public:
	ListaEnviados() { tope = NULL; }
	void push(T v);
	T pop();
	bool estaVacia();
};

template<class T>
void ListaEnviados<T>::push(T v) {
	if (estaVacia()) tope = new Nodo<T>(v);
	else tope = new Nodo<T>(v, tope);
}

template<class T>
T ListaEnviados<T>::pop() {
	if (estaVacia()) return NULL; //error pila vacia
	else {
		T elemento = tope->dato;
		tope = tope->siguiente;
		return elemento;
	}
}

template<class T>
bool ListaEnviados<T>::estaVacia() {
	return (tope == NULL);
}