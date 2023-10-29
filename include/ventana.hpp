#pragma once
#include <curses.h>
#include <iostream>
#include <unistd.h>

class Ventana
{
private:
    int x, y;
    int velocidad;
    bool ejecucion;
    int contador;

public:
    Ventana()
    {

        initscr();

        getmaxyx(stdscr, this->y, this->x); // screen --> src
        this->ejecucion = false;
        this->velocidad = 10;
        this->contador=20;
        curs_set(FALSE);
        cbreak();
        timeout(100);
        noecho();
        keypad(stdscr,TRUE);
    }
    void Iniciar()
    {

        while (this->ejecucion)
        {

            this->Actualizar();
            this->Dibujar();

            refresh();
            sleep(this->velocidad);
        }

        refresh();
        sleep(10);
    }

    void Actualizar()
    {
        this->contador = this->contador - 1;
        if (this->contador == 0)
        {
            this->Cerrar();
        }
    }

    void Dibujar()
    {
        box(stdscr, 'E', 'l');
    }

    void Cerrar()
    {
        this->ejecucion = false;
    }
    
    ~Ventana()
    {

        endwin();
    }
};