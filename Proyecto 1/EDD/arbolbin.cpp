#include "arbolbin.h"
#include <fstream>

ArbolBin::ArbolBin()
{
    root = 0;

    //ctor
}

ArbolBin::~ArbolBin()
{
    //dtor
}

string ArbolBin::Graph(Hoja* Raiz)
{

    string Retorno="";
    if(Raiz==0)
        return Retorno;


    if(Raiz->getLeft()!=0)
    {
        Retorno+=Graph(Raiz->getLeft());
        Retorno+= Raiz->getPlay()->getName()+"->"+Raiz->getLeft()->getPlay()->getName()+"; \n";
    }
    if(Raiz->getRight()!= 0)
    {
        Retorno+=Graph(Raiz->getRight());
        Retorno+= Raiz->getPlay()->getName()+"->"+Raiz->getRight()->getPlay()->getName()+"; \n";
    }
    return Retorno +Raiz->getPlay()->getName()+"[label=\" " +Raiz->getPlay()->getName()+ "\" ];\n";



}


string ArbolBin::graficar()
{


        if(this->getRoot()==0)
        {
            return "\n\n";
        }
        else
        {
            return  "\n  \n"+ Graph(this->getRoot())+"\n";
        }




    }


    void ArbolBin::insertar(Playlist* p)
    {
        if (this->getRoot()!=0)
        {
            insertarP(this->getRoot(), p);
        }
        else
        {
            Hoja* nuevo = new Hoja(p);
            this->setRoot(nuevo);
        }

    }

    void ArbolBin::insertarP(Hoja* raiz, Playlist* p)
    {
        Hoja* nuevo = new Hoja(p);
        if(p->getName().compare(raiz->getPlay()->getName())==-1)
        {
            if(raiz->getLeft()!=0)
            {
                insertarP(raiz->getLeft(), p);
            }
            else
            {
                raiz->setLeft(nuevo);
            }

        }
        else
        {
            if(raiz->getRight()!=0)
            {
                insertarP(raiz->getRight(), p);
            }
            else
            {
                raiz->setRight(nuevo);
            }
        }



    }

    string ArbolBin::menuInorden(){
        return inorden(this->getRoot(), 1);
    }

    string ArbolBin::inorden(Hoja* tmp, int x)
    {

        int y =0;
        if (tmp!=0)
        {
            y= x+1;
            return inorden(tmp->getLeft(),y) + to_string(y) +". "+ tmp->getPlay()->getName() + "\n" + inorden(tmp->getRight(), y);
        }else{
            return "";
        }
    }


    void ArbolBin::report()
    {
        ofstream archivo;
        ///Inicio archivo .dot
        archivo.open("report\\Playlists.dot", ios::out);
        archivo << "digraph G { \n";
        archivo << "nodesep=0.8;\n";
        archivo << "ranksep=0.5;\n";
        ///agrego punteros
        archivo << graficar();
        archivo <<"}";

        archivo.close();
        string crear = "dot.exe -Tpng report\\Playlists.dot -o report\\Playlists.png";
        system(crear.c_str());
        string i = "report\\Playlists.png";
        system(i.c_str());

    }



    Hoja* ArbolBin::buscar(string playlist)
    {

        return busqueda(this->getRoot(), playlist) ;
    }


    Hoja* ArbolBin::busqueda(Hoja* raiz, string name)
    {
        //NodoArbol* raiz = Arbol::raiz;
        if(raiz == 0)
        {
            //Entonces el arbol esta vacio
            return 0;
            //else... es decir que por lo menos hay un nodo
        }
        else if (raiz->getPlay()->getName().compare(name)==0)
        {


            return raiz;
        }
        else if(name.compare(raiz->getPlay()->getName())==-1 )          //Si el nombre en asccii es mas pequeño, nos vamos por la izquierda
        {

            return busqueda(raiz->getLeft(),name);

        }
        else if(name.compare(raiz->getPlay()->getName())==1)        //Es decir que es mas grande, entonces nos vamos por la derecha
        {

            return busqueda(raiz->getRight(),name);
        }
        else        //tal nodo no existe
        {
            return NULL;
        }

    }
