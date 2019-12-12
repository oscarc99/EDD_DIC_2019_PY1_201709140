#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

template<class T>
class ListaSimple
{
     class Nodo
    {
        public:
        Nodo(T x)
        {
            dato =x;
            next = 0;

        }
        void setNext(Nodo *n)
        {
            next = n;
        }

        Nodo *getNext()
        {
            return next;
        }


        T getDato()
        {
            return dato;
        }

            Nodo *next;
            T dato;
    };
    public:
        ListaSimple()
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
void ListaSimple<T>::add_first(T dato)
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
        this->first = n;
        this->size++;
    }
}

template<class T>
void ListaSimple<T>::add_last(T dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        this->last->setNext(n);
        this->last = n;
        this->size++;
    }
}


template<class T>
void ListaSimple<T>::add_at(T dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index-1){break;}
            aux = aux->getNext();
            x++;
        }
        Nodo *n = new Nodo(dato);
        n->setNext(aux->getNext());
        aux->setNext(n);
        this->size++;
    }
}


template<class T>
T ListaSimple<T>::get_element_at(int index)
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

}

template <class T>
void ListaSimple<T>::remove_at(int index)
{
    Nodo *aux = this->first;
    if(index >= 0 && index < size)
    {
        if(index ==0){

            this->first = aux->getNext();
            this->size--;
            return;
        }
        Nodo *aux = this->first;
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
#endif // ISTADOBLE_H
