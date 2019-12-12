#include "NodoC.h"

NodoC::NodoC(int X, string Y, Album* alb)
{

    adelante = 0;
    atras = 0;
    abajo = 0;
    arriba = 0;
    izquierda = 0;
    derecha = 0;
    x = X;
    y = Y;
    albu = alb;

}

NodoC::NodoC(int X, string Y, string alb)
{

    adelante = 0;
    atras = 0;
    abajo = 0;
    arriba = 0;
    izquierda = 0;
    derecha = 0;
    x = X;
    y = Y;
    dato = alb;

}

NodoC::~NodoC()
{
    //dtor
}
