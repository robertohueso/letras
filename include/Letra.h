//FIXME DOCUMENTAR Letra

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

  //FIXME Documentar
  Letra();

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

  //FIXME Documentar
  inline Letra& aumentaRepeticiones(){
    this->repeticiones++;
    return *this;
  }

  //FIXME Documentar
  inline void setPuntos(unsigned int puntos){
    this->puntuacion = puntos;
  }

  /**
		*@brief Compara 2 letras
    *
    *@return True si la letra es mayor que otra letra, false en caso contrario.
	**/
  inline bool operator<(const Letra &otra_letra){
    return (caracter < otra_letra.caracter);
  }
};
