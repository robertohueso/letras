#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "Letra.h"

using namespace std;

class ConjuntoLetras{
private:
  map<char, Letra> conjunto;

  void autoRepartirCantidades();
public:
  ConjuntoLetras();

  void insertar(const Letra &nueva_letra);

  Letra getLetra(const char &letra_a_buscar) const;

  istream& leerPuntos(istream& is);

  friend istream & operator>>(istream& is, ConjuntoLetras &conj);

  friend ostream & operator<<(ostream& os, const ConjuntoLetras &conj);

  class iterator{
  private:
  	map<char, Letra>::iterator it;
  public:
  	iterator();

  	iterator& operator++();

    Letra& operator*();

    bool operator!=(const iterator &otro_it) const;

    bool operator==(const iterator &otro_it) const;

    friend class ConjuntoLetras;
  };

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

  iterator begin();

  iterator end();

  const_iterator cbegin() const;

  const_iterator cend() const;
};
