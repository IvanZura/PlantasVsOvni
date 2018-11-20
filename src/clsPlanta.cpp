#include "clsPlanta.h"

int clsPlanta::init(clsScreen *s)
{
    if(error.get()) return error.get();

    screen = s;
    setItems(1);
    setI(0);
    error.set(load("images/plants3-100-100.png"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}
bool clsPlanta::fueClick(int x, int y)
{
    bool result = false;

    if(x >= getX() && x <= getX()+getWidth() &&
       y >= getY() && y <= getY()+getHeight())
    {
        result = true;
    }
    return result;
}
