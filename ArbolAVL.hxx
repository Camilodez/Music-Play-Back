#include <algorithm> 

#include <fstream>
#include <queue>

template < class T >
ArbolAVL<T>::ArbolAVL() {
    this->raiz = NULL;
}


template < class T >
ArbolAVL<T>::~ArbolAVL() {
    if (this->raiz != NULL){
        delete this->raiz;
        this->raiz = NULL;
    }
}



template< class T >
bool ArbolAVL<T>::insert(T& val) {
  return this->insertar(val); }




template< class T >
bool ArbolAVL<T>::insertar(T& val) {
  bool res;
  
  if (this->raiz == NULL) {
    this->raiz = new NodoAVL<T>(val);
    res = true;
  } else {
    NodoAVL<T> *nraiz = this->raiz;
    res = this->raiz->insertar(val,&nraiz);
    this->raiz = nraiz;
  }

   esBalanceado();
  return res; 

   
  }



  template< class T >
bool ArbolAVL<T>::buscar(T& val) {
  bool res;
  if (this->raiz == NULL)
    res = false;
  else
    res = this->raiz->buscar(val);
    
  return res; }



  template< class T >
bool ArbolAVL<T>::erase(T& val) {
  return this->eliminar(val); }

template< class T >
bool ArbolAVL<T>::eliminar(T& val) {
  bool res;
  
  if (this->raiz == NULL)
    res = false;
  else if (this->raiz->esHoja() && this->raiz->GetDato() == val) {
    delete this->raiz;
    this->raiz = NULL;
    res = true;
  } else {
    NodoAVL<T> *nraiz = this->raiz;
    res = this->raiz->eliminar(val,&nraiz);
    this->raiz = nraiz;
  }
  
  return res; }



template< class T >
void ArbolAVL<T>::preOrden(const std::string& archivo) {

  std::ofstream outFile(archivo, std::ios::app);
    if (!outFile) {
            return;
        }

    
        if (this->raiz != nullptr) {
         this->raiz->preOrden(outFile);
        }  

        outFile << "&" << std::endl; // Delimitador de final de árbol
        outFile.close();
}



template <class T>
  NodoAVL<T>* ArbolAVL<T>::esBalanceado() {
  NodoAVL<T>* aux = NULL;
  NodoAVL<T>* nodoRetorno = NULL;
  bool lado = false;
  if(!this->esVacio()){
        std::queue<NodoAVL<T>*> cola;

        cola.push(this->raiz);
        while(!cola.empty()){
            aux = cola.front();
            cola.pop();

            //Si esta desequilibrado, retorna el ultimo nodo desbalanceado
            if(factorEquilibrio(aux) == -2) {
              nodoRetorno = aux;
              lado = true;
            }
            else if (factorEquilibrio(aux) == 2){
              nodoRetorno = aux;
              lado = false;
            }

            if(aux->GetHijoIzq() != NULL){
                cola.push(aux->GetHijoIzq());
            }
            if(aux->GetHijoDer() != NULL){
                cola.push(aux->GetHijoDer());
            } 
        }
    }
  //Si esta equilibrado, retorna null
  if(nodoRetorno != NULL) {
    if(lado) {
       
        if(factorEquilibrio(nodoRetorno->GetHijoDer()) == 1) {
       
            rotacionDerecha(nodoRetorno->GetHijoDer()->GetDato());
        }
        rotacionIzquierda(nodoRetorno->GetDato());
    }
    else{
       
        if(factorEquilibrio(nodoRetorno->GetHijoIzq()) == -1) {
      
            rotacionIzquierda(nodoRetorno->GetHijoIzq()->GetDato());
        }
        rotacionDerecha(nodoRetorno->GetDato());
    }
    esBalanceado();
  }
  return nodoRetorno;
}

template <class T>
void ArbolAVL<T>::rotacionIzquierda(T val) {
  bool lado; //Para saber a que lado del padre esta el nodo desbalanceado
  NodoAVL<T>* nuevoPadre;
  NodoAVL<T>* hijo = this->raiz;
  NodoAVL<T>* padre = this->raiz;

  while(hijo != NULL){
      if (val < hijo->GetDato()){
          padre = hijo;
          hijo = hijo->GetHijoIzq();
          lado = true;
      } else if (val > hijo->GetDato()){
          padre = hijo;
          hijo = hijo->GetHijoDer();
          lado = false;
      } else {
          break;
      }
  }

  //el if es si el desbalanceo es en la raiz
  if(hijo->GetDato() == this->raiz->GetDato()) {
    nuevoPadre = hijo->GetHijoDer();
    hijo->SetHijoDer(nuevoPadre->GetHijoIzq());
    nuevoPadre->SetHijoIzq(hijo);
    this->raiz = nuevoPadre;
  }
  else {
    nuevoPadre = hijo->GetHijoDer();
    hijo->SetHijoDer(nuevoPadre->GetHijoIzq());
    nuevoPadre->SetHijoIzq(hijo);

    if(lado) {
      padre->SetHijoIzq(nuevoPadre);
    }
    else {
      padre->SetHijoDer(nuevoPadre);
    }
  }
}

template <class T>
void ArbolAVL<T>::rotacionDerecha(T val) {
  bool lado;
  NodoAVL<T>* nuevoPadre;
  NodoAVL<T>* hijo = this->raiz;
  NodoAVL<T>* padre = this->raiz;

  while(hijo != NULL){
      if (val < hijo->GetDato()){
          padre = hijo;
          hijo = hijo->GetHijoIzq();
          lado = true;
      } else if (val > hijo->GetDato()){
          padre = hijo;
          hijo = hijo->GetHijoDer();
          lado = false;
      } else {
          break;
      }
  }

  //el if es si el desbalanceo es en la raiz
  if(hijo->GetDato() == this->raiz->GetDato()) {
    nuevoPadre = hijo->GetHijoIzq();
    hijo->SetHijoIzq(nuevoPadre->GetHijoDer());
    nuevoPadre->SetHijoDer(hijo);
    this->raiz = nuevoPadre;
  }
  else {
    nuevoPadre = hijo->GetHijoIzq();
    hijo->SetHijoIzq(nuevoPadre->GetHijoDer());
    nuevoPadre->SetHijoDer(hijo);
    
    if(lado) {
      padre->SetHijoIzq(nuevoPadre);
    }
    else {
      padre->SetHijoDer(nuevoPadre);
    }
  }
}


template <class T>
int ArbolAVL<T>::factorEquilibrio() {
    return factorEquilibrio(this->raiz);
}


template <class T>
int ArbolAVL<T>::factorEquilibrio(NodoAVL<T>* nodo) {
    return altura(nodo->GetHijoIzq()) - altura(nodo->GetHijoDer());
    //Si el resultado esta entre -1 y 1, esta balanceado
}


template < class T >
bool ArbolAVL<T>::esVacio() {
    return this->raiz == NULL; //Si no tenemos raiz, el arbol es vacio
}


template < class T >
int ArbolAVL<T>::altura(NodoAVL<T>* nodo){
  if(nodo != NULL) {
    int hi=altura(nodo->GetHijoIzq());
    int hd=altura(nodo->GetHijoDer());
    if(hi>hd) {
      return hi+1;
    }
    else {
      return hd+1;
    }
  }
  else {
    return 0;
  }
}


template < class T >
int ArbolAVL<T>::altura() {
    if (this->esVacio()){
        return -1;
    } else {
        return this->altura(this->raiz)-1;
    }
}