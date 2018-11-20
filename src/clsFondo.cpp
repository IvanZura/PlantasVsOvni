#include "clsFondo.h"

int clsFondo::init(clsScreen *s)
{
    screen = s;
    setItems(1);
    setI(0);
    error.set(load("images/FONDO.png"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}
