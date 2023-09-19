#include<string>
#include<sstream>
#include<iostream>
using namespace std;

class Mail {
	string asunto, texto, emisor;
public:
	Mail(string asunto = '', string texto = '', string emisor = '') :asunto(asunto), texto(texto), emsior(emisor) {}
	string toString() {
		ostringstream ss;
		ss << asunto;
		ss << "&";
		ss << texto;
		ss << "&";
		ss << emisor;
		return (ss.str());
	}
	string printMail() {
		ostringstream ss;
		ss << "\nEnviado por: ";
		ss << emisor;
		ss << "\nAsunto: ";
		ss << asunto;
		ss << "\n";
		ss << texto;
		return (ss.str());
	}
};