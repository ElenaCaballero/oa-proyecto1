#include <iostream>
#include <stdio.h>
#include <fstream>  
using namespace std;

struct Cliente{
	char idCliente[20];
	char nombre[40];
	char genero;
	int idCity;
};

ostream& operator<<(ostream& output, const Cliente& item){
	output << item.idCliente << "\t" << item.nombre << "\t" << item.genero<< "\t" << item.idCity;
	return output;  
}
istream& operator>>(istream& input, Cliente& item){
	 input >> item.idCliente >> item.nombre >> item.genero >> item.idCity;
	 return input;
}

int main(int argc, char const *argv[]){
	int cont;
	Cliente item;
	ifstream file("cliente.bin", ifstream::binary);
	while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
		
		cout << item << endl;
	}
	
	file.close();

	return 0;
}