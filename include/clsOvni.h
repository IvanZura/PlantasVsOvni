#ifndef CLSOVNI_H
#define CLSOVNI_H

#include <adnConsts.h>
#include <clsSprite.h>
#include <clsRandom.h>
#include <clsScreen.h>

class clsOvni : public clsSprite
{
    public:
        clsOvni();
        void inherit(){};
        int init(clsScreen *s);
        void setVelocidad(int);
        int getVelocidad();
        void avanzar(clsScreen *);
        int getInitia();
        void setInitia(int, clsScreen*);
        bool toco(clsSprite*);

    protected:

    private:
        int initia = 0;
        clsScreen *screen;
        clsRandom random;
        int velocidad;
};

#endif // CLSOVNI_H
