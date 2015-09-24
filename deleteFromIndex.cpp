#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>  
#include <sstream>
#include <string>
using namespace std;

struct Index{
	std::vector<char*> key;		//vector de llaves
	int reference;		//referencia
};

ostream& operator<<(ostream& output, const Index& item){
	output << item.key << "\t" << item.reference;
	return output;  
}

int menu();

int main(int argc, char const *argv[])
{
	int op = menu();
	if (op == 1){
		
	}else if (op == 2){
		
	}else if (op == 3){
		
	} else if (op <= 0 || op > 3){
		cout << "Ingrese una opcion existente" << endl;
		op = menu();
	}

	return 0;
}

int menu(){
	int op = 0;
	cout << "Seleccione el archivo a indexar: " << endl;
	cout << "1. Clientes" << endl;
	cout << "2. Lineas Telefónicas" << endl;
	cout << "3. Ciudades" << endl;
	cin >> op;
	return op;
}
