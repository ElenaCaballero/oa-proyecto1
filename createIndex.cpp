#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>  
#include <sstream>
#include <string>
using namespace std;

struct Index{
	std::vector<char*> key;		//vector de llaves
	std::vector<int> reference;		//vector de referencias
};

struct Cliente{
	char idCliente[20];
	char nombre[40];
	char genero;
	int idCity;
};

struct linea_cliente{
  	char num[20];
	char id_cliente[20];
};

struct Ciudad{
  	int id;
	char nombre[40];
};

ostream& operator<<(ostream& output, const Ciudad& item){
	output << item.id << "\t" << item.nombre;
	return output;  
}

ostream& operator<<(ostream& output, const Cliente& item){
	output << item.idCliente << "\t" << item.nombre << "\t" << item.genero<< "\t" << item.idCity;
	return output;  
}

ostream& operator<<(ostream& output, const linea_cliente& item){
	output << item.num << "\t" << item.id_cliente;
	return output;  
}

int menu();

int main(int argc, char const *argv[]){
	Index indexfile;
	ofstream ifile;
	ifile.open("index.bin", ofstream::binary);

	int count = 1;
	int op = menu();
	if (op == 1){
		Cliente item;
		ifstream file("cliente.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			//cout << item.idCliente << endl;	
			indexfile.key.push_back(item.idCliente);
			indexfile.reference.push_back(count);
			count++;
		}
		for (const auto& e : indexfile.reference)
		  	std::cout << e << endl;
		std::cout << std::endl;

		file.close();
	}else if (op == 2){
		linea_cliente item;
		ifstream file("linea.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			//cout << item << endl;	
			indexfile.key.push_back(item.num);
			indexfile.reference.push_back(count);
			count++;
		}
		for (const auto& e : indexfile.key)
		  	std::cout << e << endl;
		std::cout << std::endl;

		file.close();
	}else if (op == 3){
		Ciudad item;
		ifstream file("ciudad.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			//cout << item << endl;
			//indexfile.key.push_back(item.id);	
			indexfile.reference.push_back(count);
			count++;
		}
		for (const auto& e : indexfile.key)
		  	std::cout << e << endl;
		std::cout << std::endl;

		file.close();
	} else if (op <= 0 || op > 3){
		cout << "Ingrese una opcion existente" << endl;
		op = menu();
	}

	ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile)); // insertando los indices al archivo de indices

	ifile.close();
	
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
