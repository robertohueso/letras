#include "ConjuntoLetras.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	if(argc != 4){
		cout << "Error al introducir los argumentos\n";
		return 0;
	}
	ifstream lectura_diccionario(argv[1]);
	ifstream lectura_puntos(argv[2]);
	ofstream salida_archivo(argv[3]);
	ConjuntoLetras letras;

	lectura_diccionario >> letras;
	//Asumo que deben ser los puntos del archivo ya que en el enunciado
	//la expliacion sobre para que sirve este archivo es ambigua.
	letras.leerPuntos(lectura_puntos);
	salida_archivo << letras;

	return 0;
}
