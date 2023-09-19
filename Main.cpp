#include<iostream>
#include"Menu.h"
#include"ListaEnviados.h"
#include"ListaUsuario.h"
#include"ListaRecibidos.h"
#include<cstdlib>
using namespace std;

void principal(string usu, ListaUsuario<Usuario*> uLista, ListaRecibidos<Mail*>* mrLista, ListaEnviados<Mail*>* meLista) {
	int op2;
	while (1) {
		do {
			system(cls);
			menuPrincipal();
			cout << "Ingresar opcion: "; cin >> op2;
		} while (op < 1 || op>4);
		switch (op2) {
		case 1:
			system(cls);
			Mail* elem1;
			int o1;
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
			system(cls);
			string asunto, texto;
			cout << "\nIngrese el asunto del correo que desea enviar:" << endl;
			cin >> asunto;
			cout << "\nIngrese el texto del correo que desea enviar: " << endl;
			cin >> texto;
			meLista->push(new Mail(asunto, texto, usu));
			break;
		case 3:
			system(cls);
			Mail* elem2;
			int o2;
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
			uLista.guardar();
			main();
			break;
		}
	}
}

int main() {
	while (1) {
		ListaUsuario<Usuario*> uLista;
		uLista.abrir();
		ListaRecibidos<Mail*>* mrLista;
		ListaEnviados<Mail*>* meLista;
		int op1;
		logo();
		cin >> op1;
		if (op1 == 1) {
			string usu, pass;
			string idprovisional = '102430';
			do {
				system(cls);

				cout << "Recuerde no dejar ningun espacio!" << endl;
				cout << "Si desea regresar ingrese 1 en el apartado usuario." << endl;
				cout << "Ingrese su usuario: "; cin >> usu; cout << endl;
				if (usu == '1') main();
				cout << "Ingrese su contrasena: "; cin >> pass; cout << endl;

			} while (uLista.busqueda(Usuario*(usu, pass, idprovisional)) == false);
			
			principal(usu, uLista, mrLista, meLista);
		}
		else if (op1 == 2) {
			system(cls);
			string usu, pass, passV;
			string idprovisional = '102431';

			cout << "Recuerde que los espacios tambien se consideran!" << endl;
			cout << "Ingrese un usuario: "; cin >> usu; cout << endl; 
			cout << "Ingrese una contrasena: "; cin >> pass; cout << endl;
			cout << "Verifique su contrasena: "; cin >> passV; cout << endl;

			if (pass == passV && uLista.busqueda(usu, pass) == false) {
				uLista.insertar(new Usuario(usu, pass, idprovisional));
			}

			principal(usu, uLista, mrLista, meLista);
		}
		system(cls);
		uLista.guardar();
	}
	return 0;
}