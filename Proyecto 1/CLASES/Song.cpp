#include "Song.h"

Song::Song(string nombre, string archivo, double puesto)
{
     Name = nombre;
            File = archivo;
            Ranking = puesto;

}

Song::~Song()
{
    //dtor
}
