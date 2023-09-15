#include<iostream>
#include"Menu.h"
#include"ListaUsuario.h"
#include<cstdlib>
using namespace std;

int main() {
	ListaUsuario<Usuario*> uLista;
	uLista.abrir();
	while (1) {
		int op1;
		logo();
		cin >> op1;
		if (op1 == 1) {
			do {
				system(cls);
				string usu, pass;

				cout << "Recuerde no dejar ningun espacio!" << endl;
				cout << "Si desea regresar ingrese 1 en el apartado usuario." << endl;
				cout << "Ingrese su usuario: "; cin >> usu; cout << endl;
				if (usu == '1') main();
				cout << "Ingrese su contrasena: "; cin >> pass; cout << endl;

			} while (uLista.busqueda(usu, pass) == false);
			
			int op2;
			do {
				menuPrincipal();
				cout << "Ingresar opción: "; cin >> op2;
				switch (op2) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					main();
					break;
				}
				system(cls);
			} while (op < 1 || op>3);
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

			int op2;
			do {
				menuPrincipal();
				cout << "Ingresar opción: "; cin >> op2;
				switch (op2) {
				case 1:
					break;
				case 2:
					break;
				case 3:
					main();
					break;
				}
				system(cls);
			} while (op < 1 || op>3);
		}
		system(cls);
	}

	return 0;
}