#include <stdio.h>
#include <string>
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <ctime>
#include <vector>
#include <chrono>
//#include "enemigos.h"
#include <pthread.h>

using namespace std;

void board();
void crear_nave(int,int);
void move_nave_izquierda(int,int);
void move_nave_derecha(int,int);

void borrarnave(int,int);


void balas(int,int);



void crear_enemigos();
void mover_enemigos();
void borrar_enemigos();
void bala_enemigos(int);

void llenar_enemigos();


int vida=3;
int nivel=1;

//vector<enemigos*> v_enemigos;
//instancia de enemigos
//enemigos* e;




int main(void){
    
   pthread_t hilo;
    int x=44,y=75,tx=0,ty=0;
    bool game_over=true;
    char key=' ';
    char tecla;
    int size;

    initscr();
    curs_set(false);
    //tablero de juego
    board();
    crear_enemigos();
    int n_rand;
    bool ok=true;
    
    


    while(game_over){
       // crear_enemigos();
       
        tx=x;
        ty=y;
        //DIBUJO NAVE
        crear_nave(x,y);
        key=getch();
       
        if(key == 'f'){
         game_over = false;
        } else if((key == 'd' || key =='D') && ty<155){ //155
            //fila 1
            move_nave_derecha(tx,ty);
            refresh();
            n_rand=1+rand()%(31-1);
            
            y++;

        } else if((key == 'A' || key =='a') && ty>15){//0
            
            move_nave_izquierda(tx,ty);
            refresh();
           
            y--;
        }else if(key==32){
            balas(tx,ty);
            refresh();
        }else if(ok==true ){
            
             n_rand=1+rand()%(31-1);
            bala_enemigos(n_rand);
            
        }
        //refresh();
    
    
    }
    refresh();
    endwin();


    return 0;
}


void board(){
   


    printw("Nombre del jugador: Katherine");
    move(1,0);
    printw("NIVEL: ");
    move(1,10);
    printw("%d",nivel);

    //move(2,1);
    move(1,160);
    printw("Numero de vidas:");
    move(1,180);
    printw("%d",vida);

    //cuadro inicial
    move(5,15);
    printw("*****************************************************************************************************************************************************");
    move(45,15);
    printw("*****************************************************************************************************************************************************");
    //vertical izquierda

    move(6,15);
    printw("*");
    move(7,15);
    printw("*");
    move(8,15);
    printw("*");
    move(9,15);
    printw("*");
    move(10,15);
    printw("*");
    move(11,15);
    printw("*");
    move(12,15);
    printw("*");
    move(13,15);
    printw("*");
    move(14,15);
    printw("*");
    move(15,15);
    printw("*");
    move(16,15);
    printw("*");
    move(17,15);
    printw("*");
    move(18,15);
    printw("*");
    move(19,15);
    printw("*");
    move(20,15);
    printw("*");
    move(21,15);
    printw("*");
    move(22,15);
    printw("*");
    move(23,15);
    printw("*");
    move(24,15);
    printw("*");
    move(25,15);
    printw("*");
    move(26,15);
    printw("*");
    move(27,15);
    printw("*");
    move(28,15);
    printw("*");
    move(29,15);
    printw("*");
    move(30,15);
    printw("*");
    move(31,15);
    printw("*");
    move(32,15);
    printw("*");
    move(33,15);
    printw("*");
    move(34,15);
    printw("*");
    move(35,15);
    printw("*");
    move(36,15);
    printw("*");
    move(37,15);
    printw("*");
    move(38,15);
    printw("*");
    move(39,15);
    printw("*");
    move(40,15);
    printw("*");
    move(41,15);
    printw("*");
    move(42,15);
    printw("*");
    move(43,15);
    printw("*");
    move(44,15);
    printw("*");

    //vertical derecha
    move(6,163);
    printw("*");
    move(7,163);
    printw("*");
    move(8,163);
    printw("*");
    move(9,163);
    printw("*");
    move(10,163);
    printw("*");
    move(11,163);
    printw("*");
    move(12,163);
    printw("*");
    move(13,163);
    printw("*");
    move(14,163);
    printw("*");
    move(15,163);
    printw("*");
    move(16,163);
    printw("*");
    move(17,163);
    printw("*");
    move(18,163);
    printw("*");
    move(19,163);
    printw("*");
    move(20,163);
    printw("*");
    move(21,163);
    printw("*");
    move(22,163);
    printw("*");
    move(23,163);
    printw("*");
    move(24,163);
    printw("*");
    move(25,163);
    printw("*");
    move(26,163);
    printw("*");
    move(27,163);
    printw("*");
    move(28,163);
    printw("*");
    move(29,163);
    printw("*");
    move(30,163);
    printw("*");
    move(31,163);
    printw("*");
    move(32,163);
    printw("*");
    move(33,163);
    printw("*");
    move(34,163);
    printw("*");
    move(35,163);
    printw("*");
    move(36,163);
    printw("*");
    move(37,163);
    printw("*");
    move(38,163);
    printw("*");
    move(39,163);
    printw("*");
    move(40,163);
    printw("*");
    move(41,163);
    printw("*");
    move(42,163);
    printw("*");
    move(43,163);
    printw("*");
    move(44,163);
    printw("*");

    
    
    

}
void borrar_enemigos(){
    int c=16;
    //borrar anterior
    while(c<=150){
        move(6,c);
        c++;
        init_pair(1,COLOR_BLACK,COLOR_BLACK);
        attron(COLOR_PAIR(1));
        printw(" ");
        move(7,c);
        printw(" ");

    }

}

