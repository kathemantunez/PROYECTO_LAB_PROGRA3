#ifndef THANOS_H
#define THANOS_H

#include "enemigos.h"

class thanos:public enemigos{
    protected:

    public:
     thanos(int);
     virtual bool ataque();

};
#endif