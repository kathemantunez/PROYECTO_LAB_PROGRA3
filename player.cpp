
#include "player.h"

player::player(WINDOW* win,int y,int x,char c){
    cwin=win;
    yloc=y;
    xloc=x;
    getmaxyx(cwin,ymax,xmax);
    keypad(cwin,true);
    caracter=c;
}
void player::mvup(){
    mvwaddch(cwin,yloc,xloc,' ');
    yloc--;
    if(yloc<1)
        yloc=1;
}
void player::mvdown(){
      mvwaddch(cwin,yloc,xloc,' ');
    yloc++;
    if(yloc>ymax-2)
        yloc=ymax-2;
}
void player::mvleft(){
      mvwaddch(cwin,yloc,xloc,' ');
    xloc--;
    if(xloc<1)
        xloc=1;
}
void player::mvright(){
      mvwaddch(cwin,yloc,xloc,' ');
    xloc++;
    if(xloc>xmax-2)
        xloc=xmax-2;
}
int player::getmv(){
    int opcion=wgetch(cwin);
    switch(opcion){
        case KEY_UP:
            mvup();
            break;
        case KEY_DOWN:
            mvdown();
            break;
        case KEY_LEFT:
                mvleft();
                break;
        case KEY_RIGHT:
            mvright();
            break;
        default:
        break;
    }

    return opcion;
}
void player::display(){
    mvwaddch(cwin,yloc,xloc,caracter);
}