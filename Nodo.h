using namespace std;
template<class T>
class Nodo {
public:
	T valor;
	Nodo<T>* siguiente;
public:
	Nodo(T v, Nodo<T>* sig = NULL) {
		valor = v;
		siguiente = sig;
	}
};