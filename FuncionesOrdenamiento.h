//crea una funcion que coloque todos los elementos de una lista en un vector
template<class T>
auto listaAVector = [](T* lista) {
    //asegurate de que la lista no esta vacia
    vector<Mail*> vacio = {};
    if (lista->estaVacia()) return vacio;
    vector<Mail*> v;
    Mail* elem;
    elem = lista->pop();
    while (elem != NULL) {
        v.push_back(elem);
        elem = lista->pop();
    }
    return v;
};

//crea una funcion que coloque todos los elementos de la lista en un vector y luego los ordene por tiempo con Mergesort
auto ordenarTiempo = [](vector<Mail*> v, auto&& ordenarTiempo) {
    if (v.size() == 1) return v;
    else {
        vector<Mail*> v1, v2;
        for (int i = 0; i < v.size() / 2; i++) {
            v1.push_back(v[i]);
        }
        for (int i = v.size() / 2; i < v.size(); i++) {
            v2.push_back(v[i]);
        }
        v1 = ordenarTiempo(v1, ordenarTiempo);
        v2 = ordenarTiempo(v2, ordenarTiempo);
        vector<Mail*> v3;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i]->getHora() > v2[j]->getHora()) {
                v3.push_back(v1[i]);
                i++;
            }
            else {
                v3.push_back(v2[j]);
                j++;
            }
        }
        while (i < v1.size()) {
            v3.push_back(v1[i]);
            i++;
        }
        while (j < v2.size()) {
            v3.push_back(v2[j]);
            j++;
        }
        return v3;
    }
};

//crea una funcion que coloque todos los elementos de la lista en un vector y luego los ordene por orden alfabetico con QuickSort
auto ordenarAlfAsu = [](vector<Mail*> v, auto&& ordenarAlfAsu) {
    if (v.size() == 1) return v;
    else {
        vector<Mail*> v1, v2;
        for (int i = 0; i < v.size() / 2; i++) {
            v1.push_back(v[i]);
        }
        for (int i = v.size() / 2; i < v.size(); i++) {
            v2.push_back(v[i]);
        }
        v1 = ordenarAlfAsu(v1, ordenarAlfAsu);
        v2 = ordenarAlfAsu(v2, ordenarAlfAsu);
        vector<Mail*> v3;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i]->getAsunto() < v2[j]->getAsunto()) {
                v3.push_back(v1[i]);
                i++;
            }
            else {
                v3.push_back(v2[j]);
                j++;
            }
        }
        while (i < v1.size()) {
            v3.push_back(v1[i]);
            i++;
        }
        while (j < v2.size()) {
            v3.push_back(v2[j]);
            j++;
        }
        return v3;
    }
};

//crea una funcion que coloque todos los elementos de la lista en un vector y luego los ordene por orden alfabetico del nombre de usuario con QuickSelect
auto ordenarAlfUsu = [](vector<Mail*> v, auto&& ordenarAlfUsu) {
    if (v.size() == 1) return v;
    else {
        vector<Mail*> v1, v2;
        for (int i = 0; i < v.size() / 2; i++) {
            v1.push_back(v[i]);
        }
        for (int i = v.size() / 2; i < v.size(); i++) {
            v2.push_back(v[i]);
        }
        v1 = ordenarAlfUsu(v1, ordenarAlfUsu);
        v2 = ordenarAlfUsu(v2, ordenarAlfUsu);
        vector<Mail*> v3;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i]->getEmisor() < v2[j]->getEmisor()) {
                v3.push_back(v1[i]);
                i++;
            }
            else {
                v3.push_back(v2[j]);
                j++;
            }
        }
        while (i < v1.size()) {
            v3.push_back(v1[i]);
            i++;
        }
        while (j < v2.size()) {
            v3.push_back(v2[j]);
            j++;
        }
        return v3;
    }
};
