#include "ConjuntoLetras.h"


ConjuntoLetras::ConjuntoLetras(){}

void ConjuntoLetras::autoRepartirCantidades(){
	double letras_totales = 0.0;
	for(ConjuntoLetras::iterator it = this->begin(); it != this->end(); ++it)
		letras_totales += (*it).getRepeticiones();
	for(ConjuntoLetras::iterator it = this->begin(); it != this->end(); ++it){
		unsigned int cantidad = ((*it).getRepeticiones()/letras_totales)*100;
		if(cantidad==0)
			cantidad=1;
		(*it).setRepeticiones(cantidad);
	}
}

void ConjuntoLetras::setPuntos(const char &letra, unsigned int puntos){
	map<char, Letra>::iterator it;
	it = conjunto.find(letra);
	if(it != conjunto.end())
		it->second.setPuntos(puntos);
}

void ConjuntoLetras::insertar(const Letra &nueva_letra){
	pair<map<char, Letra>::iterator, bool> resultado;
	pair<char, Letra> nueva_inserccion(nueva_letra.getCaracter(), nueva_letra);
	resultado = conjunto.insert(nueva_inserccion);
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

istream& ConjuntoLetras::leerPuntos(istream& is){
	string basura;
	string letra;
	string repeticiones;
	string puntos;
	unsigned int valor;

	getline(is, basura, '\n');
	while(!is.eof()){
		getline(is, letra, '\t');
		getline(is, repeticiones, '\t');
		getline(is, puntos, '\n');

		valor = atoi(puntos.c_str());
		this->setPuntos((char)tolower(letra[0]),valor);
	}
	return is;
}

istream & operator>>(istream& is, ConjuntoLetras &conj){
	char c;
	while(!is.eof()){
		is >> c;
		Letra nueva_letra(tolower(c));
		conj.insertar(nueva_letra);
	}
	conj.autoRepartirCantidades();
	return is;
}

void operator>>(const Diccionario &Dic, ConjuntoLetras &conj){
	Diccionario::const_iterator palabra;
	char c;

	for(palabra = Dic.cbegin(); palabra != Dic.cend(); ++palabra){
		for(size_t i = 0; i < (*palabra).size(); i++){
			c = (*palabra)[i];
			Letra nueva_letra(tolower(c));
			conj.insertar(nueva_letra);
		}
	}
	conj.autoRepartirCantidades();
}

ostream & operator<<(ostream& os, const ConjuntoLetras &conj){
	os << "#Letra Cantidad Puntos\n";
	for(ConjuntoLetras::const_iterator it = conj.cbegin(); it != conj.cend(); ++it)
		os << (*it).getCaracter() << "\t" << (*it).getRepeticiones() << "\t" << (*it).getPuntuacion() << "\n";
	return os;
}

//--------ITERATOR------------------------------------------------

ConjuntoLetras::iterator::iterator(){}

ConjuntoLetras::iterator& ConjuntoLetras::iterator::operator++(){
	++it;
	return *this;
}

Letra& ConjuntoLetras::iterator::operator*(){
	return (*it).second;
}

bool ConjuntoLetras::iterator::operator!=(const iterator &otro_it) const{
	return (this->it != otro_it.it);
}

bool ConjuntoLetras::iterator::operator==(const iterator &otro_it) const{
	return (this->it == otro_it.it);
}

ConjuntoLetras::iterator ConjuntoLetras::begin(){
	ConjuntoLetras::iterator nuevo_iterador;
	nuevo_iterador.it = conjunto.begin();
	return nuevo_iterador;
}

ConjuntoLetras::iterator ConjuntoLetras::end(){
	ConjuntoLetras::iterator nuevo_iterador;
	nuevo_iterador.it = conjunto.end();
	return nuevo_iterador;
}

//--------CONST_ITERATOR------------------------------------------

ConjuntoLetras::const_iterator::const_iterator(){}

ConjuntoLetras::const_iterator& ConjuntoLetras::const_iterator::operator++(){
	++it;
	return *this;
}

Letra ConjuntoLetras::const_iterator::operator*() const{
	return (*it).second;
}

bool ConjuntoLetras::const_iterator::operator!=(const const_iterator &otro_it) const{
	return (this->it != otro_it.it);
}

bool ConjuntoLetras::const_iterator::operator==(const const_iterator &otro_it) const{
	return (this->it == otro_it.it);
}

ConjuntoLetras::const_iterator ConjuntoLetras::cbegin() const{
	ConjuntoLetras::const_iterator nuevo_iterador;
	nuevo_iterador.it = conjunto.begin();
	return nuevo_iterador;
}

ConjuntoLetras::const_iterator ConjuntoLetras::cend() const{
	ConjuntoLetras::const_iterator nuevo_iterador;
	nuevo_iterador.it = conjunto.end();
	return nuevo_iterador;
}
