#include "ArbolGeneral.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


  //FIXME solo para testdiccionario lo he puesto public!
  struct info{
    char c;
    bool final;

    info() :c('\0'), final(false){}
    info(char caracter, bool caracter_final): c(caracter), final(caracter_final){}
  };


class Diccionario{
private:

  //FIXME DOCUMENTAR!!!

  //FIXME solo para testdiccionario lo he puesto public!
  /*struct info{
    char c;
    bool final;

    info() :c('\0'), final(false){}
    info(char caracter, bool caracter_final);
  };*/

  ArbolGeneral<info> datos;

  void insertarPalabra(string palabra);

  bool encontrar(ArbolGeneral<info>::Nodo, string palabra);

public:

	/**
		@brief Construye un diccionario vacío
	**/
  Diccionario();

	/**
		Devuelve el numero de palabras en el diccionario
	**/
	int size() const;

	/**
		@brief Obtiene todas las palabras en el diccionario de una longitud dada
		@param longitud: la longitud de las palabras de salida
		@return un vector con las palabras de longitud especifica en el parametro de entrada
	**/
	vector<string> PalabrasLongitud(int longitud);

	/**
		@brief Indica si una palabra esta en el diccionario o no.
		@param palabra: la palabra que se quiere buscar.
		@return el flujo de entrada
	**/
	bool Esta(string palabra);

	/**
		@brief lee de un flujo de entrada un diccionario.
		@param is: flujo de entrada
		@param D: el objeto donde se realiza la lectura.
		@return el flujo de entrada.
	**/
  friend istream & operator >>(istream& is, Diccionario &D);

	/**
		@brief Escribe en un flujo de salida un diccionario.
		@param os:flujo de salida.
		@param D: el objeto diccionario que se escribe.
		@return el flujo de salida.
	**/
	friend ostream& operator<<(ostream& os, const Diccionario& D);

  //FIXME DOCUMENTAR Iterator
  class iterator{
  private:
    ArbolGeneral<info>::iter_preorden it;

    string cadena;

  public:
    iterator();

    string operator*();

    iterator& operator++();

    bool operator==(const iterator &otro_it);

    bool operator!=(const iterator &otro_it);

    friend class Diccionario;
  };

  iterator begin();

  iterator end();

};
