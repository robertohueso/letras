#include <vector>
#include "ConjuntoLetras.h"

//FIXME Documentar TDA
class BolsaLetras{
private:
  /**
    *@brief Vector de char que contiene las letras aleatorias
  */
  vector<char> letras;

public:
  /**
		@brief Construye una bolsa de letras
    *Almacena en el vector cada letra con sus repeticiones
    *
    *@param conjunto Conjunto de letras del que se tomarán los datos
	**/
  BolsaLetras(const ConjuntoLetras &conjunto);

  /**
		@brief Devuelve una letra obtenida de manera aleatoria del vector
    * y marca esa letra como "\0" en el vector
    *
    *@return Char con el caracter de la letra
	**/
  char getLetra();

  /**
		@brief Obtiene una cantidad de letras extraidas de manera aleatoria
    *
    *@param cantidad Cantidad de letras que se desea extraer
    *@return vector<char> con las letras extraidas
	**/
  vector<char> getVectorLetras(unsigned int cantidad);
};
