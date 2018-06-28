#include <ncurses.h> //Libreria de Ncurses
#include <iostream>

int main(){

  int x = 10; //Corrdenadas de donde queres poner los pixeles en pantalla.
  int y = 10;

  bool salir = true;

  initscr();//Inicia la pantalla de ncurses

  start_color();//Inicializa el color

  init_pair(1, COLOR_RED, COLOR_RED);//Te deja elegir los colores
  init_pair(2,COLOR_BLACK, COLOR_BLACK);
  init_pair(3,COLOR_WHITE, COLOR_WHITE);

  while(salir){

    int tempX = x;//Temporales de valores originales que van cambiando.
    int tempY = y;

      move(x,y); //Moves el pixel a esa coordenada

      attron(COLOR_PAIR(3));//Pintas esa coordenada del color deseado
                            //En este caso es 3 que seria blanco.

      printw(" ");//Imprimis lo que deseas poner osea un espacio en blanco.

      char tecla = getch();//Agarras la tecla que el usuario toque.

    if(tecla == 'f'){

      salir = false;

    } else if(tecla == 'd'){ //Si es d va a mover a la derecha

      move(tempX,tempY);//Moves el temporal a esa posicion

      attron(COLOR_PAIR(2));// pintas de negro esa posicion

      printw("    ");//Imprimis un rastro de color negro

      y++;//Aumentas el eje y para que avance a la derecha.

    } else if(tecla == 'a'){//Si es "a" a la izquierda

      move(tempX,tempY);//Moves el temporal a esa posicion

      attron(COLOR_PAIR(2));// pintas de negro esa posicion


      printw("    ");//Imprimis un rastro de color negro

      y--;//Disminuis el eje y para que avance a la izquierda
    }

    refresh();//Refresca la pantalla en cada movimiento, esto va dentro del while
  }
  endwin();//Al salir de while termina la pantalla y la cierra.
}
