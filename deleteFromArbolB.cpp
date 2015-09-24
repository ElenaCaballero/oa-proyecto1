#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>  
#include <sstream>
#include <string>
using namespace std;

class BTreeNode{
	char* llaves[2*5-1];	//arreglo de llaves
	int o;			//orden del arbol
	BTreeNode **C;	//arreglo de hijos
	int n;		//el numero de llaves que contiene
	bool hoja;  //si el nodo es hoja
public:
	BTreeNode(bool _hoja);	// constructor
	void inorder();	//para recorrer arbol
	void insertarNoLleno(char k[40]); //para insertar a un nodo que no está lleno
	void dividirHijo(int i, BTreeNode *y); //para dividir el hijo del nodo
	BTreeNode *buscar(char k[40]); //para buscar una llave 

	friend class BTree;
};

class BTree{
	BTreeNode *raiz;	//raiz del arbol
	int o;		//orden del arbol
public:
	BTree(){raiz = NULL;  o = 5; } //constructor
	void inorder(){if (raiz != NULL) raiz->inorder(); } // para recorrer el arbol
	BTreeNode* buscar(char k[40]){return (raiz == NULL)? NULL : raiz->buscar(k); } // para buscar una llave
	void insertar(char k[40]); // para insertar al arbol
};

BTreeNode::BTreeNode(bool hoja1){
	o = 5;	//el orden del arbol será 5
	hoja = hoja1;

	//llaves = new char[2*o-1];
    C = new BTreeNode *[2*o];

    n = 0;	//inicialmente no contiene llaves
}

void BTreeNode::inorder(){
	int i;
	for (i = 0; i < n; i++){
		if (hoja == false){
			C[i]->inorder();
		}
		cout << endl << llaves[i];
	}
	if (hoja == false)
        C[i]->inorder();
}

BTreeNode *BTreeNode::buscar(char k[40]){
	int i = 0;
	while(i < n && k > llaves[i]){	//buscar la primera llave mayor que k
		i++;
	}

	if (llaves[i] == k)	// si la llave es igual a k, retorna el nodo
        return this;

    if (hoja == true)	//si k no está y estamos en hoja, retorna null
        return NULL;

    return C[i]->buscar(k); //ir al hijo correspondiente
}

void BTree::insertar(char k[40]){
	if (raiz == NULL){	//si el arbol esta vacio
		raiz = new BTreeNode(true);
		raiz->llaves[0] = k;	//agregamos la llave
		raiz->n = 1;
	}else{	//si el arbol no esta vacio
		if (raiz->n == 2*o-1){	//si la raiz esta llena, el arbol crece en altura
			BTreeNode *m = new BTreeNode(false);
			m->C[0] = raiz;
			m->dividirHijo(0, raiz);
			int i = 0;
			if (m->llaves[0] == k){
				i++;
			}
			m->C[i]->insertarNoLleno(k);
			raiz = m;
		}else{	//si la raiz no esta llena
			raiz->insertarNoLleno(k);
		}
	}


}

void BTreeNode::insertarNoLleno(char k[40]){
	int i = n-1; //el indice es el indice del elemento mas a la derecha
	if(hoja == true){	//si el nodo actual es una hoja
		while (i >= 0 && llaves[i] > k){
            llaves[i+1] = llaves[i];
            i--;
        }
        
        llaves[i+1] = k;
        n = n+1;
	}else{	//si el nodo no es hoja
		while (i >= 0 && llaves[i] > k)
            i--;

        if (C[i+1]->n == 2*o-1){
            dividirHijo(i+1, C[i+1]);
            
            if (llaves[i+1] < k)
                i++;
        }
        C[i+1]->insertarNoLleno(k);
	}

}

void BTreeNode::dividirHijo(int i, BTreeNode *y){
	BTreeNode *m = new BTreeNode(y->hoja);
    m->n = o - 1;
    
    for (int j = 0; j < o-1; j++){
        m->llaves[j] = y->llaves[j+o];
    }
    
    if (y->hoja == false){
        for (int j = 0; j < o; j++)
            m->C[j] = y->C[j+o];
    }
    
    y->n = o - 1;
    
    for (int j = n; j >= i+1; j--){
        C[j+1] = C[j];
    }
    
    C[i+1] = m;
    
    for (int j = n-1; j >= i; j--){
        llaves[j+1] = llaves[j];
    }
    
    llaves[i] = y->llaves[o-1];
    n = n + 1;
}

struct Index{
	std::vector<char*> key;		//vector de llaves
	int reference;		//referencia

	bool operator < (const Index& str) const
    {
        return (key < str.key);
    }
};

struct Cliente{
	char idCliente[20];
	char nombre[40];
	char genero;
	int idCity;
};

struct linea_cliente{
  	char num[20];
	char id_cliente[20];
};

struct Ciudad{
  	int id;
	char nombre[40];
};

ostream& operator<<(ostream& output, const Index& item){
	output << item.reference;
	return output;  
}

ostream& operator<<(ostream& output, const Ciudad& item){
	output << item.id << "\t" << item.nombre;
	return output;  
}

