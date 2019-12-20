#include "Cola.h"
#include <fstream>
#include <string>

bool Cola::estaVaciaC()
{
    return this->size==0;
}

void Cola::report(string name)
{

    string nodo="";
    string dir="";



    Nodo* temp = this->getFirst();



    ofstream archivo;

    if (this->estaVaciaC())
    {

    }
    else
    {
        ///Inicio archivo .dot
        archivo.open("report\\Cola.dot", ios::out);
        archivo << "digraph R { \n";
        archivo << "rankdir = RL;";
        archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
        archivo << "graph[ nodesep = 0.5];\n";
        int c= 0;
        while (temp!= 0)
        {

            if (temp->getDato()->getName().compare(this->getFirst()->getDato()->getName())==0 ){
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

                dir = dir + "node"+to_string(c)+" [dir=back];";
            }
            c++;
            temp = temp->getNext();
        }

        archivo << nodo;
        archivo << dir;

        archivo <<"}";


        archivo.close();
        string crear = "dot.exe -Tpng report\\Cola.dot -o report\\Cola.png";
        system(crear.c_str());
        string s="report\\Cola.png" ;
        system(s.c_str());
    }


}

void Cola::enqueque(Song* dato)
{
    Nodo *n = new Nodo(dato);
    if(estaVaciaC())
    {
        this->inicio=n;
        this->fin=n;
        this-> size++;
    }
    else
    {
        fin->setNext(n);
        this->fin=n;
        this->size++;
    }
}


Song* Cola::dequeque()
{
    if(this->estaVaciaC())
    {

        return 0;
    }
    else
    {

        Song* aux = this->inicio->getDato();
        this->inicio = this->inicio->getNext();
        this->size--;
        return aux;
    }
}


Song* Cola::peek()
{
    if(estaVaciaC())
    {

        return 0;
    }
    else
    {
        return this->inicio->getDato();
    }

}

