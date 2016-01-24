/////////////////////////////////////
// Por Roberto Hueso Gómez         //
// Por Abel José Sánchez Alba      //
/////////////////////////////////////

#include "Letra.h"

Letra& Letra::operator++(){
  repeticiones++;
  return *this;
}
