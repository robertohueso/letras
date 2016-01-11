//Constructor parametros nodo
template <class Tbase>
ArbolGeneral<Tbase>::nodo::nodo(const Tbase &etiqueta, nodo *izqda, nodo *drcha, nodo *padre)
  : etiqueta(etiqueta), izqda(izqda), drcha(drcha), padre(padre)
  {}

//Destruye el nodo n y sus descendientes.
template <class Tbase>
void ArbolGeneral<Tbase>::destruir(nodo *n){
  if(n != NULL){
    this->destruirConHermanos(n->izqda);
    delete n;
  }
}

//Destruye el nodo n, sus descendientes y sus hermanos.
template <class Tbase>
void ArbolGeneral<Tbase>::destruirConHermanos(nodo *n){
  if(n != NULL){
    this->destruirConHermanos(n->izqda);
    this->destruirConHermanos(n->drcha);
    delete n;
  }
}

//Copia subarbol FIXME
//no es lo mas apropiado
template <class Tbase>
void ArbolGeneral<Tbase>::copiar(nodo *& dest, nodo * orig){
  dest = new nodo(orig->etiqueta, NULL, NULL, NULL);

  if(orig->izqda != NULL){
    nodo * nodo_actual = orig->izqda;
    while(nodo_actual != NULL){
      this->copiar(, nodo_actual);
      nodo_actual = nodo_actual->drcha;
    }
  }

  nodo * nodo_actual = orig->izqda;
  while(nodo_actual != NULL){
    this->copiar(dest->izqda, nodo_actual);
    dest->izqda->padre = dest;
    nodo_actual = nodo_actual->drcha;
  }
}


//Cuenta el numero de nodos que cuelgan de n
template <class Tbase>
int ArbolGeneral<Tbase>::contar(const nodo *n) const{
  int tamanio = 1;
  for(Nodo hijo = n->izqda; hijo != NULL; hijo = hijo->drcha)
    tamanio = tamanio + this->contar(hijo);
  return tamanio;
}

//Comprueba si 2 subarboles son iguales
template <class Tbase>
bool ArbolGeneral<Tbase>::soniguales(const nodo *n1, const nodo *n2) const{
  if(n1->etiqueta == n2->etiqueta && soniguales(n1->izqda, n2->izqda) && soniguales(n1->drcha, n2->drcha))
    return true;
  else
    return false;
}

//Escribe subarbol en la salida
template <class Tbase>
void ArbolGeneral<Tbase>::escribe_arbol(std::ostream& out, nodo *nod) const{
  if(nod == NULL)
    out << "x"
  else{
    out << "n " << nod->etiqueta;
    escribe_arbol(out, nod->izqda);
    escribe_arbol(out, nod->drcha);
  }
}

//Lee un arbol
template <class Tbase>
void ArbolGeneral<Tbase>::lee_arbol(std::istream& in, nodo *& nod){
  //IMPLEMENTAR AUN-----------------------
}

//Constructor por defecto
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(): laraiz(NULL)
  {}

//Constructor raiz
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const Tbase& e){
  this->laraiz = new nodo;
  this->laraiz->etiqueta = e;
}

//Constructor copia
template <class Tbase>
ArbolGeneral<Tbase>::ArbolGeneral(const ArbolGeneral<Tbase>& v){
  this->copiar(this->laraiz, v.laraiz);
}

//Destructor
template <class Tbase>
ArbolGeneral<Tbase>::~ArbolGeneral(){
  this->destruir(this->laraiz);
}

//Operador =
template <class Tbase>
ArbolGeneral<Tbase>& ArbolGeneral<Tbase>::operator=(const ArbolGeneral<Tbase> &v){
  this->destruir(this->laraiz);
  this->copiar(this->laraiz, v.laraiz, NULL);
  return this;
}

//Asigna raiz
template <class Tbase>
void ArbolGeneral<Tbase>::AsignaRaiz(const Tbase& e){
  this->destruir(this->laraiz);
  this->laraiz = new nodo(e, NULL, NULL, NULL);
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
  this->destruir(this->laraiz);
  this->copiar(this->root, nod, NULL);
}

//Poda el hijo a la izquierda de n y lo copia en dest
template <class Tbase>
void ArbolGeneral<Tbase>::podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest){
  if(!(dest.empty()))
    dest.clear();
  if(n->izqda != NULL){
    dest.laraiz = n->izqda;
    dest.laraiz->padre = NULL;
    n->izqda = NULL;
  }
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
  this->destruir(this->laraiz);
  this->laraiz = NULL;
}

//Devuelve cantidad de nodos del arbol
template <class Tbase>
int ArbolGeneral<Tbase>::size() const{
  return this->contar(this->laraiz);
}

//Comprueba si el arbol esta vacio
template <class Tbase>
bool ArbolGeneral<Tbase>::empty() const{
  return this->laraiz == NULL;
}

//Comprueba si dos los arboles son iguales
template <class Tbase>
bool ArbolGeneral<Tbase>::operator==(const ArbolGeneral<Tbase>& v) const{
  return this->soniguales(this->laraiz, v.laraiz);
}

//Comprueba si dos los arboles son diferentes
template <class Tbase>
bool ArbolGeneral<Tbase>::operator!=(const ArbolGeneral<Tbase>& v) const{
  return !(this->soniguales(this->laraiz, v.laraiz));
}

//Operator >> para insertar el arbol en v
template <class T>
std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v){
  //IMPLEMENTAR AUN-----------------------
}

//Operator << para imprimir el arbol v
template <class T>
std::ostream& operator<<(std::ostream& out, const ArbolGeneral<T>& v){
  v.escribe_arbol(out, v.laraiz);
  return out;
}

//----ITERADOR NO CONSTANTE----------------------------------------------

//Constructor del iterador
template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden::iter_preorden(){
  this->it = NULL;
  this->raiz = NULL;
  this->level = 0;
}

//Devuelve la etiqueta del nodo
template <class Tbase>
Tbase& ArbolGeneral<Tbase>::iter_preorden::operator*(){
  return *(it->etiqueta);
}

//Devuelve el nivel del nodo
template <class Tbase>
int ArbolGeneral<Tbase>::iter_preorden::getlevel() const{
  return this->level;
}

//Siguiente nodo
template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden& ArbolGeneral<Tbase>::iter_preorden::operator ++(){
  if(it->izqda != NULL)
    it = it->izqda;
  else if(it->drcha != NULL)
    it = it->drcha;
  else{
    while(it->padre != NULL && it->padre->drcha == NULL){
      it = it->padre;
    }
    if(it->padre == NULL){
      iterador.it = NULL;
      iterador.raiz = this->laraiz;
    }else {
      it = it->padre->drcha;
    }
  }
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

//Iterator begin
template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::begin(){
  ArbolGeneral<Tbase>::iter_preorden iterador;
  iterador.it = this->laraiz;
  iterador.raiz = this->laraiz;
  iterador.level = 0;
  return iterador;
}

//Iterator end
template <class Tbase>
ArbolGeneral<Tbase>::iter_preorden ArbolGeneral<Tbase>::end(){
  ArbolGeneral<Tbase>::iter_preorden iterador;
  iterador.it = NULL;
  iterador.raiz = this->laraiz;
  iterador.level = 0;
  return iterador;
}
