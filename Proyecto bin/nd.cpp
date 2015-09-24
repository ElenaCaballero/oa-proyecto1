#include <iostream>
#include <stdio.h>
#include <fstream>  
using namespace std;

struct Lineas{
  	char numero[20];
	char idCliente[20];
};

ostream& operator<<(ostream& output, const Lineas& item){
	output << item.numero << "\t" << item.idCliente;
	return output;  
}
istream& operator>>(istream& input, Lineas& item){
	 input >> item.numero >> item.idCliente;
	 return input;
}

int main(int argc, char const *argv[]){
	int cont;
	Lineas item;
	ofstream out;
	out.open("lineas.txt");
	ifstream file("linea.bin", ifstream::binary);
	while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
		out << item << "\n";
		cout << item << endl;
	}
	
	out.close();
	file.close();

	return 0;
}