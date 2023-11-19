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

void centrarTexto(const string& texto) {
	int anchoConsola = 120;
	int margenIzquierdo = (anchoConsola - texto.length()) / 2;
	for (int i = 0; i < margenIzquierdo; i++) {
		cout << " ";
	}
	cout << texto << endl;
}

void centrar(const string& texto) {
	int anchoConsola = 120;
	int margenIzquierdo = (anchoConsola - texto.length()) / 2;
	for (int i = 0; i < margenIzquierdo; i++) {
		cout << " ";
	}
	cout << texto;
}

void logo() {
	cout << endl;
	centrarTexto("######## ##     ##    ###    #### ##      ");
	centrarTexto("##       ###   ###   ## ##    ##  ##      ");
	centrarTexto("##       #### ####  ##   ##   ##  ##      ");
	centrarTexto("######   ## ### ## ##     ##  ##  ##      ");
	centrarTexto("##       ##     ## #########  ##  ##      ");
	centrarTexto("##       ##     ## ##     ##  ##  ##      ");
	centrarTexto("##       ##     ## ##     ## #### ########");
	centrarTexto("-------------------------------------------------");
	centrarTexto("Bienvenido!!");
	centrarTexto("Seleccione una opcion: ");
	centrarTexto("1. Iniciar Sesion");
	centrarTexto("2. Crear una cuenta");
	centrarTexto("3. Generar Datos");
}

void menuPrincipal() {
	cout << endl;
	centrarTexto("Elija una de las sguientes opciones:");
	cout << endl;
	centrarTexto("1. Revisar Correos");
	centrarTexto("2. Enviar un Correo");
	centrarTexto("3. Ver Correos Enviados");
	centrarTexto("4. Cerrar Sesion");
}

void menuOrd() {
	cout << endl;
	centrarTexto("Como desea ordenar los correos: ");
	cout << endl;
	centrarTexto("1. Por tiempo");
	centrarTexto("2. Por orden alfabetico del usuario");
	centrarTexto("3. Por orden alfabetico del asunto");
	centrarTexto("Ingrese su opcion: ");
}