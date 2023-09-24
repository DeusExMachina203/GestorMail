using namespace std;

void logo() {
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
	cout << "Seleccione una opcion: " << endl;
	cout << "1. Iniciar Sesion" << endl;
	cout << "2. Crear una cuenta" << endl;
}

void menuPrincipal() {
	cout << "Elija una de las sguientes opciones:" << endl;
	cout << "1. Revisar Correos" << endl;
	cout << "2. Enviar un Correo" << endl;
	cout << "3. Ver Correos Enviados" << endl;
	cout << "4. Cerrar Sesion" << endl;
}

void menuOrd() {
	cout << "Como desea ordenar los correos: " << endl;
	cout << "1. Por tiempo" << endl;
	cout << "2. Por orden alfabetico del usuario" << endl;
	cout << "3. Por orden alfabetico del asunto" << endl;
	cout << "Ingrese su opcion: ";
}