#ifndef SONG_H
#define SONG_H
#include <string>

using namespace std;

class Song
{
    public:
        Song(string nombre, string archivo, double puesto);

        string getName(){return Name;}
        string getFile(){return File;}
        double getRanking(){return Ranking;}
        virtual ~Song();

    private:
        string Name;
        string File;
        double Ranking;
};

#endif // SONG_H
