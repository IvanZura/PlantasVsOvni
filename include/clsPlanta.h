#ifndef CLSPLANTA_H
#define CLSPLANTA_H

#include <clsSprite.h>
#include <clsRandom.h>
#include <clsTimer.h>
#include <clsDisparoPlanta.h>


class clsPlanta : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen *s);
        bool fueClick(int, int);
        void setSalud(char*);
        char* getSalud();
        void disparo(clsScreen*);
        bool toco(clsSprite*);
        void lastima(clsScreen*);
        int strLen(char*);
        int strToInt(char*);
        void setChoqueCero();
    protected:

    private:
        char salud[4];
        int choque = 0;
        clsScreen *screen;
        clsRandom random;
        clsTimer timer;
        clsDisparoPlanta disparoPlanta;
};

#endif // CLSPLANTA_H
