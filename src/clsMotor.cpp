#include "clsMotor.h"

int clsMotor::strLen (char *palabra)
{
    int i=0;
    while (palabra[i]!='\0')
    {
        i++;
    }
    return i;
}
int clsMotor::strToInt(char *cadena)
{
    int x=1;
    int resultado=0;
    int tam=this->strLen(cadena)-1;
    for (int c1=tam; c1>=0; c1--)
    {
        resultado+=((cadena[c1]-48)*x);
        x*=10 ;
    }
    return resultado;
}
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
    for(int t = 0; t < 5; t++)
    {
       if(t < 2)
       {
           PuntajeTexto[t].init();
           PuntajeTexto[t].loadFont("FONTS/FreeMono.ttf", 30);
           PuntajeTexto[t].setFontColor(BLUE);
           PuntajeTexto[t].setStyle(BOLD);
           PuntajeTexto[t].setBackColor(WHITE);
       }
       SaludTexto[t].init();
       SaludTexto[t].loadFont("FONTS/FreeMono.ttf", 30);
       SaludTexto[t].setFontColor(BLUE);
       SaludTexto[t].setStyle(BOLD);
    }
    bool AST = true;
    while(!salir)
    {
        fondo.paste(screen.getPtr());
        PuntajeTexto[0].write("PUNTAJE: ", 320, 550, screen.getPtr());
        cout << this->puntaje << endl;
        cout << this->bufferText << endl;
        itoa(this->puntaje, this->bufferText, 10);

        PuntajeTexto[0].write(this->bufferText, 500, 550, screen.getPtr());
        if(strcmp(planta1.getSalud(),"0")) {planta1.paste(250,50,screen.getPtr());SaludTexto[0].write(planta1.getSalud(), 270, 120, screen.getPtr());}
        if(strcmp(planta2.getSalud(),"0")) {planta2.paste(250,150,screen.getPtr());SaludTexto[1].write(planta2.getSalud(), 270, 220, screen.getPtr());}
        if(strcmp(planta3.getSalud(),"0")) {planta3.paste(250,250,screen.getPtr());SaludTexto[2].write(planta3.getSalud(), 270, 320, screen.getPtr());}
        if(strcmp(planta4.getSalud(),"0")) {planta4.paste(250,350,screen.getPtr());SaludTexto[3].write(planta4.getSalud(), 270, 420, screen.getPtr());}
        if(strcmp(planta5.getSalud(),"0")) {planta5.paste(250,450,screen.getPtr());SaludTexto[4].write(planta5.getSalud(), 270, 520, screen.getPtr());}

        // chequea cada instancia
        for(int i = 0; i < this->cantPersonajes; i++)
        {
            // crea ovnis cada determinado segundo y mientras no esten inicializados
            if(timer.getState() > this->dificultadTiempo && ovni[i].getInitia() == 0)
            {
                ovni[i].init(&screen);
                ovni[i].setX(1024);

                timer.start();
            }
            // Hace que se mueva el ovni
            if(ovni[i].getInitia() == 1)
            {
                // lastima planta
                if(planta1.fueClick(ovni[i].getX(), ovni[i].getY()) && strcmp(planta1.getSalud(),"0"))
                {
                    //cout << "toco a la planta el ovni en: " << i << " con Y en: " << ovni[i].getY() << endl;
                    ovni[i].setInitia(0, &screen);
                    planta1.lastima(&screen);
                }
                if(planta2.fueClick(ovni[i].getX(), ovni[i].getY()) && strcmp(planta2.getSalud(),"0"))
                {
                    //cout << "toco a la planta el ovni en: " << i << " con Y en: " << ovni[i].getY() << endl;
                    ovni[i].setInitia(0, &screen);
                    planta2.lastima(&screen);
                }
                if(planta3.fueClick(ovni[i].getX(), ovni[i].getY()) && strcmp(planta3.getSalud(),"0"))
                {
                    //cout << "toco a la planta el ovni en: " << i << " con Y en: " << ovni[i].getY() << endl;
                    ovni[i].setInitia(0, &screen);
                    planta3.lastima(&screen);
                }
                if(planta4.fueClick(ovni[i].getX(), ovni[i].getY()) && strcmp(planta4.getSalud(),"0"))
                {
                    //cout << "toco a la planta el ovni en: " << i << " con Y en: " << ovni[i].getY() << endl;
                    ovni[i].setInitia(0, &screen);
                    planta4.lastima(&screen);
                }
                if(planta5.fueClick(ovni[i].getX(), ovni[i].getY()) && strcmp(planta5.getSalud(),"0"))
                {
                    //cout << "toco a la planta el ovni en: " << i << " con Y en: " << ovni[i].getY() << endl;
                    ovni[i].setInitia(0, &screen);
                    planta5.lastima(&screen);
                }
                ovni[i].setX(ovni[i].getX() - this->dificultad);
                ovni[i].paste(screen.getPtr());
                if(ovni[i].getX() - this->dificultad <= 0)
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
                    if(AST)
                    {
                        this->puntaje -= this->cantPersonajes;
                        AST = false;
                    }
                    this->puntaje++;
                    ovni[w].setInitia(0, &screen);
                    disparoPlanta[i].setInitia(0, &screen);
                    if(this->puntaje == 10)
                    {
                        this->dificultad = 5;
                        this->dificultadTiempo = 750;
                    }
                    if(this->puntaje == 20)
                    {
                        this->dificultad = 7;
                        this->dificultadTiempo = 500;
                    }
                    if(this->puntaje == 30)
                    {
                        this->dificultad = 9;
                        this->dificultadTiempo = 300;
                    }
                    if(this->puntaje == 40)
                    {
                        this->dificultad = 11;
                        this->dificultadTiempo = 150;
                    }
                }

            }
        }

        screen.refresh();
        if(event.wasEvent())
        {
            if(event.getEventType() == KEY_PRESSED)
            {
                if(event.getKey() == KEY_p)
                {
                    timer.wait(1000);
                }
                error.set(keyCommand(&salir, event.getKey(), &timer));
                if(error.get()) return error.get();
            }
            if(event.getEventType() == MOUSE_DOWN)
            {
                if(planta1.fueClick(event.getCursorX(), event.getCursorY()) && strcmp(planta1.getSalud(),"0"))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta1.getX() + 100, planta1.getY() + 20);
                            break;
                        }
                    }

                }
                else if(planta2.fueClick(event.getCursorX(), event.getCursorY()) && strcmp(planta2.getSalud(),"0"))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta2.getX() + 100, planta2.getY() + 20);
                            break;
                        }
                    }
                    //screen.refresh();
                }
                else if(planta3.fueClick(event.getCursorX(), event.getCursorY()) && strcmp(planta3.getSalud(),"0"))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta3.getX() + 100, planta3.getY() + 20);
                            break;
                        }
                    }
                    //screen.refresh();
                }
                else if(planta4.fueClick(event.getCursorX(), event.getCursorY()) && strcmp(planta4.getSalud(),"0"))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta4.getX() + 100, planta4.getY() + 20);
                            break;
                        }
                    }
                    //screen.refresh();
                }
                else if(planta5.fueClick(event.getCursorX(), event.getCursorY()) && strcmp(planta5.getSalud(),"0"))
                {
                    for(int q = 0; q < this->cantPersonajes; q++)
                    {
                        if(disparoPlanta[q].getInitia() == 0)
                        {
                            disparoPlanta[q].init(&screen, planta5.getX() + 100, planta5.getY() + 20);
                            break;
                        }
                    }
                    //screen.refresh();
                }
                screen.refresh();
            }
        }
        //timer.wait(1);
    }

    log.close();
    return error.get();
}

int clsMotor::keyCommand(bool*salir, Uint16 key, clsTimer *timer)
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
            //timer->wait();
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
