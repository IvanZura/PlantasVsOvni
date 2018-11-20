#include "clsDisparoPlanta.h"

clsDisparoPlanta::clsDisparoPlanta()
{
    setItems(1);
    setI(0);

    load("images/disparo1.png");

}
int clsDisparoPlanta::init(clsScreen *s, int x, int y)
{
    setX(x);
    setY(y);
    this->initia = 1;
    paste(s->getPtr());
}
int clsDisparoPlanta::getInitia()
{
    return this->initia;
}
void clsDisparoPlanta::setInitia(int num, clsScreen *s)
{
    this->initia = num;
    setX(-500);
    paste(s->getPtr());
}
bool clsDisparoPlanta::toco(clsSprite *spr)
{
    return this->getContact(spr);
    /*bool result = false;

    if(x >= getX() && x <= getX()+getWidth() &&
       y >= getY() && y <= getY()+getHeight())
    {
        result = true;
    }
    return result;*/
}
