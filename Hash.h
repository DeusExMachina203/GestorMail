class Hash {
private:
	int key;
	string value;
public:
	Hash(int key, string value) {
		this->key = key;
		this->value = value;
	}
	Hash* siguiente = nullptr;
	int getKey() { return key; }
	string getValue() { return value; }
};
