#ifndef __NODOAVL_H__
#define __NODOAVL_H__

#include "Cancion.h"
#include <list>
#include <fstream>

template < class T >
class NodoAVL {
    public:
        std::list<Cancion> canciones;
        T dato;
        NodoAVL<T>* hijoIzq;
        NodoAVL<T>* hijoDer;
        int altura;

        
    public:
        NodoAVL();
        NodoAVL(T val);
        ~NodoAVL();
        T GetDato();
        void SetDato(T val);
        NodoAVL<T>* GetHijoIzq();
        NodoAVL<T>* GetHijoDer();
        void SetHijoIzq(NodoAVL<T> *izq);
        void SetHijoDer(NodoAVL<T> *der);
        bool esHoja();
        std::list<Cancion> GetCanciones();

        void preOrden(std::ofstream& outfile);

        bool insertar(T& val, NodoAVL<T> **nraiz);


    
};

#include "nodoAVL.hxx"

#endif