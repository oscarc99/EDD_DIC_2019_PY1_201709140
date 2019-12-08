#ifndef ALBUM_H
#define ALBUM_H
#include <string>


class Album
{
    public:
        Album(string nombre, string mes, string anio){
            Name = nombre;
            Month = mes;
            Year = anio;
        }
        virtual ~Album();
        string getName(){return Name;}
        string getMonth(){return Month;}
        string getYear(){return Year;}

    private:
        string Name;
        string Month;
        string Year;


};

#endif // ALBUM_H
