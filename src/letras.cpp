#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;

int main(int argc, char *argv[]){
	ifstream lectura_diccionario(argv[1]);
	ifstream lectura_puntos(argv[2]);
	ConjuntoLetras letras;

	lectura_diccionario >> letras;
	letras.leerPuntos(lectura_puntos);

  

	return 0;
}
