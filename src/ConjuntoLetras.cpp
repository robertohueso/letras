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

ostream & operator<<(ostream& os, const ConjuntoLetras &conj){
	os << "#Letra Cantidad Puntos\n";
	for(ConjuntoLetras::const_iterator it = conj.cbegin(); it != conj.cend(); ++it)
		os << (*it).getCaracter() << " " << (*it).getRepeticiones() << " " << (*it).getPuntuacion() << "\n";
	return os;
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
*/

ConjuntoLetras::const_iterator ConjuntoLetras::const_iterator::operator++(){
	++it;
	return *this;
}

Letra ConjuntoLetras::const_iterator::operator*() const{
	Letra letra(it->second.getCaracter(), it->second.getRepeticiones(), it->second.getPuntuacion());
	return letra;
}

bool ConjuntoLetras::const_iterator::operator!=(const const_iterator &otro_it) const{
	return (this->it == otro_it.it);
}

ConjuntoLetras::const_iterator ConjuntoLetras::cbegin() const{
	map<char, Letra>::const_iterator nuevo_iterador;
	nuevo_iterador.it = conjunto.cbegin();
	return nuevo_iterador;
}

ConjuntoLetras::const_iterator ConjuntoLetras::cend() const{
	map<char, Letra>::const_iterator nuevo_iterador;
	nuevo_iterador.it = conjunto.cend();
	return nuevo_iterador;
}
