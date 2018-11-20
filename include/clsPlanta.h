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
        void disparo(clsScreen*);
    protected:

    private:
        clsScreen *screen;
        clsRandom random;
        clsTimer timer;
        clsDisparoPlanta disparoPlanta;
};

#endif // CLSPLANTA_H