ostream& operator<<(ostream& output, const Cliente& item){
	output << item.idCliente << "\t" << item.nombre << "\t" << item.genero<< "\t" << item.idCity;
	return output;  
}

ostream& operator<<(ostream& output, const linea_cliente& item){
	output << item.num << "\t" << item.id_cliente;
	return output;  
}

int menu();
int menu2();

int main(int argc, char const *argv[])
{
	int o = menu2();
	if(o == 1){//Borrar---------------------------------------------------
		int op = menu();
		if (op == 1){
			char id[20];
			cout << "Ingrese el índice a borrar" << endl;
			cin >> id;

			int count;

			Index indexfile;
			ifstream file("index2Clientes.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
				if (strcmp(indexfile.key[count],id) == 0){
					indexfile.key.erase (indexfile.key.begin()+indexfile.reference-1);
				}
				count++;
			}
			ofstream ifile;
			ifile.open("index2Clientes.bin", ofstream::binary);

			ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));

			ifile.close();

			file.close();
		}else if (op == 2){
			char id[20];
			cout << "Ingrese el índice a borrar" << endl;
			cin >> id;

			int count;

			Index indexfile;
			ifstream file("index2Lineas.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
				if (strcmp(indexfile.key[count],id) == 0){
					indexfile.key.erase (indexfile.key.begin()+indexfile.reference-1);
				}
				count++;
			}
			ofstream ifile;
			ifile.open("index2Lineas.bin", ofstream::binary);

			ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));

			ifile.close();

			file.close();
		}else if (op == 3){
			char id[20];
			cout << "Ingrese el índice a borrar" << endl;
			cin >> id;

			int count;

			Index indexfile;
			ifstream file("index2Ciudades.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&indexfile), sizeof(indexfile))){
				if (strcmp(indexfile.key[count],id) == 0){
					indexfile.key.erase (indexfile.key.begin()+indexfile.reference-1);
				}
				count++;
			}
			ofstream ifile;
			ifile.open("index2Ciudades.bin", ofstream::binary);

			ifile.write(reinterpret_cast<const char*> (&indexfile), sizeof(indexfile));

			ifile.close();

			file.close();
		} else if (op <= 0 || op > 3){
			cout << "Ingrese una opcion existente" << endl;
			op = menu();
		}
	}else if(o == 2){//Buscar---------------------------------------------------------
		int op = menu();
		if (op == 1){
			BTree arbol;
			int count;

			Index item;
			ifstream file("index2Clientes.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				arbol.insertar(item.key[count]);
				count++;
			}

			char id[20];
			cout << "Ingrese el índice a buscar" << endl;
			cin >> id;

			arbol.buscar(id);

			file.close();
		}else if (op == 2){
			BTree arbol;
			int count;

			Index item;
			ifstream file("index2Lineas.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				arbol.insertar(item.key[count]);
				count++;
			}

			char id[20];
			cout << "Ingrese el índice a buscar" << endl;
			cin >> id;

			arbol.buscar(id);

			file.close();
		}else if (op == 3){
			BTree arbol;
			int count;

			Index item;
			ifstream file("index2Ciudades.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				arbol.insertar(item.key[count]);
				count++;
			}

			char id[20];
			cout << "Ingrese el índice a buscar" << endl;
			cin >> id;

			arbol.buscar(id);

			file.close();
		} else if (op <= 0 || op > 3){
			cout << "Ingrese una opcion existente" << endl;
			op = menu();
		}
	}else if(o == 3){//Listar-------------------------------------------
		int op = menu();
		if (op == 1){
			BTree arbol;
			int count;

			Index item;
			ifstream file("index2Clientes.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				arbol.insertar(item.key[count]);
				count++;
			}

			arbol.inorder();

			file.close();
		}else if (op == 2){
			BTree arbol;
			int count;

			Index item;
			ifstream file("index2Lineas.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				arbol.insertar(item.key[count]);
				count++;
			}

			arbol.inorder();

			file.close();
		}else if (op == 3){
			BTree arbol;
			int count;

			Index item;
			ifstream file("index2Ciudades.bin", ifstream::binary);
			while(file.read(reinterpret_cast<char*>(&item), sizeof(item))){
				arbol.insertar(item.key[count]);
				count++;
			}

			arbol.inorder();

			file.close();
		} else if (op <= 0 || op > 3){
			cout << "Ingrese una opcion existente" << endl;
			op = menu();
		}
	}else if (o <= 0 || o > 3){
		cout << "Ingrese una opcion existente" << endl;
		o = menu();
	}

	

	return 0;
}

int menu(){
	int op = 0;
	cout << "Seleccione el archivo a borrar un indice: " << endl;
	cout << "1. Clientes" << endl;
	cout << "2. Lineas Telefónicas" << endl;
	cout << "3. Ciudades" << endl;
	cin >> op;
	return op;
}
int menu2(){
	int op = 0;
	cout << "Seleccione lo que quiere realizar: " << endl;
	cout << "1. Borrar" << endl;
	cout << "2. Buscar" << endl;
	cout << "3. Listar" << endl;
	cin >> op;
	return op;
}
