#include "clsMenu.h"

int clsMenu::init(clsScreen *s)
{
    error.set(0);
    screen = s;
    setItems(1);
    setI(0);
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
