#ifndef VENGADORES_H
#define VENGADORES_H

class vengadores{

    protected:
        int vida;
        int puntos;


    public:

        vengadores(int,int);
        virtual bool ataque()=0;
        void setpuntos(int);
        int getpuntos();
        int getvidad();
        void setvidas(int);



};
#endif