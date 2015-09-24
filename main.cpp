#include <stdio.h>
#include <iostream>
#include <fstream> 
#include <time.h>


using namespace std;


struct cliente{
	    char id [20];
		char nombre[40];
		char gender;
		int id_cuidad;
	};

	struct linea_cliente{
		char num [8];
		char id_cliente [13];
		
	};

	struct llamada{
		char  num [8];
		char inicio [15];
		char final [15];
		char destino[40];
		
	};


	struct cuidad{
		int id ;
		char nombre[40];
		
	};


/*ostream& operator<<(ostream& output, const Item& item){
	output << item.name << "\t" << item.id << "\t" << item.price << "\t" << item.quantity << "\t" << item.available << "\t" << item.margin << endl;
	return output;  
}
istream& operator>>(istream& input, Item& item){
	 input >> item.name >> item.id >> item.price >> item.quantity >> item.available >> item.margin;
	 return input;
}*/
	 int menu();
	 int menu2();
	 int main(int argc, char *argv[]){
	 	bool flag = true;
	 	while (flag)
	 	{
	 		switch(menu())
	 		{
		           case 1: // Clientes
		           			switch(menu2()){
		           					case 1: // Agregar
		           					cliente cliente1;
		           					cout<< "Ingrese ID, nombre, ID cuidad, genero , separados por espacio"<<endl;
		           					//cin>>cliente.id >> "\t" >> cliente.nombre >> "\t" >> cliente.id_cuidad >> "\t" >>icliente.gender;


		           					break;

		           					case 2: // Borrar
		           					int posicion;
		           					cout<< "Ingrese posicion que desea eliminar "<<endl;

		           					break;

		           					case 3: //LIstar

		           					break;

		           					case 4: // Modificar
		           					
		           					cliente person;
		           					cout<< "Ingrese ID, nombre, ID cuidad, genero , separados por espacio"<<endl;
		           					//cin>>cliente.id >> "\t" >> cliente.nombre >> "\t" >> cliente.id_cuidad >> "\t" >>icliente.gender;

		           					break;

		           					case 5: // Buscar con indice

		           					break;

		           					case 6: // buscar sin indice

		           					break;

		           					case 7: // Reindexar

		           					break;

		           			} 
		           			break;   
		           	case 2: // Cuidades
		           			switch(menu2()){
		           					case 1: // Agregar
		           					
									cuidad cuidad1;
		           					cout<< "Ingrese ID y nombre de la cuidad separados por espacio"<<endl;
		           					//cin>>cuidad.id >> "\t" >> cuidad.nombre;

		           					break;

		           					case 2: // Borrar
		           					int posicion;
		           					cout<< "Ingrese posicion que desea eliminar "<<endl;

		           					break;

		           					case 3: //LIstar

		           					break;

		           					case 4: // Modificar
		           					
		           					cuidad city;
		           					cout<< "Ingrese ID y nombre de la cuidad separados por espacio"<<endl;
		           					//cin>>cuidad.id >> "\t" >> cuidad.nombre;

		           					break;

		           					case 5: // Buscar con indice

		           					break;

		           					case 6: // buscar sin indice

		           					break;

		           					case 7: // Reindexar

		           					break;

		           			} 
		           			break;

		           	case 3: // Linea_cliente
		           			switch(menu2()){
		           					case 1: // Agregar
		           					linea_cliente linea;
		           					cout<< "Ingrese numero y ID del cliente separados por espacio"<<endl;
		           					//cin>>linea.numero >> "\t" >> linea.id_cliente;


		           					break;

		           					case 2: // Borrar
		           					int posicion;
		           					cout<< "Ingrese posicion que desea eliminar "<<endl;

		           					break;

		           					case 3: //LIstar

		           					break;

		           					case 4: // Modificar
		           					linea_cliente line;
		           					cout<< "Ingrese numero y ID del cliente separados por espacio"<<endl;
		           					//cin>>linea.numero >> "\t" >> linea.id_cliente;

		           					break;

		           					case 5: // Buscar con indice

		           					break;

		           					case 6: // buscar sin indice

		           					break;

		           					case 7: // Reindexar

		           					break;

		           			} 
		           			break;
		           			   		   		
		       }
		   }
		   return 0;
		}

		int menu(){
	cout<<"1- Clientes"<<endl;
	cout<<"2- Cuidades"<<endl;
	cout<<"3- Linea"<<endl;
	cout << endl << "Opcion? ";
	int opcion;
	cin >> opcion;
	return opcion;

}

int menu2(){
	cout << "1. Agregar "  << endl;
	cout << "2. Borrar "  << endl;
	cout << "3. Listar " << endl;
	cout << "4. Modificar " << endl;
	cout << "5. Buscar con indice " << endl;
	cout << "6. Buscar sin indice  " << endl;
	cout << "7. Reindexar  " << endl;
	cout << endl << "Opcion? ";
	int opcion;
	cin >> opcion;
	return opcion;
}
