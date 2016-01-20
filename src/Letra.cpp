#include "Letra.h"

Letra& Letra::operator++(){
  repeticiones++;
  return *this;
}
