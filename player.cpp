
#include "player.h"
#include <ncurses.h>

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
    start_color();
      mvwaddch(cwin,yloc,xloc,' ');
    xloc--;
    if(xloc<1)
        xloc=1;
    int tempx=xloc;
    int tempy=yloc;

    //fila 10

    mvwaddch(cwin,yloc,xloc+1,' ');
    mvwaddch(cwin,yloc,xloc+2,' ');
    mvwaddch(cwin,yloc,xloc+3,' ');
    mvwaddch(cwin,yloc,xloc+4,' ');
    mvwaddch(cwin,yloc,xloc+5,' ');

    mvwaddch(cwin,yloc-1,xloc+2,' ');
    mvwaddch(cwin,yloc-1,xloc+3,' ');
    mvwaddch(cwin,yloc-1,xloc+4,' ');

    mvwaddch(cwin,yloc-2,xloc+3,' ');
 

    
  
}
void player::mvright(){
    start_color();
    mvwaddch(cwin,yloc,xloc,' ');

    mvwaddch(cwin,yloc,xloc-1,' ');
    mvwaddch(cwin,yloc,xloc+4,' ');
    mvwaddch(cwin,yloc,xloc+9,' ');

    mvwaddch(cwin,yloc-1,xloc-1,' ');

    mvwaddch(cwin,yloc-2,xloc-1,' ');
    mvwaddch(cwin,yloc-2,xloc,' ');
    mvwaddch(cwin,yloc-2,xloc+8,' ');


    
    int tempx=xloc;
    int tempy=yloc;
    //10
    mvwaddch(cwin,tempy,tempx,'.');
    mvwaddch(cwin,tempy,tempx+5,'.');
    
    mvwaddch(cwin,tempy,tempx+10,'.');
    

    //9
    mvwaddch(cwin,tempy-1,tempx,'.');
    mvwaddch(cwin,tempy-1,tempx+1,'.');
    mvwaddch(cwin,tempy-1,tempx+2,'.');
    mvwaddch(cwin,tempy-1,tempx+3,'.');
    mvwaddch(cwin,tempy-1,tempx+4,'.');
    mvwaddch(cwin,tempy-1,tempx+5,'.');
    mvwaddch(cwin,tempy-1,tempx+6,'.');
    mvwaddch(cwin,tempy-1,tempx+7,'.');
    mvwaddch(cwin,tempy-1,tempx+8,'.');
    mvwaddch(cwin,tempy-1,tempx+9,'.');
    mvwaddch(cwin,tempy-1,tempx+10,'.');
    //8
    mvwaddch(cwin,tempy-2,tempx,'.');
    mvwaddch(cwin,tempy-2,tempx+1,'.');
    mvwaddch(cwin,tempy-2,tempx+3,'.');
    mvwaddch(cwin,tempy-2,tempx+4,'.');
    mvwaddch(cwin,tempy-2,tempx+5,'.');
    mvwaddch(cwin,tempy-2,tempx+6,'.');
    mvwaddch(cwin,tempy-2,tempx+7,'.');
    mvwaddch(cwin,tempy-2,tempx+8,'.');
    mvwaddch(cwin,tempy-2,tempx+10,'.');

    xloc++;
    if(xloc>xmax-2)
        xloc=xmax-2;

    

    

 
}
int player::getmv(){
    int opcion=wgetch(cwin);
    switch(opcion){
        case KEY_UP:
            //mvup();
            break;
        case KEY_DOWN:
            //mvdown();
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
    mvwaddch(cwin,yloc,xloc,' ');
}