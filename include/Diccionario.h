#include "ArbolGeneral.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__

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



/**
   @brief T.D.A. Diccionario

   \b Definición:
   Una instancia \e a del tipo de dato abstracto Diccionario contiene
   un conjunto de palabras.

   - rep.diccionario -> ArbolGeneral que almacena la palabra
   letra por letra en cada uno de sus nodos que son nodos del tipo de dato info.
   - Se deben cargar desde un archivo las palabras

   Se establece una relacion de palabras entre las que se pueden iterar, buscar...etc.

   Para poder usar el tipo de dato ArbolGeneral se debe incluir el fichero

   <tt>\#include Diccionario.h</tt>

   @author Roberto Hueso Gómez y Abel Sánchez Alba.
   @date 24/01/2016
*/

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
	vector<string> PalabrasLongitud(const unsigned int &longitud) const;

	/**
		@brief Indica si una palabra esta en el diccionario o no.
		@param palabra: la palabra que se quiere buscar.
		@return el flujo de entrada
	**/
	bool Esta(const string &palabra) const;

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


  class iterator{
  private:
    ArbolGeneral<info>::iter_preorden it;

    string cadena;

    /**
 	  * @brief Iterador preorden al final del arbol
 	  *
 	  * */
    ArbolGeneral<info>::iter_preorden end;

  public:
    /**
 	  * @brief Constructor por defecto
 	  *
 	  * */
    iterator();

    /**
 	  * @brief Obtiene la palabra del Diccionario
 	  *
 	  * */
    inline string& operator*(){
      return this->cadena;
    }

    /**
 	  * @brief Obtiene un iterador a la siguiente palabra
 	  *
 	  * */
    iterator& operator++();

    /**
 	  * @brief Compara dos iteradores
 	  * @param otro_it iterador con el  que se compara
 	  * @return True si los dos iteradores son iguales. False en caso contrario
 	  * */
    inline bool operator==(const iterator &otro_it){
      return (this->it == otro_it.it && this->cadena == otro_it.cadena);
    }

    /**
    * @brief Compara dos iteradores
    * @param otro_it iterador con el  que se compara
    * @return False si los dos iteradores son iguales. True en caso contrario
    * */
    inline bool operator!=(const iterator &otro_it){
      return (this->it != otro_it.it || this->cadena != otro_it.cadena);
    }

    friend class Diccionario;
  };


  class const_iterator{
  private:
    ArbolGeneral<info>::const_iter_preorden it;

    string cadena;

    /**
 	  * @brief Iterador preorden al final del arbol
 	  *
 	  * */
    ArbolGeneral<info>::const_iter_preorden end;

  public:
    /**
 	  * @brief Constructor por defecto
 	  *
 	  * */
    const_iterator();

    /**
 	  * @brief Obtiene la palabra del Diccionario
 	  *
 	  * */
    inline const string & operator*() const{
      return this->cadena;
    }

    /**
 	  * @brief Obtiene un iterador a la siguiente palabra
 	  *
 	  * */
    const_iterator& operator++();

    /**
 	  * @brief Compara dos iteradores
 	  * @param otro_it iterador con el  que se compara
 	  * @return True si los dos iteradores son iguales. False en caso contrario
 	  * */
    inline bool operator==(const const_iterator &otro_it) const{
      return (this->it == otro_it.it && this->cadena == otro_it.cadena);
    }

    /**
    * @brief Compara dos iteradores
    * @param otro_it iterador con el  que se compara
    * @return False si los dos iteradores son iguales. True en caso contrario
    * */
    inline bool operator!=(const const_iterator &otro_it) const{
      return (this->it != otro_it.it || this->cadena != otro_it.cadena);
    }

    friend class Diccionario;
  };

  /**
   * @brief Inicializa un iterador a la primera palabra del Diccionario.
   */
  iterator begin();

  /**
   * @brief Inicializa un iterador a la palabra nula del Diccionario.
   */
  iterator end();

  /**
   * @brief Inicializa un iterador a la primera palabra del Diccionario.
   */
  const_iterator cbegin() const;

  /**
   * @brief Inicializa un iterador a la palabra nula del Diccionario.
   */
  const_iterator cend() const;
};

#endif
