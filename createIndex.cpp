#include <iostream>
#include <stdio.h>
#include <fstream>  
using namespace std;

struct Index{
	std::vector<char*> key;
	std::vector<int> reference;
};

struct Cliente{
	char idCliente[20];
	char nombre[40];
	char genero;
	int idCity;
};

struct Lineas{
  	char numero[20];
	char idCliente[20];
};

struct Ciudad{
  	int idCity;
	char city[40];
};

int menu();

int main(int argc, char const *argv[]){
	ifstream file;
	int op = menu();
	if (op == 1){
		Cliente item;
		file.open("cliente.bin", ifstream::binary);

	}else if (op == 2){
		Lineas item;
		file.open("linea.bin", ifstream::binary);

	}else if (op == 3){
		Ciudad item;
		file.open("ciudad.bin", ifstream::binary);
		
	} else if (op <= 0 || op > 3){
		cout << "Ingrese una opcion existente";
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