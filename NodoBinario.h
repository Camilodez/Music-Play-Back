#ifndef NODO_BINARIO_H
#define NODO_BINARIO_H

#include <list>
#include "Cancion.h"
#include <algorithm>

class NodoBinario {
private:
    std::list<Cancion> canciones; // Lista de canciones en el nodo
    NodoBinario* izquierdo; // Puntero al hijo izquierdo
    NodoBinario* derecho; // Puntero al hijo derecho
    int altura;

public:
    // Constructor
    NodoBinario() : izquierdo(nullptr), derecho(nullptr) {}

    // Getters y setters para los punteros a los nodos hijos
    NodoBinario* getIzquierdo() const { return izquierdo; }
    void setIzquierdo(NodoBinario* nodo) { izquierdo = nodo; }

    NodoBinario* getDerecho() const { return derecho; }
    void setDerecho(NodoBinario* nodo) { derecho = nodo; }


    // Funciones para manejar la lista de canciones
    void agregarCancion(const Cancion& cancion) {
        canciones.push_back(cancion);
        balancear(); // Balancear después de agregar una canción
    }

  

    void borrarCancion(int id) {
        auto it = std::find_if(canciones.begin(), canciones.end(), [id](const Cancion& cancion) {
            return cancion.getID() == id;
        });
        if (it != canciones.end()) {
            canciones.erase(it);
            balancear(); // Balancear después de borrar una canción
        }
    }


    // Métodos para calcular el factor de balance y realizar rotaciones
    int balanceFactor() {
        int alturaIzquierda = izquierdo ? izquierdo->altura : 0;
        int alturaDerecha = derecho ? derecho->altura : 0;
        return alturaIzquierda - alturaDerecha;
    }

    void actualizarAltura() {
        int alturaIzquierda = izquierdo ? izquierdo->altura : 0;
        int alturaDerecha = derecho ? derecho->altura : 0;
        altura = 1 + std::max(alturaIzquierda, alturaDerecha);
    }

    NodoBinario* rotarIzquierda() {
        NodoBinario* nodo = derecho;
        derecho = nodo->izquierdo;
        nodo->izquierdo = this;
        actualizarAltura();
        nodo->actualizarAltura();
        return nodo;
    }

    NodoBinario* rotarDerecha() {
        NodoBinario* nodo = izquierdo;
        izquierdo = nodo->derecho;
        nodo->derecho = this;
        actualizarAltura();
        nodo->actualizarAltura();
        return nodo;
    }

    // Función para balancear el nodo, esta función sería llamada después de inserciones o eliminaciones
    NodoBinario* balancear() {
        actualizarAltura();
        int balance = balanceFactor();

        if (balance > 1) {
            if (izquierdo->balanceFactor() < 0) {
                izquierdo = izquierdo->rotarIzquierda();
            }
            return rotarDerecha();
        } else if (balance < -1) {
            if (derecho->balanceFactor() > 0) {
                derecho = derecho->rotarDerecha();
            }
            return rotarIzquierda();
        }
        return this;
    }

};

#endif // NODO_BINARIO_H
