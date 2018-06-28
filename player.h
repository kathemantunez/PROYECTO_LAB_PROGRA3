#ifndef PLAYER_H
#define PLAYER_H
#include <ncurses.h>
#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_PURPLE 5
#define DARK_YELLOW 6
#define LIGHT_GREY 7
#define DARK_GREY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define WHITE 15


class player{

    protected:
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