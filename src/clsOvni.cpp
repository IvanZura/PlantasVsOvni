#include "clsOvni.h"

clsOvni::clsOvni()
{
    setItems(1);
    setI(0);
    load("images/ovni-80-80.png");
    this->velocidad = 0;

}
int clsOvni::init(clsScreen *s)
{
    this->initia = 1;
    //setX(1524);
    switch(random.getNumber(5))
    {
        case 0:
        {
            setY(60);
        }break;
        case 1:
        {
            setY(160);
        }break;
        case 2:
        {
            setY(260);
        }break;
        case 3:
        {
            setY(360);
        }break;
        case 4:
        {
            setY(460);
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
    setX(1524);
    paste(s->getPtr());
}
bool clsOvni::toco(clsSprite *spr)
{
    return this->getContact(spr);
}
