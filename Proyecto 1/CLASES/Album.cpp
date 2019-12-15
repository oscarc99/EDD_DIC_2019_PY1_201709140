#include "Album.h"

Album::Album(string nombre, string mes, string anio){
            Name = nombre;
            Month = mes;
            Year = anio;
}

Album::Album(string nombre, string mes, string anio, ListaSimple<Song*> *s){
            Name = nombre;
            Month = mes;
            Year = anio;
            canciones = s;
}

Album::~Album()
{
    //dtor
}
