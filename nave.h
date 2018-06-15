#ifndef NAVE_H
#define NAVE_H
#include <ncurses.h>

class nave{

    private:
        int size_x=7;
        int size_y=6;
        string navesita;

    public:
        nave();
        void crearnave(int,int);
        string getnave();
        

};
#endif