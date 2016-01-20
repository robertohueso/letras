#include "ConjuntoLetras.h"

void ConjuntoLetras::insertar(const Letra &nueva_letra){
	pair<map<char, Letra>::iterator, bool> resultado;
	pair<char, Letra> nueva_inserccion(nueva_letra.getCaracter(), nueva_letra);
	resultado = conjunto.insert(nueva_inserccion);
 	if(!resultado.second)
		++(resultado.first->second);
}

Letra ConjuntoLetras::getLetra(const char &letra_a_buscar) const{
	map<char, Letra>::const_iterator it;
	it = conjunto.find(letra_a_buscar);
	if(it != conjunto.end())
		return it->second;
	else{
		Letra letra;
		return letra;
	}
}

istream & operator>>(istream& is, ConjuntoLetras &conj){
	char c;
	while(!is.eof()){
		is >> c;
		conj.insertar(Letra(c));
	}
}

/*ConjuntoLetras::iterator ConjuntoLetras::begin(){
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
}*/
