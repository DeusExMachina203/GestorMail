using namespace std;

class Mail {
	string asunto, texto, emisor, remitente;
	//i want this class to store the time it was sent down to the second
	time_t hora = time(0);
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
	
	string getAsunto() { return this->asunto; }
	string getTexto() { return this->texto; }
	string getEmisor() { return this->emisor; }
	string getRemitente() { return this->remitente; }
	time_t getHora() { return this->hora; }
	void setAsunto(string asunto) { this->asunto = asunto; }
	void setTexto(string texto) { this->texto = texto; }
	void setEmisor(string emisor) { this->emisor = emisor; }
	void setRemitente(string remitente) { this->remitente = remitente; }

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