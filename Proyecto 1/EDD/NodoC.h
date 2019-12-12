#ifndef NODOCUBO_H
#define NODOCUBO_H
#include "Album.h"
#include <string>

using namespace std;

class NodoC
{
    public:
        NodoC();
        NodoC(int X, string Y, Album *albu);
        NodoC(int X, string Y, string dato);
        virtual ~NodoC();
        NodoC* getAdelante(){return adelante;}
        void setAdelante(NodoC* ade){
            adelante= ade;
        }
        NodoC* getAtras(){return atras;}
        void setAtras(NodoC* atr){
            atras = atr;
        }
        NodoC* getArriba(){return arriba;}
        void setArriba(NodoC* up){
            arriba = up;
        }
        NodoC* getAbajo(){return abajo;}
        void setAbajo(NodoC* down){
            abajo = down;
        }
        NodoC* getIzquierda(){return izquierda;}
        void setIzquierda(NodoC* left){
            izquierda = left;
        }
        NodoC* getDerecha(){return derecha;}
        void setDerecha(NodoC* right){
            derecha = right;
        }
        int getX(){return x;}
        void setX(int X){
            x = X;
        }
        string getY(){return y;}
        void setY(string Y){
            y = Y;
        }
        Album* getAlbum(){return albu;}
        void setAlbum(Album* alb){
            albu = alb;
        }
        string getDato(){return dato;}





    private:

        //NODOS para fila
        NodoC* izquierda;
        NodoC* derecha;
        //Nodo para columna
        NodoC *adelante;
        NodoC *atras;
        //Nodo en z
        NodoC *arriba;
        NodoC *abajo;
        Album *albu;
        string dato;
        int x;
        string y;


};

#endif // NODOCUBO_H
