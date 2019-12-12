#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include <string>

using namespace std;

template<class T>
class ListaDoble
{
    class Nodo
    {
        public:
        Nodo(T x)
        {
            dato =x;
            next = 0;
            before=0;
        }
        void setNext(Nodo *n)
        {
            next = n;
        }

        Nodo *getNext()
        {
            return next;
        }

        void setBefore(Nodo *n)
        {
            before = n;
        }

        Nodo *getBefore()
        {
            return before;
        }


        T getDato()
        {
            return dato;
        }

            Nodo *next;
            Nodo *before;
            T dato;
    };
    public:
        ListaDoble()
        {
             first = 0;
             last = 0;
             size = 0;
        }
         int getSize(){return size;}
         void add_first(T dato);
         void add_last(T dato);
         void add_at(T dato, int index);
         T get_element_at(int index);
         void remove_at(int index);


    private:
         bool isEmpty(){return size == 0;}
         int size;
         Nodo *first;
         Nodo *last;
};

template<class T>
void ListaDoble<T>::add_first(T dato)
{
    Nodo *n = new Nodo(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->size++;
    }
}

template<class T>
void ListaDoble<T>::add_last(T dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;
    }
}

template<class T>
void ListaDoble<T>::add_at(T dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        Nodo *n = new Nodo(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}

template<class T>
T ListaDoble<T>::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
        return 0;


}

template <class T>
void ListaDoble<T>::remove_at(int index)
{
     if(index >= 0 && index < size)
     {
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }

        if(index ==0){

            this->first = aux->getNext();
            this->first->setBefore(0);
            this->size--;

        }else if (index==this->size-1){
            this->last= aux->getBefore();
            this->last->setNext(0);
            this->size--;
        }else{
            aux->before->setNext(aux->getNext());
            aux->next->setBefore(aux->getBefore());
            this->size--;
        }





    }
}
#endif // LISTADOBLE_H
