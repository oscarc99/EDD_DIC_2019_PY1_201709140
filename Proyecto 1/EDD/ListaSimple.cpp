#include "ListaSimple.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

void ListaSimple::add_first(Song* dato)
{
    NodoLS *n = new NodoLS(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first = n;
        this->size++;
    }
}


void ListaSimple::add_last(Song* dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        NodoLS *n = new NodoLS(dato);
        this->last->setNext(n);
        this->last = n;
        this->size++;
    }
}



void ListaSimple::add_at(Song* dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0)
        {
            this->add_first(dato);
            return;
        }
        if(index == this->size)
        {
            this->add_last(dato);
            return;
        }
        NodoLS *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index-1)
            {
                break;
            }
            aux = aux->getNext();
            x++;
        }
        NodoLS *n = new NodoLS(dato);
        n->setNext(aux->getNext());
        aux->setNext(n);
        this->size++;
    }
}



Song* ListaSimple::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        NodoLS *iterador = this->first;
        int x = 0;
        while(iterador!=0)
        {
            if(index == x)
            {
                return iterador->getDato();
            }
            iterador = iterador->getNext();
            x++;
        }
    }
    else
    {

        return 0;
    }

}


void ListaSimple::remove_at(int index)
{
    if(index >= 0 && index < size)
    {
        NodoLS *aux = this->first;
        if(index ==0)
        {

            this->first = aux->getNext();
            this->size--;
            return;
        }

        int x = 0;
        while(aux!=0)
        {
            if(x == index-1)
            {
                break;
            }
            aux = aux->getNext();
            x++;
        }

        if (index==this->size-1)
        {
            aux->setNext(0);
            this->last= aux;
            this->size--;
        }
        else
        {
            aux->setNext(aux->getNext()->getNext());
            this->size--;
        }
    }

}


void ListaSimple::report(string name)
{
    string nodo="";
    string dir="";
    NodoLS* temp = this->getFirst();
    ofstream archivo;
    if (this->isEmpty())
    {
    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\canciones.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = RL;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5]; \n";
        int c= 0;
        while (temp!= 0)
        {

            nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ];\n";
            if(temp->getNext()!=0)
            {

                dir = dir + " node"+to_string(c)+ " -> ";
            }
            else
            {

                dir = dir + "node"+to_string(c)+" ; \n";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\canciones.dot -o report\\canciones.png";
        system(crear.c_str());
        string s="report\\canciones.png" ;
        system(s.c_str());
    }
}
