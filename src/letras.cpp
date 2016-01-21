#include <string.h>
#include <map>
#include "ConjuntoLetras.h"
#include "BolsaLetras.h"

using namespace std;
void imprimeLasLetras(const vector<char> &lista_letras){
	cout << "Las letras son: ";
	for(unsigned int i = 0; i < lista_letras.size(); i++)
		cout << (char)toupper(lista_letras[i]) << " ";
	cout << "\n";
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
	cout << "\nPuntuacion: ";

	//Modo de juego
	if(strcmp(argv[4], "L") == 0){
		map<char, int> map_caracteres;
		unsigned int max_longitud = 0;
		unsigned int puntuacion = solucion.size();
		cout << puntuacion;

		for(vector<char>::iterator it = letras_aleatorias.begin(); it != letras_aleatorias.end(); ++it){
			map<char, int>::iterator it_map;
			it_map = map_caracteres.find(*it);
			if(it_map == map_caracteres.end())
				map_caracteres.insert(pair<char, int>((*it), 1));
			else
				it_map->second++;
		}

		cout << "\nLas soluciones de la maquina son de mejor a peor:\n";
		while(numero_letras > 0){
			soluciones_maquina = diccionario.PalabrasLongitud(numero_letras);

			for(vector<string>::iterator palabra = soluciones_maquina.begin();
											palabra != soluciones_maquina.end(); ++palabra){
				map<char, int> map_temporal(map_caracteres);
				bool encontrado = true;
				for(size_t letra = 0; letra < palabra->size() && encontrado; letra++){
					map<char, int>::iterator it_map;
					it_map = map_temporal.find((*palabra)[letra]);
					if(it_map != map_temporal.end() && it_map->second != 0)
						it_map->second--;
					else{
						encontrado = false;
						(*palabra) = "\0";
					}
				}
			}

			for(size_t i = 0; i < soluciones_maquina.size(); i++){
				if(soluciones_maquina[i] != "\0")
					cout << soluciones_maquina[i] << " Puntuacion: " << soluciones_maquina[i].size() << "\n";
				if(soluciones_maquina[i] != "\0" && soluciones_maquina[i].size() > max_longitud)
					max_longitud = soluciones_maquina[i].size();
			}

			numero_letras--;
		}

		//Has ganado o perdido
		if(diccionario.Esta(solucion) && puntuacion == max_longitud)
			cout << "Has ganado... esta vez\n";
		else
			cout << "Has perdido :P\n";
	}else if(strcmp(argv[4], "P") == 0){
		//Por puntos
	}else{
		cout << "Error en el nº de argumentos";
		return 0;
	}


	return 0;
}
