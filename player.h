#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>


class player{

    private:
        int xloc, yloc,xmax,ymax;
        char caracter;
        WINDOW* cwin;
    public:
         player(WINDOW*,int,int,char);
        void mvup();
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();
        void display();

};
#endif