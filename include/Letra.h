//FIXME DOCUMENTAR Letra

class Letra{
private:
  char caracter;

  unsigned int repeticiones;

  unsigned int puntuacion;

public:
  Letra(char letra, unsigned int num_repeticiones, unsigned int puntuacion)
  :caracter(letra), repeticiones(num_repeticiones), puntuacion(puntuacion){}

  inline char getCaracter() const{
    return this->caracter;
  }

  inline unsigned int getRepeticiones() const{
    return this->repeticiones;
  }

  inline unsigned int getPuntuacion() const{
    return this->puntuacion;
  }
}
