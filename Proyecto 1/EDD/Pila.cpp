#include "Pila.h"

bool Pila::estaVacia(){
    return this->size==0;
}


void Pila::push(Song* dato)
{
    NodoP *n = new NodoP(dato);
    if(estaVacia())
    {
        this->cima=n;
        this-> size++;
    }else{
        n->setNext(this->cima);
        this->cima=n;
        this->size++;
    }
}


Song* Pila::pop()
{
    if(estaVacia()){

       return 0;
    }else{

   Song* aux = this->cima->getDato();
   this->cima = this->cima->getNext();
   this->size--;
   return aux;
   }
}

Song* Pila::peek()
{
    if(estaVacia()){

       return 0;
    }else{
    return this->cima->getDato();
   }
}

