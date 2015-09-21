#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>  
using namespace std;

struct Index{
	std::vector<char*> key;
	std::vector<int> reference;
};

#pragma pack(push, r1, 1)
struct Cliente{
	char idCliente[20];
	char nombre[40];
	char genero;
	int idCity;
};
#pragma pack(pop, r1)

struct Lineas{
  	char numero[20];
	char idCliente[20];
};

struct Ciudad{
  	int idCity;
	char city[40];
};

/*ostream& operator<<(ostream& output, const Ciudad& item){
	output << item.idCity << "\t" << item.city;
	return output;  
}*/

ostream& operator<<(ostream& output, const Cliente& item){
	output << item.idCliente << "\t" << item.nombre << "\t" << item.genero<< "\t" << item.idCity;
	return output;  
}

/*ostream& operator<<(ostream& output, const Lineas& item){
	output << item.numero << "\t" << item.idCliente;
	return output;  
}*/

int menu();

int main(int argc, char const *argv[]){
	
	int op = menu();
	if (op == 1){
		Cliente item;
		ifstream file("cliente.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			
			cout << item << endl;	

		}

		file.close();
	}else if (op == 2){
		Lineas item;
		ifstream file("linea.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				
		}

		file.close();
	}else if (op == 3){
		Ciudad item;
		ifstream file("ciudad.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				
		}

		file.close();
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