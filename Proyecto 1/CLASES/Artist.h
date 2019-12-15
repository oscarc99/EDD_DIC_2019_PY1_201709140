#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
#include "Cubo.h"

using namespace std;

class Artist
{
    public:
        Artist(string nombre);
        Artist(string nombre, Cubo *c);
        virtual ~Artist();
        string getName(){return Name;}
        Cubo* getDiscografia(){return Discografia;   }
    private:
        string Name;
        Cubo* Discografia= new Cubo();

};

#endif // ARTISTA_H
