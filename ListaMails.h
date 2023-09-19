#include"Nodo.h"
#include"Mails.h"
using namespace std;

template<class T>
class ListaMails {
private:
	Nodo<T>* tope;
public:
	Pila() { tope = NULL; };
	void push(T v);
	T pop();
	bool estaVacia();
};

template<class T>
void ListaMails<T>::push(T v) {
	if (estaVacia()) tope = new Nodo<T>(v);
	else tope = new Nodo<T>(v, tope);
}

template<class T>
T ListaMails<T>::pop() {
	if (estaVacia()) return NULL; //error pila vacia
	else {
		T elemento = tope->dato;
		tope = tope->siguiente;
		return elemento;
	}
}

template<class T>
bool ListaMails<T>::estaVacia() {
	return (tope == NULL);
}