#include "arbolbin.h"

ArbolBin::ArbolBin()
{
    root = 0;
    //ctor
}

ArbolBin::~ArbolBin()
{
    //dtor
}


/*
void ArbolBin::insertar(Playlist* p){
    insertarP(this->getRoot(), p);
}

void ArbolBin::insertarP(Hoja* raiz, Playlist* p){
    Hoja* nuevo = new Hoja(p);
    if(raiz == 0 ){raiz = nuevo;}
    if(p->getName().compare(raiz->getPlay()->getName() == -1)){
        insertarP(raiz->getLeft(), p);
    }
    if (p->getName().compare(raiz->getPlay()->getName() == 1)){
        insertarP(raiz->getRight(), p);
}

}
*/
