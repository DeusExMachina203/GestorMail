template<class T>
class Nodo {
public:
	T valor;
	Nodo<T>* siguiente;
public:
	Nodo(T v, Nodo<T>* sig = nullptr) {
		valor = v;
		siguiente = sig;
	}
};