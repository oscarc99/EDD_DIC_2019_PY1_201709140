#include "hoja.h"

Hoja::Hoja()
{
    right = 0;
    left = 0;
    //ctor
}

Hoja::Hoja(Playlist* p)
{
    play = p;
    right = 0;
    left = 0;
    //ctor
}

Hoja::~Hoja()
{
    //dtor
}
