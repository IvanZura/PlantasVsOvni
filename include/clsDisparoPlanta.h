#ifndef CLSDISPAROPLANTA_H
#define CLSDISPAROPLANTA_H

#include <clsSprite.h>


class clsDisparoPlanta : public clsSprite
{
    public:
        clsDisparoPlanta();
        void inherit(){};
        int init(clsScreen*, int, int);
        int getInitia();
        void setInitia(int, clsScreen*);
        bool toco(clsSprite*);

    protected:

    private:
        int initia = 0;
        clsScreen *screen;
};

#endif // CLSDISPAROPLANTA_H
