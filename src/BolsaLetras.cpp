/////////////////////////////////////
// Por Roberto Hueso Gómez         //
// Por Abel José Sánchez Alba      //
/////////////////////////////////////


#include "BolsaLetras.h"

BolsaLetras::BolsaLetras(const ConjuntoLetras &conjunto){
  ConjuntoLetras::const_iterator it;
  for(it = conjunto.cbegin(); it != conjunto.cend(); ++it)
    for(unsigned int i = 0; i < (*it).getRepeticiones(); i++)
      letras.push_back((*it).getCaracter());
  letras_aux = letras;
}

char BolsaLetras::getLetra(){
  unsigned int posicion;
  char letra_actual;
  srand(time(NULL));

  do{
    posicion = rand() % letras_aux.size();
    letra_actual = letras_aux[posicion];
  }while(letra_actual == '\0');
  letras_aux[posicion] = '\0';

  return (char)tolower(letra_actual);
}

void BolsaLetras::reiniciar(){
  this->letras_aux = this->letras;
}

vector<char> BolsaLetras::getVectorLetras(unsigned int cantidad){
  vector<char> letras;
  for(unsigned int i = 0; i < cantidad; i++)
    letras.push_back(this->getLetra());
  this->reiniciar();

  return letras;
}
