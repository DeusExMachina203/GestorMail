using namespace std;

class Mail {
	string asunto, texto, emisor, remitente;
public:
	Mail(string asunto = "", string texto = "", string emisor = "", string remitente = "") :asunto(asunto), texto(texto), emisor(emisor), remitente(remitente) {}
	string toString() {
		ostringstream ss;
		ss << asunto;
		ss << "&";
		ss << texto;
		ss << "&";
		ss << emisor;
		ss << "&";
		ss << remitente;
		return (ss.str());
	}
	string printMail() {
		ostringstream ss;
		ss << "\nEnviado por: ";
		ss << emisor;
		ss << "\nPara: ";
		ss << remitente;
		ss << "\nAsunto: ";
		ss << asunto;
		ss << "\n";
		ss << texto;
		return (ss.str());
	}
	void Enviar(string remitente) {
		ofstream archivo;
		string nombreArchivo = "./MailsRecibidos/" + remitente + ".csv";
		archivo.open(nombreArchivo, ios::app);
		if (archivo.fail()) {
			cout << "\nNo se pudo abrir el archivo";
			exit(1);
		}
		archivo << toString() << endl;
		archivo.close();
	}
};