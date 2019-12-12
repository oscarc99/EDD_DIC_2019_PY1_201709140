#ifndef ALBUM_H
#define ALBUM_H
#include <string>
#include "ListaSimple.h"

using namespace std;

class Album
{
    public:
        Album(string nombre, string mes, string anio);
        virtual ~Album();
        string getName(){return Name;}
        string getMonth(){return Month;}
        string getYear(){return Year;}



    private:
        string Name;
        string Month;
        string Year;
        int ranking;


};

#endif // ALBUM_H
