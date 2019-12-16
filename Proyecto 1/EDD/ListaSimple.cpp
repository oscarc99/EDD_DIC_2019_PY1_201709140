#include "ListaSimple.h"


void ListaSimple::add_first(Song* dato)
{
    NodoLS *n = new NodoLS(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first = n;
        this->size++;
    }
}


void ListaSimple::add_last(Song* dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        NodoLS *n = new NodoLS(dato);
        this->last->setNext(n);
        this->last = n;
        this->size++;
    }
}



void ListaSimple::add_at(Song* dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        NodoLS *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index-1){break;}
            aux = aux->getNext();
            x++;
        }
        NodoLS *n = new NodoLS(dato);
        n->setNext(aux->getNext());
        aux->setNext(n);
        this->size++;
    }
}



Song* ListaSimple::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        NodoLS *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }else{

        return 0;
    }

}


void ListaSimple::remove_at(int index)
{
    if(index >= 0 && index < size)
    {
        NodoLS *aux = this->first;
        if(index ==0){

            this->first = aux->getNext();
            this->size--;
            return;
        }

        int x = 0;
        while(aux!=0)
        {
            if(x == index-1){break;}
            aux = aux->getNext();
            x++;
        }

        if (index==this->size-1){
            aux->setNext(0);
            this->last= aux;
            this->size--;
        }else{
            aux->setNext(aux->getNext()->getNext());
            this->size--;
        }




    }

}
