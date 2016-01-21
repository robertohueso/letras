#include <string.h>
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;
void imprimeLasLetras(const vector<char> &lista_letras){
	cout << "Las letras son: ";
	for(unsigned int i = 0; i < lista_letras.size(); i++)
		cout << (char)toupper(lista_letras[i]) << " ";
	cout << "\n";
}

int imprimePuntuacionLongitud(string palabra){
	return palabra.size();
}

void palabraContieneLetras(vector<string> &palabras, vector<char> letras){
	for(int unsigned palabra_actual = 0; palabra_actual < palabras.size(); palabra_actual++){
		bool encontrado = true;
		for(int unsigned caracter_actual = 0; caracter_actual < letras.size() && encontrado; caracter_actual++){
			if(palabras[palabra_actual].find((char)tolower(letras[caracter_actual])) == string::npos)
				encontrado = false;
		}
		if(!encontrado)
			palabras[palabra_actual] = "\0";
	}
	bool vacio = true;
	for(int unsigned i = 0; i < palabras.size(); i++){
		if(palabras[i] != "\0")
			vacio = false;
	}
	if(vacio)
		palabras.clear();
}

int main(int argc, char *argv[]){
	if(argc != 5){
		cout << "Error en el nº de argumentos";
		return 0;
	}
	ifstream lectura_diccionario(argv[1]);
	ifstream lectura_puntos(argv[2]);
	Diccionario diccionario;
	ConjuntoLetras letras;
	unsigned int numero_letras;
	vector<char> letras_aleatorias;
	vector<string> soluciones_maquina;
	string solucion;
	//bool encontrado;
	vector<string> definitivas_maquina;

	//Carga los datos
	lectura_diccionario >> diccionario;
	diccionario >> letras;
	letras.leerPuntos(lectura_puntos);
	BolsaLetras bolsa(letras);

	//Carga las letras aleatorias
	numero_letras = atoi(argv[3]);
	letras_aleatorias = bolsa.getVectorLetras(numero_letras);
	imprimeLasLetras(letras_aleatorias);
	cout << "Dime tu solucion: ";
	cin >> solucion;
	cout << "\n Puntuacion: ";

	//Modo de juego
	if(strcmp(argv[4], "L") == 0){
		while(soluciones_maquina.empty() && numero_letras != 0){
			soluciones_maquina = diccionario.PalabrasLongitud(numero_letras);
			palabraContieneLetras(soluciones_maquina, letras_aleatorias);
			numero_letras--;
		}

		for(unsigned int i = 0; i < soluciones_maquina.size(); i++)
			if(soluciones_maquina[i] != "\0")
				cout << soluciones_maquina[i] << "\n";


		/*encontrado = false;
		for(int i = numero_letras; i > 0 && !encontrado; i--){
			soluciones_maquina = diccionario.PalabrasLongitud(i);
			for(int i=0; i<soluciones_maquina.size();i++){
				for(int n=0; n<numero_letras && existe;n++){
					bool existe = true;
					if(letras_aleatorias.find(soluciones_maquina[i][n])==letras_aleatorias.end()){
						existe=false;
						soluciones_maquina.erase(soluciones_maquina.begin()+i);
					}

				}
			if(!soluciones_maquina.empty())
				encontrado = true;
			}
		for(int i = 0; i < soluciones_maquina.size(); i++)
			cout << soluciones_maquina[i] << "\n";
		*/
	}else if(strcmp(argv[4], "P") == 0){
		//Por puntos
	}else{
		cout << "Error en el nº de argumentos";
		return 0;
	}


	return 0;
}
