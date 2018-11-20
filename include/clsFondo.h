#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>
#include <clsScreen.h>


class clsFondo : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen *s);

    protected:

    private:
        clsScreen *screen;
};

#endif // CLSFONDO_H
