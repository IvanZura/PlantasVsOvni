#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsSprite.h>


class clsMenu : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen *s);
        bool fueClick(int, int);

    protected:

    private:
        clsScreen *screen;
};

#endif // CLSMENU_H
