#include "Cola.h"


bool Cola::estaVaciaC(){
    return this->size==0;
}


void Cola::enqueque(Song* dato)
{
    Nodo *n = new Nodo(dato);
    if(estaVaciaC())
    {
        this->inicio=n;
        this->fin=n;
        this-> size++;
    }else{
        fin->setNext(n);
        this->fin=n;
        this->size++;
    }
}


Song* Cola::dequeque()
{
    if(this->estaVaciaC()){

       return 0;
    }else{

   Song* aux = this->inicio->getDato();
   this->inicio = this->inicio->getNext();
   this->size--;
   return aux;
   }
}


Song* Cola::peek()
{
    if(estaVaciaC()){

       return 0;
    }else{
     return this->inicio->getDato();
   }

}

