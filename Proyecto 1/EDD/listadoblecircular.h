#ifndef LISTADOBLECICULAR_H
#define LISTADOBLECICULAR_H
#include "Song.h"

class NodoDC
    {
        public:
        NodoDC(Song* x)
        {
            dato =x;
            next = 0;
            before=0;
        }
        void setNext(NodoDC *n)
        {
            next = n;
        }

        NodoDC *getNext()
        {
            return next;
        }

        void setBefore(NodoDC *n)
        {
            before = n;
        }

        NodoDC *getBefore()
        {
            return before;
        }


        Song* getDato()
        {
            return dato;
        }

            NodoDC *next;
            NodoDC *before;
            Song* dato;
    };

class ListaDobleCicular
{

    public:
        ListaDobleCircular()
        {
             first = 0;
             last = 0;
             size = 0;
        }
        NodoDC* getFirst(){return first;}
        NodoDC* getLast(){return last;}
         int getSize(){return size;}
         void add_first(Song* dato);
         void add_last(Song* dato);
         void add_at(Song* dato, int index);
         Song* get_element_at(int index);
         void remove_at(int index);
         void report(string cancion);
         void report(NodoDC* pintar);

    private:
         bool isEmpty(){return size == 0;}
         int size;
         NodoDC *first;
         NodoDC *last;
};



#endif // LISTADOBLECICULAR_H
