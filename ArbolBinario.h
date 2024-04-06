#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H

#include "NodoBinario.h"

class ArbolBinario {
private:
    NodoBinario* raiz;

    // Métodos privados para manejar el balanceo, rotaciones, inserción y eliminación
    int obtenerAltura(NodoBinario* nodo) const;
    int obtenerFactorBalance(NodoBinario* nodo) const;
    NodoBinario* rotarDerecha(NodoBinario* y);
    NodoBinario* rotarIzquierda(NodoBinario* x);
    NodoBinario* insertar(NodoBinario* nodo, const Cancion& cancion);
    NodoBinario* eliminar(NodoBinario* nodo, const Cancion& cancion);


    NodoBinario* insertar(NodoBinario* nodo, const Cancion& cancion) {
        if (nodo == nullptr) {
            return new NodoBinario(cancion);
        }

        if (cancion.getID() < nodo->clave) {
            nodo->izquierdo = insertar(nodo->izquierdo, cancion);
        } else if (cancion.getID() > nodo->clave) {
            nodo->derecho = insertar(nodo->derecho, cancion);
        } else {
            // Encontrado el nodo adecuado, agregamos la canción a este nodo
            nodo->agregarCancion(cancion);
            return nodo;
        }

        // Aquí agregarías el código para balancear el árbol si fuera necesario

        return nodo;
    }


public:
    ArbolBinario() : raiz(nullptr) {}

    // Métodos públicos para interactuar con el árbol
    void insertar(const Cancion& cancion);
    void eliminar(const Cancion& cancion);
    

    void agregar(const Cancion& cancion) {
        raiz = insertar(raiz, cancion);
    }
};

#endif // ARBOL_BINARIO_H
