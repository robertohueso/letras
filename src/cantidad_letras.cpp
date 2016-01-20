#include "ConjuntoLetras.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	ifstream lectura_diccionario(argv[1]);
	ifstream lectura_puntos(argv[2]);
	ofstream salida_archivo(argv[3]);

	ConjuntoLetras letras;
	lectura_diccionario >> letras;
	letras.leerPuntos(lectura_puntos);
	salida_archivo << letras;
	//fstream q(argv[3]);
	//char c;
/*	ConjuntoLetras conjuntazo;
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
*/
	return 0;
}
