#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Diccionario.h"
#include "Letra.h"


using namespace std;
#ifndef __CONJUNTO_LETRAS_H__
#define __CONJUNTO_LETRAS_H__

/**
   @brief T.D.A. ConjuntoLetras

   \b Definición:
   Una instancia \e a del tipo de dato abstracto ConjuntoLetras contiene
   un conjunto de objetos de tipo Letra

   - rep.conjunto -> map con el char de la letra y el objeto Letra
   letra por letra en cada uno de sus nodos que son nodos del tipo de dato info.
   - Las letras no estarán repetidas

   Se establece una relacion de Letras organizadas por su caracter.

   Para poder usar el tipo de dato ConjuntoLetras se debe incluir el fichero

   <tt>\#include ConjuntoLetras.h</tt>

   @author Roberto Hueso Gómez y Abel Sánchez Alba.
   @date 24/01/2016
*/

class ConjuntoLetras{
private:
  /**
    *@brief Almacena el conjunto de letras
  */
  map<char, Letra> conjunto;

  /**
    *@brief Transforma las cantidades de las letras en tanto por ciento.
  */
  void autoRepartirCantidades();

  /**
    *@brief Cambia los puntos de una letra
    *
    *@param letra Letra de la que se va a cambiar los Puntos
    *@param puntos Nueva cantidad de puntos
  */
  void setPuntos(const char &letra, unsigned int puntos);
public:
  /**
    *@brief Crea un conjunto de letras vacio
  */
  ConjuntoLetras();

  /**
    *@brief Inserta una letra (Si ya existe, aumenta la cantidad de la letra)
    *
    *@param nueva_letra Letra a insertar
  */
  void insertar(const Letra &nueva_letra);

  /**
    *@brief Busca y devuelve una letra del conjunto
    *
    *@param letra_a_buscar Letra que se buscará
  */
  Letra getLetra(const char &letra_a_buscar) const;

  /**
    *@brief Lee los puntos de cada letra en el formato de "letras.txt"
    *
    *@param is Flujo de el que se lee el archivo
  */
  istream& leerPuntos(istream& is);

  /**
    *@brief Carga un conjunto de letras desde un archivo de texto con un diccionario
    *
    *@param is Flujo de el que se lee el archivo
    *@param conj Conjunto en el que se carga
  */
  friend istream & operator>>(istream& is, ConjuntoLetras &conj);

  /**
    *@brief Carga un conjunto de letras desde un objeto de tipo Diccionario
    *
    *@param Dic Diccionario de el que se lee
    *@param conj Conjunto en el que se carga
  */
  friend void operator>>(const Diccionario &Dic, ConjuntoLetras &conj);

  /**
    *@brief Imprime un conjunto de letras con sus cantidades y puntos
    *
    *@param os Flujo de salida
    *@param conj Conjunto del que se lee
  */
  friend ostream & operator<<(ostream& os, const ConjuntoLetras &conj);

  class iterator{
  private:
  	map<char, Letra>::iterator it;
  public:
    /**
 	  * @brief Constructor por defecto
 	  *
 	  * */
  	iterator();

    /**
 	  * @brief Obtiene un iterador a la siguiente letra
 	  *
 	  * */
  	iterator& operator++();

    /**
 	  * @brief Obtiene la letra
 	  *
 	  * */
    inline Letra& operator*(){
      return (*it).second;
    }

    /**
    * @brief Compara dos iteradores
    * @param otro_it iterador con el  que se compara
    * @return False si los dos iteradores son iguales. True en caso contrario
    * */
    inline bool operator!=(const iterator &otro_it) const{
      return (this->it != otro_it.it);
    }

    /**
 	  * @brief Compara dos iteradores
 	  * @param otro_it iterador con el  que se compara
 	  * @return True si los dos iteradores son iguales. False en caso contrario
 	  * */
    inline bool operator==(const iterator &otro_it) const{
      return (this->it == otro_it.it);
    }

    friend class ConjuntoLetras;
  };

  class const_iterator{
  private:
  	map<char, Letra>::const_iterator it;
  public:
    /**
 	  * @brief Constructor por defecto
 	  *
 	  * */
  	const_iterator();

    /**
 	  * @brief Obtiene un iterador a la siguiente letra
 	  *
 	  * */
  	const_iterator& operator++();

    /**
 	  * @brief Obtiene la letra
 	  *
 	  * */
    inline const Letra & operator*() const{
      return (*it).second;
    }

    /**
    * @brief Compara dos iteradores
    * @param otro_it iterador con el  que se compara
    * @return False si los dos iteradores son iguales. True en caso contrario
    * */
    inline bool operator!=(const const_iterator &otro_it) const{
      return (this->it != otro_it.it);
    }

    /**
 	  * @brief Compara dos iteradores
 	  * @param otro_it iterador con el  que se compara
 	  * @return True si los dos iteradores son iguales. False en caso contrario
 	  * */
    inline bool operator==(const const_iterator &otro_it) const{
      return (this->it == otro_it.it);
    }

    friend class ConjuntoLetras;
  };

  /**
   * @brief Inicializa un iterador a la primera letra.
   */
  iterator begin();

  /**
   * @brief Inicializa un iterador a letra nula.
   */
  iterator end();

  /**
   * @brief Inicializa un iterador a la primera letra.
   */
  const_iterator cbegin() const;

  /**
   * @brief Inicializa un iterador a letra nula.
   */
  const_iterator cend() const;
};

#endif
