#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"

template <class T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;

public:
    ArbolAVL();
     ~ArbolAVL();
     bool esVacio();
    int altura();
    int altura(NodoAVL<T>* nodo);
    bool insert(T& val);
    bool insertar(T& val);
    bool buscar(T& val);
    bool erase(T& val);
    bool eliminar(T& val);
    void preOrden(const std::string& archivo);
    NodoAVL<T>* esBalanceado();
    void rotacionIzquierda(T val);
    void rotacionDerecha(T val);
    int factorEquilibrio();
    int factorEquilibrio(NodoAVL<T>* nodo);
};

#include "ArbolAVL.hxx"

#endif // ARBOLAVL_H
