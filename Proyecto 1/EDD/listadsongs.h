#ifndef LISTADSONGS_H
#define LISTADSONGS_H
#include "Song.h"

class nodeS{
public:
	Song* data;
	nodeS* next;
	nodeS* before;

	nodeS* getNext(){return next;}
	void setNext(nodeS* n){next = n;}
	void setBefore(nodeS* n){before = n;}
	nodeS* getBefore(){return before;}
	Song* getDato(){return data;}

	nodeS(Song* dato){
		data = dato;
		next = 0;
		before = 0;

	}
};


class ListaDSongs
{
    public:

        nodeS* getFirst(){return first;}
        nodeS* getLast(){return last;}
        int getSize(){return size;}
        void add_first(Song* dato);
        void add_last(Song* dato);
        void add_at(Song* dato, int index);
        Song* get_element_at(int index);
        void remove_at(int index);
        bool isEmpty(){return size == 0;}

        void insertOrdenado(Song* a);
        void report();
        ListaDSongs();
        virtual ~ListaDSongs();

    private:
        nodeS* first;
        nodeS* last;
        int size;
};

#endif // LISTADSONGS_H
