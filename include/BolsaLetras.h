#include <vector>
#include "ConjuntoLetras.h"

class BolsaLetras{
private:
  vector<char> letras;

public:
  BolsaLetras(const ConjuntoLetras &conjunto);

  char getLetra();

  vector<char> getVectorLetras(unsigned int cantidad);
};
