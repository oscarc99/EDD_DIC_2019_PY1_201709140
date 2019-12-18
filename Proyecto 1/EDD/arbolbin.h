#ifndef ARBOLBIN_H
#define ARBOLBIN_H
#include "hoja.h"
#include <string>

class ArbolBin
{
    public:
        ArbolBin();
        virtual ~ArbolBin();
        Hoja* getRoot(){return root;}
        void setRoot(Hoja* raiz){root = raiz;}
        void insertar(Playlist *play);
        void insertarP(Hoja* raiz, Playlist *play);
        void report();
        string Graph(Hoja* Raiz);
        string graficar();
        Hoja* busqueda(Hoja* raiz, string name);
        Hoja* buscar(string playlist);
        string menuInorden();
        string inorden(Hoja* raiz, int x);


    private:
        Hoja* root;
};

#endif // ARBOLBIN_H
