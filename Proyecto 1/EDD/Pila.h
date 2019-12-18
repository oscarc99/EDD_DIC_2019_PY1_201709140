#ifndef PILA_H
#define PILA_H
#include <string>
#include "Song.h"

using namespace std;

class NodoP
{
public:
    NodoP(Song* x)
    {
        dato =x;
        next = 0;
    }
    void setNext(NodoP *n)
    {
        next = n;
    }

    NodoP *getNext()
    {
        return next;
    }

    Song* getDato()
    {
        return dato;
    }
private:
    NodoP *next;
    Song* dato;



};

class Pila
{
public:
    Pila()
    {
        cima=0;
        size=0;
    }
    bool estaVacia();
    void push(Song* dato);
    int getSize(){return size;}
    Song* pop();
    Song* peek();
    void report(string name);
    NodoP* getCima(){return cima;}


private:
    NodoP *cima;
    int size;
};



#endif // PILA_H
