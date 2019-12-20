#include "listadsongs.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

ListaDSongs::ListaDSongs()
{
    first = 0;
    last = 0;
    size = 0;
}

ListaDSongs::~ListaDSongs()
{
    //dtor
}


void ListaDSongs::add_first(Song* dato)
{

    nodeS *n = new nodeS(dato);
    if(this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;

    }
    else
    {
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->size++;

    }
}

void ListaDSongs::add_last(Song* dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);

    }
    else
    {
        nodeS *n = new nodeS(dato);
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;

    }
}


void ListaDSongs::add_at(Song *dato, int index)
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
        nodeS *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index)
            {
                break;
            }
            aux = aux->getNext();
            x++;
        }
        nodeS *n = new nodeS(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;

    }
}


Song* ListaDSongs::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        nodeS *iterador = this->first;
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
    return 0;


}


void ListaDSongs::remove_at(int index)
{
    if(index >= 0 && index < size)
    {
        nodeS *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index)
            {
                break;
            }
            aux = aux->getNext();
            x++;
        }

        if(index ==0)
        {

            this->first = aux->getNext();
            this->first->setBefore(0);
            this->size--;

        }
        else if (index==this->size-1)
        {
            this->last= aux->getBefore();
            this->last->setNext(0);
            this->size--;
        }
        else
        {
            aux->before->setNext(aux->getNext());
            aux->next->setBefore(aux->getBefore());
            this->size--;
        }





    }
}

void ListaDSongs::insertOrdenado(Song* a )
{
    if(this->isEmpty())
    {
        this->add_first(a);
        return;
    }
    int posicion = 0;
    nodeS *aux = this->getFirst();
    while(aux->getNext()!=0)
    {
        if(a->getName().compare(this->getFirst()->getDato()->getName()) == -1)
        {
            posicion=0;
            break;
        }
        if(a->getName().compare(this->getLast()->getDato()->getName()) == 1)
        {
            posicion=size;
            break;
        }
        if(a->getName().compare(aux->getDato()->getName()) == 1)
        {
            posicion++;
        }
        if(a->getName().compare(aux->getNext()->getDato()->getName()) == -1)
        {
            break;
        }
        aux = aux->getNext();
    }
    this->add_at(a, posicion);





}

bool ListaDSongs::existSong(string name, string albu, string years, string mes, string artista)
{
    nodeS* tempS = this->getFirst();
    while(tempS!=0)
    {

        if(tempS->getDato()->getName().compare(name) == 0 && tempS->getDato()->getArtist().compare(artista)==0 && tempS->getDato()->getAlbum().compare(albu)==0  && tempS->getDato()->getMonth().compare(mes)==0 && tempS->getDato()->getYear().compare(years)==0)
        {
            return true;
        }
        tempS= tempS->getNext();
        if(tempS->getNext()==0)
        {
            if(tempS->getDato()->getName().compare(name) == 0 && tempS->getDato()->getArtist().compare(artista)==0 && tempS->getDato()->getAlbum().compare(albu)==0  && tempS->getDato()->getMonth().compare(mes)==0 && tempS->getDato()->getYear().compare(years)==0)
            {
                return true;
            }
            else
            {

                return false;
            }
        }


    }

}

void ListaDSongs::report(nodeS* pintar)
{
    string nodo="";
    string dir="";
    nodeS* temp = this->getFirst();
    ofstream archivo;

    if (this->isEmpty())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\PlaylistShuffle.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = LR;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while (temp!= 0)
        {
            if (temp->getDato()->getName().compare(pintar->getDato()->getName())==0){
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ;style = filled ; fillcolor= skyblue];\n";
            }else{
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ];\n";
            }

            if(temp->getNext()!=0)
            {

                dir = dir + " node"+to_string(c)+ " -> ";
            }
            else
            {

                dir = dir + "node"+to_string(c)+" [dir=both];";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\PlaylistShuffle.dot -o report\\PlaylistShuffle.png";
        system(crear.c_str());

        string s="report\\PlaylistShuffle.png" ;
        system(s.c_str());
    }
}


void ListaDSongs::report(string cancion)
{
    string nodo="";
    string dir="";
    nodeS* temp = this->getFirst();
    ofstream archivo;

    if (this->isEmpty())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\PlaylistShuffle.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = LR;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while (temp!= 0)
        {
            if (temp->getDato()->getName().compare(cancion)==0){
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ;style = filled ; fillcolor= blue];\n";
            }else{
                nodo = nodo + "node"+ to_string(c) +" [label = \" "+ temp->getDato()->getName() + " \" ];\n";
            }

            if(temp->getNext()!=0)
            {

                dir = dir + " node"+to_string(c)+ " -> ";
            }
            else
            {

                dir = dir + "node"+to_string(c)+" [dir=both];";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\PlaylistShuffle.dot -o report\\PlaylistShuffle.png";
        system(crear.c_str());
        ifstream image;
        image.open("report\\PlaylistShuffle.png");
        string s="report\\PlaylistShuffle.png" ;
        system(s.c_str());
    }
}
