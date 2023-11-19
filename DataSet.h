string generarUsuario() {
    vector<string> correos = { "gmail", "hotmail", "icloud" };

    string correo = correos[rand() % correos.size()];

    string parteAleatoria = "";
    for (int i = 0; i < 10; ++i) {
        parteAleatoria += 'a' + rand() % 26;
    }

    return parteAleatoria + "@" + correo + ".com";
}

string generarContrasena() {
    int longitud = rand() % 8 + 8;
    const string caracteresPermitidos = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    string contrasena;
    for (int i = 0; i < longitud; ++i) {
        contrasena += caracteresPermitidos[rand() % caracteresPermitidos.size()];
    }

    return contrasena;
}

string generarAsunto() {
    vector<string> temas = {
        "Reuni�n de equipo",
        "Actualizaci�n del proyecto",
        "Recordatorio de tarea",
        "Consulta sobre presupuesto",
        "Invitaci�n a evento",
        "Propuesta de colaboraci�n",
        "Solicitud de informaci�n",
        "Confirmaci�n de reserva",
        "Felicitaciones por el logro",
        "Problema t�cnico a resolver",
        "Informe de progreso",
        "Planificaci�n de eventos",
        "Feedback de cliente",
        "Anuncio de producto",
        "Nuevas oportunidades de negocio",
        "Actualizaci�n de pol�ticas",
        "Solicitud de retroalimentaci�n",
        "Novedades de la industria",
        "Propuesta de mejora",
        "Proyecto de investigaci�n",
        "Recordatorio de reuni�n",
        "Oferta exclusiva",
        "Anuncio de webinar",
        "Informe financiero trimestral",
        "Solicitud de colaboraci�n",
        "Felicitaciones por aniversario",
        "Revisi�n de desempe�o",
        "Invitaci�n a almuerzo",
        "Planificaci�n de vacaciones",
        "Seguimiento de reclamaci�n",
        "Presentaci�n de nuevos empleados",
        "Encuesta de satisfacci�n",
        "Actualizaci�n de horarios",
        "Proyecto de voluntariado",
        "Inscripci�n a curso",
        "Agradecimiento por participaci�n",
        "Reclutamiento de voluntarios",
        "Promoci�n de evento ben�fico",
        "Actualizaci�n de t�rminos de servicio",
        "Anuncio de jubilaci�n",
        "Propuesta de proyecto comunitario",
        "Solicitud de testimonios",
        "Convocatoria a concurso",
        "Anuncio de cambios organizativos",
        "Invitaci�n a sesi�n de networking",
        "Solicitud de donaciones",
        "Aviso de cierre de oficina",
        "Nuevos beneficios para empleados",
        "Anuncio de programa de capacitaci�n",
        "Solicitud de entrevista",
        "Convocatoria a asamblea general",
        "Anuncio de promoci�n interna",
        "Invitaci�n a seminario educativo",
        "Agradecimiento por colaboraci�n",
        "Felicitaciones por hito alcanzado",
        "Propuesta de proyectos de responsabilidad social",
        "Recordatorio de fecha l�mite",
        "Anuncio de feria comercial",
        "Invitaci�n a presentaci�n de producto",
        "Informe de an�lisis de mercado"
    };

    string tema = temas[rand() % temas.size()];

    vector<string> prefijos = { "Importante: ", "Recordatorio: ", "Consulta: " };
    vector<string> sufijos = { " Urgente", " para tu revisi�n", " - Acci�n requerida" };

    string asunto = prefijos[rand() % prefijos.size()] + tema + sufijos[rand() % sufijos.size()];

    return asunto;
}

string generarTexto() {
    const string loremIpsumBase = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur tempus, lectus sit amet malesuada tincidunt, erat dolor commodo sem, eget fringilla ex ex vitae purus. Proin congue eget quam a dictum. Aliquam suscipit lobortis nisl eget vestibulum. Ut faucibus arcu nibh, et vehicula tellus viverra sit amet. Etiam quis nunc leo. Nulla dignissim luctus justo scelerisque tincidunt. Phasellus arcu nisl, rutrum a purus eu, porta.";

    vector<std::string> palabras;
    istringstream iss(loremIpsumBase);
    do {
        string palabra;
        iss >> palabra;
        palabras.push_back(palabra);
    } while (iss);

    int longitudDeseada = rand() % 21 + 40;

    string loremIpsum = "Lorem Ipsum";
    for (int i = 0; i < longitudDeseada; ++i) {
        loremIpsum += " " + palabras[rand() % palabras.size()];
    }

    return loremIpsum;
}