#include <iostream>
	#include <fstream>
	#include <string.h>
	#include <sstream>
	#include <stdio.h>
	#include <stdlib.h>

	using namespace std;

	struct Cliente{
		char idCliente[20];
		char nombre[40];
		char genero;
		int idCity;
	};
	struct Header{
		int avail;
		int number;
	};
 
 int main (int argc, char *argv[]){
		
	bool flag = true;
 	while (flag)
 	{
 		cout << "1. Agregar "  << endl;
		cout << "2. Borrar "  << endl;
		cout << "3. Listar " << endl;
		cout << "4. Modificar " << endl;
		cout << "5. Buscar con indice " << endl;
		cout << "6. Buscar sin indice  " << endl;
		cout << "7. Reindexar  " << endl;
		
		cout << "8. Salir" << endl;
		cout << endl << "Opcion? ";
		int menu;
		cin>>menu;
 		if(menu==1){// Agregar
			 
				Header head;
				ifstream in("cliente.bin",ios::binary|ios::in); //lee el avail
		
				in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
				in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
		

				cout<<"Ingrese ID, nombre, genero[M/F],ID cuidad"<<endl;
				Cliente cliente; 
				Cliente cliente2; //pide los datos que se ingresaran
				cin>>cliente.idCliente;
				cin>>cliente.nombre;
				cin>>cliente.genero;
				cin>>cliente.idcity;
				//cout << ciudad.id<<" "<<ciudad.nombre<<endl;

				fstream out("cliente.bin",ios::binary|ios::out|ios::in);
				int ecuacion,rrn,cont;
				rrn=head.avail;
				cont=head.number;
		
		
	
				if (rrn==-1)
				{
					ecuacion=8+(sizeof(cliente)*cont);
					out.seekp(ecuacion,ios::beg);
			
					out.write(reinterpret_cast<char*>(&(cliente.idCliente)), 20);
					out.write(reinterpret_cast<char*>(&(cliente.nombre)), 40);
					out.write(reinterpret_cast<char*>(&(cliente.genero)), sizeof(char));
					out.write(reinterpret_cast<char*>(&(cliente.idcity)), sizeof(int));
			

					cont++; 
					head.number=cont;// suma 1 a la cantidad total de los registros
					out.seekp(0,ios::beg);
					out.write(reinterpret_cast<char*>(&(head)), sizeof(Header));
				}else{
				
					ecuacion=8+(sizeof(cliente)*(rrn-1)); // da la posicion donde debe escribirse
					in.seekg(ecuacion,ios::beg);
					in.read(reinterpret_cast<char*>(&cliente2), sizeof(cliente2)); // lee el registro que se encuentra en pos
					//cout<<" el id de cuidad "<< ciudad2.id<<endl;
					int num = atoi(cliente2.idCliente);
					if (num==-1)
					{
						head.avail=-1;

					} else{
						head.avail=(num*-1); // toma el siguiente y asigna al avail
						//cout<<"el head avail"<< head.avail<<endl;
					}
			
					in.close();
					out.seekp(ecuacion,ios::beg);
					out.write(reinterpret_cast<char*>(&(cliente.idCliente)), 20); // escribe el archivo
					out.write(reinterpret_cast<char*>(&(cliente.nombre)), 40);
					out.write(reinterpret_cast<char*>(&(cliente.genero)), sizeof(char));
					out.write(reinterpret_cast<char*>(&(cliente.idcity)), sizeof(int));
			
					out.seekp(0,ios::beg);
					out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int)); // escribe el header
					out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
			
				}						
				out.close();

		}else if(menu==2){ // Borrar
				 Header head;
				Cliente cliente; 
				ifstream in("lineas.bin",ios::binary|ios::in);
				in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int)); // leee el header
				in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
				in.close();

				
				cout<<"Ingrese posicion a elimanar"<<endl;
				int rrn;
				cin>>rrn;

				if (rrn>head.number||rrn<0) // valida que el rrn o posicion a borrar sea valida
				{
					cout<<"La posicion ingresada no es valida"<<endl;
				} else {

					int ecuacion;
					ecuacion=8+(sizeof(cliente)*(rrn-1)); // dara la poscion a donde se marcara
					
					if (head.avail==-1)
					{
						//linea.num = itoa(head.avail);
						stringstream ss;
							ss << head.avail;
							strcpy(cliente.idCliente,ss.str().c_str());
						//linea.num=ss;

					}else{
						//linea.num= itoa(head.avail*-1);
						stringstream ss;
							ss << head.avail*-1;
							strcpy(cliente.idCliente,ss.str().c_str());
						
					}
					fstream out("cliente.bin",ios::binary|ios::out|ios::in);
					out.seekp(ecuacion,ios::beg); //lo marca y pone el proximo lo sobre escribe
					out.write(reinterpret_cast<char*>(&(cliente.idCliente)), 20);
					out.write(reinterpret_cast<char*>(&(cliente.nombre)), 40);
					out.write(reinterpret_cast<char*>(&(cliente.genero)), sizeof(char));
					out.write(reinterpret_cast<char*>(&(cliente.idcity)), sizeof(int));
		

					head.avail=rrn;

					out.seekp(0,ios::beg); // reescribe el header
					out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
					out.close();
				}
		

		}else if(menu==3){ //LIstar
			Header head;
			ifstream in("cliente.bin",ios::binary|ios::in);
	
			in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
			in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
			cout << head.avail <<" "<< head.number<<endl;
			
	
			in.seekg(8,ios::beg);      
	
			Cliente cliente;
			//ifstream in("lineas.bin",ios::binary|ios::in);
			while(in.read(reinterpret_cast<char*>(&cliente), sizeof(cliente))){
				int num = atoi(cliente.idCliente);
				if (num>0)
				{
					cout << cliente.idCliente<<" "<<cliente.nombre<<cliente.genero<<" "<<cliente.idcity<<endl;
				}
			}
			in.close();

		}else if(menu==4){ // Modificar
			Header head;
				Cliente cliente; 
				ifstream in("lineas.bin",ios::binary|ios::in);
				in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int)); // leee el header
				in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
				in.close();

				
				cout<<"Ingrese posicion a modificar"<<endl;
				int rrn;
				cin>>rrn;

				if (rrn>head.number||rrn<0) // valida que el rrn o posicion a borrar sea valida
				{
					cout<<"La posicion ingresada no es valida"<<endl;
				} else {

					int ecuacion;
					ecuacion=8+(sizeof(cliente)*(rrn-1)); // dara la poscion a donde se marcara
					Cliente cliente2;
					in.seekg(ecuacion,ios::beg);
					in.read(reinterpret_cast<char*>(&cliente2), sizeof(cliente2));
					cout<<"Ingrese nuevo nombre, genro[f/m], id cuidad "<<endl;
					cin>>cliente.nombre;
					cin>>cliente.genero;
					cin>>cliente.idcity;
					fstream out("cliente.bin",ios::binary|ios::out|ios::in);
					out.seekp(ecuacion,ios::beg); //lo marca y pone el proximo lo sobre escribe
					out.write(reinterpret_cast<char*>(&(cliente2.idCliente)), 20);
					out.write(reinterpret_cast<char*>(&(cliente.nombre)), 40);
					out.write(reinterpret_cast<char*>(&(cliente.genero)), sizeof(char));
					out.write(reinterpret_cast<char*>(&(cliente.idcity)), sizeof(int));
		

				
					out.close();
				}
				in.close();	           					
				           					

		}else if(menu==5){

		

		}else if(menu==6){// buscar sin indice
			Header head;
			ifstream in("cliente.bin",ios::binary|ios::in);
	
			in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
			in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
			cout << head.avail <<" "<< head.number<<endl;
			
	
			in.seekg(8,ios::beg);      
	
			Cliente cliente;
			//ifstream in("lineas.bin",ios::binary|ios::in);
			while(in.read(reinterpret_cast<char*>(&cliente), sizeof(cliente))){
				

		
			char temp [20];

			cout<<"Ingrese el numero a buscar"<<endl;
			cin>>temp;
				if (strcmp(temp,cliente.idCliente)==0)
				{
					cout << cliente.idCliente<<" "<<cliente.nombre<<cliente.genero<<" "<<cliente.idcity<<endl;
				}
		
				
			}
			in.close();


		}else if(menu==7){ // Reindexar

		}else if(menu==8){ // crear el archivo
			flag = false;
			break;
		}
	}	
	return 0;

}