using namespace std;

template<class T>
class ListaUsuario {
private:
	Nodo<T>* inicio;
public:
	ListaUsuario() { inicio = NULL; }
	~ListaUsuario();
	string generarId();
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
string ListaUsuario<T>::generarId() {
	string id = "";
	int num;
	for (int i = 0; i < 6; i++) {
		num = rand() % 10;
		id += to_string(num);
	}
	return id;
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
		if (aux->valor->getUsu() == v->getUsu() && aux->valor->getContra() == v->getContra()) { 
			existe = true;
			return existe;
		}
		aux = aux->siguiente;
	}
	return existe;
}

template<class T>
void ListaUsuario<T>::guardar() {
	Nodo<T>* aux = inicio;
	ofstream archivo;

	archivo.open("usuarios.csv", ios::trunc);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (aux != NULL) {
		Usuario* us = (Usuario*)(aux->valor);
		if(us->getID() == "")us->setID(generarId());
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

	archivo.open("usuarios.csv", ios::in);

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
		Usuario* us = new Usuario(a, b);
		us->setID(c);
		insertar(us);
	}
	
	archivo.close();
}