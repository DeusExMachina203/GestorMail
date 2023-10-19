#include "Clases.h"

using namespace std;

void principal(string usu, ListaUsuario<Usuario> &uLista, ListaRecibidos<Mail>* &mrLista, ListaEnviados<Mail>* &meLista, Usuario* &usX) {
	int op2;
	while (1) {
		do {
			system("cls");
			menuPrincipal();
			cout << "Ingresar opci�n: "; cin >> op2;
		} while (op2 < 1 || op2>4);
		string asunto, texto, nombreRemitente;
		Mail* mensaje;
		Usuario* remitente;
		stringstream nombreRemitenteStream(nombreRemitente);
		vector<Mail*> mostrador;
		switch (op2) {
		case 1:
			system("cls");
			Mail* elem1;
			int o1;
			mrLista->abrir(usX->idArchivoRecibido());
			// for (int i = 0; i < 5; i++) {
			// 	elem1 = mrLista->pop();
			// 	if (elem1 != NULL) cout << elem1->printMail() << endl;
			// }
			mostrador = listaAVector<ListaRecibidos<Mail>>(mrLista);
			if (mostrador.size() == 0) {
				cout << "No hay correos que mostrar, pulsa cualquier tecla para continuar..." << endl;
				cin.ignore();
				cin.get();
				break;
			}
			do {
				system("cls");
				menuOrd();
				cin >> o1;
			} while (o1 < 1 || o1>3 );
			switch (o1) {
			case 1:
				mostrador = ordenarTiempo(mostrador, ordenarTiempo);
				break;
			case 2:
				mostrador = ordenarAlfUsu(mostrador, ordenarAlfUsu);
				break;
			case 3:
				mostrador = ordenarAlfAsu(mostrador, ordenarAlfAsu);
				break;
			}
			for (int i = mostrador.size()-1; i >= 0; i--) {
				cout << mostrador[i]->printMail() << endl;
			}
			cin.ignore();
			cin.get();
			break;
		case 2:
			
			meLista->abrir(usX->idArchivoEnviado());
			mrLista->abrir(usX->idArchivoRecibido());
			system("cls");
			cout<< "Ingrese el usuario al que desea enviar el correo: " << endl;
			cin.ignore();
			getline(cin, nombreRemitente);
			cin.ignore();
			cout << "\nIngrese el asunto del correo que desea enviar:" << endl;
			getline(cin, asunto);
			cin.ignore();
			cout << "\nIngrese el texto del correo que desea enviar: " << endl;
			getline(cin, texto);
			mensaje = new Mail(asunto, texto, usu, nombreRemitente);
			remitente = new Usuario(nombreRemitente);
			if (uLista.busquedaId(new Usuario(nombreRemitente)) == "") {
				cout << "El usuario al que desea enviar el correo no existe" << endl;
				break;
			}
			meLista->push(mensaje);
			meLista->guardar(usX->idArchivoEnviado());
			mensaje->Enviar(uLista.busquedaId(remitente));
			break;
		case 3:
			system("cls");
			Mail* elem2;
			int o2;
			meLista->abrir(usX->idArchivoEnviado());
			
			mostrador = listaAVector<ListaEnviados<Mail>>(meLista);
			if (mostrador.size() == 0) {
				cout << "No hay correos que mostrar, pulsa cualquier tecla para continuar..." << endl;
				cin.ignore();
				cin.get();
				break;
			}
			do {
				system("cls");
				menuOrd();
				cin >> o1;
			} while (o1 < 1 || o1>3 );
			switch (o1) {
			case 1:
				mostrador = ordenarTiempo(mostrador, ordenarTiempo);
				break;
			case 2:
				mostrador = ordenarAlfUsu(mostrador, ordenarAlfUsu);
				break;
			case 3:
				mostrador = ordenarAlfAsu(mostrador, ordenarAlfAsu);
				break;
			}
			for (int i = mostrador.size()-1; i >= 0; i--) {
				cout << mostrador[i]->printMail() << endl;
			}
			cin.ignore();
			cin.get();
			break;
		case 4:
			return;
		}
	}
}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "spanish");
	system("cls");
	while (1) {
		cin.clear();
		ListaUsuario<Usuario> uLista;
		uLista.abrir();
		ListaRecibidos<Mail>* mrLista = new ListaRecibidos<Mail>();
		ListaEnviados<Mail>* meLista = new ListaEnviados<Mail>();
		int op1;
		logo();
		cin >> op1;
		if (op1 == 1) {
			string usu, pass;
			Usuario* us;
			do {
				system("cls");

				cout << "Recuerde no dejar ningun espacio!" << endl;
				cout << "Si desea regresar ingrese 1 en el apartado usuario." << endl;
				cout << "Ingrese su usuario: "; cin >> usu; cout << endl;
				if (usu == "1") continue;
				cout << "Ingrese su contrase�a: "; cin >> pass; cout << endl;
				us = new Usuario(usu, pass);

			} while (uLista.busqueda(us) == false);
			
			principal(usu, uLista, mrLista, meLista, us);
		}
		else if (op1 == 2) {
			system("cls");
			string usu, pass, passV;

			cout << "Recuerde no dejar ningun espacio!" << endl;
			cout << "Ingrese un usuario: "; cin >> usu; cout << endl;
			cout << "Ingrese una contrase�a: "; cin >> pass; cout << endl;
			cout << "Verifique su contrase�a: "; cin >> passV; cout << endl;
			Usuario* us = new Usuario(usu, pass);

			if (uLista.busqueda(us) == true) {
				cout << "\nEste usuario ya est� en uso." << endl;
				cout << "Presione cualquier tecla para continuar..." << endl;
				cin.get();
				cin.ignore();
				continue;
			}
			else if (pass == passV && !uLista.busqueda(us)) {
				uLista.insertar(us);
				uLista.guardar();
			}

			principal(usu, uLista, mrLista, meLista, us);
		}
		system("cls");
	}
	return 0;
}