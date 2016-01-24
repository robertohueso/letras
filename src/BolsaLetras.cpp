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
}

char BolsaLetras::getLetra(){
  unsigned int posicion;
  char letra_actual;
  srand(time(NULL));

  do{
    posicion=rand() % (letras.size() + 1);
    letra_actual = letras[posicion];
  }while(letra_actual == '\0');
  letras[posicion] = '\0';

  return (char)tolower(letra_actual);
}

vector<char> BolsaLetras::getVectorLetras(unsigned int cantidad){
  vector<char> letras;
  for(unsigned int i = 0; i < cantidad; i++)
    letras.push_back(this->getLetra());

  return letras;
}
