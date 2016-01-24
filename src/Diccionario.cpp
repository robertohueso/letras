#include "Diccionario.h"

//Constructor por defecto de diccionario.
Diccionario::Diccionario(){
  info raiz;
  datos.AsignaRaiz(raiz);
}

//Inserta la palabra en el Arbol
void Diccionario::insertarPalabra(string palabra){
  ArbolGeneral<info>::Nodo nodo_actual = datos.raiz();
  ArbolGeneral<info>::Nodo nodo_padre;

  for(size_t i = 0; i < palabra.length(); i++){
    info nuevos_datos;
    nuevos_datos.c = palabra[i];
    if(i == (palabra.length() - 1))
      nuevos_datos.final = true;
    else
      nuevos_datos.final = false;

    nodo_padre = nodo_actual;
    nodo_actual = datos.hijomasizquierda(nodo_actual);
    if(nodo_actual != NULL){
      bool encontrado = false;
      bool derecha_nulo = false;
      while(!encontrado && !derecha_nulo){
        if(datos.etiqueta(nodo_actual).c == nuevos_datos.c)
          encontrado = true;
        if(nodo_actual->drcha == NULL)
          derecha_nulo = true;
        if(!encontrado && !derecha_nulo)
          nodo_actual = datos.hermanoderecha(nodo_actual);
      }

      if(derecha_nulo){
        ArbolGeneral<info> arbol_aux(nuevos_datos);
        datos.insertar_hermanoderecha(nodo_actual, arbol_aux);
        nodo_actual = datos.hermanoderecha(nodo_actual);
      }
    }else{
      ArbolGeneral<info> arbol_aux(nuevos_datos);
      datos.insertar_hijomasizquierda(nodo_padre, arbol_aux);
      nodo_actual = datos.hijomasizquierda(nodo_padre);
    }
  }
}

//Numero de palabras en el diccionario.
int Diccionario::size() const{
  int numero_palabras = 0;
  ArbolGeneral<info>::const_iter_preorden it;
  for(it = datos.cbegin(); it != datos.cend(); ++it){
    if((*it).final)
      numero_palabras++;
  }
  return numero_palabras;
}

//Devuelve palabras con una longitud dada.
vector<string> Diccionario::PalabrasLongitud(const unsigned int &longitud) const{
  vector<string> palabras;
  Diccionario::const_iterator it;

  for(it = this->cbegin(); it != this->cend(); ++it)
    if((*it).size() == longitud)
      palabras.push_back(*it);
  return palabras;
}

//Indica si una palabra esta en el diccionario.
bool Diccionario::Esta(const string &palabra) const{
  Diccionario::const_iterator it;

  for(it = this->cbegin(); it != this->cend(); ++it)
    if((*it) == palabra)
      return true;
  return false;
}

//Lee de un flujo de entrada un diccionario.
istream & operator >>(istream& is, Diccionario &D){
  string palabra;
  while(!(is.eof())){
    getline(is, palabra, '\n');
    D.insertarPalabra(palabra);
  }
  return is;
}

//Escribe salida del diccionario.
ostream& operator<<(ostream& os, const Diccionario& D){
  Diccionario::const_iterator it;
  for(it = D.cbegin(); it != D.cend(); ++it)
    os << '\n' << (*it);
  return os;
}

//----ITERADOR NO CONSTANTE----------------------------------------------

//Constructor del iterador
Diccionario::iterator::iterator(){}

//Pasa a la siguiente palabra
Diccionario::iterator& Diccionario::iterator::operator++(){
  int nivel_antiguo, nivel_actual;

  nivel_antiguo = it.getlevel();
  ++it;
  nivel_actual = it.getlevel();

  if(it != end){
    if(nivel_actual == 0){
      cadena = "";
    }else if(nivel_actual > nivel_antiguo){
      cadena += (*it).c;
      while(!(*it).final){
        ++it;
        cadena += (*it).c;
      }
    }else{
      size_t diferencia = nivel_antiguo - nivel_actual;
      for(size_t i = 0; i <= diferencia; i++)
        if(cadena.size() != 0)
          cadena.erase(cadena.size()-1);
      cadena += (*it).c;
      while(!(*it).final){
        ++it;
        cadena += (*it).c;
      }
    }
  }
  else{
    it = end;
    cadena.clear();
  }
  return *this;
}

//Begin del iterator
Diccionario::iterator Diccionario::begin(){
  //FIXME tener en cuenta el caso en el que no hay ninguna palabra
  Diccionario::iterator iter_comienzo;
  string letra;
  iter_comienzo.it = datos.begin();
  iter_comienzo.cadena = "";
  iter_comienzo.end = this->datos.end();
  return iter_comienzo;
}

//End del iterator
Diccionario::iterator Diccionario::end(){
  Diccionario::iterator iter_final;
  iter_final.it = this->datos.end();
  iter_final.cadena.clear();
  iter_final.end = this->datos.end();
  return iter_final;
}

//----ITERADOR CONSTANTE----------------------------------------------

//Constructor del iterador
Diccionario::const_iterator::const_iterator(){}

//Pasa a la siguiente palabra
Diccionario::const_iterator& Diccionario::const_iterator::operator++(){
  int nivel_antiguo, nivel_actual;

  nivel_antiguo = it.getlevel();
  ++it;
  nivel_actual = it.getlevel();

  if(it != end){
    if(nivel_actual == 0){
      cadena = "";
    }else if(nivel_actual > nivel_antiguo){
      cadena += (*it).c;
      while(!(*it).final){
        ++it;
        cadena += (*it).c;
      }
    }else{
      size_t diferencia = nivel_antiguo - nivel_actual;
      for(size_t i = 0; i <= diferencia; i++)
        if(cadena.size() != 0)
          cadena.erase(cadena.size()-1);
      cadena += (*it).c;
      while(!(*it).final){
        ++it;
        cadena += (*it).c;
      }
    }
  }
  else{
    it = end;
    cadena.clear();
  }
  return *this;
}

//Begin del iterator
Diccionario::const_iterator Diccionario::cbegin() const{
  //FIXME tener en cuenta el caso en el que no hay ninguna palabra
  Diccionario::const_iterator iter_comienzo;
  string letra;
  iter_comienzo.it = datos.cbegin();
  iter_comienzo.cadena = "";
  iter_comienzo.end = this->datos.cend();
  return iter_comienzo;
}

//End del iterator
Diccionario::const_iterator Diccionario::cend() const{
  Diccionario::const_iterator iter_final;
  iter_final.it = this->datos.cend();
  iter_final.cadena.clear();
  iter_final.end = this->datos.cend();
  return iter_final;
}
