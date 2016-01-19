#include <set>
#include "Letra.h"

using namespace std;

class ConjuntoLetras{
private:
  set<Letra> conjunto;

public:
  ConjuntoLetras();

  Letra Encontrar(Letra L);

  void Insertar(Letra L);

  void setPuntos(Letra L);

  class iterator{
  private:
  	set<Letra>::iterator it;
  public:
  	iterator();

  	iterator& operator++();

  };

  class const_iterator{
  private:
  	set<Letra>::const_iterator it;
  public:
  	const_iterator();

  	const_iterator& operator++();

  };

  iterator begin();

  iterator end();

  const_iterator cbegin();

  const_iterator cend();
};
