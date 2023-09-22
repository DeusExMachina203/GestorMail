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

	string getUsu() { return this->usu; }

	string getContra() { return this->contra; }	

	void setID(string id) { this->id = id; }

	string idArchivoEnviado() {
		ostringstream ss;
		ss << "//MailsEnviados//";
		ss << id;
		ss << ".cvs";
		return (ss.str());
	}
	string idArchivoRecibido() {
		ostringstream ss;
		ss << "//MailsRecibidos//";
		ss << id;
		ss << ".cvs";
		return (ss.str());
	}
};