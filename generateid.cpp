#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <fstream>
using namespace std;

void departmuni(char*);
void year(char*);
void code(char*);

int main(int argc, char const *argv[])
{

	char depmun[4];
	char yea[4];
	char cod[5];
	char c[1];
	strcpy(c,"\n");
	char* id;

	departmuni(depmun);
	year(yea);
	code(cod);

	id = new char[strlen(depmun)+strlen(yea)+strlen(cod)+1];
	*id = '\0';
		
	strcat(id,depmun);
	strcat(id,yea);
	strcat(id,cod);
	strcat(id,c);

	for (int i = 0; i < strlen(id); ++i)
	{
		cout << id[i];
	}

	return 0;
}

void departmuni(char* out){
	
	srand (time(NULL));
	int v1 = rand() % 18 + 1;
	int v2 = rand() % 50 + 1;

	char const *buffer;
	char const *buffer2;
	if (v1 < 10)
	{
		std::string s = "0" + std::to_string(v1);
		buffer = s.c_str(); 
	}else{
		std::string s = std::to_string(v1);
		buffer = s.c_str(); 
	}
	if (v2 < 10)
	{
		std::string s = "0" + std::to_string(v2);
		buffer2 = s.c_str();
	}else{
		std::string s = std::to_string(v2);
		buffer2 = s.c_str();
	}

	strcat(out,buffer);
	strcat(out,buffer2);

}

void year(char* out){
	srand (time(NULL));

	int v3 = rand() % 99 + 1900;
	
	sprintf(out, "%d", v3);
}

void code(char* out){
	srand (time(NULL));

	int v4 = rand() % 99999 + 10000;

	sprintf(out, "%d", v4);
}



