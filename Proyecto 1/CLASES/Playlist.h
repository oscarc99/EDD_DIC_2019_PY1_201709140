#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "Pila.h"
#include "Cola.h"
#include "ListaDoble.h"
#include "listadoblecircular.h"
#include "Song.h"


class Playlist
{
    public:
        Playlist();
        virtual ~Playlist();
        string getName(){return nombre;}
        string getType(){return type;}

        Pila<Song*>* getPila(){return pil;}
        void setPila(Pila<Song*>* stacks){pil = stacks;}

        Cola<Song*>* getCola(){return col;}
        void setCola(Cola<Song*>* queues){col = queues;}

        ListaDoble<Song*>* getListaDoble(){return doble;}
        void setLDoble(ListaDoble<Song*>* dobl){doble = dobl;}

        ListaDobleCicular<Song*>* getCircular(){return circular;}
        void setCircular(ListaDobleCicular<Song*>* circule){circular = circule;}


    private:
        string nombre;
        string type;
        Pila<Song*>* pil;
        Cola<Song*>* col;
        ListaDoble<Song*>* doble ;
        ListaDobleCicular<Song*>* circular;





};

#endif // PLAYLIST_H
