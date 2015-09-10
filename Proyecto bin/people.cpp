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

int main(int argc, char const *argv[]){

	Cliente persona;
	char data[20];

	ifstream infile; 
   	infile.open("MOCK_DATA-2.txt"); 

   	ifstream infile2;
   	infile2.open("mock.txt");

   	ifstream infile3;
   	infile3.open("MOCK_DATA.txt");

   	ofstream outfile;
   	outfile.open("cliente.bin", ifstream::binary);
 
    while(infile3 >> persona.idCity >> data){
    	infile3 >> persona.idCity >> data;
    	while(infile >> persona.nombre >> persona.genero){
    		infile2 >> persona.idCliente;
    		outfile.write(reinterpret_cast<const char*> (&persona), sizeof(persona));
    	}
    }

	infile.close();
	infile2.close();
	infile3.close();
	outfile.close();

	return 0;
}