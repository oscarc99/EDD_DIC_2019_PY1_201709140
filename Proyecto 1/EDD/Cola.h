#ifndef COLA_H
#define COLA_H
#include "Song.h"
#include <string>

using namespace std;


class Nodo
    {
        public:
        Nodo(Song* x)
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

        Song* getDato()
        {
            return dato;
        }
        private:
            Nodo *next;
            Song* dato;



    };

class Cola
{

    public:
        Cola(){
            inicio=0;
            fin=0;
            size=0;
        }
        bool estaVaciaC();
        void enqueque(Song* dato);
        Song* dequeque();
        Song* peek();


    private:
        Nodo *inicio;
        Nodo *fin;
        int size;
};



#endif // COLA_H
