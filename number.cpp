#include <iostream>
#include <stdio.h>
#include <fstream>  
using namespace std;

struct Lineas{
  	char numero[20];
	char idCliente[20];
};

int main(int argc, char const *argv[]){

	Lineas linea;

	ifstream infile; 
   	infile.open("MOCK_DATA-3.txt"); 

   	ifstream infile2;
   	infile2.open("mock.txt");

   	ofstream outfile;
   	outfile.open("linea.bin", ifstream::binary);
 
    while(infile >> linea.numero){
    	infile2 >> linea.idCliente;
      	outfile.write(reinterpret_cast<const char*> (&linea), sizeof(linea));
    }

	infile.close();
	infile2.close();
	outfile.close();

	return 0;
}