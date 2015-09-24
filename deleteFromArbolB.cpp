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

int main(int argc, char const *argv[])
{
	
	return 0;
}