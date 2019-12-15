#include "Song.h"

Song::Song(string nombre,  double puesto)
{
            Name = nombre;
            Ranking = puesto;

}

Song::Song(string nombre, double puesto, string anio, string Mes, string Album, string Artist){

        Name = nombre;
        Ranking = puesto;
        ano = anio;
        mes = Mes;
        album = Album;
        artist = Artist;

}

Song::~Song()
{
    //dtor
}
