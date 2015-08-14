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
   	infile.open("MOCK_DATA.txt"); 

   	ofstream outfile;
   	outfile.open("ciudad.bin", ifstream::binary);
 
    while(infile >> ciudad.idCity >> ciudad.city){
      outfile.write(reinterpret_cast<const char*> (&ciudad), sizeof(ciudad));
    }

	infile.close();
	outfile.close();

	return 0;
}