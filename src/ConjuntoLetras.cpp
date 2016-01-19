#include "ConjuntoLetras.h"
#include <iostream>
#include <fstream>

Letra ConjuntoLetras::Encontrar(Letra L){
	Letra *p;
	*p = conjunto.find(L);
	return *p;
}

 void ConjuntoLetras::Insertar(Letra L){
 	conjunto.insert(L);
 }

ConjuntoLetras::iterator ConjuntoLetras::begin(){
	ConjuntoLetras::iterator iter_nuevo;
	iter_nuevo.it = conjunto.begin();
	return iter_nuevo;
}

ConjuntoLetras::iterator ConjuntoLetras::end(){
	ConjuntoLetras::iterator iter_nuevo;
	iter_nuevo.it = conjunto.end();
	return iter_nuevo;
}
ConjuntoLetras::const_iterator ConjuntoLetras::cbegin(){
	ConjuntoLetras::const_iterator iter_nuevo;
	iter_nuevo.it = conjunto.cbegin();
	return iter_nuevo;
}
ConjuntoLetras::const_iterator ConjuntoLetras::cend(){
	ConjuntoLetras::const_iterator iter_nuevo;
	iter_nuevo.it = conjunto.cend();
	return iter_nuevo;
}


ConjuntoLetras::iterator ConjuntoLetras::iterator::operator++ (){
	this->it++;
	return *this;
}
