#include "Pila.h"
#include <fstream>
#include <string>


bool Pila::estaVacia()
{
    return this->size==0;
}


void Pila::push(Song* dato)
{
    NodoP *n = new NodoP(dato);
    if(estaVacia())
    {
        this->cima=n;
        this-> size++;
    }
    else
    {
        n->setNext(this->cima);
        this->cima=n;
        this->size++;
    }
}


Song* Pila::pop()
{
    if(estaVacia())
    {

        return 0;
    }
    else
    {

        Song* aux = this->cima->getDato();
        this->cima = this->cima->getNext();
        this->size--;
        return aux;
    }
}

Song* Pila::peek()
{
    if(estaVacia())
    {

        return 0;
    }
    else
    {
        return this->cima->getDato();
    }
}

void Pila::report()
{
    NodoP *temp;
    if(this->estaVacia())
    {

    }
    else
    {

        ofstream archivo;
        ///Inicio archivo .dot
        archivo.open("report\\Pila.dot", ios::out);
        archivo << "digraph G { \n";
        archivo << "node [shape = name]; \n";
        archivo << "rankdir=LR; \n";
        archivo << "2[label=  <<table border= \"1 \" cellspacing= \" 0 \">";
        string dato;
        temp = this->getCima();
        dato+= "<tr>\n";
        dato+= "<td BGCOLOR= \"skyblue\"> "+ temp->getDato()->getName() + " </td>";
        dato+=  " </tr> \n";



        temp = temp->getNext();
        while(temp!=0)
        {
            dato+= "<tr> \n";
            dato+= "<td> "+ temp->getDato()->getName() + "</td>";
            dato+=  " </tr> \n";
            temp = temp->getNext();
        }


        archivo << dato;
        archivo << "</table>>]; \n";
        archivo <<"}";

        archivo.close();
        string crear = "dot.exe -Tpng report\\Pila.dot -o report\\Pila.png";
        system(crear.c_str());
        string i = "report\\Pila.png";
        system(i.c_str());

    }
}




void Pila::report(string name)
{
    NodoP *temp;
    if(this->estaVacia())
    {

    }
    else
    {

        ofstream archivo;
        ///Inicio archivo .dot
        archivo.open("report\\Pila.dot", ios::out);
        archivo << "digraph G { \n";
        archivo << "node [shape = record];\n";
        archivo << "2[label= \" {";
        string dato;
        temp = this->getCima();
        while(temp->getNext()!=0)
        {
            dato+= temp->getDato()->getName();
            dato+=  " | ";
            temp = temp->getNext();
        }

        dato+= temp->getDato()->getName();
        archivo << dato;
        archivo << "} \" ] \n";
        archivo <<"}";

        archivo.close();
        string crear = "dot.exe -Tpng report\\Pila.dot -o report\\Pila.png";
        system(crear.c_str());
        string i = "report\\Pila.png";
        system(i.c_str());

    }
}
