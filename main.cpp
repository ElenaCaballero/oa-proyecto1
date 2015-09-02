#include <stdio.h>
#include <iostream>
#include <fstream> 
#include <time.h>


using namespace std;

struct cliente{
    char id [13];
	char nombre[4];
	char id_cuidad [13];
	char gender;
};

struct linea_cliente{
    char num [8];
	char id_cliente [13];		
};

struct llamada{
    char  num [8];
	char inicio [40];
	char final [40];
	char destino[40];	
};


struct cuidad{
    char id [13];
	char nombre[40];
};

//Modificar parametros
/*ostream& operator<<(ostream& output, const Item& item){
	output << item.name << "\t" << item.id << "\t" << item.price << "\t" << item.quantity << "\t" << item.available << "\t" << item.margin << endl;
	return output;  
}
istream& operator>>(istream& input, Item& item){
	 input >> item.name >> item.id >> item.price >> item.quantity >> item.available >> item.margin;
	 return input;
}*/

llamada Llamada();
cliente leer_cliente();
cuidad leer_cuidad();

int main(int argc, char *argv[]){
	llamada call;
	call = Llamada();

	ofstream outfile;
   	outfile.open("llamada.bin", ifstream::binary);
 
    while(cont < ){
      	outfile.write(reinterpret_cast<const char*> (&call), sizeof(call));
    }

    outfile.close();

	return 0;
}

llamada Llamada(){
	llamada call;
	srand(time(0));

	ifstream read_date; // lee las fechas y para no llenar la memoria con el random solo guarda el que necesita 
	read_date.open("fecha.txt");
	//nume random
	int num=rand()%62; 
	char date[8];
	int cont=0;
	while(!read_date.eof()){
		cont++;
		if (num==cont)
		{
			read_date >> date; 
		}

	}
	read_date.close();


	ifstream read_time; // lee las horas  y guarda 2  
	read_time.open("hora.txt");
	//nume random
	int numa = rand()%156; 
	char tiempo1[6];
	char tiempo2[6];
	int conta=0;
	while(!read_time.eof()){
		cont++;
		if (numa==conta)
		{
			read_time >> tiempo1; 
		}else if (numa==conta+1)
		{
			read_time >> tiempo2; 
		}

	}
	read_time.close();

	char* llin = new char[strlen(date)+ strlen(tiempo1) + 1];
	char* llfin = new char[strlen(date)+ strlen(tiempo1) + 1];

	strcpy(llin, date);
	strcat(llin, tiempo1);

	//call.inicio = llin;
	strcpy(call.inicio, llin);

	strcpy(llfin, date);
	strcat(llfin, tiempo2);

	//call.final = llfin;
	strcpy(call.final, llfin);

	ifstream read_city; // guarda la cuidad
	read_city.open("MOCK_DATA.txt");
	//nume random
	int nume=rand()%100; 
	char city[40];
	int x;
	int conte=0;
	while(!read_city.eof()){
		cont++;
		if (nume==conte)
		{
			read_city >> x >> call.destino; 
		}

	}
	read_city.close();



	ifstream read_number; // guarda el numero
	read_number.open("MOCK_DATA-3.txt");
	//nume random
	int numero=rand()%100; 

	int contador=0;
	while(!read_number.eof()){
		cont++;
		if (numero==contador)
		{
			read_number >> call.num; 
		}
	}
	read_number.close();

	return call;
}


cliente leer_cliente(){
	ifstream read_person; // lee lel archivo de texto , nose como lo guardas ahi solo lo modificas
	read_person.open("cliente.txt");
	//nume random
	cliente person;
	while(!read_person.eof()){
		read_person >> person.id >> person.nombre >> person.id_cuidad >> person.gender;
	}
	// si queres aqui lo podes poner de un solo a que escriba en bin
		return person;

	
	read_person.close();
}


cuidad leer_cuidad(){
	ifstream read_city; // lee lel archivo de texto , nose como lo guardas ahi solo lo modificas
	read_city.open("cuidad.txt");
	
	cuidad city;
	while(!read_city.eof()){
		read_city >> city.id >> city.nombre ;
		}
	// si queres aqui lo podes poner de un solo a que escriba en bin
		return city;

	
	read_city.close();
}
