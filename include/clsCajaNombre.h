#ifndef CLSCAJANOMBRE_H
#define CLSCAJANOMBRE_H

#include <clsSprite.h>


class clsCajaNombre : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen*, int, int);

    protected:

    private:
        clsScreen *screen;
};

#endif // CLSCAJANOMBRE_H
