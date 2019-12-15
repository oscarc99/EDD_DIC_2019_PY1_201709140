#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include <sstream>


//Estructuras
#include "Song.h"
#include "Artist.h"
#include "ListaDoble.h"
#include "Pila.h"
#include "Cola.h"
#include "Cubo.h"
#include "Album.h"
#include "listadartistas.h"
#include "arbolbin.h"

using namespace std;
using json = nlohmann::json;


ListaDArtistas *artistas;
ArbolBin *reproduccion;

int main()
{
    ///asigna estructuras a sus punteros
    artistas = new ListaDArtistas();
    reproduccion = new ArbolBin();
    ListaSimple<Song*> *canciones = new ListaSimple<Song*>();
    const string fileLibrary = "Library.json";
    ifstream reader(fileLibrary);
    json j;
    reader >> j;
    ///lectura de libreria automaticamente al inciar
    if (reader.fail()){

            cout<<"No existe el archivo necesario para el funcionamiento" << endl;
            cout <<"AGREGE ARCHIVO 'Library.json'" << endl;
    }else{




    for (const auto& libr : j)
    {
        ///ESTOY DENTRO DE LA LIBRERIA
        for (const auto& Art : libr)
        {
            cout << "----------------------------" << endl;
            cout << "      ------- ARTISTA  ------" << endl;
            ///ESTOY DENTRO DE LA artista
            string nameArtist = Art["Artist"]["Name"];
            Cubo *disc = new Cubo();



            ///Lleno cubp con los albums
            for (const auto& albums : Art["Artist"]["Albums"])
            {
                ///ESTOY DENTRO DE LA albums
                cout << "      -------           ALBUM   ------" << endl;
                string nameAlbum = albums["Name"];
                string mes = albums ["Month"];
                string year = albums["Year"];
                cout << nameAlbum <<endl;

                ListaSimple<Song*> *can = new ListaSimple<Song*>();
                for (const auto& song : albums["Songs"])
                {
                    ///ESTOY DENTRO DE canciones
                    cout << "      -------                            CANCIONES  ------" << endl;
                    string nameSong = song["Name"];
                    string rating = song["Rating"];
                    double r = atof(rating.c_str());;
                    ///cancion para lista de canciones global



                    Song *ss = new Song(nameSong,r,year,mes,nameAlbum, nameArtist);
                    canciones->add_last(ss);

                    /// cancion para el ambum del cubo del artista
                    Song *s = new Song(nameSong, r);
                    can->add_first(s);


                    cout << nameSong <<  endl;


                }

                Album *al = new Album(nameAlbum,mes,year,can);
                ///---------converit año a int..............................------------
                ///ARREGLAR
                int ye=0;

                std::istringstream(year) >> ye;
                disc->insertAlbum(ye, mes, al);


            }

            ///Luego de llenado ingresa
            Artist *a = new Artist(nameArtist,disc);




            artistas->add_last(a);


        }
    }
    reader.close();
    node* temp = artistas->getFirst();
    temp->getDato()->getDiscografia()->generarReporte(temp->getDato()->getName());

    /*
    cout << temp->getDato()->getDiscografia()->getRoot()->getAlbum()->getName() << endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getX()<< endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getY() << endl;
*/
/*
    cout << temp->getDato()->getDiscografia()->getRoot()->getAdelante()->getAlbum()->getName() << endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getAdelante()->getX()<< endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getAdelante()->getY() << endl;

    cout << temp->getDato()->getDiscografia()->getRoot()->getAdelante()->getAdelante()->getAlbum()->getName() << endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getAdelante()->getAdelante()->getX()<< endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getAdelante()->getAdelante()->getY() << endl;

    */

    /*
    cout << temp->getDato()->getDiscografia()->getRoot()->getDerecha()->getAlbum()->getName() << endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getDerecha()->getX()<< endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getDerecha()->getY() << endl;

    cout << temp->getDato()->getDiscografia()->getRoot()->getDerecha()->getDerecha()->getAlbum()->getName() << endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getDerecha()->getDerecha()->getX()<< endl;
    cout << temp->getDato()->getDiscografia()->getRoot()->getDerecha()->getDerecha()->getY() << endl;

*/




    //artistas->report();




    }




    return 0;
}

void agrgarPlaylist(string fileJson)
{
    json j;
    string nameList;
    nameList = "Playlist_Rock.json";
    int largeName = 0;
    largeName = strlen(nameList.c_str());
    cout<< largeName<< endl;

    ifstream reader(nameList);
    reader >> j;

    string type = j["Typy"];
    for (const auto& Song : j["Songs"])
    {
        cout << "------------cancion------------" << endl;
        string yea= Song["Year"];
        string mes= Song["Month"];
        string albu= Song["Album"];
        string cancion= Song["Song"];
        string artisa= Song["Artist"];


    }
    reader.close();

}


