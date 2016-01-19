#include "ConjuntoLetras.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	fstream f(argv[1]);
	fstream s(argv[2]);
	fstream q(argv[3]);
	char c;
	ConjuntoLetras conjuntazo;
	string dato;
	Letra *p;

	while(! f.eof() ){
		f>>c;
		tolower(c);
		Letra letrita(c,1,0);
		p=conjuntazo.Encontrar(c);
		if(p!=NULL)
			p->aumentaRepeticiones(*p);
		else 
			conjuntazo.insertar(letrita);
	}
	getline(s, dato, "\n");
	string numero;
	while(!s.eof()){
		getline(s,dato,"\n");
		while(dato.pop_back()!=' '){
			numero.insert(0,dato.pop_back());
		}
		char a = tolower(dato[0]);
		Letra *letra;
		int valor = atoi(numero.c_str());
		letra=conjuntazo.Encontrar(a);
		letra->setPuntos(*letra);
	}
	f<<"#Letra Cantidad Puntuacion \n";
	set<Letra>::iterator it1;
	for(it1=conjunto.begin();it1!=it.end();++it1){
		f << it->getCaracter << " " << it-> getRepeticiones << " " << it->getPuntuacion << endl;
	}

	return 0;
}
