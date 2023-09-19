using namespace std;

class Usuario {
	string usu, contra, id;
public:
	Usuario(string usu = "", string contra = "", string id = "") : usu(usu), contra(contra), id(id) {}
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
};