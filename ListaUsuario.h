using namespace std;

template<class T>
class ListaUsuario {
private:
	Nodo<T*>* inicio;
public:
	ListaUsuario() { inicio = NULL; }
	~ListaUsuario();
	string busquedaId(T* v);
	void insertar(T* v);
	bool busqueda(T* v);
	void guardar();
	void abrir();
	int cantidad();
	vector<int> getKeys();
};

template<class T>
ListaUsuario<T>::~ListaUsuario() {
	Nodo<T*>* temp;
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
void ListaUsuario<T>::insertar(T* v) {
	
	Nodo<T*>* nodo = new Nodo<T*>(v);
	if (inicio == NULL) inicio = nodo;
	else nodo->siguiente = inicio;
	inicio = nodo;
	nodo = NULL;

}

template<class T>
bool ListaUsuario<T>::busqueda(T* v) {

	//ahora con recursividad
	if (inicio == NULL) return false;
	else if (inicio->valor->getUsu() == v->getUsu() && generarKey(inicio->valor->getPass()) == v->getKey()) {
		v->setID(inicio->valor->getID());
		return true;
	}
	else {
		Nodo<T*>* aux = inicio;
		inicio = inicio->siguiente;
		bool existe = busqueda(v);
		inicio = aux;
		return existe;
	}

}

template<class T>
string ListaUsuario<T>::busquedaId(T* v) {
	Nodo<T*>* aux = inicio;
	while (aux != NULL) {
		if ( comparar<string>(aux->valor->getUsu(), v->getUsu()) == true) { 
			return aux->valor->getID();
		}
		aux = aux->siguiente;
	}
	return "";
}

template<class T>
void ListaUsuario<T>::guardar() {
	Nodo<T*>* aux = inicio;
	ofstream archivo;

	archivo.open("usuarios.csv", ios::trunc);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (aux != NULL) {
		T* us = (T*)(aux->valor);
		if(us->getID() == ""){
			us->setID(generarId());
			ofstream enviados("./MailsEnviados/" + us->getID() + ".csv");
			ofstream recibidos("./MailsRecibidos/" + us->getID() + ".csv");
			enviados.close();
			recibidos.close();
		}
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
		archivo.open("usuarios.csv");
		archivo.close();
		//exit(1);
	}

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string a, b, c;

		getline(ss, a, delimit);
		getline(ss, b, delimit);
		getline(ss, c, delimit);
		T* us = new T();
		us->setUsu(a);
		us->setPass(b);
		us->setID(c);
		insertar(us);
	}
	
	archivo.close();
}

template<class T>
int ListaUsuario<T>::cantidad() {
	int c = 0;
	Nodo<T*>* aux = inicio;
	while (aux != nullptr) {
		aux = aux->siguiente;
		c++;
	}
	return c;
}

template<class T>
vector<int> ListaUsuario<T>::getKeys() {
	Nodo<T*>* aux = inicio;
	int n=0;
	vector<int> keys(cantidad());
	T* us = new T(); 	
	while (aux != nullptr) {
		us = inicio->valor;
		keys.push_back(generarKey(us->getPass()));
		aux->siguiente;
		n++;
	}
	return keys;
}