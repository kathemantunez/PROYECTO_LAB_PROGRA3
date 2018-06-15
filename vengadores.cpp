#include "vengadores.h"
#include <iostream>

vengadores::vengadores(int _vida,int _puntos){
  vida=_vida;
  puntos=_puntos;
  
}
        
void vengadores::setpuntos(int _puntos){
        
}
int vengadores::getpuntos(){
    return puntos;
}
int vengadores::getvidad(){
    return vida;

}
void vengadores::setvidas(int _vida){
    vida=_vida;
}
