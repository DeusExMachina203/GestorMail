
using namespace std;

template<class T>
class ListaRecibidos {
private:
	Nodo<T*>* tope;
public:
	ListaRecibidos() { tope = NULL; }
	void push(T* v);
	T* pop();
	bool estaVacia();
	void guardar(string v);
	void abrir(string v);
};

template<class T>
void ListaRecibidos<T>::push(T* v) {
	if (estaVacia()) tope = new Nodo<T*>(v);
	else tope = new Nodo<T*>(v, tope);
}

template<class T>
T* ListaRecibidos<T>::pop() {
	if (estaVacia()) return NULL; //error pila vacia
	else {
		T* elemento = tope->valor;
		tope = tope->siguiente;
		return elemento;
	}
}

template<class T>
bool ListaRecibidos<T>::estaVacia() {
	return (tope == NULL);
}

template<class T>
void ListaRecibidos<T>::guardar(string v) {
	Nodo<T*>* aux = tope;
	ofstream archivo;

	archivo.open(v.c_str(), ios::trunc);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (aux != NULL) {
		T* ml = (T*)(aux->valor);
		archivo << ml->toString() << endl;
		aux = aux->siguiente;
	}

	archivo.close();
}

template<class T>
void ListaRecibidos<T>::abrir(string v) {
	ifstream archivo;
	string linea;
	char delimit = '&';

	archivo.open(v, ios::in);

	if (archivo.fail()) {
		cout << "\nNo se pudo abrir el archivo";
		exit(1);
	}

	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string asunto, texto, emisor, remitente;

		getline(ss, asunto, delimit);
		getline(ss, texto, delimit);
		getline(ss, emisor, delimit);
		getline(ss, remitente, delimit);

		T* mail = new T();
		mail->setAsunto(asunto);
		mail->setTexto(texto);
		mail->setEmisor(emisor);
		mail->setRemitente(remitente);
		push(mail);
	}
	archivo.close();
}