#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Pila.h"
#include "Cola.h"
#include "ListaDoble.h"
#include "listadoblecircular.h"
#include "listadsongs.h"
#include "Song.h"


class Playlist
{
    public:
        Playlist(string name, string tipo);
        virtual ~Playlist();
        string getName(){return nombre;}
        string getType(){return type;}

        Pila* getPila(){return pil;}
        void setPila(Pila* stacks){pil = stacks;}

        Cola* getCola(){return col;}
        void setCola(Cola* queues){col = queues;}

        ListaDSongs* getListaDoble(){return doble;}
        void setLDoble(ListaDSongs* dobl){doble = dobl;}

        ListaDobleCicular* getCircular(){return circular;}
        void setCircular(ListaDobleCicular* circule){circular = circule;}


    private:
        string nombre;
        string type;
        Pila* pil;
        Cola* col;
        ListaDSongs* doble ;
        ListaDobleCicular* circular;





};

#endif // PLAYLIST_H
