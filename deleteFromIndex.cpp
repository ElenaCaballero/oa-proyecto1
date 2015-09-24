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

ostream& operator<<(ostream& output, const Index& item){
	output << item.reference;
	return output;  
}

int menu();

int main(int argc, char const *argv[])
{
	int op = menu();
	if (op == 1){
		Index indexfile;
		ifstream file("indexClientes.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
			cout << indexfile << endl;
		}

		char id[20];
		cout << "Ingrese el índice a borrar" << endl;
		cin >> id;

		int count;
		
		while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
			cout << "wasup" << endl;
			if (strcmp(indexfile.key[count],id) == 0){
				cout << "wasup2" << endl;
				indexfile.key.erase (indexfile.key.begin()+indexfile.reference-1);
			}
			count++;
		}
		ofstream ifile;
		ifile.open("indexClientes.bin", ofstream::binary);

		ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));

		ifile.close();
		file.close();

	}else if (op == 2){
		char id[20];
		cout << "Ingrese el índice a borrar" << endl;
		cin >> id;

		int count;

		Index indexfile;
		ifstream file("indexLineas.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
			if (strcmp(indexfile.key.at(count),id) == 0){
				indexfile.key.erase (indexfile.key.begin()+indexfile.reference-1);
			}
			count++;
		}
		ofstream ifile;
		ifile.open("indexLineas.bin", ofstream::binary);

		ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));

		ifile.close();
		file.close();

	}else if (op == 3){
		char id[20];
		cout << "Ingrese el índice a borrar" << endl;
		cin >> id;

		int count;

		Index indexfile;
		ifstream file("indexCiudades.bin", ifstream::binary);
		while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
			if (strcmp(indexfile.key.at(count),id) == 0){
				indexfile.key.erase (indexfile.key.begin()+indexfile.reference-1);
			}
			count++;
		}
		ofstream ifile;
		ifile.open("indexCiudades.bin", ofstream::binary);

		ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));

		ifile.close();
		file.close();
		
	} else if (op <= 0 || op > 3){
		cout << "Ingrese una opcion existente" << endl;
		op = menu();
	}

	return 0;
}

int menu(){
	int op = 0;
	cout << "Seleccione el archivo a borrar un indice: " << endl;
	cout << "1. Clientes" << endl;
	cout << "2. Lineas Telefónicas" << endl;
	cout << "3. Ciudades" << endl;
	cin >> op;
	return op;
}
