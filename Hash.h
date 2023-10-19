class Hash {
private:
	int key;
	int value;
public:
	Hash(int key, int value) {
		this->key = key;
		this->value = value;
	}
	int getKey() { return key; }
	int getValue() { return value; }
};