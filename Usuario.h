using namespace std;

class Usuario {
	string usu, pass, id;
public:
	Usuario(string usu = "", string pass = "", string id = "") : usu(usu), pass(pass) {
		
	}
	string toString() {
		ostringstream ss;
		ss << usu;
		ss<< ",";
		ss << pass;
		ss << ",";
		ss << id;
		return (ss.str());
	}

	string getID() { return this->id; }

	void setUsu(string usu) { this->usu = usu; }

	string getUsu() { return this->usu; }

	void setID(string id) { this->id = id; }

	string getPass() { return this->pass; }

	void setPass(string pass) { this->pass = pass; }

	int getKey() { return generarKey(pass); }

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