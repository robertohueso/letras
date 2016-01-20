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
  
  return letra_actual;
}
