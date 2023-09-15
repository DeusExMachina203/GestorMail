#include<iostream>
#include"Menu.h"
#include"ListaUsuario.h"
using namespace System;
using namespace std;

int main() {
	ListaUsuario<Usuario*> uLista;
	while (1) {
		int op1;
		logo();
		cin >> op1;
		if (op1 == 1) {
			do {
				Console::Clear();
				string usu, pass;

				cout << "Recuerde no dejar ningun espacio!" << endl;
				cout << "Si desea regresar ingrese 1 en el apartado usuario." << endl;
				cout << "Ingrese su usuario: "; cin >> usu; cout << endl;
				if (usu == '1') main();
				cout << "Ingrese su contrasena: "; cin >> pass; cout << endl;

			} while (uLista.busqueda(usu, pass) == false);
			menuPrincipal();
		}
		else if (op1 == 2) {
			string usu, pass, passV;

			cout << "Recuerde que los espacios tambien se consideran!" << endl;
			cout << "Ingrese un usuario: "; cin >> usu; cout << endl; 
			cout << "Ingrese una contrasena: "; cin >> pass; cout << endl;
			cout << "Verifique su contrasena: "; cin >> passV; cout << endl;

			if (pass == passV && uLista.busqueda(usu, pass) == false) {
				uLista.insertar(new Usuario(usu, pass));
			}
			menuPrincipal();
		}
		Console::Clear();
	}

	return 0;
}