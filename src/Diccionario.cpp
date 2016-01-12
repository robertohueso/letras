#include "Diccionario.h"

void Diccionario::insertarPalabra(string palabra){
  char letra;
  ArbolGeneral<info>::Nodo nodo_actual = datos.raiz();
  ArbolGeneral<info>::Nodo nodo_padre;

  for(size_t i = 0; i < palabra.length(); i++){
    info nuevos_datos;
    nuevos_datos.c = (*letra);
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
        if(nodo_actual->etiqueta == nuevos_datos)
          encontrado = true;
        if(nodo_actual->drcha == NULL)
          derecha_nulo = true;
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

//Numero de palabras en el diccionario.
int Diccionario::size() const{
  int i = 0;
  ArbolGeneral::iter_preorden it;
  for(it = datos.begin(); it != datos.end(); it++){
    if((*it).final)
      i++;
  }
  return i;
}

//Devuelve palabras con una longitud dada.
vector<string> Diccionario::PalabrasLongitud(int longitud){
  //IMPLEMENTAR FIXME
}

//Indica si una palabra esta en el diccionario.
bool Diccionario::Esta(string palabra){
  //IMPLEMENTAR FIXME
}

//Lee de un flujo de entrada un diccionario.
friend istream & operator >>(istream& is, Diccionario &D){
  string palabra;
  while(!(is.eof())){
    getline(is, palabra, '\n');
    D.insertarPalabra(palabra);
  }
}

//Escribe salida del diccionario.
friend ostream& operator<<(ostream& os, const Diccionario& D){
  //IMPLEMENTAR FIXME
}