void mover_enemigos(){
    start_color();
    int x=6,y=16;

    int cont1=0;

    int cont=0;
    int tx=x;
    int ty=y;
    int ty2=y+1;
    //borrar anterior
      init_pair(1,COLOR_BLUE,COLOR_BLUE);
      init_pair(2,COLOR_GREEN,COLOR_GREEN);

    
    //mover
    while(cont1<=50){
        borrar_enemigos();
        refresh();
       
         while(cont<=30){
            if(cont%2==0){
                attron(COLOR_PAIR(1));

                move(tx,ty);
                printw("+++");//5

                move(tx+1,ty2);
                printw("+");//3
                
                ty+=4;
                ty2+=4;
                cont++;

            }else{
                attron(COLOR_PAIR(2));

                move(tx,ty);
                printw("---");//5

                move(tx+1,ty2);
                printw("-");//3
                
                ty+=4;
                ty2+=4;
                cont++;
                }

        }
        usleep(5000);
        refresh();
        x++;
        y++;
        
    cont1++;
    y++;
    }




}
void crear_enemigos(){
    int tx=6;
    int ty=16;
    int ty2=16+1;
    int cont=0;
        while(cont<=30){
            if(cont%2==0){
                

            move(tx,ty);
            printw("+++");//5

            move(tx+1,ty2);
            printw("+");//3
            
            ty+=4;
            ty2+=4;
            cont++;

            }else{

            move(tx,ty);
            printw("---");//5

            move(tx+1,ty2);
            printw("-");//3
            
            ty+=4;
            ty2+=4;
            cont++;
            }
        }
        

       // move(tx+2,ty+2);
        //printw("+");





    /*for(int j=0;j<2;j++){

    
        for(int i=0;i<30;i+3){
            if(i%2==0){
                if(j==0)
                
                move(tx,ty+i);
                printw("+++");
                refresh();
               
            }else{
                if(j==0)
                
                move(tx,ty+i);
                printw("---");
                refresh();
            }
            if(j==1){

            }
        }
    }*/
    /*//init_pair(1,COLOR_YELLOW,COLOR_YELLOW);
        //dibujo de arriba hacia abajo
        //FILA 1
       //attron(COLOR_PAIR(1));
        move(tx,ty);
        printw("+++");//5

        move(tx+1,ty+1);
        printw("+");//3

       // move(tx+2,ty+2);
        //printw("+");*/



  /* int x=6;
    int y=21;
    
   // int tx,ty;

    for(int i=0;i<10;i++){
        
        e=new enemigos(x,y);
        v_enemigos.push_back(e);
        y+=9;
        if(i=10){
            x+=3;
            y=18;
        }else if(i==21){
            x+=3;
            y=18;
        }
    }*/
    /*for(int i=0;i<30;i++){
       tx= v_enemigos[i]->getx();
       ty=v_enemigos[i]->gety();
        
        move(tx,ty);
        printw("+++++");//5

        move(tx+1,ty+1);
        printw("+++");//3

        move(tx+2,ty+2);
        printw("+");
        refresh();
    }*/

}

