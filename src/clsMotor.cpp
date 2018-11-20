#include "clsMotor.h"

int clsMotor::init()
{

    error.set(mode.init(1024, 585, 16));
    if(error.get()) return error.get();

    error.set(screen.init(mode.getScrWidth(),
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE
                          ));
    if(error.get()) return error.get();

    error.set(menuF.init(&screen));
    if(error.get()) return error.get();

    error.set(fondo.init(&screen));
    if(error.get()) return error.get();

    error.set(planta1.init(&screen));
    if(error.get()) return error.get();
    error.set(planta2.init(&screen));
    if(error.get()) return error.get();
    error.set(planta3.init(&screen));
    if(error.get()) return error.get();
    error.set(planta4.init(&screen));
    if(error.get()) return error.get();
    error.set(planta5.init(&screen));
    if(error.get()) return error.get();

    return error.get();
}
int clsMotor::run()
{
    log.open();
    bool salir = false;
    timer.start();

    while(!salir)
    {
        fondo.paste(screen.getPtr());
        planta1.paste(250,50,screen.getPtr());
        planta2.paste(250,150,screen.getPtr());
        planta3.paste(250,250,screen.getPtr());
        planta4.paste(250,350,screen.getPtr());
        planta5.paste(250,450,screen.getPtr());

        // chequea cada instancia
        for(int i = 0; i < this->cantPersonajes; i++)
        {
            // crea ovnis cada determinado segundo y mientras no esten inicializados
            if(timer.getState() > 1000 && ovni[i].getInitia() == 0)
            {

                ovni[i].init(&screen);
                cout << "ovni posicion;" << i << endl;
                timer.start();
            }
            // Hace que se mueva el ovni
            if(ovni[i].getInitia() == 1)
            {
                ovni[i].setX(ovni[i].getX() - 3);
                ovni[i].paste(screen.getPtr());
                if(ovni[i].getX() - 3 <= 0)
                {
                    ovni[i].setInitia(0, &screen);
                }
            }
            // Hace que se muevan los disparos inicializados
            if(disparoPlanta[i].getInitia() == 1)
            {
                disparoPlanta[i].setX(disparoPlanta[i].getX() + 3);
                disparoPlanta[i].paste(screen.getPtr());

                // Si el disparo se va a la mierda, se resetea
                if(disparoPlanta[i].getX() + 3 >= 1024)
                {
                    disparoPlanta[i].setInitia(0, &screen);
                }
            }
            // Si el disparo se encuenta con la misma posicion de un ovni, se resetean ambos
            for(int w = 0; w < this->cantPersonajes; w++)
            {
               if(disparoPlanta[i].toco(&ovni[w]))
                {
                    ovni[w].setInitia(0, &screen);
                    disparoPlanta[i].setInitia(0, &screen);
                }
            }


        }

        screen.refresh();
        if(event.wasEvent())
        {
            if(event.getEventType() == KEY_PRESSED)
            {
                error.set(keyCommand(&salir, event.getKey()));
                if(error.get()) return error.get();
            }
            if(event.getEventType() == MOUSE_DOWN)
            {
                if(planta1.fueClick(event.getCursorX(), event.getCursorY()))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta1.getX() + 100, planta1.getY() + 20);
                            cout << "planta posicion;" << q << endl;
                            break;
                        }
                    }
                    screen.refresh();
                }
                else if(planta2.fueClick(event.getCursorX(), event.getCursorY()))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta2.getX() + 100, planta2.getY() + 20);
                            cout << "planta posicion;" << q << endl;
                            break;
                        }
                    }
                    screen.refresh();
                }
                else if(planta3.fueClick(event.getCursorX(), event.getCursorY()))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta3.getX() + 100, planta3.getY() + 20);
                            cout << "planta posicion;" << q << endl;
                            break;
                        }
                    }
                    screen.refresh();
                }
                else if(planta4.fueClick(event.getCursorX(), event.getCursorY()))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta4.getX() + 100, planta4.getY() + 20);
                            cout << "planta posicion;" << q << endl;
                            break;
                        }
                    }
                    screen.refresh();
                }
                else if(planta5.fueClick(event.getCursorX(), event.getCursorY()))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta5.getX() + 100, planta5.getY() + 20);
                            cout << "planta posicion;" << q << endl;
                            break;
                        }
                    }
                    screen.refresh();
                }
            }
        }
        //timer.wait(1);
    }

    log.close();
    return error.get();
}

int clsMotor::keyCommand(bool*salir, Uint16 key)
{
    error.set(0);
    switch(key)
    {
        case KEY_ESCAPE:
        {
            *salir = true;
        }break;
        case KEY_ENTER:
        {

        }break;
        case KEY_R:
        case KEY_r:
        {
            screen.clean(BLUE);
            screen.refresh();
        }break;
    }

    return error.get();
}
int clsMotor::menu()
{
    menuF.setI(0);
    menuF.paste(0, -80, screen.getPtr());
    menuF.setI(1);
    menuF.paste(300, 100, screen.getPtr());
    screen.refresh();
    int opMenu = 0;
    bool salir = false;
    while(!salir)
    {
        if(event.wasEvent())
        {
            if(event.getEventType() == MOUSE_DOWN)
            {
                menuF.setI(1);
                if(menuF.fueClick(event.getCursorX(), event.getCursorY()))
                {
                    opMenu = 1;
                    salir = true;
                }
            }
        }
    }
    return opMenu;
}
