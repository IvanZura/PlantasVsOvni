#include "clsCajaNombre.h"

int clsCajaNombre::init(clsScreen *s, int x, int y)
{
    setItems(1);
    setI(0);
    setX(x);
    setY(y);
    load("images/caja.png");
    paste(s->getPtr());
}
