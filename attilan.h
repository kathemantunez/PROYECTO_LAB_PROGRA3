#ifndef ATTILAN_H
#define ATTILAN_H

#include "enemigos.h"

class attilan:public enemigos{
    protected:

    public:
     attilan(int);
     virtual bool ataque();

};
#endif