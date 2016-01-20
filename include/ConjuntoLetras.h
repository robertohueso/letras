#include <map>
#include <iostream>
#include <fstream>
#include "Letra.h"

using namespace std;

class ConjuntoLetras{
private:
  map<char, Letra> conjunto;

public:
  ConjuntoLetras();

  void insertar(const Letra &nueva_letra);

  Letra getLetra(const char &letra_a_buscar) const;

  friend istream & operator>>(istream& is, ConjuntoLetras &conj);

  friend ostream & operator<<(ostream& os, const ConjuntoLetras &conj);

  //void setPuntos(Letra L);

  /*class iterator{
  private:
  	set<Letra>::iterator it;
  public:
  	iterator();

  	iterator& operator++();

  };*/

  class const_iterator{
  private:
  	map<char, Letra>::const_iterator it;
  public:
  	const_iterator();

  	const_iterator& operator++();

    Letra operator*() const;

    bool operator!=(const const_iterator &otro_it) const;

    bool operator==(const const_iterator &otro_it) const;

    friend class ConjuntoLetras;
  };

  //iterator begin();

  //iterator end();

  const_iterator cbegin() const;

  const_iterator cend() const;
};
