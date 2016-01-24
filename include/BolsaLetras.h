/////////////////////////////////////
// Por Roberto Hueso Gómez         //
// Por Abel José Sánchez Alba      //
/////////////////////////////////////


#include <vector>
#include "ConjuntoLetras.h"

/**
   @brief T.D.A. BolsaLetras

   \b Definición:
   Una instancia \e a del tipo de dato abstracto BolsaLetras almacena (físicamente)
   las Letras de un ConjuntoLetras

   - rep.ConjuntoLetras -> vector<char> con cada una de las letras repetidas
   tantas veces como se indique
   - Debe contener al menos 1 letra

   De esta manera obtendremos aleatoriamente letras del Conjunto.

   Para poder usar el tipo de dato BolsaLetras se debe incluir el fichero

   <tt>\#include BolsaLetras.h</tt>

   @author Roberto Hueso Gómez y Abel Sánchez Alba.
   @date 24/01/2016
*/

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
