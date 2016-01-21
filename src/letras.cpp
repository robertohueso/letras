#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;

int main(int argc, char *argv[]){
	ifstream lectura_diccionario(argv[1]);
	ifstream lectura_puntos(argv[2]);
	Diccionario diccionario;
	ConjuntoLetras letras;

	lectura_diccionario >> diccionario;
	diccionario >> letras;
	letras.leerPuntos(lectura_puntos);



	return 0;
}
