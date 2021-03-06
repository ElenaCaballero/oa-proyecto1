#include <iostream>
#include <stdio.h>
#include <fstream>  
using namespace std;

struct Ciudad{
  	int idCity;
	char city[40];
};

int main(int argc, char const *argv[]){

	Ciudad ciudad;
	char data[20];

	ifstream infile; 
   	infile.open("ciudades.txt"); 

   	ofstream outfile;
   	outfile.open("ciudad.bin", ifstream::binary);
 
    for(int i = 0; i<30; i++){
    	infile >> ciudad.idCity >> ciudad.city;
      outfile.write(reinterpret_cast<const char*> (&ciudad), sizeof(ciudad));
    }

	infile.close();
	outfile.close();

	return 0;
}