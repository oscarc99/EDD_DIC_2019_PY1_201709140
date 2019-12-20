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
        Album(string nombre, string mes, string anio, ListaSimple *s);
        virtual ~Album();
        string getName(){return Name;}
        string getMonth(){return Month;}
        string getYear(){return Year;}
        double getRating(){return rate;}
        void setRating(double r){rate= r;}
        ListaSimple* getCanciones(){return canciones;}
        void setIndice(int index){indice=index;}
        int getIndice(){return indice;}






    private:
        string Name;
        string Month;
        string Year;
        double rate;
        ListaSimple*canciones = new ListaSimple();
        int indice;


};

#endif // ALBUM_H
