#ifndef __LETRA_H__
#define __LETRA_H__

/**
   @brief T.D.A. Letra

   \b Definición:
   Una instancia \e a del tipo de dato abstracto Letra contiene
   una letra con el numero de veces que se repite y la puntuación que recibe.

   - rep.letra -> {char(Letra), repeticones de la letra, puntación de la letra}
   letra por letra en cada uno de sus nodos que son nodos del tipo de dato info.
   - El caracter siempre es el mismo

   Se establece una relacion de caracter con sus repeticiones y puntuacion

   Para poder usar el tipo de dato Letra se debe incluir el fichero

   <tt>\#include Letra.h</tt>

   @author Roberto Hueso Gómez y Abel Sánchez Alba.
   @date 24/01/2016
*/

class Letra{
private:
  /**
    *@brief Caracter que contiene la letra.
    */
  char caracter;

  /**
    *@brief Número de veces que se repite la letra.
    */
  unsigned int repeticiones;

  /**
    *@brief Puntuación de cada letra.
    */
  unsigned int puntuacion;

public:

  /**
		*@brief Constructor por defecto, crea una letra vacia.
	**/
  Letra()
  :caracter('\0'), repeticiones(0), puntuacion(0){}

  /**
		*@brief Constructor, crea una letra con un caracter. Todo lo demás
    * lo inicializa a 0.
    *
    *@param caracter Caracter que tendrá la letra.
	**/
  Letra(char caracter)
  :caracter(caracter), repeticiones(0), puntuacion(0){}

  /**
		*@brief Constructor de Letra
    *
    *@param letra Caracter que contiene el objeto Letra.
    *@param num_repeticiones Cantiad de veces que se repite la letra.
    *@param puntuacion Puntuacion de la letra
	**/
  Letra(char letra, unsigned int num_repeticiones, unsigned int puntuacion)
  :caracter(letra), repeticiones(num_repeticiones), puntuacion(puntuacion){}

  /**
		*@brief Devuelve el caracter que tiene la letra
	**/
  inline char getCaracter() const{
    return this->caracter;
  }

  /**
		*@brief Devuelve la cantidad de repeticiones
	**/
  inline unsigned int getRepeticiones() const{
    return this->repeticiones;
  }

  /**
		*@brief Devuelve la puntuacion de la letra
	**/
  inline unsigned int getPuntuacion() const{
    return this->puntuacion;
  }

  /**
		*@brief Cambia la cantidad de repeticiones de una letra.
    *
    *@param nuevas_repeticiones Nueva cantidad de repeticiones
	**/
  inline void setRepeticiones(unsigned int nuevas_repeticiones){
    this->repeticiones = nuevas_repeticiones;
  }

  /**
		*@brief Cambia la cantidad de puntos de una letra.
    *
    *@param nuevos_puntos Nueva cantidad de puntos
	**/
  inline void setPuntos(unsigned int nuevos_puntos){
    this->puntuacion = nuevos_puntos;
  }

  /**
		*@brief Aumenta las repeticiones en 1 unidad.
	**/
  Letra& operator++();


  /**
		*@brief Compara 2 letras
    *
    *@return True si la letra es mayor que otra letra, false en caso contrario.
	**/
  inline bool operator<(const Letra &otra_letra){
    return (caracter < otra_letra.caracter);
  }
};

#endif
