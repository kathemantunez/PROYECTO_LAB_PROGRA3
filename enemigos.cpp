#include "enemigos.h"
#include <iostream>

enemigos::enemigos(int _vida){
    vida=_vida;
}

int enemigos::getvida(){
    return vida;
}
 void enemigos::setvida(int _vida){
     vida=_vida;
 }
 int enemigos::getimpacto(){
     return impacto;
 }
 void enemigos::setimpacto(int _impacto){
     impacto=_impacto;
 }