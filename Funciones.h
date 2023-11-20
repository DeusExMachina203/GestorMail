auto generarId = [](){
    string id = "";
    int num;
    for (int i = 0; i < 6; i++) {
        num = rand() % 10;
        id += to_string(num);
    }
    return id;
};

template<class T>
auto comparar = [](T a, T b) {
    bool c = false;
    if (a == b) c = true;
    return c;
};

void imprimir(string e) {
    cout << " " << e << endl << endl;
}