void bala_enemigos(int num){
    
    start_color();
    init_pair(2,COLOR_WHITE,COLOR_WHITE);
    init_pair(1,COLOR_BLACK,COLOR_BLACK);
    //init_pair(3,COLOR_RED,COLOR_RED);
    
    int bx,by;
    int tx=6;
    int ty=16;
    int ty2=16+1;
    int cont=0;
    bx=18;
    by=num;
    while(cont<=30){
        if(cont==num){
                bx=num;
                by=18;
                for(int i=7;i<44;i++){
                    attron(COLOR_PAIR(1));
                    move(i+1,num);
                    printw(" ");
                    attron(COLOR_PAIR(2));
                    move(i,num);
                    printw(" ");
                    if(i==44){
                        attron(COLOR_PAIR(1));
                        move(i,num);
                        printw(" ");
                    }
                    usleep(5000);
                    refresh();
                }
        }
    }
               
        
}
void balas(int tx,int ty){
    init_pair(2,COLOR_WHITE,COLOR_WHITE);
    init_pair(1,COLOR_BLACK,COLOR_BLACK);
    init_pair(3,COLOR_RED,COLOR_RED);
    int cont=1;
    int x=tx-6;
    int y=ty+4;


    
      for(int i = tx-6; i >=6; i--){//fil
        
        
        attron(COLOR_PAIR(1));
        move(i+1,ty+4);
        printw(" ");

        attron(COLOR_PAIR(2));
        move(i,ty+4);
        printw(" ");


        if(i==6){
            attron(COLOR_PAIR(1));
            move(i,ty+4);
            printw(" ");
        }
        usleep(4000);
        refresh();
        
               

      }

          
}



void borrarnave(int x,int y){
    init_pair(4,COLOR_BLACK,COLOR_BLACK);
    
    attron(COLOR_PAIR(4));
   
    //fila 1 borrar
    move(x,y+1);
    printw("       ");
    //Fila 2 borrar
    move(x-1,y+2);
    printw("     ");
    //Fila 3
    move(x-2,y+3);
    printw("   ");
    //Fila 4
    move(x-3,y+4);
    printw(" ");


    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_RED,COLOR_RED);
    init_pair(3,COLOR_BLUE,COLOR_BLUE);
    //FILA 1
    attron(COLOR_PAIR(1));
    move(x,y+1);
    printw("       ");

    //FILA 2
    //blanco
    attron(COLOR_PAIR(2));
    move(x-1,y+2);
    printw("     ");
    
    
    //Fila 3
    //blanco
    attron(COLOR_PAIR(3));
    move(x-2,y+3);
    printw("   ");
    //fila 4
    move(x-3,y+4);
    printw(" ");

}

void move_nave_derecha(int x,int y){
    init_pair(1,COLOR_BLACK,COLOR_BLACK);
    init_pair(2,COLOR_WHITE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_RED);
    init_pair(4,COLOR_BLUE,COLOR_BLUE);
    
    attron(COLOR_PAIR(1));
   
    //fila 1 borrar
    move(x,y+1);
    printw("       ");
    //Fila 2 borrar
    move(x-1,y+2);
    printw("     ");
    //Fila 3
    move(x-2,y+3);
    printw("   ");
    //Fila 4
    move(x-3,y+4);
    printw(" ");

    //volver a dibujar
   //fila 1
    attron(COLOR_PAIR(2));
    move(x,y+2);
    printw("       ");
    //Fila 2
    attron(COLOR_PAIR(3));
    move(x-1,y+3);
    printw("     ");
    //fila 3
    attron(COLOR_PAIR(4));
    move(x-2,y+4);
    printw("   ");
    //Fila 4
    move(x-3,y+5);
    printw(" ");
}

void move_nave_izquierda(int x,int y){
     init_pair(1,COLOR_BLACK,COLOR_BLACK);
    init_pair(2,COLOR_WHITE,COLOR_WHITE);
    init_pair(3,COLOR_RED,COLOR_RED);
    init_pair(4,COLOR_BLUE,COLOR_BLUE);

    attron(COLOR_PAIR(1));
   
    //fila 1 borrar
    move(x,y+1);
    printw("       ");
    //Fila 2 borrar
    move(x-1,y+2);
    printw("     ");
    //Fila 3
    move(x-2,y+3);
    printw("   ");
    //Fila 4
    move(x-3,y+4);
    printw("  ");

    //volver a dibujar
    //fila 1
    attron(COLOR_PAIR(2));
    move(x,y);
    printw("       ");

}
void crear_nave(int x, int y){
    //LAS FILAS SE DIBUJARAN DE ABAJO HACIA ARRIBA
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_WHITE);
    init_pair(2,COLOR_RED,COLOR_RED);
    init_pair(3,COLOR_BLUE,COLOR_BLUE);
    //FILA 1
    attron(COLOR_PAIR(1));
    move(x,y+1);
    printw("       ");

    //FILA 2
    //blanco
    attron(COLOR_PAIR(2));
    move(x-1,y+2);
    printw("     ");
    
    
    //Fila 3
    //blanco
    attron(COLOR_PAIR(3));
    move(x-2,y+3);
    printw("   ");
    //fila 4
    move(x-3,y+4);
    printw(" ");
   
}