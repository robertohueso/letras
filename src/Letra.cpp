#include "Letra.h"

Letra& Letra::operator++(){
  this->repeticiones++;
  return *this;
}
