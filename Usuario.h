using namespace std;

class Usuario {
	string usu, key, id;
public:
	Usuario(string usu = "", string key = "", string id = "") : usu(usu), key(key) {
		
	}
	string toString() {
		ostringstream ss;
		ss << usu;
		ss<< ",";
		ss << key;
		ss << ",";
		ss << id;
		return (ss.str());
	}

	string getID() { return this->id; }

	void setUsu(string usu) { this->usu = usu; }

	string getUsu() { return this->usu; }

	void setKey(string key) { this->key = key; }

	string getKey() { return this->key; }	

	void setID(string id) { this->id = id; }

	string idArchivoEnviado() {
		ostringstream ss;
		ss << "./MailsEnviados/";
		ss << id;
		ss << ".csv";
		return (ss.str());
	}
	string idArchivoRecibido() {
		ostringstream ss;
		ss << "./MailsRecibidos/";
		ss << id;
		ss << ".csv";
		return (ss.str());
	}
};