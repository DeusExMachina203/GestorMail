using namespace std;

template<class T>
class ListaUsuario {
private:
	Nodo<T>* inicio;
public:
	ListaUsuario() { inicio = NULL; }
	~ListaUsuario();
	void insertar(T v);
	bool busqueda(T v);
	void guardar();
	void abrir();
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

template<class T>
void ListaUsuario<T>::guardar() {
	Nodo<T>* aux = inicio;
	ofstream archivo;

	archivo.open("usuarios.cvs", ios::trunc);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (aux != NULL) {
		Usuario* us = (Usuario*)(aux->valor);
		archivo << us->toString() << endl;
		aux = aux->siguiente;
	}

	archivo.close();
}

template<class T>
void ListaUsuario<T>::abrir() {
	ifstream archivo;
	string linea;
	char delimit = ',';

	archivo.open("usuarios.cvs", ios::in);

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
		Usuario* us = new Usuario(a, b, c);
		insertar(us);
	}
	
	archivo.close();
}