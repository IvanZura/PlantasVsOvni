#include "clsMenu.h"

int clsMenu::init(clsScreen *s)
{
    screen = s;
    setItems(2);
    setI(0);
    error.set(load("images/menu2.png"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    setI(1);
    error.set(load("images/btnIniciar.png"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}
bool clsMenu::fueClick(int x, int y)
{
    bool result = false;

    if(x >= getX() && x <= getX()+getWidth() &&
       y >= getY() && y <= getY()+getHeight())
    {
        result = true;
    }
    return result;
}
