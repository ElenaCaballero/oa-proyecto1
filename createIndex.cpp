#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>  
#include <sstream>
#include <string>
using namespace std;

struct Index{
	std::vector<char*> key;		//vector de llaves
	int reference;		//vector de referencias

	bool operator < (const Index& str) const
    {
        return (key < str.key);
    }
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
	
	int count = 1;
	int op = menu();
	if (op == 1){
		Index indexfile;

		ofstream ifile;
		ifile.open("indexClientes.bin", ofstream::binary);

		Cliente item;
		ifstream file("cliente.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			indexfile.key.push_back(item.idCliente);
			indexfile.reference = count;
			count++;

			std::sort(indexfile.key.begin(), indexfile.key.end());

			ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));
		}

		file.close();
		ifile.close();
	}else if (op == 2){
		Index indexfile;

		ofstream ifile;
		ifile.open("indexLineas.bin", ofstream::binary);

		linea_cliente item;
		ifstream file("linea.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			indexfile.key.push_back(item.num);
			indexfile.reference = count;
			count++;
			std::sort(indexfile.key.begin(), indexfile.key.end());

			ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile)); 
		}

		file.close();
		ifile.close();
	}else if (op == 3){
		Index indexfile;

		ofstream ifile;
		ifile.open("indexCiudades.bin", ofstream::binary);

		Ciudad item;
		ifstream file("ciudad.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
			//indexfile.key.push_back(item.id);	
			indexfile.reference = count;
			count++;

			std::sort(indexfile.key.begin(), indexfile.key.end());

			ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile)); 
		}

		file.close();
		ifile.close();
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
