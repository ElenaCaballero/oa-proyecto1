#include <iostream>
	#include <fstream>
	#include <string.h>
	#include <sstream>
	#include <stdio.h>
	#include <stdlib.h>

	using namespace std;

	struct linea_cliente{
		char num [20];
		char id_cliente [20];
		
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
			cout << "8. Crear Archivo" << endl;
			cout << "9. Salir" << endl;
			cout << endl << "Opcion? ";
			int menu;
			cin>>menu;
	 		if(menu==1){// Agregar
				 
					Header head;
					ifstream in("lineas.bin",ios::binary|ios::in); //lee el avail
			
					in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
			

					cout<<"Ingrese Numero y id"<<endl;
					linea_cliente linea; 
					linea_cliente linea2; //pide los datos que se ingresaran
					cin>>linea.num;
					cin>>linea.id_cliente;
					//cout << ciudad.id<<" "<<ciudad.nombre<<endl;

					fstream out("lineas.bin",ios::binary|ios::out|ios::in);
					int ecuacion,rrn,cont;
					rrn=head.avail;
					cont=head.number;
			
			
		
					if (rrn==-1)
					{
						ecuacion=8+(sizeof(linea_cliente)*cont);
						out.seekp(ecuacion,ios::beg);
				
						out.write(reinterpret_cast<char*>(&(linea.num)), 20);
						out.write(reinterpret_cast<char*>(&(linea.id_cliente)), 20);
				

						cont++; 
						head.number=cont;// suma 1 a la cantidad total de los registros
						out.seekp(0,ios::beg);
						out.write(reinterpret_cast<char*>(&(head)), sizeof(Header));
					}else{
					
						ecuacion=8+(sizeof(linea)*(rrn-1)); // da la posicion donde debe escribirse
						in.seekg(ecuacion,ios::beg);
						in.read(reinterpret_cast<char*>(&linea2), sizeof(linea2)); // lee el registro que se encuentra en pos
						//cout<<" el id de cuidad "<< ciudad2.id<<endl;
						int num = atoi(linea.num);
						if (num==-1)
						{
							head.avail=-1;

						} else{
							head.avail=(num*-1); // toma el siguiente y asigna al avail
							cout<<"el head avail"<< head.avail<<endl;
						}
				
						in.close();
						out.seekp(ecuacion,ios::beg);
						out.write(reinterpret_cast<char*>(&(linea.num)), 20); // escribe el archivo
						out.write(reinterpret_cast<char*>(&(linea.id_cliente)), 20);
						out.seekp(0,ios::beg);
						out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int)); // escribe el header
						out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
				
					}						
					out.close();

				}else if(menu==2){ // Borrar
						 Header head;
						linea_cliente linea; 
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
							ecuacion=8+(sizeof(linea)*(rrn-1)); // dara la poscion a donde se marcara
							
							if (head.avail==-1)
							{
								//linea.num = itoa(head.avail);
								stringstream ss;
  								ss << head.avail;
  								strcpy(linea.num,ss.str().c_str());
								//linea.num=ss;

							}else{
								//linea.num= itoa(head.avail*-1);
								stringstream ss;
  								ss << head.avail*-1;
  								strcpy(linea.num,ss.str().c_str());
								
							}
							fstream out("lineas.bin",ios::binary|ios::out|ios::in);
							out.seekp(ecuacion,ios::beg); //lo marca y pone el proximo lo sobre escribe
							out.write(reinterpret_cast<char*>(&(linea.num)), 20);
							out.write(reinterpret_cast<char*>(&(linea.id_cliente)), 20);

							head.avail=rrn;

							out.seekp(0,ios::beg); // reescribe el header
							out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
							out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
							out.close();
						}
				

				}else if(menu==3){ //LIstar
					Header head;
					ifstream in("lineas.bin",ios::binary|ios::in);
			
					in.read(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					in.read(reinterpret_cast<char*>(&(head.number)), sizeof(int));
					cout << head.avail <<" "<< head.number<<endl;
					
			
					in.seekg(8,ios::beg);      
			
					linea_cliente linea;
					//ifstream in("lineas.bin",ios::binary|ios::in);
					while(!in.eof()){
						in.read(reinterpret_cast<char*>(&(linea.num)), 20);
						in.read(reinterpret_cast<char*>(&(linea.id_cliente)), 20);
						cout << linea.num<<" "<<linea.id_cliente<<endl;
					}
					in.close();

				}else if(menu==4){ // Modificar
						           					
						           					

				}else if(menu==5){

				

				}else if(menu==6){// buscar sin indice

				}else if(menu==7){ // Reindexar

				}else if(menu==8){ // crear el archivo
					ifstream in("lineas.txt",ios::in);
					ofstream out("lineas.bin",ios::binary|ios::out|ios::app);
					Header head;
					head.avail=-1;
					head.number=750;

					out.write(reinterpret_cast<char*>(&(head.avail)), sizeof(int));
					out.write(reinterpret_cast<char*>(&(head.number)), sizeof(int));
					out.close();

					while(!in.eof()){
						string linea;
						getline(in,linea);
						cout<<linea<<endl;
						char num[9];
						for(int  i = 0; i<8; i++){
							num[i] = linea[i];
						}
						num[8] = '\0';
						char id_cliente[14];
						int j = 0;
						for(int  i = 8; i<linea.length(); i++){
							id_cliente[j] = linea[i];
							j++;
						}
						id_cliente[j] = '\0';
						ofstream out("lineas.bin",ios::binary|ios::out|ios::app);
			
						cout<<num<<" "<<id_cliente<<endl;
						out.write(reinterpret_cast<char*>(&num), 20);
						out.write(reinterpret_cast<char*>(&id_cliente), 20);

						out.close();
						}
						in.close();
				}else if(menu==8){ 
					break;
				}

			 
		}	
	return 0;

}