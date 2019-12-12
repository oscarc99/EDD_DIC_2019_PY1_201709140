#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include "hoja.h"


class ArbolBin
{
    public:
        ArbolBin();
        virtual ~ArbolBin();
        Hoja* getRoot(){return root;}
        void setRoot(Hoja* raiz){root = raiz;}
        void insertar(Playlist *play);
        void insertarP(Hoja* raiz, Playlist *play);


    private:
        Hoja* root;
};

#endif // ARBOLBIN_H
