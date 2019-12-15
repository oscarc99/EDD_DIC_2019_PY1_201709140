#include "Artist.h"
#include <string>

using namespace std;


Artist::Artist(string nombre)
{
    Name = nombre;
    //ctor
}
Artist::Artist(string nombre, Cubo *c)
{
    Name = nombre;
    Discografia = c;
    //ctor
}

Artist::~Artist()
{
    //dtor
}
