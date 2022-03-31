#ifndef RESPONSABLE_H
#define RESPONSABLE_H
#include"vendeur.h"

class responsable:public vendeur
{
    public:
        responsable();
responsable(int,string,string ,float,int,float );
int get_ref(){return refer;}
    private:
     int nb_equipe;
     float prime;
};

#endif // RESPONSABLE_H
