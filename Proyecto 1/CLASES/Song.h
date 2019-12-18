#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song
{
    public:
        Song(string nombre, double puesto);
        Song(string nombre, string ano, string mes, string album, string artista);

        string getName(){return Name;}
        string getYear(){return ano;}
        string getMonth(){return mes;}
        string getAlbum(){return album;}
        string getArtist(){return artist;}


        double getRanking(){return Ranking;}
        virtual ~Song();

    private:
        string Name;
        double Ranking;
        string ano;
        string mes;
        string album;
        string artist;
};

#endif // SONG_H
