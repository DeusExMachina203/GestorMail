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

int generarKey(string pass) {
    int sum = 0;
    int key;
    for (char c : pass) { //se calcula la suma de los c�digos ascii de cada caracter en la contrasena
        sum += static_cast<int>(c);
    }
    key = ((sum * 17) / 5) % 500;
    return key;
}