#include "Clases.h"

using namespace std;

void principal(string usu, ListaUsuario<Usuario*> uLista, ListaRecibidos<Mail*>* mrLista, ListaEnviados<Mail*>* meLista, Usuario* usX) {
	int op2;
	while (1) {
		do {
			system("cls");
			menuPrincipal();
			cout << "Ingresar opcion: "; cin >> op2;
		} while (op2 < 1 || op2>4);
		string asunto, texto;
		switch (op2) {
		case 1:
			system("cls");
			Mail* elem1;
			int o1;
			mrLista->abrir(usX->idArchivoRecibido());
			for (int i = 0; i < 5; i++) {
				elem1 = mrLista->pop();
				if (elem1 != NULL) cout << elem1->printMail() << endl;
			}
			cout << "\nSi desea imprimir todos los correos presione 1, si quiere regresar presione cualquier tecla";
			cin >> o1;
			if (o1 == 1) {
				do {
					elem1 = mrLista->pop();
					if (elem1 != NULL) cout << elem1->printMail() << endl;
				} while (elem1 != NULL);
			}
			break;
		case 2:
			
			meLista->abrir(usX->idArchivoEnviado());
			system("cls");
			cout << "\nIngrese el asunto del correo que desea enviar:" << endl;
			cin >> asunto;
			cout << "\nIngrese el texto del correo que desea enviar: " << endl;
			cin >> texto;
			meLista->push(new Mail(asunto, texto, usu));
			meLista->guardar(usX->idArchivoEnviado());
			break;
		case 3:
			system("cls");
			Mail* elem2;
			int o2;
			meLista->abrir(usX->idArchivoEnviado());
			for (int i = 0; i < 5; i++) {
				elem2 = meLista->pop();
				if (elem2 != NULL) cout << elem2->printMail() << endl;
			}
			cout << "\nSi desea imprimir todos los correos presione 1, si quiere regresar presione cualquier tecla";
			cin >> o2;
			if (o2 == 1) {
				do {
					elem2 = meLista->pop();
					if (elem2 != NULL) cout << elem2->printMail() << endl;
				} while (elem2 != NULL);
			}
			break;
		case 4:
			return;
		}
	}
}

int main() {
	while (1) {
		cin.clear();
		ListaUsuario<Usuario*> uLista;
		uLista.abrir();
		ListaRecibidos<Mail*>* mrLista;
		ListaEnviados<Mail*>* meLista;
		int op1;
		logo();
		cin >> op1;
		if (op1 == 1) {
			string usu, pass;
			string idprovisional = "102430";
			Usuario* us;
			do {
				system("cls");

				cout << "Recuerde no dejar ningun espacio!" << endl;
				cout << "Si desea regresar ingrese 1 en el apartado usuario." << endl;
				cout << "Ingrese su usuario: "; cin >> usu; cout << endl;
				if (usu == "1") continue;
				cout << "Ingrese su contrasena: "; cin >> pass; cout << endl;
				us = new Usuario(usu, pass, idprovisional);

			} while (uLista.busqueda(us) == false);
			
			principal(usu, uLista, mrLista, meLista, us);
		}
		else if (op1 == 2) {
			system("cls");
			string usu, pass, passV;
			string idprovisional = "102431";

			cout << "Recuerde que los espacios tambien se consideran!" << endl;
			cout << "Ingrese un usuario: "; cin >> usu; cout << endl; 
			cout << "Ingrese una contrasena: "; cin >> pass; cout << endl;
			cout << "Verifique su contrasena: "; cin >> passV; cout << endl;
			Usuario* us = new Usuario(usu, pass, idprovisional);
			if (pass == passV && !uLista.busqueda(us)) {
				uLista.insertar(us);
				uLista.guardar();
			}

			principal(usu, uLista, mrLista, meLista, us);
		}
		system("cls");
	}
	return 0;
}