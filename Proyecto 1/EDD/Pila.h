#ifndef PILA_H
#define PILA_H
#include <string>

using namespace std;

template<class T>
class Pila
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
        Pila<T>(){
            cima=0;
            size=0;
        }
        bool estaVacia();
        void push(T dato);
        T pop();
        T peek();


    private:
        Nodo *cima;
        int size;
};

template<class T>
bool Pila<T>::estaVacia(){
    return this->size==0;
}

template<class T>
void Pila<T>::push(T dato)
{
    Nodo *n = new Nodo(dato);
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

template<class T>
T Pila<T>::pop()
{
    if(estaVacia()){

       return 0;
    }else{

   T aux = this->cima->getDato();
   this->cima = this->cima->getNext();
   this->size--;
   return aux;
   }
}

template<class T>
T Pila<T>::peek()
{
    if(estaVacia()){

       return 0;
    }else{
    return this->cima->getDato();
   }
}

#endif // PILA_H
