//Constructor por defecto
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(){
  this->laraiz = NULL;
}

//Constructor raiz
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
  this->laraiz = new nodo;
  this->laraiz->etiqueta = e;
}

//Constructor copia
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v){
  //IMPLEMENTAR AUN-----------------------
}

//Destructor
template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
  //IMPLEMENTAR AUN-----------------------
}

//Operador =
template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase> &v){
  //IMPLEMENTAR AUN-----------------------
}

//Asigna raiz
template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
  //IMPLEMENTAR AUN-----------------------
}

//Devuelve la raiz
template <class Tbase>
ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::raiz() const{
  return this->laraiz;
}

//Devuelve hijo mas izquierda
template <class Tbase>
ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hijomasizquierda(const Nodo n) const{
  return n->izqda;
}

//Devuelve hermano a la derecha
template <class Tbase>
ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::hermanoderecha(const Nodo n) const{
  return n->drcha;
}

//Devuelve padre
template <class Tbase>
ArbolGeneral<Tbase>::Nodo ArbolGeneral<Tbase>::padre(const Nodo n) const{
  return n->padre;
}

//Devuelve referencia a etiqueta
template <class Tbase>
Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n){
  return *(n->etiqueta);
}

//Devuelve referencia a etiqueta
template <class Tbase>
const Tbase& ArbolGeneral<Tbase>::etiqueta(const Nodo n) const{
  return *(n->etiqueta);
}

//Copia arbol en subarbol
template <class Tbase>
void ArbolGeneral<Tbase>::asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod){
  //IMPLEMENTAR AUN-----------------------
}

//Poda el hijo a la izquierda de n y lo copia en dest
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
  //IMPLEMENTAR AUN-----------------------
}

//Poda el hermano a la derecha de n y lo copia en dest
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest){
  //IMPLEMENTAR AUN-----------------------
}

//Inserta como hijo a la izquierda de n el arbol rama
template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama){
  //IMPLEMENTAR AUN-----------------------
}

//Inserta como hermano a la derecha de n el arbol rama
template <class Tbase>
void ArbolGeneral<Tbase>::insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama){
  //IMPLEMENTAR AUN-----------------------
}

//Vacia el arbol
template <class Tbase>
void ArbolGeneral<Tbase>::clear(){
  //IMPLEMENTAR AUN-----------------------
}

//Devuelve cantidad de nodos del arbol
template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
  //IMPLEMENTAR AUN-----------------------
}

//Comprueba si el arbol esta vacio
template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
  return this->laraiz == NULL;
}

//Comprueba si dos los arboles son iguales
template <class Tbase>
bool ArbolGeneral<Tbase>::operator==(const ArbolGeneral<Tbase>& v) const{
  //IMPLEMENTAR AUN-----------------------
}

//Comprueba si dos los arboles son diferentes
template <class Tbase>
bool ArbolGeneral<Tbase>::operator!=(const ArbolGeneral<Tbase>& v) const{
  //IMPLEMENTAR AUN-----------------------
}

//Operator >> para insertar el arbol en v
template <class T>
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v){
  //IMPLEMENTAR AUN-----------------------
}

//Operator << para imprimir el arbol v
template <class T>
std::ostream& operator<<(std::ostream& out, const ArbolGeneral<T>& v){
  //IMPLEMENTAR AUN-----------------------
}

//ITERADOR NO CONSTANTE----------------------------------------------

//Constructor del iterador
template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden::iter_preorden(){
  //IMPLEMENTAR AUN-----------------------
}

//Devuelve la etiqueta del nodo
template <class Tbase>
Tbase& ArbolGeneral<Tbase>::iter_preorden::operator*(){
  return *(it->etiqueta);
}

//Devuelve el nivel del nodo
template <class Tbase>
int ArbolGeneral<Tbase>::iter_preorden::getlevel() const{
  //IMPLEMENTAR AUN-----------------------
}

//Siguiente nodo
template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden& ArbolGeneral<Tbase>::iter_preorden::operator ++(){
  //IMPLEMENTAR AUN-----------------------
}

//Compara la igualdad de 2 iteradores
template <class Tbase>
bool ArbolGeneral<Tbase>::iter_preorden::operator==(const iter_preorden &i){
  return (this->it == i.it && this->raiz == i.raiz);
}

//Compara la desigualdad de 2 iteradores
template <class Tbase>
bool ArbolGeneral<Tbase>::iter_preorden::operator!=(const iter_preorden &i){
  return (this->it != i.it || this->raiz != i.raiz);
}
