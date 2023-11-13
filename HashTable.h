
class HashTabla {
private:
	Hash** tabla;
	int numElementos;
	int TABLE_SIZE;
public:
	HashTabla(int TABLE_SIZE = 500) {
		this->TABLE_SIZE = TABLE_SIZE;
		tabla = new Hash * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i)
			tabla[i] = nullptr;
		numElementos = 0;
	}
	~HashTabla() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			if (tabla[i] != nullptr) delete tabla[i];
		}
		delete[] tabla;
	}

	void insertar(int key, string value) {
		int base, step, hash;

		if (numElementos == TABLE_SIZE) return;
		base = key % TABLE_SIZE;
		hash = base;
		step = 0;
		while (tabla[hash] != nullptr) { 
			hash = (base + step) % TABLE_SIZE;
			step++;
		}
		
		tabla[hash] = new Hash(key, value);
		numElementos++;
	}

	int size() { return TABLE_SIZE; }

	int sizeactual() { return numElementos; }

	string buscar(int key) {
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE;
		while (true) {
			if (tabla[i] == nullptr) return 0;
			else if (tabla[i]->getKey() == key) return tabla[i]->getValue();
			else step++;
			i + (base + step) % TABLE_SIZE;
		}
	}

	int generarKey(string pass) {
		int sum = 0;
		int key;
		for (char c : pass) { //se calcula la suma de los códigos ascii de cada caracter en la contrasena
			sum += static_cast<int>(c);
		}

		key = ((sum * 17) / 5) % 100;
		return key;
	}

	void guardar(int keys[]) {
		ofstream archivo;
		ostringstream ss;
		archivo.open("hashtable.csv", ios::trunc);

		if (archivo.fail()) {
			cout << "\nNo se pudo abrir el archivo";
			exit(1);
		}

		for (int i = 0; i < size(); i++) {
			ss << to_string(keys[i]);
			ss << ",";
			ss << buscar(keys[i]);
			archivo << ss.str() << endl;
		}
		archivo.close();
	}

	void abrir() {
		ifstream archivo;
		string linea;
		char delimit = ',';

		archivo.open("hashtable.csv", ios::in);
		if (archivo.fail()) {
			cout << "\nNo se pudo abrir el archivo";
			archivo.open("usuarios.csv");
			archivo.close();
			//exit(1);
		}

		while (getline(archivo, linea)) {
			stringstream ss(linea);
			string a, b;

			getline(ss, a, delimit);
			getline(ss, b, delimit);
			
			insertar(stoi(a), b);
		}
		archivo.close();
	}
};