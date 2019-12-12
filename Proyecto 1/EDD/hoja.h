#ifndef HOJA_H
#define HOJA_H
#include"playlist.h"

class Hoja
{
    public:
        Hoja();
        Hoja(Playlist *p);
        virtual ~Hoja();
        Hoja* getLeft(){return left;}
        void setLeft(Hoja* izquierda){left = izquierda; }
        void setRight(Hoja *derecha){ right = derecha;}
        Hoja* getRight(){return right;}
        Playlist* getPlay(){return play;}
        void setPlay(Playlist* lists){play = lists;}


    private:
        Playlist *play;
        Hoja* right;
        Hoja* left;


};

#endif // HOJA_H
