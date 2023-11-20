template<class T>
class ListaContactos {
private:
	Nodo<T>* raiz;
	void(*procesar)(T);

	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr) return 0;
		return nodo->altura;
	}

	void _rotarDerecha(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;

		nodo = p;
	}

	void _rotarIzquierda(Nodo<T>*& nodo) {
		Nodo<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;

		nodo = p;
	}
	void _balanceo(Nodo<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) {
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) {
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1) { 
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(Nodo<T>*& nodo, T e) {

		if (nodo == nullptr) {
			
			nodo = new Nodo<T>();
			nodo->elemento = e;
			return true;
		}
		else if (e == nodo->elemento)
			return false;
		else if (e < nodo->elemento) {
			_insertar(nodo->izq, e);
		}
		else if (e > nodo->elemento) {
			_insertar(nodo->der, e);
		}
		_balanceo(nodo);
		return true;
	}

	void _inOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		procesar(nodo->altura);
		_inOrdenH(nodo->der);
	}

	void _guardar(Nodo<T>* nodo, ofstream archivo) {
		if (nodo == nullptr) return;
		_guardar(nodo->izq, archivo);
		archivo << nodo->elemento << endl;
		_guardar(nodo->der, archivo);
	}

public:
	ListaContactos(void(*nuevaFuncion)(T)) {
		this->procesar = nuevaFuncion;
		this->raiz = nullptr;
	}

	bool Insertar(T e) {
		return _insertar(raiz, e);
	}
	void inOrden() {
		_inOrden(raiz);
	}
	void inOrdenH() {
		_inOrdenH(raiz);
	}

	void guardar(string v) {
		ofstream archivo;
		v = "./Contactos/" + v + ".csv";

		archivo.open(v, ios::trunc);

		if (archivo.fail()) {
			cout << "\nNo se pudo abrir el archivo";
			exit(1);
		}

		_guardar(raiz, archivo);

		archivo.close();
	}

	void abrir(string v) {
		ifstream archivo;
		string linea;
		v = "./Contactos/" + v + ".csv";
		archivo.open(v, ios::in);

		if (archivo.fail()) {
			cout << "\nNo se pudo abrir el archivo";
			exit(1);
		}

		while (getline(archivo, linea)) {
			Insertar(linea);
		}
		archivo.close();
	}
};