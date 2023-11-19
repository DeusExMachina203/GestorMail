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
        "Reunión de equipo",
        "Actualización del proyecto",
        "Recordatorio de tarea",
        "Consulta sobre presupuesto",
        "Invitación a evento",
        "Propuesta de colaboración",
        "Solicitud de información",
        "Confirmación de reserva",
        "Felicitaciones por el logro",
        "Problema técnico a resolver",
        "Informe de progreso",
        "Planificación de eventos",
        "Feedback de cliente",
        "Anuncio de producto",
        "Nuevas oportunidades de negocio",
        "Actualización de políticas",
        "Solicitud de retroalimentación",
        "Novedades de la industria",
        "Propuesta de mejora",
        "Proyecto de investigación",
        "Recordatorio de reunión",
        "Oferta exclusiva",
        "Anuncio de webinar",
        "Informe financiero trimestral",
        "Solicitud de colaboración",
        "Felicitaciones por aniversario",
        "Revisión de desempeño",
        "Invitación a almuerzo",
        "Planificación de vacaciones",
        "Seguimiento de reclamación",
        "Presentación de nuevos empleados",
        "Encuesta de satisfacción",
        "Actualización de horarios",
        "Proyecto de voluntariado",
        "Inscripción a curso",
        "Agradecimiento por participación",
        "Reclutamiento de voluntarios",
        "Promoción de evento benéfico",
        "Actualización de términos de servicio",
        "Anuncio de jubilación",
        "Propuesta de proyecto comunitario",
        "Solicitud de testimonios",
        "Convocatoria a concurso",
        "Anuncio de cambios organizativos",
        "Invitación a sesión de networking",
        "Solicitud de donaciones",
        "Aviso de cierre de oficina",
        "Nuevos beneficios para empleados",
        "Anuncio de programa de capacitación",
        "Solicitud de entrevista",
        "Convocatoria a asamblea general",
        "Anuncio de promoción interna",
        "Invitación a seminario educativo",
        "Agradecimiento por colaboración",
        "Felicitaciones por hito alcanzado",
        "Propuesta de proyectos de responsabilidad social",
        "Recordatorio de fecha límite",
        "Anuncio de feria comercial",
        "Invitación a presentación de producto",
        "Informe de análisis de mercado"
    };

    string tema = temas[rand() % temas.size()];

    vector<string> prefijos = { "Importante: ", "Recordatorio: ", "Consulta: " };
    vector<string> sufijos = { " Urgente", " para tu revisión", " - Acción requerida" };

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