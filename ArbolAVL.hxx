#include <algorithm> // Para std::max

template <class T>
ArbolAVL<T>::ArbolAVL() : raiz(nullptr) {}

template <class T>
ArbolAVL<T>::~ArbolAVL() {
    // Aquí debes implementar la lógica para liberar los recursos
    // Por ejemplo, llamando a una función recursiva para eliminar todos los nodos
    destruirNodos(raiz);
}

template <class T>
void ArbolAVL<T>::destruirNodos(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        destruirNodos(nodo->GetHijoIzq());
        destruirNodos(nodo->GetHijoDer());
        delete nodo;
    }
}

template <class T>
void ArbolAVL<T>::insertar(const T& val) {
    raiz = insertarRecursivo(raiz, val);
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::insertarRecursivo(NodoAVL<T>* nodo, const T& val) {
    if (nodo == nullptr) {
        return new NodoAVL<T>(val);
    }

    if (val < nodo->GetDato()) {
        nodo->SetHijoIzq(insertarRecursivo(nodo->GetHijoIzq(), val));
    } else if (val > nodo->GetDato()) {
        nodo->SetHijoDer(insertarRecursivo(nodo->GetHijoDer(), val));
    } else {
        
        return nodo;
    }


    actualizarAltura(nodo);
    nodo = balancear(nodo);

    return nodo;
}

template <class T>
void ArbolAVL<T>::actualizarAltura(NodoAVL<T>* nodo) {
    int alturaIzq = (nodo->GetHijoIzq() != nullptr) ? nodo->GetHijoIzq()->altura : 0;
    int alturaDer = (nodo->GetHijoDer() != nullptr) ? nodo->GetHijoDer()->altura : 0;
    nodo->altura = 1 + std::max(alturaIzq, alturaDer);
}


template <class T>
NodoAVL<T>* ArbolAVL<T>::balancear(NodoAVL<T>* nodo) {
    if (nodo == nullptr) return nodo;

    actualizarAltura(nodo);

    int balance = getBalance(nodo);

    // Si el nodo está desequilibrado hacia la izquierda
    if (balance > 1) {
        if (getBalance(nodo->GetHijoIzq()) < 0) {
            nodo->SetHijoIzq(rotarIzquierda(nodo->GetHijoIzq()));
        }
        return rotarDerecha(nodo);
    }
    // Si el nodo está desequilibrado hacia la derecha
    else if (balance < -1) {
        if (getBalance(nodo->GetHijoDer()) > 0) {
            nodo->SetHijoDer(rotarDerecha(nodo->GetHijoDer()));
        }
        return rotarIzquierda(nodo);
    }

    return nodo;
}

template <class T>
int ArbolAVL<T>::getBalance(NodoAVL<T>* nodo) {
    if (nodo == nullptr) return 0;
    int alturaIzq = (nodo->GetHijoIzq() != nullptr) ? nodo->GetHijoIzq()->altura : 0;
    int alturaDer = (nodo->GetHijoDer() != nullptr) ? nodo->GetHijoDer()->altura : 0;
    return alturaIzq - alturaDer;
}


template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarDerecha(NodoAVL<T>* y) {
    NodoAVL<T>* x = y->GetHijoIzq();
    NodoAVL<T>* T2 = x->GetHijoDer();

    // Realizar rotación
    x->SetHijoDer(y);
    y->SetHijoIzq(T2);

    // Actualizar alturas
    actualizarAltura(y);
    actualizarAltura(x);

    return x;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarIzquierda(NodoAVL<T>* x) {
    NodoAVL<T>* y = x->GetHijoDer();
    NodoAVL<T>* T2 = y->GetHijoIzq();

    // Realizar rotación
    y->SetHijoIzq(x);
    x->SetHijoDer(T2);

    // Actualizar alturas
    actualizarAltura(x);
    actualizarAltura(y);

    return y;
}


