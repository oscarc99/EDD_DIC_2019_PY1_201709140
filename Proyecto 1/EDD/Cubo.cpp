#include "Cubo.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

#include "Album.h"


Cubo::Cubo()
{
    Album *b = new Album("root","0","1999");
    root = new NodoC(0,"MESES",b);

}

Cubo::~Cubo()
{
    //dtor
}

bool Cubo::isEmpty()
{
    if (this->getRoot()->getDerecha() ==0 || this->getRoot()->getAdelante() ==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


NodoC* Cubo::buscarColumna(int X)
{
    NodoC *temp = this->root;
    while (temp != 0)
    {
        if (temp->getX()==X)
        {
            return temp;
        }
        temp= temp->getDerecha();
    }


    return 0;
}


NodoC* Cubo::buscarFila(string Y)
{
    NodoC *temp = this->root;
    while (temp != 0)
    {
        if (temp->getY()==Y)
        {
            return temp;
        }
        temp= temp->getAdelante();
    }


    return 0;
}

NodoC* Cubo::insertColumna(NodoC* nov,  NodoC* headC)
{
    NodoC *temp = headC;
    bool bandera = false;
    while (true)
    {
        if (temp->getX()==nov->getX())
        {

            temp->setY(nov->getY());
            temp->setAlbum(nov->getAlbum());
            return temp;
        }
        else if(temp->getX() > nov->getX())
        {
            bandera = true;
            break;
        }
        if (temp->getDerecha() != 0)
        {
            temp = temp->getDerecha();
        }
        else
        {
            break;
        }
    }
    if (bandera)
    {
        ///Insertar antes de temp
        nov->setDerecha(temp);
        //Aqui hay clavo
        nov->setIzquierda(temp->getIzquierda());
        temp->getIzquierda()->setDerecha(nov);
        temp->setIzquierda(nov);
    }
    else
    {
        ///Temp es el ultimpo inserto luego de
        temp->setDerecha(nov);
        nov->setIzquierda(temp);
    }
    return nov;
}


NodoC* Cubo::insertFila(NodoC* novo,  NodoC *headF)
{
    NodoC *temp = headF;

    while (temp->getAdelante() != 0)
    {
        if (temp->getY()==novo->getY())
        {
            temp->setX(novo->getX());
            temp->setAlbum(novo->getAlbum());
            return temp;
        }
        temp = temp->getAdelante();

    }
    ///Si no es igual siempre va a insertar al final
    temp->setAdelante(novo);
    novo->setAtras(temp);
    return novo;
}

NodoC* Cubo::crearColumna(int X)
{
    NodoC *HeadCol = this->getRoot();
    Album *Co = new Album("MESES","0", "1999");
    NodoC *n = new NodoC(X,"MESES",Co);
    NodoC* columna = this->insertColumna(n,HeadCol);
    return columna;

}

NodoC* Cubo::crearFila(string Y)
{
    NodoC *HeadFila = this->getRoot();
    Album *Fi = new Album("FILA","0","1999");
    NodoC *n = new NodoC(0,Y,Fi);
    NodoC *columna = this->insertFila(n, HeadFila);
    return columna;
}


void Cubo::insertAlbum(int X, string Y, Album* alb)
{



    NodoC *nuevo = new  NodoC(X, Y, alb);
    NodoC *NodoColumna = buscarColumna(X);
    NodoC *NodoFila = buscarFila(Y);
    ///Columna no existe y fila no existe
    if (NodoColumna == 0 && NodoFila == 0)
    {
        NodoFila = this->crearFila(Y);
        NodoColumna = this->crearColumna(X);
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);

    }///Columna no existe y fila exista
    else if (NodoColumna == 0 && NodoFila != 0)
    {
        NodoColumna = this->crearColumna(X);
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);


    }///Columna existe y fila no existe
    else if (NodoColumna != 0  && NodoFila == 0)
    {
        NodoFila = this->crearFila(Y);
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);

    }///Colimna y fila existe
    else
    {
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);

    }




}

void Cubo::generarReporte(string nameArt)
{
    string nodo="";
    string dir="";
    string alinea="";//rank


    NodoC *Head = this->getRoot();


    ofstream archivo;


    ///Inicio archivo .dot
    archivo.open("report\\"+nameArt+"_Discografy.dot", ios::out);
    archivo << "digraph R { \n";
    archivo << "rankdir = TB;";
    archivo << "node [shape=rectangle, height=0.5, width=0.5];\n";
    archivo << "graph[ nodesep = 0.5];\n";



    ///RECORRIDO POR FILA
    while (Head->getAdelante() != 0)
    {

        alinea = alinea + "{ rank = same;";
        ///recorro de ia la fila selecionada
        while(Head->getDerecha() != 0)
        {
            ///creando nodo
            nodo = nodo + "node"+Head->getY()+to_string(Head->getX())+ " [label = = \"  ("+Head->getY()+" , "+to_string(Head->getX())+" ) "+ Head->getAlbum()->getName()+"  \" ]; \n";
            ///lista alineados
            alinea = alinea+  "node"+Head->getY()+to_string(Head->getX())+" ;";

            ///direccion de los apuntadores
            if (Head->getDerecha() != 0)
            {
                dir = dir + "node"+Head->getY()+to_string(Head->getX())+ " -> "+"node"+Head->getDerecha()->getY()+""+to_string(Head->getDerecha()->getX())+ "; \n";
            }

            Head = Head->getDerecha();
            if(Head->getDerecha()==0)
            {
                ///creando nodo
                nodo = nodo + "node"+Head->getY()+to_string(Head->getX())+ " [label = \"  ("+Head->getY()+" , "+to_string(Head->getX())+" ) "+ Head->getAlbum()->getName()+"  \" ]; \n";
                ///lista alineados
                alinea = alinea+  "node"+Head->getY()+to_string(Head->getX())+" ;";
            }
        }

        ///Debo regresar (izquierda) a root
        while(Head->getIzquierda() != 0)
        {
            if (Head->getIzquierda() != 0)
            {
                dir = dir + "node"+Head->getY()+to_string(Head->getX())+ " -> "+"node"+Head->getIzquierda()->getY()+""+to_string(Head->getIzquierda()->getX())+ "; \n";
            }

            Head = Head->getIzquierda();

        }



        alinea = alinea + "} \n";
        Head = Head->getAdelante();
    }
    ///Agregamos strings´s a archivos y lo generamos
    archivo << nodo;
    archivo << dir;
    archivo << alinea;
    archivo <<"}";

    archivo.close();
    string crear = "neato -Tpng report\\" +nameArt+"_Discografy.dot -o report\\" + nameArt+ "_Discografy.png";
    system(crear.c_str());
    string i = "report\\"+ nameArt+"_Discografy.png";
    system(i.c_str());
}

