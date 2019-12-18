#include "listadoblecircular.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>


void ListaDobleCicular::add_first(Song* dato)
{
    NodoDC *n = new NodoDC(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        n->setBefore(this->last);
        this->first->setBefore(n);
        this->first = n;
        this->last->setNext(n);

        this->size++;
    }
}


void ListaDobleCicular::add_last(Song* dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);
    }
    else
    {
        NodoDC *n = new NodoDC(dato);
        n->setNext(this->first);
        n->setBefore(this->last);
        this->last->setNext(n);
        this->first->setBefore(n);
        this->last = n;
        this->size++;
    }
}


void ListaDobleCicular::add_at(Song* dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        NodoDC *aux = this->first;
        int x = 0;
        while(x<this->size)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        NodoDC *n = new NodoDC(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}


Song* ListaDobleCicular::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        NodoDC *iterador = this->first;
        int x = 0;
        while(x< this->getSize())
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
    return 0;
}


void ListaDobleCicular::report(NodoDC* pintar)
{
    string nodo="";
    string dir="";
    NodoDC* temp = this->getFirst();
    ofstream archivo;

    if (this->isEmpty())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\PlaylistCircular.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = LR;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while (c<this->getSize())
        {
            if (temp->getDato()->getName().compare(pintar->getDato()->getName())==0){
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ;style = filled ; fillcolor= blue];\n";
            }else{
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ];\n";
            }

            if(temp == this->getLast())
            {
    dir = dir+  "node"+to_string(this->getSize()-1)+  "-> node0"+ "[dir=both];";
                dir = dir + "node"+to_string(c)+" [dir=both];";

            }
            else
            {
                dir = dir + " node"+to_string(c)+ " -> ";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\PlaylistCircular.dot -o report\\PlaylistCircular.png";
        system(crear.c_str());

        string s="report\\PlaylistCircular.png" ;
        system(s.c_str());
    }
}


void ListaDobleCicular::report(string cancion)
{
    string nodo="";
    string dir="";
    NodoDC* temp = this->getFirst();
    ofstream archivo;

    if (this->isEmpty())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\PlaylistCircular.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = LR;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while(c<this->getSize())
        {
            if (temp->getDato()->getName().compare(cancion)==0){
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ;style = filled ; fillcolor= blue];\n";
            }else{
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ];\n";
            }

            if(temp == this->getLast())
            {
    dir = dir+  "node"+to_string(this->getSize()-1)+  "-> node0"+ "[dir=both];";
                dir = dir + "node"+to_string(c)+" [dir=both];";

            }
            else
            {
                dir = dir + " node"+to_string(c)+ " -> ";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\PlaylistCircular.dot -o report\\PlaylistCircular.png";
        system(crear.c_str());

        string s="report\\PlaylistCircular.png" ;
        system(s.c_str());
    }
}


void ListaDobleCicular::remove_at(int index)
{
     if(index >= 0 && index < size)
    {
        NodoDC *aux = this->first;
        int x = 0;
        while(x<this->size)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        if(index ==0){

            this->first = aux->getNext();

        }else if (index==this->size-1){
            this->last= aux->getBefore();
        }
        aux->before->setNext(aux->getNext());
        aux->next->setBefore(aux->getBefore());
        this->size--;

    }
};
