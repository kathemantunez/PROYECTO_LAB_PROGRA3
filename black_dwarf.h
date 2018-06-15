#ifndef BLACK_DWARF_H
#define BLACK_DWARF_H

#include "enemigos.h"

class black_dwarf:public enemigos{
    protected:

    public:
     black_dwarf(int);
     virtual bool ataque();

};
#endif