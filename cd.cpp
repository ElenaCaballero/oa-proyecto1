#include <iostream>
#include <stdio.h>
#include <fstream>  
using namespace std;

struct Ciudad{
  	int idCity;
	char city[40];
};

ostream& operator<<(ostream& output, const Ciudad& item){
	output << item.idCity << "\t" << item.city;
	return output;  
}
istream& operator>>(istream& input, Ciudad& item){
	 input >> item.idCity >> item.city;
	 return input;
}

int main(int argc, char const *argv[]){
	int cont;
	Ciudad item;
	ifstream file("ciudad.bin", ifstream::binary);
	while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
		
		cout << item << endl;
	}
	
	file.close();

	return 0;
}