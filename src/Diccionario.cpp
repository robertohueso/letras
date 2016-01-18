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

//Devuelve true si la palabra se encuentra en el arbol que cuelga del Nodo nodo
bool Diccionario::encontrar(ArbolGeneral<info>::Nodo nodo, string palabra){
  ArbolGeneral<info>::Nodo nodo_actual = datos.hijomasizquierda(nodo);

  bool encontrado = false;
  bool derecha_nulo = false;
  while(!encontrado && !derecha_nulo){
    if((datos.etiqueta(nodo_actual)).c == (*(palabra.begin())))
      encontrado = true;
    if(nodo_actual->drcha == NULL)
      derecha_nulo = true;
    if(!encontrado)
      nodo_actual = datos.hermanoderecha(nodo_actual);
  }

  if(derecha_nulo)
    return false;
  else if(derecha_nulo && (datos.etiqueta(nodo_actual)).final)
    return true;
  else{
    palabra.erase(palabra.begin());
    return this->encontrar(nodo_actual, palabra);
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
vector<string> Diccionario::PalabrasLongitud(int longitud){
  vector<string> palabras;
  string palabra;
  ArbolGeneral<info>::iter_preorden it;

  for(it=datos.begin();it!=datos.end() && it.getlevel()<=longitud ;++it){
    if((*it).final==true && it.getlevel()==longitud) {
      palabra.push_back((*it).c);
      palabras.push_back(palabra);
    }
    else
      palabra.push_back((*it).c);
    if(it.getlevel()==longitud)
      palabra.clear();
  }

  /*while(p->drcha !=NULL || final_arbol==false){
      while(p.getlevel()<=longitud && (*it).getlevel()<=longitud){
        if(p->etiqueta->final==true)
          palabra_encontrada = true;
        palabra.push_back(p->etiqueta->c);




      }
*/
  return palabras;
}

//Indica si una palabra esta en el diccionario.
bool Diccionario::Esta(string palabra){
  return this->encontrar(datos.raiz(), palabra);
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

//Escribe salida del diccionario. FIXME PONER CONST DICCIONARIO
ostream& operator<<(ostream& os, Diccionario& D){
  Diccionario::iterator it(D.datos);
  for(it = D.begin(); it != D.end(); ++it)
    os << '\n' << (*it);
  return os;
}

//Constructor del iterador
Diccionario::iterator::iterator(const ArbolGeneral<info> &arbol){
  this->end = arbol.cend();
}

//Devuelve la palabra a la que apunta
string Diccionario::iterator::operator*(){
  return this->cadena;
}

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

//Comprueba si 2 iteradores son iguales
bool Diccionario::iterator::operator==(const iterator &otro_it){
  return (this->it == otro_it.it && this->cadena == otro_it.cadena);
}

//Comprueba si 2 iteradores son diferentes
bool Diccionario::iterator::operator!=(const iterator &otro_it){
  return (this->it != otro_it.it || this->cadena != otro_it.cadena);
}

//Begin del iterator
Diccionario::iterator Diccionario::begin(){
  //FIXME tener en cuenta el caso en el que no hay ninguna palabra
  Diccionario::iterator iter_comienzo(this->datos);
  string letra;
  iter_comienzo.it = datos.cbegin();
  iter_comienzo.cadena = "";
  return iter_comienzo;
}

//End del iterator
Diccionario::iterator Diccionario::end(){
  Diccionario::iterator iter_final(this->datos);
  iter_final.it = this->datos.cend();
  iter_final.cadena.clear();
  return iter_final;
}
