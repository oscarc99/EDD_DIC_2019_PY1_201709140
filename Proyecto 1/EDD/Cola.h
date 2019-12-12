#ifndef COLA_H
#define COLA_H

#include <string>

using namespace std;

template<class T>
class Cola
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
        private:
            Nodo *next;
            T dato;



    };
    public:
        Cola<T>(){
            inicio=0;
            fin=0;
            size=0;
        }
        bool estaVacia();
        void enqueque(T dato);
        T dequeque();
        T peek();


    private:
        Nodo *inicio;
        Nodo *fin;
        int size;
};

template<class T>
bool Cola<T>::estaVacia(){
    return this->size==0;
}

template<class T>
void Cola<T>::enqueque(T dato)
{
    Nodo *n = new Nodo(dato);
    if(estaVacia())
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

template<class T>
T Cola<T>::dequeque()
{
    if(estaVacia()){

       return 0;
    }else{

   T aux = this->inicio->getDato();
   this->inicio = this->inicio->getNext();
   this->size--;
   return aux;
   }
}

template<class T>
T Cola<T>::peek()
{
    if(estaVacia()){

       return 0;
    }else{
     return this->inicio->getDato();
   }

}


#endif // COLA_H
