#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "Song.h"

class NodoLS
    {
        public:
        NodoLS(Song* x)
        {
            dato =x;
            next = 0;

        }
        void setNext(NodoLS *n)
        {
            next = n;
        }



        NodoLS *getNext()
        {
            return next;
        }


        Song* getDato()
        {
            return dato;
        }

            NodoLS *next;
            Song* dato;
    };



class ListaSimple
{

    public:
        ListaSimple()
        {
             first = 0;
             last = 0;
             size = 0;
        }
         int getSize(){return size;}
         NodoLS* getFirst(){return first;}
         void add_first(Song* dato);
         void add_last(Song* dato);
         void add_at(Song* dato, int index);
         Song* get_element_at(int index);
         void remove_at(int index);


    private:
         bool isEmpty(){return size == 0;}
         int size;
         NodoLS *first;
         NodoLS *last;
};




#endif // LISTASIMPLE_H
