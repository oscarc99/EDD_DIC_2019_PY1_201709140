#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>
#include "Cubo.h"

using namespace std;

class Artist
{
    public:
        Artist(string nombre);
        virtual ~Artist();
        string getName(){return Name;}

    private:
        string Name;
        Cubo* Albums= new Cubo();
};

#endif // ARTISTA_H
