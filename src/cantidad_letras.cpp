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

	return 0;
}
