#include <iostream>
#include <ncurses.h>
#include <time.h>
#include "player.h"
/*#include "enemigos.h"
#include "attilan.h"
#include "black_dwarf.h"
#include "thanos.h"
#include "vengadores.h"
#include "iron_man.h"
#include "thor.h"
#include "capitan_america.h"*/

using namespace std;

int main(int argc,char ** argv){

   initscr();
    noecho();
    curs_set(FALSE);
    //ventana 1 juego
    int height1,width1,start_y1,start_x1;
    height1=35;
    width1=125;
    start_x1=30;
    start_y1=1;
    
    WINDOW* win1 =newwin(height1,width1,start_y1,start_x1);//ventana de juego
    refresh();
    box(win1,0,0);
    mvwprintw(win1,0,59,"INFINITY WAR");
    mvwprintw(win1,1,1,"+");
    mvwprintw(win1,1,123,"+");
    mvwprintw(win1,33,1,"+");
    mvwprintw(win1,33,123,"+");
    wrefresh(win1);

    //ventana 2 VIDASS
      int height2,width2,start_y2,start_x2;
    height2=5;
    width2=30;
    start_x2=30;
    start_y2=40;
    
    WINDOW* win2 =newwin(height2,width2,start_y2,start_x2);
    refresh();
    box(win2,0,0);
    mvwprintw(win2,0,12,"HEALTH");
    wrefresh(win2);

     //ventana 3 SCORE
    int height3,width3,start_y3,start_x3;
    height3=5;
    width3=30;
    start_x3=125;
    start_y3=40;
    
    WINDOW* win3 =newwin(height3,width3,start_y3,start_x3);
    refresh();
    box(win3,0,0);
    mvwprintw(win3,0,12,"SCORE");
    wrefresh(win3);
    //------------------------------------
    player* p=new player(win1,1,1,'@');
    do{
        p->display();
        wrefresh(win1);
    }while(p->getmv()!='x');


    int c=getch();
    
    endwin();



    return  0;
}


