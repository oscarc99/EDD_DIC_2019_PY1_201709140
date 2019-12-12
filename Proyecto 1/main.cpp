#include <iostream>
#include <string>
#include "Song.h"
#include "Artist.h"
#include "ListaDoble.h"
#include "Pila.h"
#include "Cola.h"
#include "json.hpp"

using namespace std;

int main()
{
    ///main proyecto 1
    ListaDoble<Artist*> *LD = new ListaDoble<Artist*>();
    Artist *a = new Artist("a");
    Artist *b = new Artist("b");
    Artist *c = new Artist("c");
    Artist *d = new Artist("d");
    cout << d->getName() << endl;
    if ("BACA".strcmp( "Arbol")==1 ){
        cout<< "Son a es mayor" <<endl;

    }else{
            cout<< "b es el mayor" <<endl;
    }

    LD->add_last(a);
    LD->add_last(b);
    LD->add_last(c);
    LD->add_last(d);

    cout << "--EDDDfg--!" << endl;
    return 0;
}
