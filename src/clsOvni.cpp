#include "clsOvni.h"

clsOvni::clsOvni()
{
    setItems(1);
    setI(0);
    load("images/ovni-100-100.png");
    this->velocidad = 0;

}
int clsOvni::init(clsScreen *s)
{
    this->initia = 1;
    setX(1024);
    switch(random.getNumber(5))
    {
        case 0:
        {
            setY(50);
        }break;
        case 1:
        {
            setY(150);
        }break;
        case 2:
        {
            setY(250);
        }break;
        case 3:
        {
            setY(350);
        }break;
        case 4:
        {
            setY(450);
        }break;
    }
    paste(s->getPtr());
}

void clsOvni::setVelocidad(int vel)
{
    if(vel < 10 && vel >= 0) this->velocidad = vel;

}
int clsOvni::getVelocidad()
{
    return this->velocidad;
}
void clsOvni::avanzar(clsScreen *screen)
{
    setX(getX()+getVelocidad());
    if(getX()>screen->getWidth())
    {
        setX(0-getWidth());
    }
    paste(screen->getPtr());
}
int clsOvni::getInitia()
{
    return this->initia;
}
void clsOvni::setInitia(int num, clsScreen *s)
{
    this->initia = 0;
    setX(1024);
    paste(s->getPtr());
}
bool clsOvni::toco(clsSprite *spr)
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
