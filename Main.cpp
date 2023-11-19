#include "Clases.h"

using namespace std;

void principal(string usu, ListaUsuario<Usuario> &uLista, ListaRecibidos<Mail>* &mrLista, ListaEnviados<Mail>* &meLista, Usuario* &usX) {
	int op2;
	while (1) {
		do {
			system("cls");
			menuPrincipal();
			centrar("Ingresar opcion: "); cin >> op2;
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
				centrarTexto("No hay correos que mostrar, pulsa cualquier tecla para continuar...");
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
			centrarTexto("Ingrese el usuario al que desea enviar el correo: ");
			cin.ignore();
			getline(cin, nombreRemitente);
			cin.ignore();
			cout << endl;
			centrarTexto("Ingrese el asunto del correo que desea enviar:");
			getline(cin, asunto);
			cin.ignore();
			cout << endl;
			centrarTexto("Ingrese el texto del correo que desea enviar: ");
			getline(cin, texto);
			mensaje = new Mail(asunto, texto, usu, nombreRemitente);
			remitente = new Usuario(nombreRemitente);
			if (uLista.busquedaId(new Usuario(nombreRemitente)) == "") {
				centrarTexto("El usuario al que desea enviar el correo no existe");
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
				centrarTexto("No hay correos que mostrar, pulsa cualquier tecla para continuar...");
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
		HashTabla* ht = new HashTabla();
		uLista.abrir();
		int keys[uLista.cantidad()] = uLista.getKeys();
		ht->abrir();

		ListaRecibidos<Mail>* mrLista = new ListaRecibidos<Mail>();
		ListaEnviados<Mail>* meLista = new ListaEnviados<Mail>();
		int op1;
		logo();
		cin >> op1;
		switch(op1) {
		case 1:
			string usu, pass;
			int key;
			Usuario* us;
			do {
				system("cls");
				
				cout << endl;
				centrarTexto("Recuerde no dejar ningun espacio!");
				centrarTexto("Si desea regresar ingrese 1 en el apartado usuario.");
				centrar("Ingrese su usuario: "); cin >> usu; cout << endl;
				if (usu == "1") continue;
				centrar("Ingrese su contrasena: "); cin >> pass; cout << endl;
				key = ht->generarKey(pass);
				us = new Usuario(usu, to_string(key));

			} while (uLista.busqueda(us) == false && ht->buscar(key) != pass);
			
			principal(usu, uLista, mrLista, meLista, us);
			break;
		case 2:
			system("cls");
			string usu, pass, passV;

			cout << endl;
			centrarTexto("Recuerde no dejar ningun espacio!");
			centrar("Ingrese su usuario: "); cin >> usu; cout << endl;
			centrar("Ingrese su contrasena: "); cin >> pass; cout << endl;
			centrar("Verifique su contrasena: "); cin >> passV; cout << endl;
			int key = ht->generarKey(pass);
			Usuario* us = new Usuario(usu, to_string(key));

			if (uLista.busqueda(us) == true) {
				cout << endl;
				centrarTexto("Este usuario ya esta en uso.");
				centrarTexto("Presione cualquier tecla para continuar...");
				cin.get();
				cin.ignore();
				continue;
			}
			else if (pass == passV && !uLista.busqueda(us)) {
				uLista.insertar(us);
				uLista.guardar(keys[]);
				ht->insertar(key, pass);
				ht->guardar(uLista.cantidad());
			}

			principal(usu, uLista, mrLista, meLista, us);
			break;
		case 3:
			const int numDatos = 500;
			int key;
			Usuario* us;
			for (int i = 0; i < numDatos; i++) {
				key = ht->generarKey(generarContrasena());
				us = new Usuario(generarUsuario(), to_string(key));
				uLista.insertar(us);

			}

			Mail* mensaje;
			int numAzarUs, numAzarRem;
			for (int i = 0; i < numDatos; i++) {
				numAzarUs = rand() % (numDatos + 1);
				numAzarRem = rand() % (numDatos + 1);
				if (numAzarUs == numAzarRem) numAzarRem = rand() % (numDatos + 1);
				mensaje = new Mail(generarAsunto(), generarTexto(), uLista.usuarioAlAzar(numAzarUs), uLista.usuarioAlAzar(numAzarRem));
				meLista->push(mensaje);
				mensaje->Enviar(uLista.busquedaId(numAzarRem));
			}
		}
		system("cls");
	}
	return 0;
}