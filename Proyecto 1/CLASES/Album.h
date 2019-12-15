#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "ListaSimple.h"
#include "Song.h"

using namespace std;

class Album
{
    public:
        Album(string nombre, string mes, string anio);
        Album(string nombre, string mes, string anio, ListaSimple<Song*> *s);
        virtual ~Album();
        string getName(){return Name;}
        string getMonth(){return Month;}
        string getYear(){return Year;}
        ListaSimple<Song*>* getCanciones(){return canciones;}



    private:
        string Name;
        string Month;
        string Year;
        int ranking;
        ListaSimple<Song*> *canciones = new ListaSimple<Song*>();


};

#endif // ALBUM_H
