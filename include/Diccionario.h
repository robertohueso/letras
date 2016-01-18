#include "ArbolGeneral.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
  *@brief info
  *
  * En cada  estructura \e info se almacena un caracter y un booleano
  * donde el booleano indica si el caracter es el final de una palabra.
  */
struct info{
  /**
    *@brief Caracter
    */
  char c;

  /**
    *@brief Final
    *
    * True si es el final de una palabra, false si no
    */
  bool final;

  /**
    *@brief Constructor por defecto
    *
    * Crea una estructura con el caracter nulo y el bool false
    */
  info() :c('\0'), final(false){}

  /**
    *@brief Construye una estructura con los datos dados
    *
    * @param caracter Letra con la que se inicializa
    * @param caracter_final Bool con el que se inicializa
    */
  info(char caracter, bool caracter_final): c(caracter), final(caracter_final){}
};

//FIXME Documentar el TDA!

class Diccionario{
private:
  
  /**
		@brief Contiene el arbol en el que se almacena el diccionario
	**/
  ArbolGeneral<info> datos;

  /**
		*@brief Inserta una palabra en el diccionario.
    *
    *@param palabra String que contiene la palabra a insertar
	**/
  void insertarPalabra(string palabra);

  /**
		*@brief Busca una palabra en el diccionario y devuelve true si existe
    *
    *@param nodo Nodo del que cuelga el arbol con la palabra a buscar.
    *@param palabra String que contiene la palabra a buscar.
	**/
  bool encontrar(ArbolGeneral<info>::Nodo nodo, string palabra);

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
	friend ostream& operator<<(ostream& os, Diccionario& D);

  //FIXME DOCUMENTAR Iterator
  class iterator{
  private:
    ArbolGeneral<info>::const_iter_preorden it;

    string cadena;

    ArbolGeneral<info>::const_iter_preorden end;

  public:
    iterator(const ArbolGeneral<info> &arbol);

    string operator*();

    iterator& operator++();

    bool operator==(const iterator &otro_it);

    bool operator!=(const iterator &otro_it);

    friend class Diccionario;
  };

  iterator begin();

  iterator end();

  friend class iterator;
};
