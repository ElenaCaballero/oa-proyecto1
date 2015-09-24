	#include <iostream>
	#include <fstream>
	#include <string.h>
	#include <sstream>
	#include <stdio.h>
	#include <stdlib.h>

	using namespace std;

	struct Ciudad{
		int id;
		char nombre[40];
	};
	struct Header{
		int avail;
		int number;
	};
 int menu2();
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
			cout << "8. Crear Archivo" << endl;
			cout << "9. Salir" << endl;
			cout << endl << "Opcion? ";
			int menu;
			cin>>menu;
	 		if(menu==1){// Agregar
				 
					Header head;
					ifstream in("ciudades.bin",ios::binary|ios::in); //lee el avail
			
					in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
			

					cout<<"Ingrese id nombre"<<endl;
					Ciudad ciudad; 
					Ciudad ciudad2; //pide los datos que se ingresaran
					cin>>ciudad.id;
					cin>>ciudad.nombre;
					cout << ciudad.id<<" "<<ciudad.nombre<<endl;

					fstream out("ciudades.bin",ios::binary|ios::out|ios::in);
					int ecuacion,rrn,cont;
					rrn=head.avail;
					cont=head.number;
			
			
		
					if (rrn==-1)
					{
						ecuacion=8+(sizeof(ciudad)*cont);
						out.seekp(ecuacion,ios::beg);
				
						out.write(reinterpret_cast<char*>(&(ciudad.id)), sizeof(int));
						out.write(reinterpret_cast<char*>(&(ciudad.nombre)), 40);
				

						cont++; 
						head.number=cont;// suma 1 a la cantidad total de los registros
						out.seekp(0,ios::beg);
						out.write(reinterpret_cast<char*>(&(head)), sizeof(Header));
					}else{
					
						ecuacion=8+(sizeof(ciudad)*(rrn-1)); // da la posicion donde debe escribirse
						in.seekg(ecuacion,ios::beg);
						in.read(reinterpret_cast<char*>(&ciudad2), sizeof(ciudad2)); // lee el registro que se encuentra en pos
						cout<<" el id de cuidad "<< ciudad2.id<<endl;
						if (ciudad2.id==-1)
						{
							head.avail=-1;

						} else{
							head.avail=(ciudad2.id*-1); // toma el siguiente y asigna al avail
							cout<<"el head avail"<< head.avail<<endl;
						}
				
						in.close();
						out.seekp(ecuacion,ios::beg);
						out.write(reinterpret_cast<char*>(&(ciudad.id)), sizeof(int)); // escribe el archivo
						out.write(reinterpret_cast<char*>(&(ciudad.nombre)), 40);
						out.seekp(0,ios::beg);
						out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int)); // escribe el header
						out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
				
					}						
					out.close();

				}else if(menu==2){ // Borrar
						 Header head;
						Ciudad ciudad;
						ifstream in("ciudades.bin",ios::binary|ios::in);
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
							ecuacion=8+(sizeof(ciudad)*(rrn-1)); // dara la poscion a donde se marcara
							
							if (head.avail==-1)
							{
								ciudad.id=head.avail;
							}else{
								ciudad.id=head.avail*-1;
							}
							fstream out("ciudades.bin",ios::binary|ios::out|ios::in);
							out.seekp(ecuacion,ios::beg); //lo marca y pone el proximo lo sobre escribe
							out.write(reinterpret_cast<char*>(&(ciudad.id)), sizeof(int));
							out.write(reinterpret_cast<char*>(&(ciudad.nombre)), 40);

							head.avail=rrn;

							out.seekp(0,ios::beg); // reescribe el header
							out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
							out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
							out.close();
						}
				

				}else if(menu==3){ //LIstar
					Header head;
					ifstream in("ciudades.bin",ios::binary|ios::in);
			
					in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
					cout << head.avail <<" "<< head.number<<endl;
					
			
					in.seekg(8,ios::beg);      
			
					Ciudad ciudad;
					while(in.read(reinterpret_cast<char*>(& ciudad), sizeof(ciudad))){
				
						cout << ciudad.id<<" entro "<<ciudad.nombre<<endl;
	
					}
					in.close();

				}else if(menu==4){ // Modificar
					Header head;
						Ciudad ciudad;
						ifstream in("ciudades.bin",ios::binary|ios::in);
						in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int)); // leee el header
						in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
						

						
						cout<<"Ingrese posicion a Modificar"<<endl;
						int rrn;
						cin>>rrn;

						if (rrn>head.number||rrn<0) // valida que el rrn o posicion a borrar sea valida
						{
							cout<<"La posicion ingresada no es valida"<<endl;
						} else {
	
							int ecuacion;
							ecuacion=8+(sizeof(ciudad)*(rrn-1)); // dara la poscion a donde se marcara
							in.seekg(ecuacion,ios::beg);
							Ciudad ciudad2;
							in.read(reinterpret_cast<char*>(&ciudad2), sizeof(ciudad2));
							
							fstream out("ciudades.bin",ios::binary|ios::out|ios::in);
							cout<<"Ingrese el nuevo nombre"<<endl;
							cin>>ciudad.nombre;
							out.seekp(ecuacion,ios::beg); //lo marca y pone el proximo lo sobre escribe
							out.write(reinterpret_cast<char*>(&(ciudad2.id)), sizeof(int));
							out.write(reinterpret_cast<char*>(&(ciudad.nombre)), 40);

							out.close();
						}
						in.close();	           					
						           					

				}else if(menu==5){

				

				}else if(menu==6){// buscar sin indice
					Header head;
					ifstream in("ciudades.bin",ios::binary|ios::in);
			
					in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
					cout << head.avail <<" "<< head.number<<endl;
					
			
					in.seekg(8,ios::beg);      
					cout<<"Ingrese id a buscar"<<endl;
					int temp;
					cin>>temp;
					Ciudad ciudad;
					while(in.read(reinterpret_cast<char*>(& ciudad), sizeof(ciudad))){
				
						if (temp==cuidad.id)
						{
							cout << ciudad.id<<" "<<ciudad.nombre<<endl;
						}
						
	
					}
					in.close();


				}else if(menu==7){ // Reindexar

				}else if(menu==8){ // crear el archivo
					ifstream in("ciudades.txt",ios::in);
					ofstream out("ciudades.bin",ios::binary|ios::out|ios::app);
					Header head;
					head.avail=-1;
					head.number=30;

					out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
					out.close();

					while(!in.eof()){
						string linea;
						getline(in,linea);
						cout<<linea<<endl;
						char id[3];
						for(int  i = 0; i<2; i++){
							id[i] = linea[i];
						}
						id[2] = '\0';
						char nombre[40];
						int j = 0;
						for(int  i = 2; i<linea.length(); i++){
						nombre[j] = linea[i];
						j++;
						}
						nombre[j] = '\0';
						ofstream out("ciudades.bin",ios::binary|ios::out|ios::app);
						int temp =atoi(id);
						cout<<temp<<" "<<nombre<<endl;
						out.write(reinterpret_cast<char*>(&temp), sizeof(int));
						out.write(reinterpret_cast<char*>(&nombre), 40);

						out.close();
					}
					in.close();

				}else if(menu==8){ 
					break;
				}

			 
		}	
	return 0;

}




	int menu2(){
		cout << "1. Agregar "  << endl;
		cout << "2. Borrar "  << endl;
		cout << "3. Listar " << endl;
		cout << "4. Modificar " << endl;
		cout << "5. Buscar con indice " << endl;
		cout << "6. Buscar sin indice  " << endl;
		cout << "7. Reindexar  " << endl;
		cout << "8. Crear Archivo" << endl;
		cout << endl << "Opcion? ";
		int opcion;
		cin >> opcion;
		return opcion;
	}
