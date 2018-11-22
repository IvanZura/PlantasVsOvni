#include "clsPlanta.h"

void clsPlanta::setSalud(char* sal)
{
    strcpy(this->salud, sal);
}
int clsPlanta::strLen (char *palabra)

{
    int i=0;
    while (palabra[i]!='\0')
    {
        i++;
    }
    return i;
}
int clsPlanta::strToInt(char *cadena)
{
    int x=1;
    int resultado=0;
    int tam=strLen(cadena)-1;
    for (int c1=tam; c1>=0; c1--)
    {
        resultado+=((cadena[c1]-48)*x);
        x*=10 ;
    }
    return resultado;
}
int clsPlanta::init(clsScreen *s)
{
    strcpy(this->salud, "100");
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
char* clsPlanta::getSalud()
{
    return this->salud;
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
bool clsPlanta::toco(clsSprite *spr)
{
    return this->getContact(spr);
}
void clsPlanta::setChoqueCero()
{
    this->choque = 0;
}
void clsPlanta::lastima(clsScreen *s)
{
    if(this->choque == 0)
    {
        strcpy(this->salud, "75");
        this->choque = 1;
    }
    else if(this->choque == 1)
    {
        strcpy(this->salud, "50");
        this->choque = 2;
    }
    else if(this->choque == 2)
    {
        strcpy(this->salud, "25");
        this->choque = 3;
    }
    else if(this->choque == 3)
    {
        strcpy(this->salud, "0");
        this->choque = 4;
    }

    if(strcmp(this->salud,"0"))
    {
        setY(-100);
        paste(s->getPtr());
    }
    //load("images/plants3-100-100-lastimado.png");

}
