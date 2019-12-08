#ifndef CANCION_H
#define CANCION_H


class Cancion
{
     public:
        Song(string nam, string fil, double ranks){
            Name=nam;
            File=fil;
            Ranking=ranks;
        }
        virtual ~Song();

    private:
        string Name;
        string File;
        double Ranking;
};

#endif // CANCION_H
