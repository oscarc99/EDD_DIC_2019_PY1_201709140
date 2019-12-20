#ifndef LISTADALBUM_H
#define LISTADALBUM_H
#include "Album.h"


class nodeA{
public:
	Album* data;
	nodeA* next;
	nodeA* before;

	nodeA* getNext(){return next;}
	void setNext(nodeA* n){next = n;}
	void setBefore(nodeA* n){before = n;}
	nodeA* getBefore(){return before;}
	Album* getDato(){return data;}

	nodeA(Album* dato){
		this->data = dato;
		next = 0;
		before = 0;

	}
};


class ListaDAlbum
{
    public:
        ListaDAlbum();
        virtual ~ListaDAlbum();
        nodeA* getFirst(){return first;}
        nodeA* getLast(){return last;}
        int getSize(){return size;}
        void add_first(Album* dato);
        void add_last(Album* dato);
        void add_at(Album* dato, int index);
        Album* get_element_at(int index);
        void remove_at(int index);
        bool isEmpty(){return size == 0;}

        void insertOrdenado(Album* a);
        void insertOrdenadoRate(Album* a);
        void report();
        void topFive();
        double promedioRating();


    private:
        nodeA* first;
        nodeA* last;
        double prom;
        int size;
};

#endif // LISTADALBUM_H
