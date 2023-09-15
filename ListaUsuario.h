#include"Nodo.h"
#include"Usuario.h"

template<class T>
class ListaUsuario {
private:
	Nodo<T>* inicio;
public:
	ListaUsuario() { inicio = NULL; }
	~ListaUsuario();
	void insertar(T v);
	bool busqueda(T v);
};

template<class T>
ListaUsuario<T>::~ListaUsuario() {
	Nodo<T>* temp;
	while (inicio != NULL) {
		temp = inicio;
		inicio = inicio->siguiente;
		delete temp;
		temp = NULL;
	}
	delete inicio;
	inicio = NULL;
}

template<class T>
void ListaUsuario<T>::insertar(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (inicio == NULL) inicio = nodo;
	else nodo->siguiente = inicio;
	inicio = nodo;
	nodo = NULL;
}

template<class T>
bool ListaUsuario<T>::busqueda(T v) {
	Nodo<T>* aux = inicio;
	bool existe = false;

	while (aux != NULL) {
		if (aux->valor == v) { existe = true; }
		aux = aux->siguiente;
	}
	return existe;
}
