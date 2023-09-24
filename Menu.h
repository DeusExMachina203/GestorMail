using namespace std;

/*void logo() {
	cout << "	 ▄████████   ▄▄▄▄███▄▄▄▄      ▄████████  ▄█   ▄█" << endl;
	cout << "	███    ███ ▄██▀▀▀███▀▀▀██▄   ███    ███ ███  ███" << endl;
	cout << "	███    █▀  ███   ███   ███   ███    ███ ███▌ ███" << endl;
	cout << "  ▄███▄▄▄     ███   ███   ███   ███    ███ ███▌ ███" << endl;
	cout << " ▀▀███▀▀▀     ███   ███   ███ ▀███████████ ███▌ ███" << endl;
	cout << "	███        ███   ███   ███   ███    ███ ███  ███" << endl;
	cout << "	███        ███   ███   ███   ███    ███ ███  ███▌    ▄" << endl;
	cout << "	███         ▀█   ███   █▀    ███    █▀  █▀   █████▄▄██" << endl;
	cout << "											     ▀" << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "						Bienvenido!!" << endl;
	cout << "Seleccione una opción: " << endl;
	cout << "1. Iniciar Sesión" << endl;
	cout << "2. Crear una cuenta" << endl;
}*/

void logo() {
	cout << "	######## ##     ##    ###    #### ##" << endl;
	cout << "	##       ###   ###   ## ##    ##  ##" << endl;
	cout << "	##       #### ####  ##   ##   ##  ##" << endl;
	cout << "	######   ## ### ## ##     ##  ##  ##" << endl;
	cout << "	##       ##     ## #########  ##  ##" << endl;
	cout << "	##       ##     ## ##     ##  ##  ##" << endl;
	cout << "	##       ##     ## ##     ## #### ########" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "				  Bienvenido!!" << endl;
	cout << "Seleccione una opción: " << endl;
	cout << "1. Iniciar Sesión" << endl;
	cout << "2. Crear una cuenta" << endl;
}

void menuPrincipal() {
	cout << "Elija una de las sguientes opciones:" << endl;
	cout << "1. Revisar Correos" << endl;
	cout << "2. Enviar un Correo" << endl;
	cout << "3. Ver Correos Enviados" << endl;
	cout << "4. Cerrar Sesión" << endl;
}

void menuOrd() {
	cout << "Como desea ordenar los correos: " << endl;
	cout << "1. Por tiempo" << endl;
	cout << "2. Por orden alfabético del usuario" << endl;
	cout << "3. Por orden alfabético del asunto" << endl;
	cout << "Ingrese su opción: ";
}