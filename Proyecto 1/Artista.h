#ifndef ARTISTA_H
#define ARTISTA_H
#include <string>

using namespace std;
class Artista
{
    public:
        Artista(string nombre);
        virtual ~Artista();
        string getName(){return Name;}

    private:
        string Name;
};

#endif // ARTISTA_H
