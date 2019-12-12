#ifndef LISTADOBLECICULAR_H
#define LISTADOBLECICULAR_H

template<class T>
class ListaDobleCicular
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
        ListaDobleCircular()
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
void ListaDobleCicular<T>::add_first(T dato)
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
        n->setBefore(this->last);
        this->first->setBefore(n);
        this->first = n;
        this->last->setNext(n);

        this->size++;
    }
}

template<class T>
void ListaDobleCicular<T>::add_last(T dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        Nodo *n = new Nodo(dato);
        n->setNext(this->first);
        n->setBefore(this->last);
        this->last->setNext(n);
        this->first->setBefore(n);
        this->last = n;
        this->size++;
    }
}

template<class T>
void ListaDobleCicular<T>::add_at(T dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        Nodo *aux = this->first;
        int x = 0;
        while(x<this->size)
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
T ListaDobleCicular<T>::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        Nodo *iterador = this->first;
        int x = 0;
        while(x< this->getSize())
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
    return 0;
}

template <class T>
void ListaDobleCicular<T>::remove_at(int index)
{
     if(index >= 0 && index < size)
    {
        Nodo *aux = this->first;
        int x = 0;
        while(x<this->size)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        if(index ==0){

            this->first = aux->getNext();

        }else if (index==this->size-1){
            this->last= aux->getBefore();
        }
        aux->before->setNext(aux->getNext());
        aux->next->setBefore(aux->getBefore());
        this->size--;

    }
};

#endif // LISTADOBLECICULAR_H
