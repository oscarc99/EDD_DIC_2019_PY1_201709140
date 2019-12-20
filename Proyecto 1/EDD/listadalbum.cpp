#include "listadalbum.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>


ListaDAlbum::ListaDAlbum()
{

    first = 0;
    last = 0;
    size = 0;
    //ctor
}

ListaDAlbum::~ListaDAlbum()
{
    //dtor
}

void ListaDAlbum::add_first(Album* dato)
{
    nodeA *n = new nodeA(dato);
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

void ListaDAlbum::add_last(Album* dato)
{
    if(this->isEmpty())
    {
        this->add_first(dato);

    }
    else
    {
        nodeA *n = new nodeA(dato);
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;

    }
}


void ListaDAlbum::add_at(Album *dato, int index)
{
    if(index >= 0 && index <= this->size)
    {
        if(index == 0){ this->add_first(dato); return;}
        if(index == this->size) {this->add_last(dato); return;}
        nodeA *aux = this->first;
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }
        nodeA *n = new nodeA(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;

    }
}


Album* ListaDAlbum::get_element_at(int index)
{
    if(index >= 0 && index < size)
    {
        nodeA *iterador = this->getFirst();
        int x = 0;
        while(iterador!=0)
        {
            if(index == x){return iterador->getDato();}
            iterador = iterador->getNext();
            x++;
        }
    }
        return 0;


}


void ListaDAlbum::remove_at(int index)
{
     if(index >= 0 && index < size)
     {
        nodeA *aux = this->getFirst();
        int x = 0;
        while(aux!=0)
        {
            if(x == index){break;}
            aux = aux->getNext();
            x++;
        }

        if(index ==0){

            this->first = aux->getNext();
            this->first->setBefore(0);
            this->size--;

        }else if (index==this->size-1){
            this->last= aux->getBefore();
            this->last->setNext(0);
            this->size--;
        }else{
            aux->before->setNext(aux->getNext());
            aux->next->setBefore(aux->getBefore());
            this->size--;
        }





    }
}

void ListaDAlbum::insertOrdenado(Album* art ){
            if(this->isEmpty()){
            this->add_first(art); return;
        }
        int posicion = 0;
        nodeA *aux = this->getFirst();
        while(aux!=0){
            if(art->getName().compare(this->getFirst()->getDato()->getName()) == -1){
                    posicion=0; break;
            }
            if(art->getName().compare(this->getLast()->getDato()->getName()) == 1){
                    posicion=size; break;
            }
            if(art->getName().compare(aux->getDato()->getName()) == 1){
                    posicion++;
            }
            if(art->getName().compare(aux->getNext()->getDato()->getName()) == -1){ break;}
            aux = aux->getNext();
        }
        this->add_at(art, posicion);


}



void ListaDAlbum::insertOrdenadoRate(Album* art ){
            if(this->isEmpty()){
            this->add_first(art); return;
        }
        int posicion = 0;
        nodeA *aux = this->getFirst();
        while(aux!=0){
            if(art->getRating() < this->getFirst()->getDato()->getRating() ){
                    posicion=0; break;
            }
            if(art->getRating() > this->getLast()->getDato()->getRating() ){
                    posicion=size; break;
            }
            if(art->getRating() > aux->getDato()->getRating() ){
                    posicion++;
            }
            if(art->getRating() < aux->getDato()->getRating()){ break;}
            aux = aux->getNext();
        }
        this->add_at(art, posicion);


}


double ListaDAlbum::promedioRating(){
    double prom=0;
    nodeA* al = this->getFirst();
    while(al != 0){
        prom= prom + al->getDato()->getRating();

        al = al->getNext();
    }
    prom = prom / this->getSize();
    return prom;


}



void ListaDAlbum::report(){
    string nodo="";
    string dir="";



    nodeA* temp = this->getFirst();



    ofstream archivo;

    if (this->isEmpty())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\artistas.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = LR;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while (temp!= 0){

            nodo = nodo + "node"+ to_string(c) +" [label = \" "+to_string(temp->getDato()->getRating())+".  "+ temp->getDato()->getName() + " \" ];\n";
            if(temp->getNext()!=0){

               dir = dir + " node"+to_string(c)+ " -> ";
            }else{

                dir = dir + "node"+to_string(c)+" [dir=both];";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\artistas.dot -o report\\artistas.png";
        system(crear.c_str());
        ifstream image;
        image.open("report\\artistas.png");
        string s="report\\artistas.png" ;
        system(s.c_str());
    }
}


void ListaDAlbum::topFive(){
string nodo="";
    string dir="";
    nodeA* temp = this->getLast();
    ofstream archivo;
    if (this->isEmpty())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\topAlbum.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = LR;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while (temp!= 0 && c<5){

            nodo = nodo + "node"+ to_string(c) +" [label = \" TOP "+to_string(c+1)+". "+to_string(temp->getDato()->getRating())+".  "+ temp->getDato()->getName() + " \" ];\n";
            if(c!=4){
                if(temp->getBefore()!=0){
                cout << c << endl;
               dir = dir + " node"+to_string(c)+ " -> ";
            }else{

                dir = dir + "node"+to_string(c)+" [dir=both];";
            }
            }else{
                dir = dir + "node"+to_string(c)+" [dir=both];";
            }

            c++;

            temp = temp->getBefore();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\topAlbum.dot -o report\\topAlbum.png";
        system(crear.c_str());
        string s="report\\topAlbum.png" ;
        system(s.c_str());
    }




}
