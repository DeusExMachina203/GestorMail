auto generarId = [](){
    string id = "";
    int num;
    for (int i = 0; i < 6; i++) {
        num = rand() % 10;
        id += to_string(num);
    }
    return id;
};