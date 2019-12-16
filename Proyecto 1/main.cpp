#include <iostream>
#include <fstream>
#include <string>
#include "json.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

//Estructuras
#include "Song.h"
#include "ListaSimple.h"
#include "Artist.h"
#include "NodoC.h"
#include "Pila.h"
#include "Cola.h"
#include "Cubo.h"
#include "Album.h"
#include "listadartistas.h"
#include "arbolbin.h"
#include "listadsongs.h"

using namespace std;
using json = nlohmann::json;


ListaDArtistas *artistas;
ArbolBin *reproduccion;
ListaDSongs *canciones;
int main()
{
    ///asigna estructuras a sus punteros
    artistas = new ListaDArtistas();
    reproduccion = new ArbolBin();
    canciones = new ListaDSongs();
    const string fileLibrary = "Library.json";
    ifstream reader(fileLibrary);
    json j;
    reader >> j;
    ///lectura de libreria automaticamente al inciar
    if (reader.fail())
    {

        cout<<"No existe el archivo necesario para el funcionamiento" << endl;
        cout <<"AGREGE ARCHIVO 'Library.json'" << endl;
    }
    else
    {




        for (const auto& libr : j)
        {
            ///ESTOY DENTRO DE LA LIBRERIA
            for (const auto& Art : libr)
            {
                //cout << "----------------------------" << endl;
                //cout << "      ------- ARTISTA  ------" << endl;
                ///ESTOY DENTRO DE LA artista
                string nameArtist = Art["Artist"]["Name"];
                Cubo *disc = new Cubo();
                ///Lleno cubp con los albums
                for (const auto& albums : Art["Artist"]["Albums"])
                {
                    ///ESTOY DENTRO DE LA albums
                    //cout << "      -------           ALBUM   ------" << endl;
                    string nameAlbum = albums["Name"];
                    string mes = albums ["Month"];
                    string year = albums["Year"];
                    //cout << nameAlbum <<endl;

                    ListaSimple *can = new ListaSimple();
                    for (const auto& song : albums["Songs"])
                    {
                        ///ESTOY DENTRO DE canciones
                        //cout << "      -------                            CANCIONES  ------" << endl;
                        string nameSong = song["Name"];
                        string rating = song["Rating"];
                        double r = atof(rating.c_str());;

                        ///cancion para lista de canciones global
                        Song *ss = new Song(nameSong,r,year,mes,nameAlbum, nameArtist);
                        canciones->insertOrdenado(ss);

                        /// cancion para el ambum del cubo del artista
                        Song *s = new Song(nameSong, r);
                        can->add_first(s);
                        //cout << nameSong <<  endl;
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
                artistas->insertOrdenado(a);
            }
        }
        reader.close();

        ListaSimple* albumS;
        bool bandera=false;
        char tecla;
        int c=1;
        int sA, sS;
        node* fart= artistas->getFirst();
        nodeS* fsong = canciones->getFirst();
        //fart->getDato()->getDiscografia()->generarReporte(fart->getDato()->getName());
        //artistas->report();
        Artist* selectArt;
        int indexAlb=0;
        int selecSong;
        Song* selectSong;
        NodoC * cubo;
        Album* selectAlb;
        NodoLS* nodoLista;
        do
        {
            fart= artistas->getFirst();
            fsong = canciones->getFirst();
            cin.clear();
            cout << "----------------------------------------------" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "---------------MENU PRINCIPAL----------------" << endl;
            cout << "----------------------------------------------" << endl;
            cout << "----------------------------------------------" << endl << endl;
            cout << "\t1 .- Visualizar Artistas" << endl;
            cout << "\t2 .- Visualizar Canciones" << endl;
            cout << "\t3 .- Ver Playlist" << endl;
            cout << "\t4 .- Importar Playlist" << endl;
            cout << "\t5 .- Estadisticas" << endl;
            cout << "\t6 .- Salir" << endl << endl;
            cout << "Elije una opcion: ";

            cin >> tecla;

            switch(tecla)
            {
            case '1':
                cout <<"--------------NAVEGACION POR ARTISTA-------------"<<endl;
                cout << "----------------------------------------------" << endl;

                while (fart!=0)
                {
                    cout << c <<". " << fart->getDato()->getName()<<endl;
                    fart= fart->getNext();
                    c++;
                }
                c=1;
                cout << "Elija un artista opcion:";
                cin >> sA;
                cout << "\n "<<endl;

                selectArt=artistas->get_element_at(sA-1);
                cubo = selectArt->getDiscografia()->getRoot();

                ///RECORRO PRIMERO AÑOS
                while(cubo!= 0)
                {

                    cout << "ALBUM DE AÑO: "<<cubo->getX() <<endl;
                    ///RECORRO MESES DEL AÑO
                    while(cubo->getAdelante()!=0)
                    {
                        if(cubo->getAlbum()->getName().compare("root") == 0 ||  cubo->getAlbum()->getName().compare("FILA") == 0 || cubo->getAlbum()->getName().compare("MESES") == 0 )
                        {

                        }
                        else
                        {
                            ///Debo recorrer en z si existe
                            if(cubo->getArriba()!=0){
                                while(cubo->getArriba()!=0){
                                    cout<<c<<". " <<cubo->getAlbum()->getName() << endl;
                                    cubo->getAlbum()->setIndice(c);
                                        c++;
                                    cubo= cubo->getArriba();
                                    if(cubo->getArriba()==0){
                                        cout<<c<<". " <<cubo->getAlbum()->getName() << endl;
                                        cubo->getAlbum()->setIndice(c);
                                        c++;
                                    }
                                }
                                while(cubo->getAbajo()!= 0){
                                    cubo = cubo->getAbajo();
                                }

                            }
                            cout<<c<<". " <<cubo->getAlbum()->getName() << endl;
                            cubo->getAlbum()->setIndice(c);
                            c++;

                        }

                        cubo=cubo->getAdelante();



                        if(cubo->getAdelante()==0)
                        {
                            if(cubo->getAlbum()->getName().compare("root") == 0 ||  cubo->getAlbum()->getName().compare("FILA") == 0 || cubo->getAlbum()->getName().compare("MESES") == 0 )
                            {

                            }
                            else
                            {
                            ///Debo recorrer en z si existe
                            if(cubo->getArriba()!=0){
                                while(cubo->getArriba()!=0){
                                    cout<<c<<". " <<cubo->getAlbum()->getName() << endl;
                                    cubo->getAlbum()->setIndice(c);
                                        c++;
                                    cubo= cubo->getArriba();
                                    if(cubo->getArriba()==0){
                                        cout<<c<<". " <<cubo->getAlbum()->getName() << endl;
                                        cubo->getAlbum()->setIndice(c);
                                        c++;
                                    }
                                }
                                while(cubo->getAbajo()!= 0){
                                    cubo = cubo->getAbajo();
                                }

                            }
                            cout<<c<<". " <<cubo->getAlbum()->getName() << endl;
                            cubo->getAlbum()->setIndice(c);
                            c++;

                        }

                        }


                    }


                    ///REGRESO
                    while(cubo->getAtras()!=0)
                    {
                        cubo=cubo->getAtras();
                    }
                    cubo= cubo->getDerecha();
                }
                cout << "Elija un album opcion:";
                cin >> indexAlb;
                selectAlb= selectArt->getDiscografia()->getAlbum(indexAlb);
                albumS = selectAlb->getCanciones();
                cout << "-" << endl;
                cout <<"Seleccione cancion del album   "<< selectAlb->getName()<< endl;
                cout <<" "<<  endl;
                c=1;
                nodoLista = albumS->getFirst();
                while(nodoLista!=0){
                    cout << c <<".  "<< nodoLista->getDato()->getName()<<endl;
                    c++;
                    nodoLista= nodoLista->getNext();
                }
                //VAMOS BIEN
                c=1;
                cout << "Elija una cancion opcion:";
                cin >> selecSong;
                nodoLista = albumS->getFirst();
                while(nodoLista!=0){
                    if (selecSong == c){break;}
                    c++;
                    nodoLista= nodoLista->getNext();
                }
                c=1;
                cout << "----------------------------"<<endl;
                cout << "SELECCIONO"<<nodoLista->getDato()->getName()<< endl;
                cout << "SELECCIONO"<<nodoLista->getDato()->getRanking()<< endl;

                break;

            case '2':
                cout <<"---------------------------"<<endl;
                cout << "NAVEGACION POR CANCION."<< endl;
                cout << "--------------------------" << endl;

                while (fsong!=0)
                {
                    cout << c <<". " << fsong->getDato()->getName()<<endl;
                    c++;
                    fsong= fsong->getNext();
                }
                cout << " \n"<<endl;
                cout << "Elija una opcion:";
                cin >>sS;
                cout << "---------" << endl;
                cout <<"YOU SELECT :" <<endl;
                selectSong= canciones->get_element_at(sS-1);
                cout << selectSong->getName()<<endl;
                cout << selectSong->getArtist()<<endl;
                cout << selectSong->getAlbum()<<endl;
                cout << selectSong->getRanking()<<endl;
                cout << "---------" << endl;
                c=1;
                break;

            case '3':
                system("cls");
                cout << "Has elejido Multiplicar.\n";

                break;

            case '4':
                system("cls");
                cout << "Has elejido Dividir.\n";

                break;

            case '5':
                bandera=true;
                exit(1);
                break;
            case '6':
                bandera=true;
                exit(1);
                break;
            default:

                cout << "Opcion no valida.\a\n";

                break;
            }
        }
        while(bandera!=true);






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
void pausa()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}


