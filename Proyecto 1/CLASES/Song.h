#ifndef SONG_H
#define SONG_H
#include <string>

class Song
{
    public:
        Song(string nombre, string archivo, double puesto){
            Name = nombre;
            File = archivo;
            Ranking = puesto;
        }
        string getName(){return Name;}
        string getFile(){return File;}
        double getRanking(return Ranking;)
        virtual ~Song();

    private:
        string Name;
        string File;
        double Ranking;
};

#endif // SONG_H

