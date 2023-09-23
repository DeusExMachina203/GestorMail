using namespace std;

class Usuario {
	string usu, contra, id;
public:
	Usuario(string usu = "", string contra = "", string id = "") : usu(usu), contra(contra) {
		
	}
	string toString() {
		ostringstream ss;
		ss << usu;
		ss<< ",";
		ss << contra;
		ss << ",";
		ss << id;
		return (ss.str());
	}

	string getID() { return this->id; }

	void setUsu(string usu) { this->usu = usu; }

	string getUsu() { return this->usu; }

	void setContra(string contra) { this->contra = contra; }

	string getContra() { return this->contra; }	

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