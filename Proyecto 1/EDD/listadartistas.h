#ifndef LISTADARTISTAS_H
#define LISTADARTISTAS_H
#include "Artist.h"

class node{
public:
	Artist* data;
	node* next;
	node* before;

	node* getNext(){return next;}
	void setNext(node* n){next = n;}
	void setBefore(node* n){before = n;}
	node* getBefore(){return before;}
	Artist* getDato(){return data;}

	node(Artist* dato){
		this->data = dato;
		next = 0;
		before = 0;

	}
};

class ListaDArtistas
{
    public:
            ListaDArtistas();
        node* getFirst(){return first;}
        node* getLast(){return last;}
         int getSize(){return size;}
         void add_first(Artist* dato);
         void add_last(Artist* dato);
         void add_at(Artist* dato, int index);
         Artist* get_element_at(int index);
         void remove_at(int index);
         bool isEmpty(){return size == 0;}
         virtual ~ListaDArtistas();

         void report();

    private:
        node* first;
        node* last;
        int size;
};

#endif // LISTADARTISTAS_H
