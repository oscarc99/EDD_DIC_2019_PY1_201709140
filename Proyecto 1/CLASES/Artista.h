#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>

class Artista
{
    public:
        Artista();
        virtual ~Artista();
        string getName(){return Name;}

    private:
        string Name;
};

#endif // ARTISTA_H
