
using namespace std;

template<class T>
class ListaEnviados {
private:
	Nodo<T*>* tope;
public:
	ListaEnviados(): tope(nullptr) { }
	void push(T* v);
	T* pop();
	bool estaVacia();
	void guardar(string v);
	void abrir(string v);
};

template<class T>
void ListaEnviados<T>::push(T* v) {
	if (estaVacia()) {
		tope = new Nodo<T*>(v);
	}
	else tope = new Nodo<T*>(v, tope);
}

template<class T>
T* ListaEnviados<T>::pop() {
	if (estaVacia()) return NULL; //error pila vacia
	else {
		T* elemento = tope->valor;
		tope = tope->siguiente;
		return elemento;
	}
}

template<class T>
bool ListaEnviados<T>::estaVacia() {
	if(tope == nullptr) return true;
	else return false;
}

template<class T>
void ListaEnviados<T>::guardar(string v) {
	Nodo<T*>* aux = tope;
	ofstream archivo;

	archivo.open(v, ios::trunc);

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
void ListaEnviados<T>::abrir(string v) {
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