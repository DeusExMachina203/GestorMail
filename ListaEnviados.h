
using namespace std;

template<class T>
class ListaEnviados {
private:
	Nodo<T>* tope;
public:
	ListaEnviados(): tope(nullptr) { }
	void push(T v);
	T pop();
	bool estaVacia();
	void guardar(string v);
	void abrir(string v);
};

template<class T>
void ListaEnviados<T>::push(T v) {
	if (estaVacia()) {
		cout << "tope" << endl;
		tope = new Nodo<T>(v);
		
	}
	else tope = new Nodo<T>(v, tope);
}

template<class T>
T ListaEnviados<T>::pop() {
	if (estaVacia()) return NULL; //error pila vacia
	else {
		T elemento = tope->valor;
		tope = tope->siguiente;
		return elemento;
	}
}

template<class T>
bool ListaEnviados<T>::estaVacia() {
	cout<< "funcionesvacia" << endl;
	if(tope) return true;
	else return false;
}

template<class T>
void ListaEnviados<T>::guardar(string v) {
	Nodo<T>* aux = tope;
	ofstream archivo;

	archivo.open(v, ios::trunc);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (aux != NULL) {
		Mail* ml = (Mail*)(aux->valor);
		archivo << ml->toString() << endl;
		aux = aux->siguiente;
	}

	archivo.close();
}

template<class T>
void ListaEnviados<T>::abrir(string v) {
	ifstream archivo;
	string linea;
	char delimit = '&';
	cout<< endl << v << endl;
	archivo.open(v, ios::in);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string a, b, c;

		getline(ss, a, delimit);
		getline(ss, b, delimit);
		getline(ss, c, delimit);


		push(new Mail(a, b, c));
	}
	archivo.close();
}