#include "Cubo.h"

Cubo::Cubo()
{
    root = new NodoC(-1,"MESES","root");
}

Cubo::~Cubo()
{
    //dtor
}


NodoC* Cubo::buscarColumna(int X){
    NodoC *temp = this->root;
    while (temp != 0){
        if (temp->getX()==X){
            return temp;
        }
        temp= temp->getDerecha();
    }


    return 0;
}


NodoC* Cubo::buscarFila(string Y){
    NodoC *temp = this->root;
    while (temp != 0){
        if (temp->getY()==Y){
            return temp;
        }
        temp= temp->getAdelante();
    }


    return 0;
}

NodoC* Cubo::insertColumna(NodoC* nov,  NodoC* headC){
    NodoC *temp = headC;
    bool bandera = false;
    while (true){
        if (temp->getX()==nov->getX()){
            temp->setY(nov->getY());
            temp->setAlbum(nov->getAlbum());
            return temp;
        }else if(temp->getX() > nov->getX()){
            bandera = true;
            break;
        }
        if (temp->getDerecha() != 0){
            temp = temp->getDerecha();
        }else{
            break;
        }
    }
    if (bandera){
        ///Insertar antes de temp
        nov->setDerecha(temp);
        temp->getIzquierda()->setDerecha(nov);
        nov->setIzquierda(temp->getIzquierda());
        temp->setIzquierda(nov);
    }else{
        ///Temp es el ultimpo inserto luego de
        temp->setDerecha(nov);
        nov->setIzquierda(temp);
    }
    return nov;
}


NodoC* Cubo::insertFila(NodoC* novo,  NodoC *headF){
    NodoC *temp = headF;

    while (temp->getAdelante() != 0){
        if (temp->getY()==novo->getY()){
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

NodoC* Cubo::crearColumna(int X){
    NodoC *HeadCol = this->getRoot();
    NodoC *n = new NodoC(X,"MESES","COLUMNA");
    NodoC* columna = this->insertColumna(n,HeadCol);
    return columna;

}

NodoC* Cubo::crearFila(string Y){
    NodoC *HeadFila = this->getRoot();
    NodoC *n = new NodoC(-1,Y,"FILA");
    NodoC *columna = this->insertColumna(n, HeadFila);
    return columna;
}



void Cubo::insertAlbum(int X, string Y, Album* alb){
    NodoC *nuevo = new  NodoC(X, Y, alb);
    NodoC *NodoColumna = buscarColumna(X);
    NodoC *NodoFila = buscarFila(Y);
    ///Cumna y fila no existe
    if (NodoColumna == 0 && NodoFila == 0){
        NodoColumna = this->crearColumna(X);
        NodoFila = this->crearFila(Y);
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);

    }///Columna no existe y fila exista
    else if (NodoColumna == 0 && NodoFila != 0){
        NodoColumna = this->crearColumna(X);
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);


    }///Columna existe y fila no existe
    else if (NodoColumna != 0  && NodoFila == 0){
        NodoFila = this->crearFila(Y);
        nuevo = this->insertColumna(nuevo,NodoFila);
        nuevo = this->insertFila(nuevo,NodoColumna);

    }///Colimna y fila existe
    else{
        while(NodoFila != 0){
            if (NodoFila->getX()==X){
                if (NodoFila ==0){
                    ///No tiene elemento dentro de nodo, guarda en el
                    nuevo = this->insertColumna(nuevo,NodoFila);
                    nuevo = this->insertFila(nuevo,NodoColumna);
                }else{
                    ///Tiene elemento dentro de ese nodo agregar arriba
                    NodoFila->setArriba(nuevo);
                    nuevo->setAbajo(NodoFila);

                }
            }

            NodoFila = NodoFila->getDerecha();
        }


    }




}
