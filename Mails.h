#include<string>
#include<sstream>
using namespace std;

class Mails {
	string asunto, texto, emisor;
public:
	Mails(string asunto = '', string texto = '', string emisor = '') :asunto(asunto), texto(texto), emsior(emisor) {}
	string toString() {
		ostringstream ss;
		ss << asunto;
		ss << "&";
		ss << texto;
		ss << "&";
		ss << emisor;
		return (ss.str());
	}
};