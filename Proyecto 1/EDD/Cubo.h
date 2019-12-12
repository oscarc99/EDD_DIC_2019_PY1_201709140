#ifndef CUBO_H
#define CUBO_H
#include "Album.h"
#include "NodoC.h"

class Cubo
{
    public:
        Cubo();
        virtual ~Cubo();
        NodoC* getRoot(){return root;}
        NodoC* buscarFila(string y);
        NodoC* buscarColumna(int x);
        NodoC* insertFila(NodoC* nov, NodoC* HeadC);
        NodoC* insertColumna(NodoC* novo, NodoC* HeadF);
        NodoC* crearColumna(int X);
        NodoC* crearFila(string Y);
        void insertAlbum(int X, string Y,Album* alb);





    private:
        NodoC *root;


};

#endif // CUBO_H