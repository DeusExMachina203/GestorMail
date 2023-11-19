
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
		// int base, step, hash;
		// base = key % TABLE_SIZE;
		// hash = base;
		
		// if(tabla[hash] == nullptr) { 
		// 	hash = (base) % TABLE_SIZE;
		// 	tabla[hash] = new Hash(key, value);
		// }else if (tabla[hash]->siguiente == nullptr) {
		// 	hash = (base) % TABLE_SIZE;
		// 	tabla[hash]->siguiente = new Hash(key, value);
		// }else{
		// 	Hash* temp = tabla[hash];
		// 	while (temp->siguiente != nullptr) {
		// 		temp = temp->siguiente;
		// 	}
		// 	temp->siguiente = new Hash(key, value);
		// }
		// numElementos++;
	}
	
 
	int size() { return TABLE_SIZE; } 
  
	int sizeactual() { return numElementos; }

	string buscar(string pass) {
		int step = 0;
		int i, base;
		int key = generarKey(pass);
		
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
		for (char c : pass) { //se calcula la suma de los c�digos ascii de cada caracter en la contrasena
			sum += static_cast<int>(c);
		}
		key = ((sum * 17) / 5) % 500;
		return key;
	}

	void guardar(vector<int> keys) {
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
			ss << buscar(std::to_string(keys[i]));
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