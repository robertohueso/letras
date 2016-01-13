#include "Diccionario.h"

Diccionario::Diccionario(){
  info raiz;
  datos.AsignaRaiz(raiz);
}

//Inserta la palabra en el Arbol
void Diccionario::insertarPalabra(string palabra){
  char letra;
  ArbolGeneral<info>::Nodo nodo_actual = datos.raiz();
  ArbolGeneral<info>::Nodo nodo_padre;

  for(size_t i = 0; i < palabra.length(); i++){
    info nuevos_datos;
    nuevos_datos.c = letra;
    if(i == (palabra.length() - 1))
      nuevos_datos.final = true;
    else
      nuevos_datos.final = false;

    letra = palabra[i];
    nodo_padre = nodo_actual;
    nodo_actual = nodo_actual->izqda;
    if(nodo_actual != NULL){
      bool encontrado = false;
      bool derecha_nulo = false;
      while(!encontrado && !derecha_nulo){
        if(datos.etiqueta(nodo_actual).c == nuevos_datos.c)
          encontrado = true;
        if(nodo_actual->drcha == NULL)
          derecha_nulo = true;
        if(!encontrado)
          nodo_actual = datos.hermanoderecha(nodo_actual);
      }

      if(derecha_nulo){
        ArbolGeneral<info> arbol_aux(nuevos_datos);
        datos.insertar_hermanoderecha(nodo_actual, arbol_aux);
      }
    }else{
      ArbolGeneral<info> arbol_aux(nuevos_datos);
      datos.insertar_hijomasizquierda(nodo_padre, arbol_aux);
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
  return palabras;
  //IMPLEMENTAR FIXME
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

//Escribe salida del diccionario.
ostream& operator<<(ostream& os, const Diccionario& D){
  return os;
  //IMPLEMENTAR FIXME
}
