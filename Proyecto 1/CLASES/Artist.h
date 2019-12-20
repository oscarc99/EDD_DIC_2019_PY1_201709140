#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
#include "Cubo.h"
#include "listadalbum.h";

using namespace std;

class Artist
{
    public:
        Artist(string nombre);
        Artist(string nombre, Cubo *c);
        virtual ~Artist();
        string getName(){return Name;}
        double getRating(){return rating;}
        void setRating(double r){ rating = r;}
        Cubo* getDiscografia(){return Discografia;   }
        ListaDAlbum* getAlbums(){return albums;}
        void setAlbums(ListaDAlbum* al){albums=al;}
    private:
        string Name;
        double rating;
        Cubo* Discografia= new Cubo();
        ListaDAlbum* albums = new ListaDAlbum();

};

#endif // ARTISTA_H
