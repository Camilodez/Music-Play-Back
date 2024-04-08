#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"

template <class T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;

    NodoAVL<T>* insertarRecursivo(NodoAVL<T>* nodo, const T& val);
    void actualizarAltura(NodoAVL<T>* nodo);
    NodoAVL<T>* balancear(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarDerecha(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarIzquierda(NodoAVL<T>* nodo);
    int getBalance(NodoAVL<T>* nodo);
    void destruirNodos(NodoAVL<T>* nodo);

public:
    ArbolAVL();
     ~ArbolAVL();
    void insertar(const T& val);
    
};

#include "ArbolAVL.hxx"

#endif // ARBOLAVL_H
