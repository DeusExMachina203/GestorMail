#include<string>
#include<sstream>
#include<iostream>
using namespace std;

class Usuario {
	string usu, contra;
public:
	Usuario(string usu = '', string contra = '') : usu(usu), contra(contra) {}
};