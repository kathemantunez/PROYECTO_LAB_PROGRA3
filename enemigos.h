#ifndef ENEMIGOS_H
#define ENEMIGOS_H

class enemigos{

    protected:
        int vida;
        int impacto;
        

    public:
        enemigos(int);
        virtual bool ataque()=0;
        int getimpacto();
        void setimpacto(int);
        int getvida();
        void setvida(int);

};
#endif