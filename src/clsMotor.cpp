//#############################################################################
// ARCHIVO             : clsMotor.cpp
// AUTOR               : Ivan Alejandro Zura.
// VERSION             : v. 14.11 estable.
// FECHA DE CREACION   : 1/11/2018.
// ULTIMA ACTUALIZACION: 22/11/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Esta clase maneja todo el juego
//
///////////////////////////////////////////////////////////////////////////////
#include "clsMotor.h"

//=============================================================================
// METODO    : int strLen(char*)
// ACCION    : Devuelve la cantidad de caracteres que tiene una palabra que se le pase
// PARAMETROS: char*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMotor::strLen (char *palabra)
{
    int i=0;
    while (palabra[i]!='\0')
    {
        i++;
    }
    return i;
}
//=============================================================================
// METODO    : int strToInt(char*)
// ACCION    : Devuelve en numero entero la cadena que se le pase
// PARAMETROS: char*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
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
//=============================================================================
// METODO    : int init()
// ACCION    : Inicializa todo lo necesario para lanzar el juego
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
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
//=============================================================================
// METODO    : int mostrarPuntos()
// ACCION    : Muestra todos los puntajes del archivo de puntos
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMotor::mostrarPuntos()
{
    error.set(0);
    menuF[0].paste(0, -80, screen.getPtr());
    screen.refresh();
    TodosPuntos.mostrarPuntos(&screen);
    timer.waitForKey(KEY_ENTER);
    return error.get();
}
//=============================================================================
// METODO    : int PerdistePapu()
// ACCION    : Muesta el cartel para poner el nombre cuando perdes
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMotor::PerdistePapu()
{
    error.set(0);
    int salir = false;
    for(int i = 0; i < 3; i++)
    {
        NombreText[i].init();
        NombreText[i].loadFont("FONTS/snap.TTF", 20);
        NombreText[i].setFontColor(BLACK);
        //NombreText[i].setStyle(BOLD);
    }
    this->nombre[0] = '\0';
    PerdisteText.init();
    PerdisteText.loadFont("FONTS/snap.TTF", 40);
    PerdisteText.setFontColor(BLACK);
    //PerdisteText.setStyle(BOLD);
    PerdisteText.centredWrite("Perdiste PAPU", 250, screen.getPtr());

    screen.refresh();
    int i=0;
    while(!salir)
    {
        caja.init(&screen, 400, 310);
        NombreText[0].write("Ingresa tu nombre", 410, 315, screen.getPtr());
        NombreText[1].write("Y luego apreta ENTER", 410, 335, screen.getPtr());
        if(event.wasEvent())
        {
            if(event.getEventType() == KEY_PRESSED)
            {
                int letra = (int) event.getKey();
                if(letra == ' ' || (letra >= '0' && letra <= '9') || (letra >= 'a' && letra <= 'z'))
                {
                    if(event.getKeyMode() == KEY_MDF_CAPSLOCK && letra != ' ' && (letra < '0' || letra > '9'))
                        letra -= 32;
                    if(i < 18)
                    {
                        this->nombre[i] = letra;
                        this->nombre[i+1] = '\0';
                        i++;
                    }
                }
                if(event.getKey() == KEY_BACKSPACE && i > 0)
                {
                    this->nombre[i-1] = '\0';
                    i--;
                }
                if(event.getKey() == KEY_ENTER && i > 0)
                {
                    salir = true;
                }
            }
        }
        if(nombre[0] != '\0')
        {
            NombreText[2].write(this->nombre, 420, 365, screen.getPtr());
        }
        screen.refresh();
    }
    puntos.setPuntos(this->puntaje);
    puntos.setNombre(this->nombre);
    puntos.Guardar();
    //error.set(puntos.setPuntos(this->nombre, this->puntaje));
    return error.get();
}
//=============================================================================
// METODO    : int run()
// ACCION    : Este realiza toda la "magia" del juego. lleva a cabo el juego.
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMotor::run()
{
    this->dificultad = 3;
    this->dificultadTiempo = 1000;
    planta1.paste(250,50,screen.getPtr());
    planta2.paste(250,150,screen.getPtr());
    planta3.paste(250,250,screen.getPtr());
    planta4.paste(250,350,screen.getPtr());
    planta5.paste(250,450,screen.getPtr());
    planta1.setSalud("100");
    planta2.setSalud("100");
    planta3.setSalud("100");
    planta4.setSalud("100");
    planta5.setSalud("100");
    planta1.setChoqueCero();
    planta2.setChoqueCero();
    planta3.setChoqueCero();
    planta4.setChoqueCero();
    planta5.setChoqueCero();

    this->puntaje = 0;

    for(int as = 0; as < cantPersonajes; as++){
        this->ovni[as].setInitia(0, &screen);
        this->disparoPlanta[as].setInitia(0, &screen);
    }

    log.open();
    bool salir = false;
    timer.start();
    PausaText.init();
    PausaText.loadFont("FONTS/snap.TTF", 50);
    PausaText.setFontColor(BLACK);
    //PausaText.setStyle(BOLD);
    PausaText.setBackColor(WHITE);
    for(int t = 0; t < 5; t++)
    {
       if(t < 2)
       {
           PuntajeTexto[t].init();
           PuntajeTexto[t].loadFont("FONTS/snap.TTF", 30);
           PuntajeTexto[t].setFontColor(BLACK);
           //PuntajeTexto[t].setStyle(BOLD);
           PuntajeTexto[t].setBackColor(WHITE);
       }
       SaludTexto[t].init();
       SaludTexto[t].loadFont("FONTS/snap.TTF", 30);
       SaludTexto[t].setFontColor(BLACK);
       //SaludTexto[t].setStyle(BOLD);
    }

    while(!salir)
    {
        fondo.paste(screen.getPtr());
        PuntajeTexto[0].write("PUNTAJE: ", 320, 550, screen.getPtr());
        itoa(this->puntaje, this->bufferText, 10);

        PuntajeTexto[1].write(this->bufferText, 550, 550, screen.getPtr());
        if(strcmp(planta1.getSalud(),"0")) {planta1.paste(250,50,screen.getPtr());SaludTexto[0].write(planta1.getSalud(), 270, 120, screen.getPtr());}
        if(strcmp(planta2.getSalud(),"0")) {planta2.paste(250,150,screen.getPtr());SaludTexto[1].write(planta2.getSalud(), 270, 220, screen.getPtr());}
        if(strcmp(planta3.getSalud(),"0")) {planta3.paste(250,250,screen.getPtr());SaludTexto[2].write(planta3.getSalud(), 270, 320, screen.getPtr());}
        if(strcmp(planta4.getSalud(),"0")) {planta4.paste(250,350,screen.getPtr());SaludTexto[3].write(planta4.getSalud(), 270, 420, screen.getPtr());}
        if(strcmp(planta5.getSalud(),"0")) {planta5.paste(250,450,screen.getPtr());SaludTexto[4].write(planta5.getSalud(), 270, 520, screen.getPtr());}
        if(!strcmp(planta1.getSalud(),"0") && !strcmp(planta2.getSalud(),"0") && !strcmp(planta3.getSalud(),"0") && !strcmp(planta4.getSalud(),"0") && !strcmp(planta5.getSalud(),"0")) { salir = true;}
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
                    if(strcmp(planta1.getSalud(),"0")) {planta1.lastima(&screen);}
                    if(strcmp(planta2.getSalud(),"0")) {planta2.lastima(&screen);}
                    if(strcmp(planta3.getSalud(),"0")) {planta3.lastima(&screen);}
                    if(strcmp(planta4.getSalud(),"0")) {planta4.lastima(&screen);}
                    if(strcmp(planta5.getSalud(),"0")) {planta5.lastima(&screen);}
                }

            }
            // Hace que se muevan los disparos inicializados
            if(disparoPlanta[i].getInitia() == 1)
            {
                disparoPlanta[i].setX(disparoPlanta[i].getX() + 6);
                disparoPlanta[i].paste(screen.getPtr());

                // Si el disparo se va a la mierda, se resetea
                if(disparoPlanta[i].getX() + 6 >= 1024)
                {
                    disparoPlanta[i].setInitia(0, &screen);
                }
            }
            // Si el disparo se encuenta con la misma posicion de un ovni, se resetean ambos
            for(int w = 0; w < this->cantPersonajes; w++)
            {
               if(disparoPlanta[i].toco(&ovni[w]))
                {
                    if(this->AST)
                    {
                        //this->puntaje -= this->cantPersonajes*2;
                        this->AST = false;
                    }
                    this->puntaje++;
                    ovni[w].setInitia(0, &screen);
                    disparoPlanta[i].setInitia(0, &screen);
                    if(this->puntaje == 10)
                    {
                        this->dificultad = 5;
                        this->dificultadTiempo = 850;
                    }
                    if(this->puntaje == 20)
                    {
                        this->dificultad = 7;
                        this->dificultadTiempo = 600;
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
                    if(this->puntaje == 50)
                    {
                        this->dificultad = 15;
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
                    PausaText.loadFont("FONTS/snap.TTF", 50);
                    PausaText.centredWrite("PAUSA", 250, screen.getPtr());
                    screen.refresh();
                    timer.waitForKey(KEY_p);
                    PausaText.write("PAUSA", -512, -350, screen.getPtr());
                    screen.refresh();
                }
                if(event.getKey() == KEY_ESCAPE)
                {
                    PausaText.loadFont("FONTS/snap.TTF", 20);
                    PausaText.centredWrite("¿Realmente desea salir? ENTER para salir o ESC para continuar", 200, screen.getPtr());
                    screen.refresh();
                    bool salirESC = false;
                    while(!salirESC)
                    {
                       if(event.wasEvent())
                        {
                            if(event.getEventType() == KEY_PRESSED)
                            {
                                if(event.getKey() == KEY_ENTER)
                                {
                                    salir = true;
                                    salirESC = true;
                                    PausaText.write("PAUSA", -512, -350, screen.getPtr());
                                    screen.refresh();
                                }
                                if(event.getKey() == KEY_ESCAPE)
                                {
                                    salirESC = true;
                                    PausaText.write("PAUSA", -512, -350, screen.getPtr());
                                    screen.refresh();
                                }
                            }
                        }
                    }

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
//=============================================================================
// METODO    : int keyCommand(bool*, Uint16, ClsTimer*)
// ACCION    : Maneja las teclas del juego
// PARAMETROS: bool*, Uint16, ClsTimer*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMotor::keyCommand(bool*salir, Uint16 key, clsTimer *timer)
{
    error.set(0);
    switch(key)
    {
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
//=============================================================================
// METODO    : int menu()
// ACCION    : Maneja el menu principal del juego.
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMotor::menu()
{
    for(int m = 0; m < 4; m++)
    {
        menuF[m].init(&screen);
        if(m==0){menuF[0].load("images/menu2.png");menuF[0].paste(0, -80, screen.getPtr());}
        if(m==1){menuF[1].load("images/btnIniciar2.png");menuF[1].paste(300, 150, screen.getPtr());}
        if(m==2){menuF[2].load("images/btnPuntajes.png");menuF[2].paste(300, 300, screen.getPtr());}
        if(m==3){menuF[3].load("images/btnSalir.png");menuF[3].paste(300, 450, screen.getPtr());}
    }
    screen.refresh();

    TodosPuntos.init();
    int opMenu = 0;
    bool salir = false;
    while(!salir)
    {
        if(event.wasEvent())
        {
            if(event.getEventType() == MOUSE_DOWN)
            {
                if(menuF[1].fueClick(event.getCursorX(), event.getCursorY()))
                {
                    opMenu = 1;
                    salir = true;
                }
                else
                {
                    if(menuF[2].fueClick(event.getCursorX(), event.getCursorY()))
                    {
                        opMenu = 2;
                        salir = true;
                    }
                    else
                    {
                        if(menuF[3].fueClick(event.getCursorX(), event.getCursorY()))
                        {
                            opMenu = 3;
                            salir = true;
                        }
                    }
                }
            }
        }
    }
    return opMenu;
}
//=============================================================================
// METODO    : void presentacion()
// ACCION    : Presentacion
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsMotor::presentacion()
{
    screen.clean(BLACK);
    otroText.init();
    otroText.loadFont("FONTS/snap.TTF", 50);
    otroText.setFontColor(WHITE);
    otroText.centredWrite("Bienvenidos muahahaha", 250, screen.getPtr());
    screen.refresh();
    timer.wait(5000);
}
//=============================================================================
// METODO    : void despedida()
// ACCION    : Presentacion
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsMotor::despedida()
{
    screen.clean(BLACK);
    otroText.init();
    otroText.loadFont("FONTS/snap.TTF", 50);
    otroText.setFontColor(WHITE);
    otroText.centredWrite("adios muahahaha", 250, screen.getPtr());
    screen.refresh();
    timer.wait(5000);
}
