#include "NodoAVL.h"
#include <list>
#include "Cancion.h"
template < class T >
NodoAVL<T>::NodoAVL(){
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
}

template < class T >
NodoAVL<T>::NodoAVL(T val){
    this->hijoIzq = nullptr;
    this->hijoDer = nullptr;
    this->dato = val;
}

template < class T >
NodoAVL<T>::~NodoAVL(){
    if (this->hijoIzq != nullptr){
        delete this->hijoIzq;
        this->hijoIzq = nullptr;
    }
    if (this->hijoDer != nullptr){
        delete this->hijoDer;
        this->hijoDer = nullptr;
    }
}

template < class T >
T NodoAVL<T>::GetDato() {
    return this->dato;
}

template < class T >
void NodoAVL<T>::SetDato(T val) {
    this->dato = val;
}

template < class T >
NodoAVL<T>* NodoAVL<T>::GetHijoDer() {
    return this->hijoDer;
}

template < class T >
NodoAVL<T>* NodoAVL<T>::GetHijoIzq() {
    return this->hijoIzq;
}

template < class T >
void NodoAVL<T>::SetHijoDer(NodoAVL<T> *der) {
    this->hijoDer = der;
}

template < class T >
void NodoAVL<T>::SetHijoIzq(NodoAVL<T> *izq) {
    this->hijoIzq = izq;
}

template < class T >
bool NodoAVL<T>::esHoja(){
    return (this->hijoIzq == nullptr && this->hijoDer == nullptr);
}

template < class T >
std::list<Cancion> NodoAVL<T>::GetCanciones() {
    return this->canciones;
}
